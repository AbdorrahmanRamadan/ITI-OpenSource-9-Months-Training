#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>


/* Struct: node of the stack */
typedef struct
{
	int ID;
	char Name[50];
}Employee;

typedef struct
{
	Employee Data;
	struct node* Next;
}node;

/* Initialization of top = NULL */
node* top = NULL;

/*
    Function: push()
    Push elements to Stack
    return: - true(1)  if Stack is not full
            - false(0) if Stack is full
*/
int push(Employee data)
{
    int retval=0;
	node* newNode = (node*)malloc(sizeof(node));
    if (newNode != 0)
	{
        newNode->Data = data;
		newNode->Next = top;
		top = newNode;
		retval=1;
    }
    return retval;
}

/*
	Function: isEmpty()
	return: - true(1)  if Stack is empty
            - false(0) if Stack is not empty
*/
int isEmpty(void)
{
    return(top == 0);
}

/*
	Function: pop()
	return: Top value "Stack is LIFO"
*/
Employee pop(void)
{
	Employee result;
	node* temp;
    if (isEmpty())
	{
		result.ID = -1;
        printf("Nothing to take from stack!\n");
    }
	else
	{
		result = top->Data;
		temp = top;
		top = top->Next;
		temp->Next = NULL;
		free(temp);
	}
	return result;
}

/*
    Function: peek() (getTop())
	return: Top value "Stack is LIFO"
*/
Employee peek()
{
	Employee retVal;
    if (top == 0)
	{
        printf("Nothing to take from stack!\n");
		retVal.ID = -1;
        return retVal;
    }
	else
	{
		return (top->Data);
	}
}

/*
	Function: print()
	Print all elements of the Stack till top
*/

void print_Employee(Employee employee)
{
	printf("\nEmployee ID: %d, Name: %s\n",employee.ID,employee.Name);
}

void print(void)
{
	int sum = 0;
	//printf("Stack Elements: ");
	node* temp = (node*)malloc(sizeof(node));
	temp = top;
	while(temp != NULL)
	{
		print_Employee(temp->Data);
		temp = temp->Next;
	}
	//printf("\n");
	free(temp);
}


void fill_Employee(void)
{
	Employee employee;
	printf("\nEnter ID of the employee: ");
	scanf("%d",&(employee.ID));
	printf("Employee Name: ");
	scanf("%s",employee.Name);
	push(employee);
}

void menu(void)
{
	system("cls");
    printf("1-PUSH\n");
    printf("2-POP\n");
    printf("3-Display\n");
    printf("4-Exit\n");
    printf("Please Select: ");
}

int main(void)
{
	int select,flag,loc,de;
	char ch;
	Employee emp;
	flag = 1;
	while(flag)
	{
		menu();
		printf("Pleas Select: ");
		scanf("%d",&select);

		switch(select)
		{
			case 1:
				system("cls");
				fill_Employee();
			break;
			case 2:
				system("cls");
				printf("Are you sure?? 1-Yes | 2-No: ");
				scanf("%d",&de);
				if (de == 1)
				{
					emp = pop();
					if (emp.ID != -1)
					{
						print_Employee(emp);
					}
					printf("Done\n");
				}
				else if (de == 2)
				{
					printf("Nothing deleted\n");
				}
				else
				{
					printf("Error || wrong select\n");
				}
				printf("\nPress any key to show menu\n");
				getch();
			break;
			case 3:
				system("cls");
				print();
				printf("\nPress any key to show menu\n");
				getch();
			break;
			case 4:
				system("cls");
				printf("Bye see you next time :)");
				flag = 0;
			break;
			default:
				system("cls");
				printf("Error :: Wrong select!");
				printf("\nPress any key to show menu\n");
				getch();
			break;
		}
	}
	return 0;
}
