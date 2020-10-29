#include "sym_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
    Add the address (one address after the last instruction) to all data symbols (data segment is after instruction segment)
    input:
        sym_table - the symbol table
        ic - one address after the last instruction
*/
void updete_data_adrress(SymbolTable sym_tbl,int ic)
{
	SymbolTable temp = sym_tbl;
	while (temp != NULL)
	{
		if (temp->_type == SENTENCE_DIRECTIVE)
		{
			temp->_value = (temp->_value + ic);
		}
		temp = temp->_next;
	}
}

/*
    checks if a given symbol is in the symbol table
    input:
        sym_table - the symbol table
        lbl - symbol name
*/
BOOL check_if_lbl_in_tbl(SymbolTable sym_tbl,char* lbl)
{
	BOOL FLAG = FALSE; /* indicates if the symbol was found */
	SymbolTable check_lbl = sym_tbl;
	while (check_lbl != NULL)
	{
		if (strcmp(lbl,check_lbl->_label) == 0)
		{
			FLAG = TRUE;
			break;
		}
		else
		{
			check_lbl = check_lbl->_next;
		}
	}
    return FLAG;
}


/*
    add a symbol and its parameters to the symbol table
    input:
        sym_table - the symbol table
        lbl - symbol name
        val - symbol value
        type - symbol type
*/
BOOL add_to_symbol_table(SymbolTable * sym_tbl,char* lbl,int val,int type, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag)
{
	SymbolTable new_node,p1;
	new_node = (SymbolTable) malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(ferr,"file- %s.as, line- %d:: cannot allocate memory for lbl -  %s \n",
					file_name,line_counter,lbl);
		*failure_flag = TRUE;
		return FALSE;
	}
	strcpy(new_node->_label,lbl);
	new_node->_value = val;
	new_node->_type = type;	
	new_node->_next = NULL;	
	if(*sym_tbl == NULL)  /* empty list */
	{
		new_node->_next = NULL;	
		*sym_tbl = new_node;
		return TRUE;
	}
	if (check_if_lbl_in_tbl(*sym_tbl,lbl) == TRUE)
	{
		fprintf(ferr,"file- %s.as, line- %d:: this lbl -  %s is already in sym tbl \n",
					file_name,line_counter,lbl);
		*failure_flag = TRUE;
		return FALSE;
	}
	p1 = *sym_tbl;
	while(p1->_next)
	{
		p1= p1->_next;
	}
	p1->_next = new_node;
	return TRUE;	
}

/*
    prints all the data in the symbol table
    input:
        sym_table - the symbol table
*/
void print_sym_table(SymbolTable sym_tbl)
{
	SymbolTable temp = sym_tbl;
	if (sym_tbl == NULL) printf("sym tbl is NULL\n");   /* TODO to error file ?? */
	printf("*the sym table is*\n");
	while (temp)
	{
		printf("lbl =|%s| value =|%d| type =|%d|\n",temp->_label,temp->_value,temp->_type) ;
		temp = temp->_next;
	}
	printf("*end of sym print*\n");
}

/*
    checks if a given symbol is in the symbol table and returns its value
    input:
        sym_table - the symbol table
        lbl - symbol name
        the_value - an address where the value will be stored
*/
BOOL get_value_by_lbl(SymbolTable* sym_tbl,char* lbl, int* the_value)
{
	BOOL FLAG = FALSE; /* indicates if the symbol was found */
	SymbolTable check_lbl = *sym_tbl;
	while (check_lbl != NULL)
	{
		if (strcmp(lbl,check_lbl->_label) == 0)
		{
			FLAG = TRUE;
			*the_value = check_lbl->_value;
			break;
		}
		else
		{
			check_lbl = check_lbl->_next;
		}
	}
    return FLAG;
}

/*
    checks if a given symbol is in the symbol table and returns its type
    input:
        sym_table - the symbol table
        lbl - symbol name
        the_type - an address where the type will be stored
*/
BOOL get_type_by_lbl(SymbolTable* sym_tbl,char* lbl, int* the_type)
{
	BOOL FLAG = FALSE;  /* indicates if the symbol was found */
	SymbolTable check_lbl = *sym_tbl;
	while (check_lbl != NULL)
	{
		if (strcmp(lbl,check_lbl->_label) == 0)
		{
			FLAG = TRUE;
			*the_type = check_lbl->_type;
			break;
		}
		else
		{
			check_lbl = check_lbl->_next;
		}
	}
	return FLAG;
}

void free_list_sym(SymbolTable sym_tbl)
{
   SymbolTable tmp;
   /*sym_tbl = sym_tbl->_next;*/
   while (sym_tbl != NULL)
    {
       tmp = sym_tbl;
       sym_tbl = sym_tbl->_next;
       free(tmp);
    }

}
