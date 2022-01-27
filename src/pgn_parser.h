#ifndef PGN_PARSER_H
#define PGN_PARSER_H

#include <stdbool.h>

#define EVENT_HEADER "[Event "
#define SITE_HEADER "[Site "
#define DATE_HEADER "[Date "
#define WHITE_HEADER "[White "
#define BLACK_HEADER "[Black "
#define RESULT_HEADER "[Result "
#define UTCDATE_HEADER "[UTCDate "
#define UTCTIME_HEADER "[UTCTime "
#define WHITEELO_HEADER "[WhiteElo "
#define BLACKELO_HEADER "[BlackElo "
#define WHITERATINGDIFF_HEADER "[WhiteRatingDiff "
#define BLACKRATINGDIFF_HEADER "[BlackRatingDiff "
#define VARIANT_HEADER "[Variant "
#define TIMECONTROL_HEADER "[TimeControl "
#define ECO_HEADER "[ECO "
#define TERMINATION_HEADER "[Termination "
#define MOVES_PATTERN "1. "


int sep_index(char sep, char *line);

bool is_event(char *line);
bool is_site (char *line);
bool is_date(char *line);
bool is_white(char *line);
bool is_black(char *line);
bool is_result(char *line);
bool is_utc_date(char *line);
bool is_utc_time(char *line);
bool is_white_elo(char *line);
bool is_black_elo(char *line);
bool is_white_rating_diff(char *line);
bool is_black_rating_diff(char *line);
bool is_variant(char *line);
bool is_time_control(char *line);
bool is_termination(char *line);
bool is_moves(char *line);
char *get_value(char *line, bool quoted);

#endif // PGN_PARSER_H
