#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void copyString(char name[]){
    char copiedName[10];
    for(int i = 0 ; i < 10 ; i++){
        copiedName[i] = name[i];
    }
    printf("Hello %s",copiedName);

}

int main()
{
    printf("please enter your name:");
    char name[10];
    scanf("%s",name);
    copyString(name);
    return 0;
}
