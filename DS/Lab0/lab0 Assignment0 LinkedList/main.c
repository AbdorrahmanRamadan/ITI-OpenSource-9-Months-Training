#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

struct Employee
{
	int ID;
	char Name[50];
};

struct node
{
       struct Employee Data;
       struct node* Prev;
       struct node* Next;
};
struct node* pHead;
struct node* pTail;

/* Prototypes */
struct node* createNode(void);
int addNode(void);
int insertNode(int loc);
struct Employee searchNode_ID(int id);
struct Employee searchNode_Name(char* name);
int deleteNode(int loc);
void freeNode(void);
struct Employee fill_Employee(void);
void print_AllEmployees(void);
void print_Employee(struct Employee employee);
void gotoxy(int x, int y);
void printMenu(void);
char getASCII(void);

int main(void)
{
	int select,flag,loc,de;
	char ch;
	char name[50];
	struct Employee emp;
	flag = 1;
	while(flag)
	{
		printMenu();
		printf("Please Select: ");
		scanf("%d",&select);

		switch(select)
		{
			case 1:
				system("cls");
				addNode();
			break;
			case 2:
				system("cls");
				printf("Put location to insert: ");
				scanf("%d",&loc);
				insertNode(loc);
			break;
			case 3:
				system("cls");
				printf("ID: ");
				scanf("%d",&loc);
				emp = searchNode_ID(loc);
				if (emp.ID == -1)
				{
					printf("Not found\n");
				}
				else
				{
					print_Employee(emp);
				}
				printf("\nPress any key to show menu\n");
				getch();
			break;
			case 4:
				system("cls");
				printf("Name: ");
				scanf("%s",name);
				emp = searchNode_Name(name);
				if (emp.ID == -1)
				{
					printf("Not found\n");
				}
				else
				{
					print_Employee(emp);
				}
				printf("\nPress any key to show menu\n");
				getch();
			break;
			case 5:
				system("cls");
				printf("Location to delete: ");
				scanf("%d",&loc);
				de = deleteNode(loc);
				if(de)
				{
					printf("Are you sure?? 1-Yes | 2-No: ");
					scanf("%d",&de);
					if (de == 1)
					{
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
				}
				else
				{
					printf("Error || wrong location\n");
				}
				printf("\nPress any key to show menu\n");
				getch();
			break;
			case 6:
				system("cls");
				printf("Are you sure?? 1-Yes | 2-No: ");
				scanf("%d",&de);
				if (de == 1)
				{
					printf("Done all data deleted\n");
					freeNode();
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
			case 7:
				system("cls");
				print_AllEmployees();
				printf("\nPress any key to show menu\n");
				getch();
			break;
			case 8:
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

struct node* createNode(void)
{
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr)
	{
		ptr->Data = fill_Employee();
		ptr->Prev = NULL;
		ptr->Next = NULL;
	}
}

int addNode(void)
{
	int retVal = 0;
	struct node* ptr;
	ptr = createNode();
	if (ptr)
	{
		if (!pHead)
		{
			pHead = ptr;
		}
		else
		{
			ptr->Prev = pTail;
			pTail->Next = ptr;
		}
		pTail = ptr;
		retVal = 1;
	}
	return retVal;
}

int insertNode(int loc)
{
	int retVal = 0;
	struct node* ptr;
	struct node* cur;
	ptr = createNode();
	if (ptr)
	{
		if (!pHead)
		{
			pHead = pTail = ptr;
		}
		else
		{
			if (!loc)
			{
				ptr->Next = pHead;
				pHead->Prev = ptr;
				pHead = ptr;
			}
			else
			{
				cur = pHead;
				for (int i=0; (i<(loc-1))&&cur; i++)
				{
					cur = cur->Next;
				}
				if ((cur == NULL) || (cur==pTail))
				{
					ptr->Prev = pTail;
					pTail->Next = ptr;
					pTail = ptr;
				}
				else
				{
					ptr->Next = cur->Next;
					cur->Next->Prev = ptr;
					cur->Next = ptr;
					ptr->Prev = cur;
				}
			}
		}
		retVal = 1;
	}
	return retVal;
}

struct Employee searchNode_ID(int id)
{
	struct node* ptr;
	struct Employee emp;
	for(ptr = pHead; ((ptr)&&((ptr->Data).ID!=id)); ptr=ptr->Next);
	if(!ptr)
	{
		emp.ID = -1;
		return emp;
	}
	else
	{
		return ptr->Data;
	}
}

struct Employee searchNode_Name(char* name)
{
	struct node* ptr;
	struct Employee emp;
	for(ptr = pHead; ((ptr)&&strcmp((ptr->Data).Name,name)); ptr=ptr->Next);
	if(!ptr)
	{
		emp.ID = -1;
		return emp;
	}
	else
	{
		return ptr->Data;
	}
}

int deleteNode(int loc)
{
	int retVal = 0;
	struct node* ptr;
	struct node* cur;
	if(pHead)
	{
		if (!loc)
		{
			ptr = pHead;
			pHead = pHead->Next;
			pHead->Prev = NULL;
			free(ptr);
			retVal = 1;
		}
		else
		{
			cur = pHead;
			for (int i=0; (i<loc)&&cur; i++)
			{
				cur = cur->Next;
			}
			if(cur)
			{
				if (cur==pTail)
				{
					ptr = pTail;
					pTail = ptr->Prev;
					pTail->Next = NULL;
				}
				else
				{
					ptr = cur;
					cur->Prev->Next = cur->Next;
					cur->Next->Prev = cur->Prev;
				}
				retVal = 1;
				free(ptr);
			}
		}
	}
	return retVal;
}

void freeNode(void)
{
	struct node* ptr;
	while (pHead)
	{
		ptr = pHead;
		pHead = pHead->Next;
		free(ptr);
	}
	pTail = NULL;
}

struct Employee fill_Employee(void)
{
	struct Employee employee;
	printf("\nEnter ID of the employee: ");
	scanf("%d",&(employee.ID));
	printf("Employee Name: ");
	scanf("%s",employee.Name);
	return employee;
}

void print_AllEmployees(void)
{
	struct node* ptr;
	int sum = 0;

	for(ptr = pHead; ptr; ptr=ptr->Next)
	{
		printf("\nEmployee ID: %d, Name: %s\n",(ptr->Data).ID,(ptr->Data).Name);
	}
}

void print_Employee(struct Employee employee)
{
	printf("\nEmployee ID: %d, Name: %s\n",employee.ID,employee.Name);

}

void printMenu(void)
{
    system("cls");
    printf("1-Add Employee\n");
    printf("2-Insert Employee\n");
    printf("3-Search Employees by ID\n");
    printf("4-Search Employees by Name\n");
    printf("5-Delete Employee\n");
    printf("6-Free the list\n");
    printf("7-Display\n");
    printf("8-Exit\n");
}

char getASCII(void)
{
	char ch;
	ch = getch();
	if (ch == -32)
	{
		ch = getch();
	}
	return ch;
}
