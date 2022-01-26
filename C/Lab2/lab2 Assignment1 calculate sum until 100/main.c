#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Sum=0,num;
    printf("This program will exit when the sum equals or exceeds 100\n");
    while(Sum<100){
        printf("Please enter next number: ");
        scanf("%d",&num);
        Sum += num;
    }
    printf("The sum is %d",Sum);
    return 0;
}
