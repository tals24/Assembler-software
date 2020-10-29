#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "asembler.h"

/*
	checks if the given character is alpha_beta
	inputs:
		c - character to check
*/
BOOL is_alpha_beta(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


/*
	checks if the given character is tab or space
	input:
		c - character to check
*/
int is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

/*
	gets a line and checks if the next word is an opcode and returns its binary value
	input:
		cmd - current line
		code - stores the opcode number
		sentence_check - stores if the line is a directive line
		oppcode_str - stored the opcode binary value
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
		first_pass_bool - BOOL to check if eror message print alredy in the first pass 
*/
char* op_code_check(char* cmd,int* code,sentence_type* sentence_check,char* oppcode_str, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool)
{
	char op_check_string[MAX_LINE_LEN]; 
	int i =0;
	while (!is_whitespace(*cmd) && *cmd != '\n')
	{
		*(op_check_string +i) = *cmd;
		i++;
		cmd++;
	}
	*(op_check_string +i) = 0;
	if (strcmp(op_check_string,"stop") == 0)
	{
		*code = 15;
		strcpy(oppcode_str,"1111");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"mov") == 0)
	{
		*code = 0;
		strcpy(oppcode_str,"0000");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}		
	else if (strcmp(op_check_string,"cmp") == 0)
	{
		*code = 1;
		strcpy(oppcode_str,"0001");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}
	else if (strcmp(op_check_string,"add") == 0)
	{
		*code = 2;
		strcpy(oppcode_str,"0010");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"sub") == 0)
	{
		*code = 3;
		strcpy(oppcode_str,"0011");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"not") == 0)
	{
		*code = 4;
		strcpy(oppcode_str,"0100");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"clr") == 0)
	{
		*code = 5;
		strcpy(oppcode_str,"0101");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"lea") == 0)
	{
		*code = 6;
		strcpy(oppcode_str,"0110");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"inc") == 0)
	{
		*code = 7;
		strcpy(oppcode_str,"0111");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"dec") == 0)
	{
		*code = 8;
		strcpy(oppcode_str,"1000");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"jmp") == 0)
	{
		*code = 9;
		strcpy(oppcode_str,"1001");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"bne") == 0)
	{
		*code = 10;
		strcpy(oppcode_str,"1010");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"red") == 0)
	{
		*code = 11;
		strcpy(oppcode_str,"1011");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"prn") == 0)
	{
		*code = 12;
		strcpy(oppcode_str,"1100");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"jsr") == 0)
	{
		*code = 13;
		strcpy(oppcode_str,"1101");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}	
	else if (strcmp(op_check_string,"rts") == 0)
	{
		*code = 14;
		strcpy(oppcode_str,"1110");
		*sentence_check = SENTENCE_INSTRUCTION;
		return cmd;
	}
	else
	{
		*code = 16;
		if(first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: the code is \"%s\" iligel\n",
						file_name,line_counter,op_check_string);
			*failure_flag = TRUE;
		}
		*sentence_check = SENTENCE_DEFAULT;	
		return cmd;
	}
}
/* 
	checks if a given string is not a saved name
	input:
		macro_name - string to check
*/
BOOL isnot_saved_name(char* macro_name)
{
		
	if (strcmp(macro_name,"stop") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"mov") == 0)
	{
		return FALSE;
	}		
	if (strcmp(macro_name,"cmp") == 0)
	{
		return FALSE;
	}
	if (strcmp(macro_name,"add") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"sub") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"not") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"clr") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"lea") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"inc") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"dec") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"jmp") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"bne") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"red") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"prn") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"jsr") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"rts") == 0)
	{
		return FALSE;
	}
	if (strcmp(macro_name,"r0") == 0)    /*REGISTER*/ 
	{
		return FALSE;
	}
	if (strcmp(macro_name,"r1") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"r2") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"r3") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,"r4") == 0)
	{
		return FALSE;
	}
	if (strcmp(macro_name,"r5") == 0)
	{
		return FALSE;
	}
	if (strcmp(macro_name,"r6") == 0)
	{
		return FALSE;
	}
	if (strcmp(macro_name,"r7") == 0)
	{
		return FALSE;
	}
	if (strcmp(macro_name,".data") == 0) /* הנחיה*/
	{
		return FALSE;
	}	
	if (strcmp(macro_name,".string") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,".entry") == 0)
	{
		return FALSE;
	}	
	if (strcmp(macro_name,".extern") == 0)
	{
		return FALSE;
	}	
	return TRUE;

}

/* 
	checks if a given string is all digits
	input:
		macro_name - string to check
*/
BOOL is_all_digits (char* check_str)	
{
	if (*check_str == '+' || *check_str == '-')
	{
		check_str++;
	}
	while (*check_str != 0)
	{
		if (!(*check_str >= '0' && *check_str <= '9'))
		{
			return FALSE;
		}
		check_str++;
	}
	return TRUE;
}

/* 
	checks if a the first character in a given string is a digit
	input:
		macro_name - string to check
*/
BOOL if_first_isnot_digit (char* macro_name)
{
	if (!(*macro_name >= '0' && *macro_name <= '9'))
	{
		return TRUE;
	}
	return FALSE;
}


/* The method extract number if there is or send eror flag if the parametr illegal 	
	input:
		cmd - current line
		macro_val - ptr for number
		check_num - flag for wrong input num
*/
char* extract_number(char* cmd, int* macro_val, int* check_num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag,BOOL first_pass_bool)
{
	char* ptr;
	char* ptr_cmd = cmd;
	double num;
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	ptr_cmd = cmd;
	num = strtod(ptr_cmd, &ptr);
	*macro_val = num;
	if (ptr_cmd == ptr)       /*strtod faild, invald number */
	{
		*check_num = 0;
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: Invald number!\n",file_name,line_counter);
		}
		*failure_flag = TRUE;
		return ptr_cmd;
	}
	if(!checking_num(num,line_counter,file_name,ferr,failure_flag,first_pass_bool)) 
		/*check if the num in the limit */
	{
		*check_num = 0;	 /*not in the limit */
		return ptr_cmd;
	}
	*check_num = 1;
	return ptr;
}
/* The method check if the cur line is macro Declaration, return bool_flag 0 if its not a define sentence, return err_check TRUE if there is a problem in the Declaration of current macro 
	input:
		cmd 		- current line
		macro_name 	- ptr for the address of the macro name
		macro_val 	- ptr for the value of the macro
		sentence_check  - ptr for the sentence type
		bool_flag	- flag for macro. 0 means its not DIRECTIVE_DEFINE
		line_counter	- current line number
		file_name 	- the name of current file
		ferr		- ptr to eror file	
		failure_flag 	- ptr to BOOL to check if there is fail	
		first_pass_bool - bool for checking if we are in the first pass in case we need to print eror
		err_check	- bool for checking if the macro is ligel

*/

char* is_macro (char* cmd,char* macro_name, int* macro_val, sentence_type* sentence_check, int* bool_flag, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool,BOOL* err_check) 
{
	char* copy_cmd = cmd;
	int i =0;
	int check_num = 0;
	directive_type directive_check;
	if (*cmd != '.')   /* not DIRECTIVE_DEFINE */
	{
		*bool_flag = 0;
		return copy_cmd;
	}
	if(first_pass_bool == FALSE)  /* second pass, move on */
	{
		*bool_flag = 1;
		return copy_cmd;
	}
	cmd++;
	cmd = dotecheck (cmd , &directive_check);
	if (directive_check != DIRECTIVE_DEFINE)
	{
		*bool_flag = 0;
		return copy_cmd;
	}
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	while(*cmd != '=' && !(is_whitespace(*cmd)))  /*catch the macro name */
	{
		macro_name[i] = *cmd;
		i++;
		cmd++;
	}
	macro_name[i] = 0;
	if (isnot_saved_name(macro_name)== FALSE)
	{
		*bool_flag = 0;
		*err_check = TRUE;
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: the name - \"%s\" for macro is a saved name!\n",
						file_name,line_counter,macro_name);
		}
		*failure_flag = TRUE;
		return copy_cmd;
	}			
	if (is_all_digits(macro_name)== TRUE)
	{
		*bool_flag = 0;
		*err_check = TRUE;
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: the name - \"%s\" for macro is FULL WITH JUST DIGITS!\n",file_name,line_counter,macro_name);
		}
		*failure_flag = TRUE;
		return copy_cmd;
	}					
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	if (*cmd != '=')
	{
		*bool_flag = 0;
		*err_check = TRUE;
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: in the  name - \"%s\"   for macro there is no = after space!\n",file_name,line_counter,macro_name);
		}
		*failure_flag = TRUE;
		return copy_cmd;
	}	
	cmd++;
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	/* extract the value of the macro */
	cmd = extract_number(cmd , macro_val,&check_num,line_counter,file_name,ferr,failure_flag,first_pass_bool);
	if (check_num == 0)  /*if there is a problem in the macro val Declaration */
	{
		*bool_flag = 0;
		*err_check = TRUE;
		return copy_cmd;
	}
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	if ( *cmd != '\n' )
	{
		*bool_flag = 0;
		*err_check = TRUE;
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: in the  name - \"%s\" for macro there more char after the number\n",file_name,line_counter,macro_name);
		}
		*failure_flag = TRUE;
		return copy_cmd;
	}
	*sentence_check = SENTENCE_MACRO;
	*bool_flag = 1;
	return cmd;
}

/*
	checks what comes after a dot in an assembly line
	input:
		cmd - current part in the parsed line
		directive - pointer used to store the directive type of the result
*/
char* dotecheck (char* cmd,directive_type* directive) 
{
	char* copy_cmd = cmd;
	char dote_check_string[MAX_LINE_LEN]; 
	int i = 0;
	while (!is_whitespace(*cmd))
	{
		*(dote_check_string +i) = *cmd;
		i++;
		cmd++;
	}
	*(dote_check_string +i) = 0;
	if (strcmp(dote_check_string,"define") == 0)  /*macro */ 
	{
		*directive = DIRECTIVE_DEFINE;
		return cmd;
	}
	else if (strcmp(dote_check_string,"extern") == 0)
	{
		*directive = DIRECTIVE_EXTERN;
	}
	else if (strcmp(dote_check_string,"string") == 0)
	{
		*directive = DIRECTIVE_STRING;
	}
	else if (strcmp(dote_check_string,"data") == 0)
	{
		*directive = DIRECTIVE_DATA;
	}
	else if (strcmp(dote_check_string,"entry") == 0)
	{
		*directive = DIRECTIVE_ENTRY;
	}
	else
	{
		*directive = DIRECTIVE_DEFAULT;	
		return copy_cmd;
	}
	return cmd;
}

/*
	extracts the first word a given line and checks if it is a label
	input:
		cmd - current line
		lbl_name -if label is found used to store the label name
		LBL_FLAG - stores true if a label is found
		lbl_error - stores false if there is eror in label
*/
char* extract_lbl(char* cmd, char* lbl_name ,int* LBL_FLAG, BOOL * lbl_error)
{
	int i= 0;
	char* copy_cmd = cmd;
	BOOL alpha_numeric = TRUE;
	if (!is_alpha_beta(*copy_cmd)) /* didnt start in alpha_beta */
	{
		*LBL_FLAG = 0;
		*lbl_error = TRUE;
		return cmd;
	}
	while (*copy_cmd != ':' && !(is_whitespace(*copy_cmd)))
	{
		lbl_name[i] = *copy_cmd;
		if (!((*copy_cmd >= '0' && *copy_cmd <= '9') || (is_alpha_beta(*copy_cmd))))
		{
			alpha_numeric = FALSE;   /*if there is char that not alph_beta or number */
		}
		i++;
		copy_cmd++;
	}
	lbl_name[i] = 0;
	if (*copy_cmd != ':')
	{
		*LBL_FLAG = 0;
		return cmd; 
	}
	else
	{
		if (!alpha_numeric)	/*if there is char that not alph_beta or number */
		{
			*LBL_FLAG = 0;
			*lbl_error = TRUE;
			return cmd;
		}
		*LBL_FLAG = 1;
	}
	copy_cmd++;
	return copy_cmd;
}

/*
	 check if the line is sentence directive or not
	input:
		cmd - current line
		cd_counter - count how many dc line
		sentence_check - check whice sentece it is
		flag - return 0 if the sentence is not directive
		directive - ptr that send to "dotecheck" for checking the directive type
*/

char* is_directive (char* cmd,int* cd_counter,sentence_type* sentence_check,int* flag, directive_type* directive) 
{
	char* copy_cmd = cmd;
	*flag = 1;
	*sentence_check = SENTENCE_DEFAULT;
	if (*cmd != '.')
	{
		*flag = 0;
		return copy_cmd;
	}
	cmd++;
	cmd = dotecheck (cmd , directive);
	if (*directive == DIRECTIVE_EXTERN)
	{
		*sentence_check = SENTENCE_DIRECTIVE;
		return cmd;
	}
	if (*directive == DIRECTIVE_STRING)
	{
		*sentence_check = SENTENCE_DIRECTIVE;
		return cmd;
	}
	if (*directive == DIRECTIVE_DATA)
	{
		*sentence_check = SENTENCE_DIRECTIVE;
		return cmd;
	}	
	if (*directive == DIRECTIVE_ENTRY)
	{
		*sentence_check = SENTENCE_DIRECTIVE;
		return cmd;
	}
	if (*directive == DIRECTIVE_DEFAULT)
	{
		*sentence_check = SENTENCE_ERROR;
		return cmd;
	}
/*	if (*directive == DIRECTIVE_DEFINE || *directive == DIRECTIVE_DEFAULT)*/
	*flag = 0;
	return copy_cmd;
}

/* The method extract comma if there is comma, and sends a number of error options. returns a pointer to the array after the end of comma or before if there is eror 
	input:
		cmd = cur line
		check = ptr for eror message
 */
char* extract_comma(char* cmd,int * check)
{
	char* ptrC = cmd + 1;
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	while (is_whitespace(*ptrC))
	{
		ptrC++;
	}
	if (*cmd == 0)   			/*EOF*/
	{
		*check = EOF;
		return cmd;
	}	
	if (*cmd != ',')  		 /*There is not comma */
	{
		*check = THERE_IS_NO_COMMA;
		return cmd;
	}
	if ((*cmd == ',')&&(*ptrC == ','))  /* To manny comma */
	{
		*check = TO_MANY_COMMA;
		return cmd;
	}
	if ((*cmd == ',')&&(*ptrC == 0))  /* Comma and then EOF*/
	{
		*check = COMMA_AND_THEN_EOF;
		return cmd;
	}
	else	
	{
		*check = COMMA_OK;
		cmd++;
		return cmd;
	}
}

/*
	counts how many numbers and macros are in .data type of line and add the values to
	the binary table
	input:
		cmd - current line
		sym_tbl - symbol table - used to check macros
		data_bin - binary table - used to represent the data segment, the 
		binary translation is added to this structure
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
*/
int how_many_parm_data(char * cmd, BinaryTable * data_bin,SymbolTable* sym_tbl,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag)
{
	int counter = 0;
	char curr_data[MAX_SYMBOL_STR_LEN];   /* MACRO FOR 10 */
	char bin_array[BINARY_WORD_STR_LEN] = {0};
	int num;
	int i = 0;
	while (*cmd != 0)
	{
		i=0;
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		while (!is_whitespace(*cmd) && *cmd != ',' && *cmd != '\n' )
		{
			curr_data[i++] = *cmd;
			cmd++;
		}
		curr_data[i] = 0;
		/*check if only digits*/
		if (is_all_digits (curr_data) == TRUE)
		{
			num = atoi(curr_data);
			if (!checking_num(num,line_counter,file_name,ferr,failure_flag,TRUE))
			{
					return -1;
			}
		}
		else
		{
			if (get_value_by_lbl(sym_tbl,curr_data,&num)== FALSE) /* get macro val from stn_tbl*/
			{
				fprintf(ferr,"file- %s.as, line- %d:: there is no macro with this name -  \"%s\" \n",
							file_name,line_counter,curr_data);
				*failure_flag = TRUE;
				return -1;
			}
		}	
		/*at this point we have a number in num*/
		decToBinary_for_data_string(num,bin_array);
		/* now add to data list*/
		add_to_binary_table(data_bin,bin_array,-1,line_counter,file_name,ferr, failure_flag);
		counter++ ;
		cmd++;
	}
	return counter;
}

/*
	counts how many characters are in .string type of line and add the values to
	the binary table
	input:
		cmd - current line
		data_bin - binary table - used to represent the data segment, the 
		binary translation is added to this structure
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
*/

int how_many_char_string(char * cmd, BinaryTable * data_bin,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag)
{
	int counter = 1;  /*-1 for skip the line */
	char ch;
	char last_not_apos = 0;
	int count_apos_index = 0;
	int count_apos = 0;
	char* copy_cmd ;
	char bin_array[BINARY_WORD_STR_LEN] = {0};
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	if (*cmd != '"')
	{
		fprintf(ferr,"file- %s.as, line- %d:: there is string without \"   \n",
					file_name,line_counter);
		*failure_flag = TRUE;
		counter = -1;
		return counter;
	}
	cmd++;	
	copy_cmd = cmd;
	
	
	
	while(*copy_cmd != 0 && *copy_cmd != '\n')
	{
		if (*copy_cmd == '"')
		{
			count_apos++;
		}
		if (!is_whitespace(*copy_cmd)) last_not_apos = *copy_cmd;
		copy_cmd++;
	}
	
	if (!count_apos || (last_not_apos != '"'))
	{
		fprintf(ferr,"file- %s.as, line- %d:: there is string without \" at the end of string   \n",
					file_name,line_counter);
		*failure_flag = TRUE;
		counter = -1;
		return counter;
	}
	
	while (count_apos_index != count_apos)
	{
		ch = *cmd;
		cmd++;
		if (ch == '"')
		{
			count_apos_index++;	
			if (count_apos == count_apos_index) break;
		}
		counter++;
		/*at this point we have a char in ch*/
		decToBinary_for_data_string(ch,bin_array);		
		/* now add to data list*/
		add_to_binary_table(data_bin,bin_array,-1,line_counter,file_name,ferr, failure_flag);	
	}
	
	decToBinary_for_data_string(0,bin_array);
	/* now add to data list*/
	add_to_binary_table(data_bin,bin_array,-1,line_counter,file_name,ferr, failure_flag);
	return counter;
}


/*
	returns the number of operands for a given opcode num
	input:
		code - the opcode number
*/
int how_many_opp(int code)
{
	if (code == 0 || code == 1 ||code == 2 ||code == 3 || code == 6)
	{
		return 2;
	}
	if (code == 4 || code == 5 ||code == 7 ||code == 8 || code == 9|| code == 10|| code == 11|| code == 12|| 				code == 13)
	{
		return 1;
	}
	return 0 ;
}

/*
	gets the next operand and its addressing method
	input:
		cmd - current line
		miaon - used to store the current addressing method
		opp_string - used to store the current operand
		r_num - if the operand is a register then r_num stores its binary reg num
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
		first_pass_bool - BOOL to check if eror message print alredy in the first pass 
*/
char* get_opp(char* cmd, int* miaon, char* opp_string,char* r_num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool) 
{
	int i = 0;
	int num;
	if (*cmd == '#')  /* Immediate addressing */
	{
		cmd++;
		if(is_whitespace(*cmd))
		{
			if(first_pass_bool)
			{
				fprintf(ferr,"file- %s.as, line- %d:: in Immediate addressing after # cannot be space \n",file_name,line_counter);
				*failure_flag = TRUE;
			}
			return "EROR";
		}
		*miaon = 0;
		while (*cmd != ',' && *cmd != 0 && *cmd !='\t' && *cmd != ' ' && *cmd != '\n' )
		{
			opp_string[i] = *cmd;
			i++;
			cmd++;
		}
		opp_string[i] = 0;
		num = atoi(opp_string);	
	        if(!checking_num(num,line_counter,file_name,ferr,failure_flag,first_pass_bool))
		{
			return "EROR";
		}
		return cmd;
	}
	/*not immedite addressing, catch the str */
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	if (!is_alpha_beta(*cmd))
	{
		if(first_pass_bool)
			{
				fprintf(ferr,"file- %s.as, line- %d:: invalid operand \n",file_name,line_counter);
				*failure_flag = TRUE;
			}
			return "EROR";
	}
	while (*cmd != ',' && *cmd != 0 /*&& *cmd !='\t' && *cmd != ' ' */&& *cmd != '\n' )
	{
		opp_string[i] = *cmd;
		i++;
		cmd++;
	}
	opp_string[i] = 0;
	*miaon = miaon_idx(opp_string,r_num,line_counter,file_name,ferr,failure_flag,first_pass_bool);
	return cmd;
}



/*
	check whice adrressing system this is (1,2,3)
	input:
		opp - opp_string to check
		r_num - if the operand is a register then r_num stores its binary reg num
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
		first_pass_bool - BOOL to check if eror message print alredy in the first pass 

*/
int miaon_idx(char* opp,char* r_num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool)
{
	int miaon = -1;
	int cond_miaon_flag = 0;
	char temp_arr[MAX_LINE_LEN];		
	char * temp_ptr = temp_arr;
	BOOL reg_flag = TRUE;
	BOOL miaon_flag = TRUE;
	strcpy(temp_ptr,opp);
	/* register*/	
	if (*temp_ptr == 'r')
	{
		temp_ptr++;
		while (*temp_ptr != 0 && is_whitespace(*temp_ptr))
		{
			if (!(*temp_ptr >= '0' && *temp_ptr <= '9'))
			{
				reg_flag = FALSE;
			}
			temp_ptr++;
		}
		strcpy(temp_ptr,opp);
		if (reg_flag)
		{
			if (!isnot_saved_name(temp_ptr))
			{
				strcpy(r_num,num_of_register(temp_ptr));
				return 3;
			}
			else
			{
				if(first_pass_bool == TRUE)
				{
					fprintf(ferr,"file- %s.as, line- %d:: NUMBER OF REGISTER ARE WRONG! %s \n",
							file_name,line_counter,temp_ptr);
					*failure_flag = TRUE;	
				}
				return NO_MIAON;
			}
		}
	}
	if(*temp_ptr == 0 || *temp_ptr == '\n') 
	{
		return NO_MIAON;
	}
	/* check addressing 1*/
	if (is_alpha_beta(*temp_ptr))
	{
		temp_ptr++;
		while (*temp_ptr != 0 && *temp_ptr != ',')
		{
			if (!(is_alpha_beta(*temp_ptr) || (*temp_ptr >= '0' && *temp_ptr <= '9')))
			{
				miaon_flag = FALSE;
				break;
			}
			temp_ptr++;
		}	
	}
	if (miaon_flag)
	{
		return 1;
	}
	strcpy(temp_ptr,opp);
	while (*temp_ptr != 0 && *temp_ptr != ',')
	{
		if (cond_miaon_flag == 0)
		{
			if (is_alpha_beta(*temp_ptr))
			{
				cond_miaon_flag |= 1;
			}
			else
			{
				if(first_pass_bool == TRUE)
				{
					fprintf(ferr,"file- %s.as, line- %d:: INVALD LBL \"%s\" \n",
							file_name,line_counter,temp_ptr);
					*failure_flag = TRUE;	
				}
				return NO_MIAON;
			}
		}
		else if (cond_miaon_flag == 1)
		{
			if (*temp_ptr == '[')
			{
				cond_miaon_flag |= 2;
			}
			else if (!(is_alpha_beta(*temp_ptr) || (*temp_ptr >= '0' && *temp_ptr <= '9')))
			{
				if(first_pass_bool == TRUE)
				{
					fprintf(ferr,"file- %s.as, line- %d:: INVALD LBL \"%s\" \n",
							file_name,line_counter,temp_ptr);
					*failure_flag = TRUE;	
				}
				return NO_MIAON;
			}
		}
		else if (cond_miaon_flag == 3)
		{
			if (is_alpha_beta(*temp_ptr) || (*temp_ptr >= '0' && *temp_ptr <= '9'))
			{
				cond_miaon_flag |= 4;
			}
			else
			{
				if(first_pass_bool == TRUE)
				{
					fprintf(ferr,"file- %s.as, line- %d:: bad argument in parenthesis\n",
							file_name,line_counter);
					*failure_flag = TRUE;	
				}
				return NO_MIAON;
			}
		}
		else if (cond_miaon_flag == 7)
		{
			if (*temp_ptr == ']')
			{
				cond_miaon_flag |= 8;
			}
			else if (!(is_alpha_beta(*temp_ptr) || (*temp_ptr >= '0' && *temp_ptr <= '9')))
			{
				if(first_pass_bool == TRUE)
				{
					fprintf(ferr,"file- %s.as, line- %d:: INVALD LBL \"%s\" \n",
							file_name,line_counter,temp_ptr);
					*failure_flag = TRUE;	
				}
				return NO_MIAON;
			}
		}
		else if (cond_miaon_flag == 15)
		{
			if (!is_whitespace(*temp_ptr))
			{
				if(first_pass_bool == TRUE)
				{
					fprintf(ferr,"file- %s.as, line- %d:: INVALD LBL \"%s\" \n",
							file_name,line_counter,temp_ptr);
					*failure_flag = TRUE;	
				}
				return NO_MIAON;
			}
		}
		temp_ptr++;
	}
	if (cond_miaon_flag == 15)
	{ 
		return 2;
	}
	return miaon;	
}


/*
	the func clear whitspace before and after cur string
	input:
		cmd = cur string
*/
void clear_cmd(char* cmd)
{
	int i =0;
	while (is_whitespace(*cmd))
	{
		cmd++;
	}
	while (cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != 0 &&  cmd[i] != '\n')
	{
		i++;
	}
	cmd[i] = 0;
}

/*
	gets a binary word (14 bits) and stores the given number in 
	the 12 designated bits (other 2 are ARE bits)
	input:
		n - given number
		binaryNum - stores the binary representation of the given number
*/
void decToBinaryString(int n,char* binaryNum) 
{ 
	int i = PRE_ARE_BIN_WORD_IDX; 
	while (i >= 0)
	{ 
        	binaryNum[i] = (n & 1 )? '1' : '0'; 
		n = (n >> 1); 
		i -= 1; 
	} 
}

/*
	returns how many binary words are needed to the current instruction given
	the operands addressing methods
	inputs:
		miaon1 - first operand's addressing method
		miaon2 - second operand's addressing method
*/
int count_line_of_ic(int miaon1,int miaon2)
{
	if (miaon1 == -1 && miaon2 == -1)   /* no opp*/
	{
		return 1;
	}
	if (miaon2 == -1)   /*1 opp*/
	{
		if (miaon1 == 2)  /* miaon idx*/
		{
			return 3;
		}
		return 2;  /*else*/
	}
	if (miaon1 == 3 && miaon2 == 3)  /*two rigester*/
	{
		return 2;
	}
	if (miaon1 == 2 && miaon2 == 2)  /* two idx */
	{
		return 5;
	}
	if(miaon1 == 2 || miaon2 == 2)  /* one idx */
	{
		return 4;
	}
	return 3;  /* no idx miaon*/
}

/*
	gets a string with a register and returns its binary representation
	input:
		str - string to check
*/
char* num_of_register(char* str)
{
	if (strcmp(str,"r0") == 0)    
	{
		return "000";
	}
	if (strcmp(str,"r1") == 0)
	{
		return "001";
	}	
	if (strcmp(str,"r2") == 0)
	{
		return "010";
	}	
	if (strcmp(str,"r3") == 0)
	{
		return "011";
	}	
	if (strcmp(str,"r4") == 0)
	{
		return "100";
	}
	if (strcmp(str,"r5") == 0)
	{
		return "101";
	}
	if (strcmp(str,"r6") == 0)
	{
		return "110";
	}
	if (strcmp(str,"r7") == 0)
	{
		return "111";
	}
	return "-11";
}
	
/*
	fills the the addressing method in the first binary word of the current 
	instruction according to the current addressing method
	input:
		mem_word - first instruction binary word to fill in the correct location
		miaon - current operand addressing method
*/
void miaon_to_word(char* mem_word,int miaon)
{
	switch (miaon)
	{
		case 0:
			strcpy(mem_word,"00");
			break;
		case 1 :
			strcpy(mem_word,"01");
			break;
		case 2 :
			strcpy(mem_word,"10");
			break;
		case 3 :
			strcpy(mem_word,"11");
			break;
	}
}

/*
	fills the first binary word of the current instruction
	input:
		binary_code - binary word to fill
		oppcode_str - binary representation of the current instruction's opcode
		miaon1 - addressing method of the first operand (if exists)
		miaon2 - addressing method of the second operand (if exists)
*/
void first_instruction_word(char* binary_code,char* oppcode_str,int miaon1,int miaon2)
{
	int i = 0;
	while (i < NOT_USE_4_BITS)
	{
		binary_code[i++] = '0';
	}
	strcpy(binary_code + i,oppcode_str);
	i += OPPCODE_BITS;
	
	/*no operands*/
	if (miaon1 == -1 && miaon2 == -1)
	{
		while (i < (PRE_ARE_BIN_WORD_IDX + 1))
		{
			binary_code[i++] = '0';
		}	
	}
	else if (miaon2 == -1)
	{
		while (i < POST_TARGET_BIN_WORD_IDX)
		{
			binary_code[i++] = '0';
		}
		miaon_to_word(binary_code + i,miaon1);
		i += NUM_ARE_BITS;
	}
	else
	{
		miaon_to_word(binary_code + i,miaon1);
		i += NUM_ADDRESSING_BITS;
		miaon_to_word(binary_code + i,miaon2);
		i += NUM_ADDRESSING_BITS;
	}
	binary_code[i++] = '0';
	binary_code[i++] = '0';
	/*close string*/
	binary_code[i++] = 0;
}
/*
	the func break a string for two parts, lbl and index
	input:
		opp_string - string to be broken
		lbl - ptr for the lbl 
		idx - ptr fot the index	
*/

void break_string(char* opp_string,char* lbl,char* idx)
{
	int i=0;
	while(*opp_string != '[')
	{
		lbl[i] = *opp_string;
		i++;
		opp_string++;
	}
	lbl[i] = 0;
	i=0;
	opp_string++;
	while(*opp_string != ']')
	{
		idx[i] = *opp_string;
		i++;
		opp_string++;
	}
	idx[i] = 0;
}

/*
	gets a binary word (14 bits) and stores the given number in 
	the 14 designated bits 
	input:
		n - given number
		binaryNum - stores the binary representation of the given number
*/

void decToBinary_for_data_string(int n,char* binaryNum) 
{ 
	int i = (BINARY_WORD_STR_LEN - NUM_ARE_BITS); 
	while (i >= 0)
	{ 
        	binaryNum[i] = (n & 1 )? '1' : '0'; 
		n = (n >> 1); 
		i -= 1; 
	} 
}
 

/*
	extracts the name of an extern or entry from the current line
	input:
		cmd - current line after the extern parsing
		lbl_name - stores the extern's name
		extr - TRUE means its extern and FALSE entry
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
*/
char* extract_extern_entry(char* cmd, char* lbl_name,int line_counter,char* file_name,FILE* ferr,BOOL* failure_flag,BOOL extr)
{
	int i= 0;
	char* copy_cmd = cmd;
	while (is_whitespace(*copy_cmd))
	{
		copy_cmd++;
	}
	if (*copy_cmd == '\n' || *copy_cmd == 0)
	{
		if(extr) /*extern message */
		{
			fprintf(ferr,"file- %s.as, line- %d:: there is no extrn name  Declaration!\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return "EROR";
		}
		fprintf(ferr,"file- %s.as, line- %d:: there is no entry name  Declaration!\n",
					file_name,line_counter);
		*failure_flag = TRUE;
		return "EROR";
	}	
	while (!(is_whitespace(*copy_cmd))&& *copy_cmd != '\n')
	{
		lbl_name[i] = *copy_cmd;
		i++;
		copy_cmd++;
	}
	lbl_name[i] = 0;
	while (is_whitespace(*copy_cmd))
	{
		copy_cmd++;
	}
	if (*copy_cmd != '\n')
	{
		if(extr)	/*extern message */
		{
			fprintf(ferr,"file- %s.as, line- %d:: there is more char in extrn Declaration \n",file_name,line_counter);
			*failure_flag = TRUE;
		}
		fprintf(ferr,"file- %s.as, line- %d:: there is more char in entry Declaration \n",file_name,line_counter);
		*failure_flag = TRUE;
	}
	copy_cmd++;
	return copy_cmd;
}

/*
	fills the extra instructions word or words that needed for the opernads
	input:
		sym_tbl - symbol table - used to extracts symbol values
		binary_code - the current operand first binary word to fill
		binary_code_2 - the current operand first binary word to fill if needed
		miaon - current operand addressing method
		opp_string - the cur string to be check
		is_src - indicates if this is a source operand
		r_num - holds the binary representation if current operand is a register
		extern_flag - flag for check if the line is extern
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	

*/
void extra_instruction_word(SymbolTable sym_tbl,char* binary_code,char* binary_code_2,int miaon,char* opp_string,BOOL is_src,char* r_num,int* extern_flag,int line_counter,char* file_name,FILE* ferr,BOOL* failure_flag)
{
	int i;
	int value =-1;
	int type = -1;
	char lbl_name[MAX_SYMBOL_STR_LEN];
	char idx[BINARY_WORD_STR_LEN];
	*extern_flag = 0; /*init*/
	clear_cmd(opp_string);
	switch (miaon)
	{

		case 0:	 /* Immediate addressing */
			if(is_all_digits(opp_string) == TRUE)  /*not macro*/
			{
				decToBinaryString(atoi(opp_string),binary_code);
			}
			else  					/*macro*/
			{
				
				if (get_type_by_lbl(&sym_tbl,opp_string,&type) == TRUE)
				{
					if (type != SENTENCE_MACRO)  /*not macro and not number*/
					{
						fprintf(ferr,"file- %s.as, line- %d:: idx %s is lbl not macro or  number\n",file_name,line_counter,opp_string);
						*failure_flag = TRUE;
						return;
					}
				}
				if (get_value_by_lbl(&sym_tbl,opp_string,&value)== TRUE)
				{
					decToBinaryString(value,binary_code);
					i = (BINARY_WORD_STR_LEN - NUM_ARE_BITS - 1);
					binary_code_2[i++] = '0';
					binary_code_2[i++] = '0';
					/*close string*/
					binary_code_2[i++] = 0;
				}
				else
				{
					fprintf(ferr,"file- %s.as, line- %d::there is no this macro \"%s\" - in the sym tbl \n",file_name,line_counter,opp_string);
					*failure_flag = TRUE;
				}	
			}
			break;
		case 1 :   	/*lbl addressing */
						/*get label address*/
			if (get_value_by_lbl(&sym_tbl,opp_string,&value)== TRUE)
			{
				decToBinaryString(value,binary_code);
				i = (BINARY_WORD_STR_LEN - NUM_ARE_BITS - 1);
				if (get_type_by_lbl(&sym_tbl,opp_string,&type) == TRUE)
				{
					if (type == SENTENCE_EXTERN) /*extern*/
					{
						binary_code[i++] = '0';
						binary_code[i++] = '1';
						/*close string*/
						binary_code[i++] = 0;
						*extern_flag = 1;
					}else{
						binary_code[i++] = '1';
						binary_code[i++] = '0';
						/*close string*/
						binary_code[i++] = 0;
					}
				}
			}
			else  /*not found lbl */
			{
				fprintf(ferr,"file- %s.as, line- %d::there is no this lbl \"%s\"- in the sym tbl \n",file_name,line_counter,opp_string);
				*failure_flag = TRUE;
			}
			break;
		case 2 :
			if (!binary_code_2) return;/*null*/
			break_string(opp_string,lbl_name,idx);
				/*get label address if exist*/	
			if (get_value_by_lbl(&sym_tbl,lbl_name,&value)== TRUE)
			{
				decToBinaryString(value,binary_code);
				i = (BINARY_WORD_STR_LEN - NUM_ARE_BITS - 1);
				if (get_type_by_lbl(&sym_tbl,lbl_name,&type) == TRUE)
				{
					if (type == SENTENCE_EXTERN) /*extern*/
					{
						binary_code[i++] = '0';
						binary_code[i++] = '1';
						/*close string*/
						binary_code[i++] = 0;
						*extern_flag = 1;
					}
					else
					{
						binary_code[i++] = '1';
						binary_code[i++] = '0';
						/*close string*/
						binary_code[i++] = 0;
					}
				}
			}
			else /* not found lbl */
			{
				fprintf(ferr,"file- %s.as, line- %d::there is no this lbl %s- in the sym tbl \n",file_name,line_counter,opp_string);
				*failure_flag = TRUE;
				return;
			}		
			/*number to array_1*/
			if(is_all_digits(idx) == TRUE)
			{
				decToBinaryString(atoi(idx),binary_code_2);
			}
			else
			{
				
				if (get_type_by_lbl(&sym_tbl,idx,&type) == TRUE)
				{
					if (type != SENTENCE_MACRO) 
					{
						fprintf(ferr,"file- %s.as, line- %d:: idx %s is lbl not macro or number\n",file_name,line_counter,opp_string);
						*failure_flag = TRUE;
						return;
					}
				}
				if (get_value_by_lbl(&sym_tbl,idx,&value)== TRUE)
				{
					decToBinaryString(value,binary_code_2);
					i = (BINARY_WORD_STR_LEN - NUM_ARE_BITS - 1);
					binary_code_2[i++] = '0';
					binary_code_2[i++] = '0';
					/*close string*/
					binary_code_2[i++] = 0;
				}
				else
				{
					fprintf(ferr,"file- %s.as, line- %d::there is no this macro \"%s\"- in the sym tbl \n",file_name,line_counter,opp_string);
					*failure_flag = TRUE;
				}				
			}
			break;
		case 3 :  /* reg */
			if (TRUE == is_src)  /*for source*/
			{
				strcpy(binary_code,"00000000000000");
				for (i = 6; i < 9; i++) binary_code[i] = r_num[i-6];
				/*strcpy(binary_code + 3,r_num);*/
			}
			else  /* for destination */
			{
				for (i = 9; i < 12; i++) binary_code[i] = r_num[i-9];
					/*strcpy(binary_code + 6,r_num);*/
			}
			/*ARE always 00*/
			i = BINARY_WORD_STR_LEN;
			/*close string*/
			binary_code[i++] = 0;
			break;
	}
}

/*
	gets a binary word and translate it to quaternary (base 4)
	input:
		src - binary word
		buffer - stores the translated quaternary word
*/
void translate_to_quaternary(char* src, char* buffer)
{
	int i;
	for (i = 0; i < (BINARY_WORD_STR_LEN- 1); i +=2)
	{
		if (src[i] == '0' && src[i + 1] == '0')
		{
			buffer[i/2] = '*';
		}
		else if (src[i] == '0' && src[i + 1] == '1')
		{
			buffer[i/2] = '#';
		}
		else if (src[i] == '1' && src[i + 1] == '0')
		{
			buffer[i/2] = '%';
		}
		else /* (src[i] == '1' && src[i + 1] == '1') */
		{
			buffer[i/2] = '!';
		}
	}
}

/*
	translate the entire binary code to quaternary code to the ob file
	inputs:
		fp - ob file pointer
		instruction_bin - holds the translated program in binary
*/	
void to_quaternary(FILE* fp,BinaryTable * instruction_bin)
{
	BinaryTable instruction_node = *instruction_bin;
	char cur_word[QUAT_WORD_STR_LEN] = {0};	
	while (instruction_node)
	{
		translate_to_quaternary(instruction_node->_binary,cur_word);
		fprintf(fp,"%d\t%s\n",instruction_node->_address,cur_word);
		instruction_node = instruction_node->_next;
	}
}


/*
	creates a ob file
	inputs:
		instruction_bin - holds the translated program in binary
		name - current file name
		ic - instruction counter, printed in the ob file
		dc - data counter, printed in the ob file
*/
void create_ob_file(BinaryTable * instruction_bin,char name [], int ic, int dc)
{
	FILE * fp;
	char ob []  = ".ob";
	char file_name[MAX_LINE_LEN];	
	strcpy(file_name,name);
	strcat(file_name,ob);
	fp = fopen(file_name,"w");
	fprintf(fp,"%d %d\n",ic,dc);
	to_quaternary(fp,instruction_bin);
	fclose(fp);
}

/*
	Make the first pass on the file for making a symbol table , count dc and coding as a binar to the 		data_bin ,count ic, maintains the extern list and print eroer
	input:
		fp		- ptr to the file
		sym_tbl		- ptr to ptr of symbol table
		data_bin  	- ptr to ptr of table for directive data 
		ic_ptr
		dc_ptr	
		failure_flag	- ptr for fail flag
		ferr		- ptr for the error file
		file_name	- name of the file
*/
void first_pass(FILE* fp, SymbolTable * sym_tbl,BinaryTable * data_bin,int * ic_ptr, int * dc_ptr,BOOL * failure_flag, FILE* ferr,char* file_name)
{
	char macro_name[MAX_SYMBOL_STR_LEN];
	char* cmd;
        int macro_val;
	sentence_type sentence_check;
	char buf[MAX_LINE_LEN];
	int bool_flag;
	int lbl_flag;
	int code;
	char lbl_name[MAX_SYMBOL_STR_LEN];
	int dc_counter = 0;
	int opp_num;
	int check;
	char opp_string1[MAX_LINE_LEN];
	char opp_string2[MAX_LINE_LEN];
	int miaon1 = -1; 		/* initialized*/
	int miaon2 = -1; 		/* initialized*/
	char r_num1 [LEN_REGISTER_BIN]; /*number of reg in binary */
	char r_num2 [LEN_REGISTER_BIN];	/*number of reg in binary */
	char oppcode_str[LEN_OPP_CODE];
	directive_type directive;
	int ic_counter= START_OF_IC;
	int line_counter = -1;
	int dc_flag;
	BOOL first_pass_bool = TRUE;
	BOOL err_check = FALSE;
	BOOL lbl_error = FALSE;
	while (fgets(buf,MAX_LINE_LEN,fp))
	{
		line_counter++;
		miaon1 = -1;		/* initialized*/
		miaon2 = -1;		/* initialized*/
		err_check = FALSE;	/* initialized*/
		lbl_error = FALSE;	/* initialized*/
		dc_flag = 0;		/* initialized*/
		cmd = buf;
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		if(*cmd == ';' || *cmd == '\n' )   /* SENTENCE_NOP or SENTENCE_COMMENT */
		{
			continue;
		}
		/* check if the line is macro */
 		cmd = is_macro (cmd,macro_name,&macro_val, &sentence_check,&bool_flag,line_counter,
					file_name,ferr, failure_flag,first_pass_bool,&err_check);
		if(bool_flag == 1)
		{
			add_to_symbol_table(sym_tbl,macro_name,macro_val,sentence_check,line_counter, file_name, 							ferr,failure_flag);
			continue;
		}
		if(err_check == TRUE)
		{
			continue;
		}
		/* check if there is lbl and catch him */	
		cmd =  extract_lbl(cmd,lbl_name ,&lbl_flag,&lbl_error);
		if (lbl_error && lbl_flag)
		{
			fprintf(ferr,"file- %s.as, line- %d:: INVAL lbl - \"%s\"  \n",file_name,line_counter,lbl_name);
			*failure_flag = TRUE;
			continue;
		}
		if (lbl_flag != 0)
		{
			if (isnot_saved_name(lbl_name) == FALSE)
			{
				fprintf(ferr,"file- %s.as, line- %d::	\"%s\" is save name\n",file_name,line_counter,lbl_name);
				*failure_flag = TRUE;
				continue;
			}
			if (is_all_digits (lbl_name) == TRUE)
			{
				fprintf(ferr,"file- %s.as, line- %d::	label \"%s\" is all digits\n",file_name,line_counter,lbl_name);
				*failure_flag = TRUE;
				continue;
			}
			if (if_first_isnot_digit(lbl_name) == FALSE)
			{
				fprintf(ferr,"file- %s.as, line- %d::	label \"%s\" first char is digits\n",file_name,line_counter,lbl_name);
				*failure_flag = TRUE;
				return;
			}
		}
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		/*check if its directive sentence */
		cmd =  is_directive (cmd,&dc_counter,&sentence_check,&bool_flag,&directive);
		if (sentence_check == SENTENCE_ERROR)
		{
			fprintf(ferr,"file- %s.as, line- %d:: ilegal expression after dot \n",file_name,line_counter);
			*failure_flag = TRUE;
			continue;
		}
		if (bool_flag != 0)
		{
			if (directive == DIRECTIVE_DATA)
			{
				dc_flag = how_many_parm_data(cmd,data_bin,sym_tbl,             							line_counter, file_name,ferr,failure_flag);
				if(dc_flag == -1)
				{
					continue;
				}
				add_to_symbol_table(sym_tbl,lbl_name,dc_counter,sentence_check,             							line_counter, file_name,ferr,failure_flag);
				dc_counter += dc_flag;
			}
			if (directive == DIRECTIVE_STRING)
			{
				dc_flag = how_many_char_string(cmd,data_bin,             							line_counter, file_name,ferr,failure_flag);
				if(dc_flag == -1)
				{
					continue;
				}
				add_to_symbol_table(sym_tbl,lbl_name,dc_counter,sentence_check,             							line_counter, file_name,ferr,failure_flag);
				dc_counter += dc_flag;
			}
			if (directive == DIRECTIVE_EXTERN)
			{
				cmd = extract_extern_entry(cmd,lbl_name,line_counter, 						file_name,ferr,failure_flag,TRUE);
				if (!strcmp(cmd,"EROR"))
				{
					continue;
				}
				sentence_check = SENTENCE_EXTERN;
				add_to_symbol_table(sym_tbl,lbl_name,0,sentence_check,             							line_counter, file_name,ferr,failure_flag);
			}
			continue;
		}
		if (lbl_flag != 0)
		{
			add_to_symbol_table(sym_tbl,lbl_name,ic_counter,SENTENCE_INSTRUCTION,             							line_counter, file_name,ferr,failure_flag);
		}
		/*instructions*/
		cmd = op_code_check(cmd,&code,&sentence_check,oppcode_str,			 					line_counter,file_name,ferr,failure_flag,first_pass_bool);  /*get opcode*/
		opp_num = how_many_opp(code);						/*number of operands*/

		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		if (opp_num == 1)							/*addressing*/
		{
			cmd =  get_opp(cmd,&miaon1,opp_string1,r_num1
					,line_counter,file_name,ferr,failure_flag,first_pass_bool);
			if (!strcmp(cmd,"EROR"))
			{
				continue;
			}
		} 
		if (opp_num == 2)
		{
			cmd =  get_opp(cmd,&miaon1,opp_string1,r_num1
					,line_counter,file_name,ferr,failure_flag,first_pass_bool);
			if (!strcmp(cmd,"EROR"))
			{
				continue;
			}
			cmd =  extract_comma(cmd,&check);
			if (check != COMMA_OK)
			{
				comma_messeage(check,line_counter,file_name,ferr,failure_flag,first_pass_bool);
				continue;
			}
			cmd =  get_opp(cmd,&miaon2,opp_string2,r_num2
					,line_counter,file_name,ferr,failure_flag,first_pass_bool);
			if (!strcmp(cmd,"EROR"))
			{
				continue;
			}
		}
		if(miaon1 != NO_MIAON && miaon2 != NO_MIAON);  /*cehck about code with out opperand */
		{
			ic_counter = ic_counter+ count_line_of_ic(miaon1,miaon2);
		}
	}
	 updete_data_adrress(*sym_tbl,ic_counter);
	*ic_ptr = ic_counter - START_OF_IC;
	*dc_ptr = dc_counter;
}
/*
	Make the second pass on the file for making coding for instruction sentence, maintains the entry list  		and in the end concatenate bin list
	input:
		fp		- ptr to the file
		sym_tbl		- ptr to ptr of symbol table
		data_bin  	- ptr to ptr of table for directive data 
		g_instruction_bin- ptr to ptr of table for instruction data 
		failure_flag	- ptr for fail flag
		ferr		- ptr for the error file
		file_name	- name of the file
*/
void second_pass(FILE* fp, SymbolTable * sym_tbl,BinaryTable * data_bin,BinaryTable * g_instruction_bin,char* file_name,BOOL * failure_flag, FILE* ferr)
{
	directive_type directive;
	int ic_counter = START_OF_IC;
	int extern_flag = 0;
	int cur_ic;
	char* cmd;
	char buf[MAX_LINE_LEN];
	int lbl_flag;
	char lbl_name[MAX_SYMBOL_STR_LEN];
	int bool_flag;
	sentence_type sentence_check;
	char opp_string1[MAX_LINE_LEN];
	char opp_string2[MAX_LINE_LEN];
	int miaon1 = -1; 	/* initialized*/
	int miaon2 = -1;	/* initialized*/
	char r_num1 [LEN_REGISTER_BIN];
	char r_num2 [LEN_REGISTER_BIN];
	char oppcode_str[LEN_OPP_CODE];
	int code;
	char binary_code [BINARY_WORD_STR_LEN];
	char binary_code_2 [BINARY_WORD_STR_LEN]; 
	int dc_counter = 0;
	int opp_num;
	int check;
	int macro_val;
	int entry_adrress;
	char macro_name[MAX_SYMBOL_STR_LEN];
	char ext_file_name[MAX_NAME_FILE_LEN] = {0};
	char ext []  = ".ext";
	char ent_file_name[MAX_NAME_FILE_LEN] = {0};
	char ent []  = ".ent";
	BOOL first_extern = FALSE;
	BOOL first_entry = FALSE;
	FILE * ext_ptr;
	FILE * ent_ptr;
	int line_counter = -1;
	BOOL first_pass_bool = FALSE;
	BOOL err_check = FALSE;
	BOOL lbl_error = FALSE;
	strcpy(ext_file_name,file_name);
	strcat(ext_file_name,ext);

	strcpy(ent_file_name,file_name);
	strcat(ent_file_name,ent);
	while (fgets(buf,MAX_LINE_LEN,fp))
	{
		miaon1 = -1;		/* initialized*/
		miaon2 = -1;		/* initialized*/
		err_check = FALSE;	/* initialized*/
		lbl_error = FALSE;	/* initialized*/
		line_counter++;
		cmd = buf;
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		if(*cmd == ';' || *cmd == '\n' )   /* SENTENCE_NOP or SENTENCE_COMMENT */
		{
			continue;
		}
 		cmd = is_macro (cmd,macro_name,&macro_val, &sentence_check,&bool_flag
				,line_counter, file_name,ferr, failure_flag,first_pass_bool,&err_check);
		if(err_check == TRUE)
		{
			continue;
		}
		if(bool_flag == 1)
		{
			continue;
		}
		cmd =  extract_lbl(cmd,lbl_name ,&lbl_flag,&lbl_error);
		if (lbl_error)
		{
			continue;
		}
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		cmd =  is_directive (cmd,&dc_counter,&sentence_check,&bool_flag,&directive);
		if (bool_flag != 0)
		{
			if (directive != DIRECTIVE_ENTRY)	
			{
				continue;
			}
			cmd = extract_extern_entry(cmd,lbl_name,line_counter, 						file_name,ferr,failure_flag,FALSE);
			if (!check_if_lbl_in_tbl(*sym_tbl,lbl_name))
			{
				fprintf(ferr,"file- %s.as, line- %d:: cannot entry this lbl - \"%s\" canot found in the sym tbl \n",file_name,line_counter,lbl_name);
				*failure_flag = TRUE;
				continue;
			}			
			get_value_by_lbl(sym_tbl,lbl_name,&entry_adrress);
			if (!first_entry)
			{
				ent_ptr = fopen(ent_file_name,"w"); 
				first_entry = TRUE;
			}
		        fprintf(ent_ptr,"%s\t%d\n",lbl_name,entry_adrress);			
		}
		/* instructions */
		/* get opcode */
		cmd = op_code_check(cmd,&code,&sentence_check
					,oppcode_str,line_counter,file_name,ferr,failure_flag,first_pass_bool);
		opp_num = how_many_opp(code); 			/*number of operands*/
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		if (opp_num == 1)				/* addressing */
		{
			cmd =  get_opp(cmd,&miaon1,opp_string1,r_num1
					,line_counter,file_name,ferr,failure_flag,first_pass_bool);
			if (!strcmp(cmd,"EROR"))
			{
				continue;
			}
		}
		if (opp_num == 2)
		{
			cmd =  get_opp(cmd,&miaon1,opp_string1,r_num1
					,line_counter,file_name,ferr,failure_flag,first_pass_bool);
			if (!strcmp(cmd,"EROR"))
			{
				continue;
			}
			cmd =  extract_comma(cmd,&check);
			if (check != COMMA_OK)
			{
				comma_messeage(check,line_counter,file_name,ferr,failure_flag,first_pass_bool);
				continue;
			}
			cmd =  get_opp(cmd,&miaon2,opp_string2,r_num2
					,line_counter,file_name,ferr,failure_flag,first_pass_bool);
			if (!strcmp(cmd,"EROR"))
			{
				continue;
			}
		}
		while (is_whitespace(*cmd))
		{
			cmd++;
		}
		if (*cmd != '\n' && *cmd != 0)
		{
			fprintf(ferr,"file- %s.as, line- %d:: invalid number of operands\n",file_name,line_counter);
			*failure_flag = TRUE;
			continue;
		}
		/* check valid addressing for cur opcode */
		if (!check_valid_addressing_for_opcode(code,miaon1,miaon2,line_counter,file_name,ferr, failure_flag))
		{
				continue;
		}
		/* to binary */
		first_instruction_word(binary_code,oppcode_str,miaon1,miaon2); 
		add_to_binary_table(g_instruction_bin,binary_code,ic_counter,line_counter,
					file_name,ferr, failure_flag);
		cur_ic = ic_counter + 1;
		if (miaon1 == 3 && miaon2 ==3)	/*2 REGISTER IN ONE BUNARY_CODE */
		{
			extra_instruction_word(*sym_tbl,binary_code,binary_code_2,
						miaon1,opp_string1,TRUE,r_num1,&extern_flag,line_counter,
							file_name,ferr, failure_flag);
			extra_instruction_word(*sym_tbl,binary_code,binary_code_2,
						miaon2,opp_string2,FALSE,r_num2,&extern_flag,line_counter,
							file_name,ferr, failure_flag);
			add_to_binary_table(g_instruction_bin,binary_code,cur_ic,line_counter,
						file_name,ferr, failure_flag);
		}
		else
		{
		    if (miaon1 != -1)
		    {
		        extra_instruction_word(*sym_tbl,binary_code,binary_code_2,miaon1,opp_string1,TRUE,r_num1
					,&extern_flag,line_counter,file_name,ferr, failure_flag);
		        add_to_binary_table(g_instruction_bin,binary_code,cur_ic,line_counter,
						file_name,ferr, failure_flag);
		        if (extern_flag)
		        {
				if (!first_extern)
				{
					ext_ptr = fopen(ext_file_name,"w");
					first_extern = TRUE;
				}
				if (miaon1 == 1)
				{
		        		fprintf(ext_ptr,"%s\t%d\n",opp_string1,cur_ic);
				}
				else /* miaon1 == 2 */
				{
					fprintf(ext_ptr,"%s\t%d\n",strtok(opp_string1,"["),cur_ic);
				}
		        }
		        cur_ic = cur_ic + 1;
		        if (miaon1 == 2)
		        {
		            add_to_binary_table(g_instruction_bin,binary_code_2,cur_ic,line_counter,
							file_name,ferr, failure_flag);
		            cur_ic = cur_ic + 1;
		        }
		    }

		    if (miaon2 != -1)   /* MIAON 1 NEED 2 BINARY CODE */
		    {
		        extra_instruction_word(*sym_tbl,binary_code,binary_code_2,miaon2,opp_string2,FALSE,r_num2
						,&extern_flag,line_counter,file_name,ferr, failure_flag);
		        add_to_binary_table(g_instruction_bin,binary_code,cur_ic,line_counter,
						file_name,ferr, failure_flag);
		        if (extern_flag)
		        {
				if (!first_extern)
				{
					ext_ptr = fopen(ext_file_name,"w"); 
					first_extern = TRUE;
				}
				if (miaon2 == 1)
				{
		        		fprintf(ext_ptr,"%s\t%d\n",opp_string2,cur_ic);
				}
				else /* miaon2 == 2 */
				{
					fprintf(ext_ptr,"%s\t%d\n",strtok(opp_string2,"["),cur_ic);
				}
		        }
		        cur_ic = cur_ic + 1;
		        if (miaon2 == 2)
		        {
		            add_to_binary_table(g_instruction_bin,binary_code_2,cur_ic,line_counter,
							file_name,ferr, failure_flag);
		            cur_ic = cur_ic + 1;
		        }

		    }
		}
        	ic_counter = ic_counter+ count_line_of_ic(miaon1,miaon2);
	}
	concatenate_bin_list(g_instruction_bin,data_bin);
}
/*
	checking if the addressing system are valid for cur code
	input:
		code	-	the cur code
		miaon1	-	addressing system for source	
		miaon2	-	addressing system for destination
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
*/

BOOL check_valid_addressing_for_opcode(int code,int miaon1,int miaon2,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag)
{
	if (miaon1 == NO_MIAON)
	{
		fprintf(ferr,"file- %s.as, line- %d::	No valid source method accepted \n",
				file_name,line_counter);
		*failure_flag = TRUE;
		return FALSE;
	}
	if (miaon2 == NO_MIAON)
	{
		fprintf(ferr,"file- %s.as, line- %d::	No valid destination method accepted \n",
				file_name,line_counter);
		*failure_flag = TRUE;
		return FALSE;
	}
	if (code == 1)
	{
		return TRUE;    			/*Invalid source method*/
	}
	if (code == 0 || code == 2 || code == 3)   	/*mov,add,sub*/
	{
		if (miaon2 == 0)
		{
			fprintf(ferr,"file- %s.as, line- %d::	Invalid destination method \n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
		return TRUE;
	}
	if (code == 4 || code == 5 || code == 7 || code == 8 || code == 11) /*not,clr,inc,dec,red*/
	{
		if (miaon2 != -1)
		{
			fprintf(ferr,"file- %s.as, line- %d::	No valid source method accepted\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
		if (miaon1 == 0)
		{
			fprintf(ferr,"file- %s.as, line- %d::	Invalid destination method\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
		return TRUE;
	}
	if (code == 6) /*lea*/
	{
		if( miaon1 == 0 || miaon1 == 3)
		{
			fprintf(ferr,"file- %s.as, line- %d::	Invalid source method\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
		if(miaon2 ==0)
		{
			fprintf(ferr,"file- %s.as, line- %d::	Invalid destination method\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
		return TRUE;
	}
	if (code == 9 || code == 10 || code == 13) /*jmp,bne,jsr*/
	{
		if (miaon2 != -1)
		{
			fprintf(ferr,"file- %s.as, line- %d::	No valid source method accepted \n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
		if (miaon1 == 0 || miaon1 == 2)
		{
			fprintf(ferr,"file- %s.as, line- %d::	Invalid destination method\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}		
		return TRUE;
	}
	if (code == 12 && miaon2!= -1) /*prn*/
	{
		fprintf(ferr,"file- %s.as, line- %d::	No valid source method accepted\n",
					file_name,line_counter);
		*failure_flag = TRUE;
		return FALSE;
	}else{
		return TRUE;
	}
	if (code == 14 || code == 15) /*rts,stop*/
	{
		if (miaon1 != -1 || miaon2 != -1)
		{
			fprintf(ferr,"file- %s.as, line- %d::	No valid source method accepted\n",
						file_name,line_counter);
			*failure_flag = TRUE;
			return FALSE;
		}
	}
	return TRUE;
}
/*
	get a number and print error messeage for work with comma
	input:
		check 	- numbmer of error
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
		first_pass_bool - BOOL to check if eror message print alredy in the first pass 
*/
void comma_messeage(int check,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag,BOOL first_pass_bool)
{
	if (first_pass_bool == FALSE)
	{
		return;
	}
	if (check == THERE_IS_NO_COMMA)   				/* There is no comma */
	{
		fprintf(ferr,"file- %s.as, line- %d:: There is no comma!\n",
						file_name,line_counter);
		*failure_flag = TRUE;
		return;	
	}
	if (check == TO_MANY_COMMA)						/* There is to many comma */
	{
		fprintf(ferr,"file- %s.as, line- %d:: There is to many comma!\n",
						file_name,line_counter);
		*failure_flag = TRUE;
		return;	
	}
	if (check == COMMA_AND_THEN_EOF)	/* There is comma and after EOF */				
	{
		fprintf(ferr,"file- %s.as, line- %d:: There is comma and after EOF!\n",
						file_name,line_counter);
		*failure_flag = TRUE;
		return;	
	}
	if (check == EOF_MESSAGE)						/* EOF */
	{
		fprintf(ferr,"file- %s.as, line- %d:: There is no comma!\n",
						file_name,line_counter);
		*failure_flag = TRUE;		
		return;	
	}
}
/*\
	get a number and checks if it is within the boundaries between 2047>x>-2048
	input:
		num 	- the numbmer to check
		line_counter - current line number
		file_name - the name of current file
		ferr - ptr to eror file	
		failure_flag - ptr to BOOL to check if there is fail	
		first_pass_bool - BOOL to check if eror message print alredy in the first pass 
*/
BOOL checking_num(int num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag,BOOL first_pass_bool)
{
	if( num > 2047 )
	{
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: positive immediate too large to fit in 12 bits 					 \n",file_name,line_counter);
		}
		*failure_flag = TRUE;
		return FALSE;
	}
	if( num < -2048 )
	{
		if (first_pass_bool == TRUE)
		{
			fprintf(ferr,"file- %s.as, line- %d:: negative immediate too large to fit in 12 bits 					 \n",file_name,line_counter);
		}
		*failure_flag = TRUE;
		return  FALSE;
	}
	return TRUE;
}
