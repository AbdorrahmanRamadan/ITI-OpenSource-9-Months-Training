#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[20];
}Employee;

Employee temp;
Employee array[10];
int count =0;

/*Prototypes*/
void printMenu(void);
int BinarySearchById(Employee array[], int start_index, int end_index, int element);
void addEmployee(Employee emp);
Employee fillEmp();
void mergeSort(Employee arr[], int low, int high);
void merge(Employee arr[] , int low, int mid, int high);
void printArray(void);
void bubbleSort(Employee arr[]);
void swap(Employee *x, Employee *y);

int main()
{
    temp.id = -1;

    int i,input,id,bs;

    int flag = 1;
    char name[20];
    while(flag)
    {
        printMenu();
        scanf("%d", &input);
        switch(input)
        {
        case 1:
            system("cls");
            addEmployee(fillEmp());
            break ;

        case 2:
            system("cls");
            printArray();
            break ;

        case 3:
            system("cls");
            mergeSort(array,0,count-1);
            break ;

        case 4:
            system("cls");
            bubbleSort(array);
            break ;

        case 5:
            system("cls");
            bubbleSort(array);
            printf("Enter the id to search with: ");
            scanf("%d",&id);
            bs = BinarySearchById(array,0,count-1,id);
            if(bs==-1){
                printf("Not found!\n");
            }else{
                printf("Element found at index: %d\n",bs);
                printf("Employee ID: %d, Name: %s", array[bs].id, array[bs].name);
            }
            break ;
        case 6:
            system("cls");
            flag = 0;
            break ;
        default:

            break;
        }
        printf("\npress any key to continue\n");
        getch();
    }
    return 0;
}

void swap(Employee *x, Employee *y)
{
    Employee temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(Employee arr[])
{
   int i, j;
   for (i = 0; i < count-1; i++)
       // Last i elements are already in place
       for (j = 0; j < count-i-1; j++)
           if (arr[j].id > arr[j+1].id)
              swap(&arr[j], &arr[j+1]);
}

void printArray(){
    int i;
    for(i=0;i<count ; i++){
        printf("\nEmployee ID: %d, Name: %s" ,array[i].id, array[i].name);
    }
    printf("\n");
}


void merge(Employee arr[] , int low, int mid, int high){
    int i,j,k;

    int n1 = mid - low +1;
    int n2 = high - mid ;

    Employee Left [n1];
    Employee Right[n2];

    int x;
    for(x=0; x< n1; x++){
        Left[x] = arr[low + x];
    }
    for(x=0; x< n2; x++){
        Right[x] = arr[mid+1 + x];
    }

    i=0;
    j=0;
    k = low;

    while( i <n1 && j < n2){
        if(  stricmp(Left[i].name , Right[j].name)<0 ){
            arr[k] = Left[i];
            i++;
            k++;

        }else{
            arr[k] = Right[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k] = Left[i];
            i++;
            k++;
    }
    while(j<n2){
        arr[k] = Right[j];
        j++;
        k++;
    }

}


void mergeSort(Employee arr[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(arr, low,mid);
        mergeSort(arr, mid+1, high);
        merge(arr,low,mid,high);
    }
}


Employee fillEmp()
{
    Employee e1 ;
    printf("enter id :");
    scanf("%d", &e1.id) ;
    printf("enter name :");
    scanf("%s", e1.name) ;
    return e1;
}

void addEmployee(Employee emp)
{
    if(count<10){
        array[count++] = emp;
    }else{
        printf("array full!! \n");
    }

}


int BinarySearchById(Employee array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle].id == element)
         return middle;
      if (array[middle].id > element)
         return BinarySearchById(array, start_index, middle-1, element);
      return BinarySearchById(array, middle+1, end_index, element);
   }
   return -1;
}

void printMenu(void)
{
    system("cls");
    printf("1-Add Employee\n");
    printf("2-Display All\n");
    printf("3-Merge Sort By Name\n");
    printf("4-Bubble Sort By ID\n");
    printf("5-Binary Search By ID\n");
    printf("6-Exit\n");
    printf("Please Select: ");
}

