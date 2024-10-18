# LinkedList
- Linked list is one of the basic data structure that stores data in a linear but non continuous manner.

- In the memory by default int is provided with 4 bytes of data in 64 bit architecture and 2 bytes in 32 bit architecture.

- And the next item in the structure is pointer part that stores next node address.

- Since this is demonstration of single linked list their is only one pointer/address.

- Also this program is written in CentOS 7 therefore the given below commands are used to write and execute the program.

- To create a editor vi followed by the file name with proper extension
	$vi list.h

- The extension ".h" indicates that it is a user defined header file that includes all functions which we use in the program.

- Once the entire header file is completely written with all the functions required we write main function in another file with again the same extension.

- In the main function file which is list.c in this case we need to include list.h header file by adding a statement #include "list.h".

- To compile the program
	$cc list.c -o list

- If the file does not contains any error then the cursor will go to next prompt if any error if displays that error.

- This will create a list executable which is the output file.
  
	$./list
- This command will run that particular output file and displays your desired output.
