#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void gotoxy1(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void line_editor(char* str,int size)
{
    char buttonDown;
    int col=0;
    gotoxy1(col,5);
    do{
        buttonDown=getch();
        if(buttonDown==-32){
            buttonDown=getch();
                //right
            if(buttonDown==77){
                col++;
                if(col>strlen(str)){
                    col=0;
                }
                gotoxy1(col,5);
            }
            //left
            else if(buttonDown==75){
                col--;
                if(col<0){
                    col=strlen(str);
                }
                gotoxy1(col,5);
            }
            //home
            else if(buttonDown==71){
                col=0;
                gotoxy1(col,5);
            }
            //end
            else if(buttonDown==79){
                col=strlen(str);
                gotoxy1(col,5);
            }

        }
        else{
            //enter
            if(buttonDown==13){
                gotoxy1(0,10);
                printf("%s",str);
            }
            else if(isprint(buttonDown)&&strlen(str)<size)
            {
                printf("%c",buttonDown);
                str[col]=buttonDown;
                col++;
            }
    }
    }while(buttonDown!=27&&buttonDown!=13);


}
int main()
{
    printf("this is your line editor please enter the size you want it to be:");

    char *str;
    int size;
    scanf("%d",&size);
    str = (char *) malloc(size * sizeof(char));
    for(int i = 0 ; i<=size; i++ ){
        str[i]='\0';
    }
    line_editor(str,size);

    return 0;
}
