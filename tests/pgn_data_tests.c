#include <criterion/criterion.h>
#include "../src/pgn_parser.h"

// Test pgn lines:
char *event_line =        "[Event \"Rated Correspondence game\"]";
char *site_line =         "[Site \"htttps://lichess.org/AbcDef12\"]";
char *date_line =         "[Date \"2021.02.22\"]";
char *white_line =        "[White \"white name\"]";
char *black_line =        "[Black \"black name\"]";
char *result_line =       "[Result \"O-1\"]";
char *utc_date_line =     "[UTCDate \"2021.02.22\"]";
char *utc_time_line =     "[UTCTime \"14:58:55\"]";
char *white_elo_line =    "[WhiteElo \"1522\"]";
char *black_elo_line =    "[BlackElo \"1752\"]";
char *white_diff_line =   "[WhiteRatingDiff \"-2\"]";
char *black_diff_line =   "[BlackRatingDiff \"+5\"]";
char *variant_line =      "[Variant \"Standard\"]";
char *time_control_line = "[TimeControl \"-\"]";
char *termination_line =  "[Termination \"Normal\"]";
char *moves_line = "1. e4 e5 2. Nf3 Nf6 3. Nxe5 Nc6 4. Nxf7 1-0";

char sep = ' ';

void suite_setup(void)
{
}

void suite_teardown(void)
{
}

TestSuite(splitter_tests, .init=suite_setup, .fini=suite_teardown);

Test(splitter_tests, sep_index_test)
{
  cr_expect(sep_index(sep, event_line) == 6, "'[Event ' first space is at 6");
}

Test(splitter_tests, is_event_test)
{
  cr_expect(is_event(event_line) == true, "is_event should recognize false for '[Event '");
}

Test(splitter_tests, is_site_test)
{
  cr_expect(is_site(site_line) == true, "is_site should return true for '[Site ...'");
}

Test(splitter_tests, is_date_test)
{
  cr_expect(is_date(date_line) == true, "is_date should return true for '[Date ...'");
}

Test(splitter_tests, is_white_test)
{
  cr_expect(is_white(white_line) == true, "is_white should recognize true for '[White ...'");
}

Test(splitter_tests, is_black_test)
{
  cr_expect(is_black(black_line) == true, "is_black should return true for '[Black ...'");
}

Test(splitter_tests, is_result_test)
{
  cr_expect(is_result(result_line) == true, "is_result should return true for '[Result ...'");
}

Test(splitter_tests, is_utc_date_test)
{
  cr_expect(is_utc_date(utc_date_line) == true, "is_utc_date should return true for '[UTCDate ...'");
}

Test(splitter_tests, is_utc_time_test)
{
  cr_expect(is_utc_time(utc_time_line) == true, "is_utc_time should return true for '[UTCTime ...'");
}

Test(splitter_tests, is_white_elo_test)
{
  cr_expect(is_white_elo(white_elo_line) == true, "is_white_elo should return true for '[WhiteElo ...'");
}

Test(splitter_tests, is_black_elo_test)
{
  cr_expect(is_black_elo(black_elo_line) == true, "is_black_elo should return true for '[Result ...'");
}

Test(splitter_tests, is_white_rating_diff_test)
{
  cr_expect(is_white_rating_diff(white_diff_line) == true, "is_white_rating_diff should return true for '[WhiteRatingDiff ...'");
}

Test(splitter_tests, is_black_rating_diff_test)
{
  cr_expect(is_black_rating_diff(black_diff_line) == true, "is_black_rating_diff should return true for '[BlackRatingDiff ...");
}

Test(splitter_tests, is_variant_test)
{
  cr_expect(is_variant(variant_line) == true, "is_variant should return true for '[variant ...'");
}

Test(splitter_tests, is_termination_test)
{
  cr_expect(is_termination(termination_line) == true, "is_termination should return true for '[Termination ...'");
}

Test(splitter_tests, is_moves_test)
{
  cr_expect(is_moves(moves_line) == true, "is_moves should return true for '1. e4 e5 2. Nf3 Nf6 ...'");
}
