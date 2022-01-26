#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdint.h>
#include<limits.h>

/* Global Variables */
typedef struct
{
	int ID;
	char Name[50];
}Employee;

Employee queue[5];	// Items of the Queue
int last = -1;         		// Last of the Queue
int front = -1;         		// Front of the Queue

int enqueue(Employee data)
{
    int retval=0;
    if (last >= 4)
	{
        printf("There's no space in the stack!\n");
    }
	else
	{
		if (front == -1)
			front = 0;
		last++;
		queue[last] = data;
		retval=1;
	}
    return retval;
}

Employee dequeue(void)
{
	Employee result;
    if (last == -1)
    {
		result.ID = -1;
    }
    else
    {
		result = queue[front];
		for(int i=front; i<last; i++)
		{
			queue[i] = queue[i+1];
		}
		last--;
    }
	return result;
}

void fill_Employee(void)
{
	int flag;
	Employee employee;
	printf("\nEnter ID of the employee: ");
	scanf("%d",&(employee.ID));
	printf("Employee Name: ");
	scanf("%s",employee.Name);
	flag = enqueue(employee);
	if (!flag)
	{
        printf("There's no space in the stack!\n");
	}
}

void print_Employee(Employee employee)
{
	printf("\nEmployee ID: %d, Name: %s\n",employee.ID,employee.Name);
}

void print(void)
{
	for (int i=0; i<=last; i++)
	{
		print_Employee(queue[i]);
	}
}

void menu(void)
{
	system("cls");
    printf("1-ENQUEUE\n");
    printf("2-DEQUEUE\n");
    printf("3-Display\n");
    printf("4-Exit\n");
    printf("Please Select: ");
}

int main(int argc, char* argv[])
{
	int select,flag,de;
	Employee emp;
	flag = 1;
	while(flag)
	{
		menu();
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
					emp = dequeue();
					if (emp.ID != -1)
					{
						print_Employee(emp);
						printf("Done\n");
					}
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
