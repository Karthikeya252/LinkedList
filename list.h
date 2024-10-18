#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//A structure called Node that has data part and link part next node. This structure the template
struct Node
{	
	int data;		//Stores data part
	struct Node *next;	//Stores next node address
};

//Declaration of a list with two pointers. This structure is to reduce time complexity for insertion and deletion.
struct list
{	
	struct Node *start;	//stores starting node address
	struct Node *end;	//stores ending node address
};

//The below function is used to store start and end values so that no garbage values are stored.
struct list *createList()
{	struct list *list;
	list = (struct list *)malloc(sizeof(struct list));
	list->start = NULL;	//initializing start with NULL 
	list->end = NULL;	//initializing end with NULL
	return list;		//returning the address of list
}

//Creation of Node and providing data to the node
//Receives data to be placed in a node. Creates a node, stode data in the node and return the node address
struct Node *createNode(int data)	//Takes int type as parameter
{	struct Node *node;
	node = (struct Node *)malloc (sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//linking the nodes that are created with the help of CreateNode function
void append(struct Node *node, struct list *list)
{	if (list->start == NULL)
	{	list->start = list->end = node;	
		return;
	}
	else
	{	list->end->next = node;
		list->end = node;
		return;
	}
}

//Checks whether the list is empty or not
int isEmpty(struct list *list)
{	if (list->start == NULL)
		return 1;
	else
		return 0;	
}

//Deallocate the given memory to the list
int emptyList(struct list *list)
{	struct Node *pri=list->start;
	struct Node *curr;
	if (list->start == NULL)
		return 1;
	else
	{	while(pri!=NULL)
		{	curr = 	pri->next;
			free(pri);
			pri=curr;
		}
		list->start = NULL;
		list->end = NULL; 
		free(list);
		return 0;
	}	
}

//Display all the data elements present in the list
void display(struct list *list)
{	struct Node *ptr;
	if (list->start == NULL)
	{	printf("\nList is empty\n");
		return;
	}
	printf("\nData elements present in list:\n");
	for (ptr=list->start;ptr!=NULL;ptr=ptr->next)
		printf("%d\n",ptr->data);
	free(ptr);
	return;
}

//Delete a particular data element from the list
int delete(struct list *list, int data)
{	struct Node *pri,*curr;	

	for (pri=list->start,curr=list->start;curr->data!=data && curr->next!=NULL;pri=curr, curr=curr->next);
	if(curr->data == data && list->start == curr)
	{	curr = pri->next;
		list->start = curr;
		pri->next = NULL;
		free(pri);
		return 0;
	}
	if (curr->data == data && list->end == curr)
	{	list->end = pri;
		pri->next = NULL;
		free(curr);
		return 0;
	}
	if (curr->data == data)
	{	pri->next = curr->next;
		curr->next = NULL;
		free(curr);
		return 0;
	}
	else
		return 1;
}

//Insert a particular data element into the list at given index
int insert(struct Node *node, struct list *list, int index)
{	
	struct Node *pri, *curr;
	int i;
	
	if (list->start == NULL)
	{	append(node,list);
		return 0;
	}

	curr = pri = list->start;
	for(i = 0;i<index-1 && curr!=NULL;pri=curr,curr=curr->next,i++);

	if(i == index-1 && curr == list->start)
	{	node->next = curr;
		list->start = node;
		return 0;
	}
	if (i == index-1 && curr == NULL)
	{	pri->next = node;
		list->end = node;
		return 0;
	}
	if(i == index-1 && curr!=NULL)
	{	pri->next = node;
		node->next = curr;
		return 0;
	}
	else 
		return 1;
}
//linear search for a given data
int search(struct list *list, int data)
{	int i;
	struct Node *ptr;
	
	for (i=0,ptr= list->start;ptr!=NULL;ptr = ptr->next,i++)
		if (ptr->data == data)
		{	free(ptr);
			return i+1;
		}	
	free(ptr);
	return 0;
}

