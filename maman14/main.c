#include "asembler.h"
#include "sym_table.h"
#include "binary_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
this function get a file name to work with and performs the assembler tasks 
on this file and prints errors if needed
*/
void run_assembler(char* file_name,FILE* ferr)
{
	SymbolTable sym_tbl = NULL;
	BinaryTable data_bin = NULL;
	BinaryTable instruction_bin = NULL;
	FILE * fp;
	int ic = 0;
	int dc = 0;
	char  as_file_name[MAX_NAME_FILE_LEN] = {0}; 
	char as []  = ".as";
	BOOL failure_flag = FALSE;
	/*get as file name*/
	strcpy(as_file_name,file_name);
	strcat(as_file_name,as);
	fp = fopen(as_file_name,"r");
	if (fp == NULL)
	{
		fprintf(ferr,"file name %s does not exist\n",as_file_name);
		return;
	}
	printf("Now compiling \"%s\"\n",as_file_name);
		/*first pass*/
	
	fprintf(ferr,"#######################################################\n");
	fprintf(ferr,"General errors - first pass of file- %s.as\n",file_name);
	fprintf(ferr,"#######################################################\n");
	first_pass(fp,&sym_tbl,&data_bin,&ic,&dc,&failure_flag,ferr,file_name);

	/*second pass*/
	rewind(fp);
	fprintf(ferr,"#######################################################\n");
	fprintf(ferr,"Translate Instructions errors - second pass of file- %s.as\n",file_name);
	fprintf(ferr,"#######################################################\n");
	second_pass(fp,&sym_tbl,&data_bin,&instruction_bin,file_name,&failure_flag,ferr);

	/*create_ob_file*/
	printf("translate......\n");
	if (failure_flag == FALSE)
	{ 
		fprintf(ferr,"No errors in file- %s.as\n\n\n",file_name);
		create_ob_file(&instruction_bin,file_name,ic,dc);/*change name to create ob*/
		printf("Finished successfully!\n");
		printf("create ob file....\n\n");
	}
	else
	{
		printf("Finished with errors.\n\n");
	}
	free_list_sym(sym_tbl);
	free_list_bin(instruction_bin);
	instruction_bin = NULL;
	fclose(fp);
	return;
}
/*
the main function gets a list of strings that coresponds to a list of files.
It is running the assembler on these files and print errors if needed
*/
int main(int argc, char *argv[])
{
	/*iterate over files*/
	int i=1;
	FILE * ferr;
	ferr = fopen("err.txt","w");
    	if (argc == 1)
	{
		fprintf(ferr,"no input files");/*close all files*/
		return 1;
	}
	for (i = 1; i < argc; i++)
	{
		run_assembler(argv[i],ferr);
	}
	fclose(ferr);
	printf("Done.\n");
	return 0;
}

