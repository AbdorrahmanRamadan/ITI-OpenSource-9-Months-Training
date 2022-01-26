#include <stdio.h>
#include <stdlib.h>

int main()
{

    int min=0,max=0,num;
    printf("Please Enter Five Numbers to get the min and the max\n");
    printf("Please Enter number 1 :");
    scanf("%d",&num);
    min=max=num;
    for(int i=2;i<=5;i++){
        printf("Please Enter number %d :",i);
        scanf("%d",&num);
        if(num>max){
            max=num;
        }
        if(num<min){
            min=num;
        }
    }
    printf("the maximum number is %d and the minimum number is %d",max,min);
    return 0;
}
