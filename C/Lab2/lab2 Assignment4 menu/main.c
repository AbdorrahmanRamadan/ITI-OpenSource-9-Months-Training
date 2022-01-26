#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    printf("select from this menu:\n 1. Add\n 2. Edit\n 3. Delete\n 4. Exit\nEnter your choice (1-4):\n");
    do{
       scanf("%d",&choice);
       if(choice==1){
            printf("add\n");
       }
        else if(choice==2){
            printf("edit\n");
        }
        else if(choice==3){
            printf("delete\n");
        }
    }while (choice!=4);


    return 0;
}
