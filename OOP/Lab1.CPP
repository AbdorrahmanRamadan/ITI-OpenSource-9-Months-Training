#include <iostream.h>
#include <string.h>
#include <conio.h>

class employee
{
  private:
    int id;
    char name[20];
    int salary;
  public:
    void setID(int userEnteredID){
      id = userEnteredID;
    };
    void setName(char userEnteredName[]){
      strcpy(name,userEnteredName);
    };
    void setSalary(int userEnteredSalary){
      salary = userEnteredSalary;
    };
    int getID(){
      return id;
    };
    char* getName(){
      return name;    
    };
    int getSalary(){
      return salary;
    };
};

employee fillemp()
{
    clrscr();
    employee e;
    int id,salary;
    char name[20];
    cout<<"enter id: ";
    cin>>id;
    e.setID(id);
    cout<<"enter name: ";
    cin>>name;
    e.setName(name);
    cout<<"enter salary: ";
    cin>>salary;
    e.setSalary(salary);
    return e;
}
void papulateIndex(employee *pt,employee emp)
{
 pt->setID(emp.getID());
 pt->setName(emp.getName());
 pt->setSalary(emp.getSalary());
}
void display(employee *pt,int count)
{
  clrscr();

  for(int i = 0 ; i<count ; i++)
  {
      cout<<"id is "<< (pt+i)->getID() <<endl;
      cout<<"name is "<<(pt+i)->getName()<<endl;;
      cout<<"salary is "<< (pt+i)->getSalary()<<endl;
  }
  getch();
}
int main()
{
  clrscr();
  int count =0,again=1,input=0,numOfEmps;
  employee * empPtr;
  employee employeeToAdd;
  empPtr = new employee[3];

  do{
    clrscr();
    cout<<"1- add emp"<<endl;
    cout<<"2- show all"<<endl;
    cout<<"3- exit"<<endl;
    cin>>input;

    switch(input)
    {
      case 1:
	    employeeToAdd=fillemp();
	    papulateIndex((empPtr+count),employeeToAdd);
	    count++;
        break;
      case 2:
	    display(empPtr,count);
	      break;
      case 3:
	    again=0;
        break;
    }
  }while(again);

 return 0;
}