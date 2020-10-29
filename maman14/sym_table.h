#ifndef SYM_TABLE_H
#define SYM_TABLE_H
#include "common_utils.h"
#include <stdio.h>
#include <stdlib.h>

/*

In sym_table.h and sym_table.c the structure of symbol table wich stores
the symbols (labels, externs, etc.) is defines

*/

typedef struct node_s{
	char _label[MAX_SYMBOL_STR_LEN];  /* שם התווית*/
	int _value;   /* ערך*/
	int _type;    /* מאפיין*/
	struct node_s* _next;
} Node;

typedef struct node_s* SymbolTable;

BOOL add_to_symbol_table(SymbolTable * sym_tbl,char* lbl,int val,int type, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag);
void print_sym_table(SymbolTable sym_tbl);
BOOL check_if_lbl_in_tbl(SymbolTable sym_tbl,char* lbl);
BOOL get_value_by_lbl(SymbolTable* sym_tbl,char* lbl, int* the_value);
void updete_data_adrress(SymbolTable sym_tbl,int ic);
BOOL get_type_by_lbl(SymbolTable* sym_tbl,char* lbl, int* the_type);
void free_list_sym(SymbolTable sym_tbl);

#endif	/* SYM_TABLE_H */
