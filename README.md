# LinkedList
- Linked list is one of the basic data structure that stores data in a linear but non continuous manner.

- We use linked list due to its Dynamic memory allocation and efficient insertion and deletion.

- This is a simple demostration of single linked list. Node of a single linked list consist of 2 fields data and pointer parts.
	- The data part stores data provide to it's respective type.
   	- The pointer part stores next Node address developing a link between privious and next nodes of the list.

- To create a editor vi followed by the file name with proper extension-
	$vi list.h

- The extension ".h" indicates that it is a user defined header file that includes all functions which we use in the program.

- Once the entire header file is completely written with all the functions required we write main function in another file with again the same extension.

- In the main function file which is list.c in this case we need to include list.h header file by adding a statement #include "list.h".

- To compile the program
	$cc list.c -o list
	- "cc" this means c compiler which is inbuilt in the linux based operating systems.
   	- "-o" this represent output file in this case "list" is the output file.

- After successful execution the command mentioned above will create list file which is the output file.
  
- To get the output on the screen you have to execute this particular file not the file that contains programming part.Since the program file does not have "x"
  permission that is execution permission.

- After successful compilation, now it's time to run the program. To run the output file which is list in this case you have to run the command given below
  	$./list
  	- This command will run the output file that contains information about the program provided.
