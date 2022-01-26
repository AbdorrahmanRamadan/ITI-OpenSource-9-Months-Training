#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5], min, max;
    printf("enter five integer numbers to get the maximum and minimum of them \n");
    for(int i = 0 ; i < 5 ; i++){
        printf("enter number #%d :",i+1);
        scanf("%d",&arr[i]);
    }
    min=max=arr[0];
    for(int i = 1 ; i < 5 ; i++){
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    printf("maximum will be %d and the minimum will be %d",max,min);

    return 0;
}
