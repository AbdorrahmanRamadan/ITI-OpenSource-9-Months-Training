#include <iostream.h>
#include <conio.h>
#include <fstream.h>


int main()
{
    //textfile
    clrscr();
    // creating object from f stream
    fstream obj;
    // openning testfile for writing
    obj.open("testfile.txt", ios::out);

    int x = 12;

    //Write to file
    obj<<x<<endl;
    //close file
    obj.close();

    // openning testfile for reading
    obj.open("testfile.txt", ios::in);
    int y;
    // Read From file (ifstream )
    obj>> y;
    obj.close();
    cout<<y;

    getch();

    //binaryfile
    clrscr();
    // creating object from f stream
    fstream objb;
    // openning binaryfile for writing
    objb.open("binaryfile.bin", ios::out);

    int x = 12;

    //Write to file
    obj<<x<<endl;
    //close file
    objb.close();

    // openning binaryfile for reading
    objb.open("binaryfile.bin", ios::in);
    int y;
    // Read From file (ifstream )
    obj>> y;
    objb.close();
    cout<<y

    return 0;
}
