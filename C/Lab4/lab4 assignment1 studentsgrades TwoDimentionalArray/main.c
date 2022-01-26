#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3][4],studentSumOfGrades,subjectSumOfGrades,subjectAverageGrades;

    printf("you will be asked to enter three students degrees in four subjects to get the sum of each student grades and the average of a subject grade\n");

    for(int studentIndex = 0 ; studentIndex < 3 ; studentIndex++){
        for(int gradeIndex = 0 ; gradeIndex < 4 ; gradeIndex++){
        printf("enter student number #%d's degree in subject number #%d : ",studentIndex+1,gradeIndex+1);
        scanf("%d",&arr[studentIndex][gradeIndex]);
        }
    }

    for(int studentIndex = 0 ; studentIndex < 3 ; studentIndex++){
        studentSumOfGrades=0;
        for(int gradeIndex = 0 ; gradeIndex < 4 ; gradeIndex++){
        studentSumOfGrades+=arr[studentIndex][gradeIndex];
        }
        printf("the sum of student number #%d's degrees is %d \n",studentIndex+1,studentSumOfGrades);
    }

    for(int gradeIndex = 0 ; gradeIndex < 4 ; gradeIndex++){
        subjectSumOfGrades=0;
        for(int studentIndex = 0 ; studentIndex < 3 ; studentIndex++){
        subjectSumOfGrades+=arr[studentIndex][gradeIndex];
        }
        subjectAverageGrades=subjectSumOfGrades/3;
        printf("the average of degrees in subject number #%d is %d \n",gradeIndex+1,subjectAverageGrades);
    }
    return 0;
}
