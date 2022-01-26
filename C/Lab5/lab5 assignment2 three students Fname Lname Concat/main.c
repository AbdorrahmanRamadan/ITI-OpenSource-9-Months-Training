#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void concatStrings(char Fnames[3][25],char Lnames[3][25]){
    char fullNames[3][50];
    for(int i = 0; i < 3; i++){
        strcpy(fullNames[i],Fnames[i]);
        strcat(fullNames[i]," ");
        strcat(fullNames[i],Lnames[i]);
    }

    for(int i = 0; i < 3; i++){
        printf("Hello %s \n",fullNames[i]);
    }
}

int main()
{
    char Fnames[3][25],Lnames[3][25];
    for(int i = 0; i < 3; i++){
        printf("student number %d\n",i+1);
        printf("please enter your First name:");
        scanf("%s",Fnames[i]);
        printf("please enter your last name:");
        scanf("%s",Lnames[i]);
        system("cls");
    }

    concatStrings(Fnames,Lnames);
    return 0;
}
