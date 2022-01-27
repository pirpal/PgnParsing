#include <string.h>
#include "pgn_parser.h"

int sep_index(char sep, char *line)
{
  int si = 0;
  for (unsigned int i = 0; i < strlen(line); i++) {
    if (line[i] == sep) {
      return i;
    }
  }
  return si;
}

bool is_event(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(EVENT_HEADER); i++) {
    if (line[i] != EVENT_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_site(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(SITE_HEADER); i++) {
    if (line[i] != SITE_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_date(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(DATE_HEADER); i++) {
    if (line[i] != DATE_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_white(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(WHITE_HEADER); i++) {
    if (line[i] != WHITE_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_black(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(BLACK_HEADER); i++) {
    if (line[i] != BLACK_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_result(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(RESULT_HEADER); i++) {
    if (line[i] != RESULT_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_utc_date(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(UTCDATE_HEADER); i++) {
    if (line[i] != UTCDATE_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_utc_time(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(UTCTIME_HEADER); i++) {
    if (line[i] != UTCTIME_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_white_elo(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(WHITEELO_HEADER); i++) {
    if (line[i] != WHITEELO_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_black_elo(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(BLACKELO_HEADER); i++) {
    if (line[i] != BLACKELO_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_white_rating_diff(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(WHITERATINGDIFF_HEADER); i++) {
    if (line[i] != WHITERATINGDIFF_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_black_rating_diff(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(BLACKRATINGDIFF_HEADER); i++) {
    if (line[i] != BLACKRATINGDIFF_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_variant(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(VARIANT_HEADER); i++) {
    if (line[i] != VARIANT_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_time_control(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(TIMECONTROL_HEADER); i++) {
    if (line[i] != TIMECONTROL_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_eco(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(ECO_HEADER); i++) {
    if (line[i] != ECO_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_termination(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(TERMINATION_HEADER); i++) {
    if (line[i] != TERMINATION_HEADER[i]) {
      return false;
    }
  }
  return r;
}

bool is_moves(char *line)
{
  bool r = true;
  for (unsigned int i = 0; i < strlen(MOVES_PATTERN); i++) {
    if (line[i] != MOVES_PATTERN[i]) {
      return false;
    }
  }
  return r;
}

