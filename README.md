# Assembler-software
Project for the Open University "Laboratory in Systems Programming" course.

## Description
in this project I wrote a asmbleer software for an asembly language that was defined in the project.
the assembler works in a two pass algorithm. 
the compiler gets a file written in the defined assembly language and creates a file in machine langauge.
The assembly maintains a table who have all the information about the symbol and data adress 

### The language is complex  from a statements : command, comment, macro and directive.

```python

# Command 
  a sentence who produces coding of machine instruction
 
# Comment
  help us to understand the code better [start with ;]
  
# macro
  a sentence to declare a symbolic name that can be defined that represents a numerical constant
 
# directive
  variables initialization: strings, characters, integers and arrays.
```


## The assembler run twice on the file.



### the first round 
```python
Maintains the IC and DC counter. check how many space should allocate in the memory and update the counters.
Also he coded the operand.
```
```C
 1. initialize IC <- 0 , DC <- 0.
 2. read to next line, if its the end of the file jump to 16
 3. if this a macro? if not jump to 5
 4. insert macro name into symbol table
 5. if the first word is a symbol?  if not jump to 7
 6. turn on symbol flag
 7. check if this is directive sentence for data or string? if not jump to10
 8. if there is symbol flag, insert into symbol table with DC 
 9. coded the data into the memory, update the DC counter. back to 2
 10. if this is extern or entry? if not jump to 12
 11. if this extern ? insert any symbol into the symbol table with external feature. back to 2
 12. if there is symbol feature insert into symbol table with code feature and update to IC +100
 13. serach for comand opp 
 14. Analyze the structure of the operands. bulid the binary code for the first comand 
 15. IC = IC + L back to 2
 16. finish read the source file. 
 17. update in symbol table any data feature in a +  IC+100
 18. start second pass
```


### the second round 
```python
Complete the machine code after the information about the operand and leabel 
```
```c
 1. initialize IC <- 0 
 2. read to next line, if its the end of the file jump to 9
 3. if this a symbol? pass the sentence 
 4. if this data,string or extern? jump to 2
 5. if this entry? if not, jump to 7
 6. target in the symbol table the entry feature and jump to 2
 7. Complete the encoding according to the addressing method
 8. IC <- IC+ L. jump to 2
 9. finish read the source file. 
 10 bulid the output file

```
