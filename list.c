#include "list.h"

void main()
{	int elements, data,i,option=1;
	struct Node *node;
	struct list *list;

	list = createList();	//Initializing start and end pointer to NULL
	printf("================================================================");
	printf("\nEnter the number of data elements:");
	scanf("%d",&elements);
	if (elements == 0)
		printf("List is currently empty\nYou can still insert data elements into the list!!\n");	
	else	
	{	printf("================================================================");
		printf("\nEnter data elements one by one:\n");
		for (i=0;i<elements;i++)
		{	printf("Enter data element %d:",i+1);
			scanf("%d",&data);
			node = createNode(data);
			append(node,list);
		}
	}
	while (1)
	{	printf("================================================================");
		printf("\nOpertions  performed on list\n");
		printf("___________________________________\n");
		printf("0.To Exit\n1.To Check the lsit\n2.To Delete\n3.To Display\n4.To Insert\n5.To Search");
		printf("\nEnter your choice:");
		scanf("%d",&i);	
		switch(i)
		{	case 0:
				printf("================================================================");
				printf("\nProgram Terminated\n");
				printf("================================================================\n");
				if(isEmpty(list))
				{	free(list);
					exit(0);
				}		
				else
				{	emptyList(list);
					exit(0);
				}
			case 1:	
				printf("================================================================");	
				if(isEmpty(list))
				{	printf("\nList is Empty!!!!\n");
					break;
				}
				else
					printf("\nList is Not Empty\n");
				break;
			case 2:
				printf("================================================================");
				if(isEmpty(list))
					printf("List is empty can not delete any data\n");
				else
				{	printf("\nEnter the data to be delete:");
					scanf("%d",&data);
					if (!delete(list,data))
						printf("\nData deleted\n");
					else 
						printf("\nData is not found\n");
				}
				break;
			case 3:	
				printf("================================================================");
				display(list);
				break;
			case 4:
				printf("================================================================");
				printf("i\nEnter the data to insert:");
				scanf("%d",&data);
				node = createNode(data);
				printf("Enter the index to insert the data:");
				scanf("%d",&i);
				if(insert(node,list,i))
					printf("Index not found\n");
				else
					printf("Data inserted to desired index\n");
				break;
			case 5:
				printf("================================================================");
				printf("\nEnter the data to search:");
				scanf("%d",&data);
				option = search(list, data);
				if (option != -1)
					printf("Data found at %d\n",option);
				else
					printf("Data not found\n");
				break;
			default:
				printf("================================================================");
				printf("\n!!!Invalid operation please select properly!!!\n");
		}
	}
}
