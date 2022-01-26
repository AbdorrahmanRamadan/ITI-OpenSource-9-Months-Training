#include <stdio.h>
#include <stdlib.h>

int getPower(int base,int power)
{
    int sum;
    if(power==0)
        sum = 1;
    else
        sum = base*getPower(base,power-1);

    return sum;
}

int main()
{
    int base,power;
    printf("This is a program to compute powers you'll be asked to enter a base and a power to get the answer\n");
    printf("Please enter the base :");
    scanf("%d",&base);
    printf("Please enter the power :");
    scanf("%d",&power);

    printf("base %d to the power of %d will equal %d",base,power,getPower(base,power));

    return 0;
}
