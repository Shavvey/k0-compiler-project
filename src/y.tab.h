#ifndef INCLUDE_SRC_YTAB_H_
#define INCLUDE_SRC_YTAB_H_
// include filename and linenumber of file we are currently tokenizing
extern const char *filename;
extern int lineno;
// control values, not a part of synatx
#define ERRNO -1 // error value
#define EOFNO -2 // end-of-file value

#define ADD 258 
#define MULT 259 
#define DIV 260 
#define MOD 261 
#define SUB 262 
#define ASSIGNMENT 263 
#define ADD_ASSIGNMENT 264 
#define SUB_ASSIGNMENT 265 
#define MULT_ASSIGNMENT 266 
#define DIV_ASSIGNMENT 267 
#define MOD_ASSIGNMENT 268 
#define DOT 269 
#define COMMA 270 
#define INCR 271 
#define DECR 272 
#define CONJ 273 
#define DISJ 274 
#define EXCL_WS 275 
#define EXCL_NO_WS 276 
#define QUEST_WS 277 
#define QUEST_NO_WS 278 
#define LANGLE 279 
#define RANGLE 280 
#define LE 281 
#define GE 282 
#define EXCL_EQ 283 
#define EXCL_EQEQ 284 
#define EQEQ 285 
#define EQEQEQ 286 
#define FUN 287 
#define VAL 288 
#define VAR 289 
#define IF 290 
#define ELSE 291 
#define FOR 292 
#define DO 293 
#define WHILE 294 
#define RETURN 295 
#define CONTINUE 296 
#define BREAK 297 
#define INTEGERLITERAL 298 //NOTE: collaspes bin, hex
#define BINLITERAL 299 
#define HEXLITERAL 300 
#define DOUBLELITERAL 301 
#define FLOATLITERAL 302 
#define REALLITERAL 303 //NOTE: collopses float, double
#define BOOLEANLITERAL 304 
#define NULLLITERAL 305 
#define CHARACTERLITERAL 306 
#define STRINGLITERAL 307 
#define IDENTIFIER 308 
#define LPAR 309 
#define RPAR 310 
#define LSQUARE 311 
#define RSQUARE 312 
#define COLON 313 //NOTE: we may need white space version of this token
#define SEMICOLON 314 
#define LCURL 315 
#define RCURL 316 
#define EXCL_EXCL 317 
#define RANGE 318 
#define RANGE_UNTIL 319 //NOTE: Kotlin spec doesn't include this? Figure out why
#define CONST 320 
#define IMPORT 321 
#define HASH 322 //NOTE: This will just be like a comment for now
#define IN 323

#define TABLE_SIZE 66
#define MAX_LENGTH 17
static const char ytab_ltable[TABLE_SIZE][MAX_LENGTH] = {
	"ADD",
	"MULT",
	"DIV",
	"MOD",
	"SUB",
	"ASSIGNMENT",
	"ADD_ASSIGNMENT",
	"SUB_ASSIGNMENT",
	"MULT_ASSIGNMENT",
	"DIV_ASSIGNMENT",
	"MOD_ASSIGNMENT",
	"DOT",
	"COMMA",
	"INCR",
	"DECR",
	"CONJ",
	"DISJ",
	"EXCL_WS",
	"EXCL_NO_WS",
	"QUEST_WS",
	"QUEST_NO_WS",
	"LANGLE",
	"RANGLE",
	"LE",
	"GE",
	"EXCL_EQ",
	"EXCL_EQEQ",
	"EQEQ",
	"EQEQEQ",
	"FUN",
	"VAL",
	"VAR",
	"IF",
	"ELSE",
	"FOR",
	"DO",
	"WHILE",
	"RETURN",
	"CONTINUE",
	"BREAK",
	"INTEGERLITERAL",
	"BINLITERAL",
	"HEXLITERAL",
	"DOUBLELITERAL",
	"FLOATLITERAL",
	"REALLITERAL",
	"BOOLEANLITERAL",
	"NULLLITERAL",
	"CHARACTERLITERAL",
	"STRINGLITERAL",
	"IDENTIFIER",
	"LPAR",
	"RPAR",
	"LSQUARE",
	"RSQUARE",
	"COLON",
	"SEMICOLON",
	"LCURL",
	"RCURL",
	"EXCL_EXCL",
	"RANGE",
	"RANGE_UNTIL",
	"CONST",
	"IMPORT",
	"HASH",
  "IN"
};

#endif  // INCLUDE_SRC_YTAB_H_
