#include <math.h>
#include <stdio.h>
int main() {
    printf("Enter coefficient a,b,and c for an equation like (ax² + bx + c = 0)\n");
    float a, b, c, discriminant, firstAnswer, secondAnswer;
    printf("Enter coefficient a: ");
    scanf("%f",&a);
    printf("Enter coefficient b: ");
    scanf("%f",&b);
    printf("Enter coefficient c: ");
    scanf("%f",&c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        firstAnswer = (-b + sqrt(discriminant)) / (2 * a);
        secondAnswer = (-b - sqrt(discriminant)) / (2 * a);
        printf("firstAnswer X = %f and secondAnswer X = %f", firstAnswer, secondAnswer);
    }

    else if (discriminant == 0) {
        firstAnswer = -b / (2 * a);
        printf("there is only one answer X %f;", firstAnswer);
    }

    else {
        printf("the answer is imaginary");
    }

    return 0;
}
