#include "binary_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*
    prints all the data in the binary table
    input:
        bin_tbl - the binary table
*/

void print_binary_table(BinaryTable bin_tbl)
{
	BinaryTable temp = bin_tbl;
	if (bin_tbl == NULL) printf("bin tbl is NULL\n");
	printf("*********the bin table is*********\n");
	while (temp)
	{
		printf("binary string  =|%s| address =|%d| \n",temp->_binary,temp->_address) ;
		temp = temp->_next;
	}
	printf("*********end of bin print*********\n");
}



/*
    add a new binary word to the binary table
    input:
        bin_tbl - the binary table
        binary -  binary string that represents a word
        address - the binary word's address
*/

BOOL add_to_binary_table(BinaryTable * bin_tbl, char* binary, int address, int line_counter, char* file_name, FILE* ferr, BOOL* failure_flag)
{
	BinaryTable new_node = NULL;
	BinaryTable p1 = NULL;
	new_node = (BinaryTable) malloc(sizeof(binary_list));
	if (new_node == NULL)
	{
		fprintf(ferr,"file- %s.as, line- %d:: cannot allocate memory for binary string -  %s \n",
					file_name,line_counter,binary);
		*failure_flag = TRUE;
		return FALSE;
	}
	strcpy(new_node->_binary,binary);
	new_node->_address = address;
	new_node->_next = NULL;
	if (*bin_tbl == NULL)  /* empty list */
	{
		new_node->_next = NULL;	
		*bin_tbl = new_node;
		return TRUE;
	}
	p1 = *bin_tbl;
	while(p1->_next)
	{
		p1 = p1->_next;
	}     
            /*p1 is the last NODE */
	p1->_next = new_node;
	return TRUE;	
}


/*
    concatenates the 2 binary lists (instructions segment and data segment) and 
    puts the data segment after the instructions segment
    input:
        instruction_tbl - the binary table of the instructions segment
        data_tbl -  the binary table of the data segment
*/
void concatenate_bin_list(BinaryTable * instruction_tbl, BinaryTable * data_tbl)
{
	int add;   				 /* current address */
	BinaryTable temp;
	temp= *instruction_tbl;
	if (temp)
	{
		while(temp->_next)			 /* go to the end of instructions segment's list */
		{
			temp= temp->_next;
		}
		add = temp->_address + 1;
		temp->_next = *data_tbl;
		temp = temp->_next;
		temp->_address = add;
		while(temp->_next)
		{
			temp= temp->_next;
			add++;
			temp->_address = add;
		}
		*data_tbl = NULL;
	}
}

void free_list_bin(BinaryTable bin_tbl)
{
   BinaryTable tmp;
   while (bin_tbl != NULL)
    {
   	tmp = bin_tbl;
       bin_tbl = bin_tbl->_next;
       free(tmp);
    }

}


