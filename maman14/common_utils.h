#ifndef _COMMOM_UTILS_H_
#define _COMMOM_UTILS_H_

/*

In this file you can find various defines
and structures that were used in the program in 
a variety of files

*/

#define MAX_NAME_FILE_LEN 		(80)
#define MAX_SYMBOL_STR_LEN	 	(32)
#define MAX_LINE_LEN 			(82)
#define START_OF_IC 			(100)
#define LEN_REGISTER_BIN 		(4)
#define LEN_OPP_CODE 			(5)
#define BINARY_WORD_STR_LEN		(15)
#define DIRECTIVE_MACRO_LEN_STR 	(7)
#define NOT_USE_4_BITS 			(4)
#define OPPCODE_BITS 			(4) 
#define INITIALIZATION 			(-1)
#define PRE_ARE_BIN_WORD_IDX		(11)
#define POST_TARGET_BIN_WORD_IDX	(10)
#define NUM_ARE_BITS			(2)
#define NUM_ADDRESSING_BITS		(2)
#define QUAT_WORD_STR_LEN		(8)
#define EOF_MESSAGE			(4)
#define THERE_IS_NO_COMMA		(0)
#define TO_MANY_COMMA			(2)
#define	COMMA_AND_THEN_EOF 		(3)
#define COMMA_OK			(1)
#define NO_MIAON			(-3)
#define INVALD_NUMBER			(-10)
#define TOO_LOW_NUMBER			(-11)
#define TOO_HIGH_NUMBER			(-12)

typedef enum {DIRECTIVE_DEFAULT, DIRECTIVE_DEFINE, DIRECTIVE_EXTERN, DIRECTIVE_STRING, DIRECTIVE_DATA, DIRECTIVE_ENTRY} directive_type;

typedef enum {SENTENCE_DEFAULT, SENTENCE_NOP, SENTENCE_COMMENT, SENTENCE_DIRECTIVE, SENTENCE_INSTRUCTION, SENTENCE_MACRO,SENTENCE_EXTERN, SENTENCE_ERROR} sentence_type;

#ifndef ENUM_BOOL
#define ENUM_BOOL
typedef enum { FALSE, TRUE } BOOL;
#endif /* ENUM_BOOL */



#endif /* COMMOM_UTILS_H */

