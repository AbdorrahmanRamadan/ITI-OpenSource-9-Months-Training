#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void concatString(char Fname[],char Lname[]){
    char fullName[50];
    strcpy(fullName,Fname);
    strcat(fullName," ");
    strcat(fullName,Lname);
    printf("Hello %s",fullName);
}

int main()
{
    char Fname[10],Lname[10];
    printf("please enter your First name:");
    scanf("%s",Fname);
    printf("please enter your last name:");
    scanf("%s",Lname);
    concatString(Fname,Lname);
    return 0;
}
