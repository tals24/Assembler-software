#ifndef BIN_TABLE_H
#define BIN_TABLE_H

#include "common_utils.h"
#include <stdio.h>
#include <stdlib.h>
/*
this data structure represents the binary representation of the translated code,
each node corresponds to a single binary word.
the nodes are ordered in the translated words actual order (and their address is also part of 
the struct
*/
typedef struct binary_list_s{
	char _binary[BINARY_WORD_STR_LEN];  /* string */
	int _address;   
	struct binary_list_s* _next;
} binary_list;

typedef struct binary_list_s * BinaryTable;



BOOL add_to_binary_table(BinaryTable * bin_tbl, char* binary, int address, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag);

void print_binary_table(BinaryTable bin_tbl);

void concatenate_bin_list(BinaryTable * instruction_tbl, BinaryTable * data_tbl);

void free_list_bin(BinaryTable bin_tbl);

#endif	/*BIN_TABLE_H*/

