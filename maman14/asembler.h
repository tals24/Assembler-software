#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_table.h"
#include "binary_table.h"

/*

In this file you can find the main function that perform the assembler tasks.
some of the function parse the input, some of them anallyze it and some of them
stores the data in the binary table and symbol table (as explained in their h files).

*/

BOOL isnot_saved_name(char* macro_name);
BOOL is_all_digits (char* check_str);
BOOL if_first_isnot_digit (char* macro_name);
char* extract_number(char* cmd, int* macro_val, int* check_num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag,BOOL first_pass_bool);
int is_whitespace(char c);
char* is_macro (char* cmd,char* macro_name, int* macro_val, sentence_type* sentence_check,int* bool_flag, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool,BOOL* err_check);
char* dotecheck (char* cmd,directive_type* directive); 
char* extract_lbl(char* cmd, char* lbl_name ,int* LBL_FLAG, BOOL * lbl_error);
char* is_directive (char* cmd,int* cd_counter,sentence_type* sentence_check,int* flag ,directive_type* directive); 
char* extract_comma(char* cmd,int * check);	
int how_many_parm_data(char * cmd, BinaryTable * data_bin,SymbolTable* sym_tbl,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag);
int how_many_char_string(char * cmd, BinaryTable * data_bin,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag);
int how_many_opp(int code);
char* get_opp(char* cmd, int* miaon, char* opp_string,char* r_num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool);
int miaon_idx(char* opp,char* r_num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool);	
void clear_cmd(char*cmd);	
char* op_code_check(char* cmd,int* code,sentence_type* sentence_check,char* oppcode_str, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag, BOOL first_pass_bool);
void decToBinaryString(int n,char* binaryNum);
int count_line_of_ic(int miaon1,int miaon2);
char* num_of_register(char* str);
void first_instruction_word(char* binary_code,char* oppcode_str,int miaon1,int miaon2);
void miaon_to_word(char* mem_word,int miaon);
void break_string(char* opp_string,char* lbl,char* idx);
void decToBinary_for_data_string(int n,char* binaryNum);	
char* extract_extern_entry(char* cmd, char* lbl_name,int line_counter,char* file_name,FILE* ferr,BOOL* failure_flag,BOOL exter);
BOOL get_type_by_lbl(SymbolTable* sym_tbl,char* lbl, int* the_type);
void extra_instruction_word(SymbolTable sym_tbl,char* binary_code,char* binary_code_2,int miaon,char* opp_string,BOOL is_src,char* r_num,int* extern_flag,int line_counter,char* file_name,FILE* ferr,BOOL* failure_flag);
void create_ob_file(BinaryTable * instruction_bin,char* name, int ic, int dc); 
void to_quaternary(FILE* fp,BinaryTable * instruction_bin);
void translate_to_quaternary(char* src, char* buffer);
void first_pass(FILE* fp, SymbolTable * sym_tbl,BinaryTable * data_bin,int * ic_ptr, int * dc_ptr,BOOL * failure_flag, FILE* ferr,char* file_name);
void second_pass(FILE* fp, SymbolTable * sym_tbl,BinaryTable * data_bin,BinaryTable * g_instruction_bin, char* file_name,BOOL * failure_flag, FILE* ferr); 
void comma_messeage(int check,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag,BOOL first_pass_bool);
BOOL check_valid_addressing_for_opcode(int code,int miaon1,int miaon2,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag);
BOOL checking_num(int num,int line_counter,char *file_name, FILE* ferr, BOOL* failure_flag,BOOL first_pass_bool);



#endif	/*NODE_H*/
