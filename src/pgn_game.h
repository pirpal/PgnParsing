#ifndef PGN_GAME_H
#define PGN_GAME_H

typedef struct PgnGame
{
  char *event[MAXCHAR];         //8 "Live Tournament xxx"
  char *site[MAXCHAR];          //8 "Chess.com",
  char *date[MAXCHAR];          //8 "Rated Rapid game", etc (grep it)
  char *round[MAXCHAR];         //8 "?", "Round 1", etc
  char *white[MAXCHAR];         //8 "Alireza Firoujza"
  char *black[MAXCHAR];         //8 "Magnus Carlsen"
  char *result[MAXCHAR_RESULT]; //8 "1-0" | "0-1" | "1/2-1/2"
  char *eco[MAXCHAR_ECO];       //8 "C41", "D00", etc
  unsigned int white_elo;       //8 ELO should not be negative,
  unsigned int black_elo;       //8 < to ~600 ? (TODO check)
                                //8 or superior to ??
  char *termination[MAXCHAR];   //8 "blackname won by resignation"
  char *time_control[MAXCHAR]; 
  // Time Control:
  // "-" if not, or:
  // format: "minutes as seconds + increment in seconds" :  
  // "300+3" =  5min + 3sec
  // "600+0" =  10min + 0sec, etc
} PgnGame;



#endif // PGN_GAME_H
