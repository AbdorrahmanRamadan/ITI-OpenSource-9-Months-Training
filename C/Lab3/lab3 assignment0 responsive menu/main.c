#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int main()
{
    char ch;
    int row=0;
    printmenu();
    gotoxy1(0,row);
    do{

        ch=getch();
        //down
        if(ch==80){
            row++;
            if(row>3){
                row=0;
            }
            gotoxy1(0,row);
        }
        else{
            //up
            if(ch==72){
            row--;
            if(row<0){
                row=3;
            }
            gotoxy1(0,row);
        }
        }
        //home
        if(ch==71){
            row=0;
            gotoxy1(0,row);
        }
        //end
        if(ch==79){
            row=3;
            gotoxy1(0,row);
        }
        //enter
        if(ch==13){
        //add
        if(row==0)
        {
           add();
        }
        else{
            //subtract
            if(row==1){
                subtract();
            }
            else{
                //multiply
                if(row==2){
                  multiply();
                }
            }
        }
        printmenu();
        gotoxy1(0,row);
    }
    }while(ch!=27&&!(ch==13&&row==3));
    system("cls");
    return 0;
}

void add(){
    int firstNumber,secondNumber;
    system("cls");
    printf("please provide two numbers to be added \n please enter the first number: ");
    scanf("%d",&firstNumber);
    printf("please enter the second number: ");
    scanf("%d",&secondNumber);
    printf("the answer will be %d",firstNumber+secondNumber);
    getch();
}
void subtract(){
    int firstNumber,secondNumber;
    system("cls");
    printf("please provide two numbers to be subtracted \n please enter the first number: ");
    scanf("%d",&firstNumber);
    printf("please enter the second number: ");
    scanf("%d",&secondNumber);
    printf("the answer will be %d",firstNumber-secondNumber);
    getch();
}
void multiply(){
    int firstNumber,secondNumber;
    system("cls");
    printf("please provide two numbers to be multiplied \n please enter the first number: ");
    scanf("%d",&firstNumber);
    printf("please enter the second number: ");
    scanf("%d",&secondNumber);
    printf("the answer will be %d",firstNumber*secondNumber);
    getch();
}

void gotoxy1(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void printmenu(){
    system("cls");
    printf("Add\nSub\nMultiply\nExit\n");
}

