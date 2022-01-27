CC=gcc
CFLAGS=-g -Wall -Wextra

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
TEST_DIR=tests
TEST_BIN_DIR=$(TEST_DIR)/bin
TEST_LINK=-lcriterion

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TESTS=$(wildcard $(TEST_DIR)/*.c)
TEST_OBJS=$(subst $(OBJ_DIR)/main.o,,$(OBJS))

BIN=$(BIN_DIR)/prog
TESTBINS=$(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TESTS))

all: $(BIN)

# create executable from objects:
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# create an object file for each C source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# create an executable test for each test source file:
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $< $(TEST_OBJS) -o $@ $(TEST_LINK)

# run tests:
test: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done


# remove objects and executables:
clean:
	rm $(OBJ_DIR)/*.o $(BIN_DIR)/* $(TEST_BIN_DIR)/*


