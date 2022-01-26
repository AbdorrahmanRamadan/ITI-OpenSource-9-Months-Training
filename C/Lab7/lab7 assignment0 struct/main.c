#include <stdio.h>
#include <stdlib.h>

struct student{
int id;
char name [25];
int grades[3];
};

void printStudent(struct student s);
struct student fillStudent();

static int studIndex,size;


int main()
{
    int menuChoice,orderChoice;

    printf("Please enter how many students are there: ");
    scanf("%d",&size);
    struct student *students;
    students = (struct student *) malloc(size * sizeof(struct student));


    do{
        system("cls");
        printf("Please select an action by entering a number\n1.Add Student\n2.Display Student\n3.Display All\n4.Exit\n");
        scanf("%d",&menuChoice);
        switch(menuChoice){
            case 1:
                students[studIndex] = fillStudent();
                break;
            case 2:
                system("cls");
                printf("please enter the student order:");
                scanf("%d",&orderChoice);
                if(orderChoice<studIndex+1){
                    printStudent(students[orderChoice-1]);
                }
                else{
                    printf("there is no student with this order!\a");
                }
                getch();
                break;
            case 3:
                for(int i = 0 ; i < studIndex ; i++){
                    if(studIndex!=0){
                        printStudent(students[i]);
                    }
                }
                getch();
                break;
            default:
                break;
        }
    }while(menuChoice!=4);
    return 0;
}


struct student fillStudent()
{
struct student s;
    if(studIndex>size-1){
        printf("you've exceeded the limits");
        getch();
        return;
    }
    else{
    printf("Please enter student's %d id:",studIndex+1);
    scanf("%d",&s.id);
    printf("Please enter student's %d name:",studIndex+1);
    scanf("%s",s.name);
    for(int i = 0 ; i < 3 ; i++){
        printf("Please enter student's %d grade %d:",studIndex+1,i+1);
        scanf("%d",&s.grades[i]);
    }
    studIndex++;
    return s;
    }
}

void printStudent(struct student s)
{
    printf("\n");
    printf("studentId: %d\nstudentName: %s\n", s.id,s.name);
    for(int i = 0 ; i < 3 ; i++){
        printf("student's grade %d: %d\n",i,s.grades[i]);
    }
}

