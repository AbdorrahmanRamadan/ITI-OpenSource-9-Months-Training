#include <iostream.h>
#include <string.h>
#include <conio.h>

class Employee
{
  private:
    int id;
    char* name;
    int salary;
    int size;
  public:
    //setters&getters
    void setID(int userEnteredID);
    void setName(char* userEnteredName);
    void setSalary(int userEnteredSalary);
    int getID();
    char* getName();
    int getSalary();
    //constructors
    Employee();
    Employee(int objID);
    Employee(int objID,char* objName);
    Employee(int objID,char* objName,int objSal);
    Employee(Employee &emp); 
};

Employee fillemp()
{
    clrscr();
    Employee e;
    int id,salary,size;
    char* name;
    cout<<"enter id: ";
    cin>>id;
    e.setID(id);
    cout<<"enter employee name size: ";
    cin>>size;
    name = new char[size];
    cout<<"enter name: ";
    cin>>name;
    e.setName(name);
    cout<<"enter salary: ";
    cin>>salary;
    e.setSalary(salary);
    return e;
}
void display(Employee emp)
{
  clrscr();
  cout<<"id is "<< emp.getID() <<endl;
  cout<<"name is "<<emp.getName()<<endl;
  cout<<"salary is "<< emp.getSalary()<<endl;
  getch();
}
int main()
{
  Employee emp = new Employee(12,"abdo",2000);
  display(emp);
  emp.setName("Mohamed");
  display(emp);
  return 0;
}

void Employee::setID(int userEnteredID){
  id = userEnteredID;
};

void Employee::setName(char* userEnteredName){
  name=new char[size];
  strcpy(name,userEnteredName);
};

void Employee::setSalary(int userEnteredSalary){
  salary = userEnteredSalary;
};

int Employee::getID(){
  return id;
};

char* Employee::getName(){
  return name;    
};

int Employee::getSalary(){
  return salary;
};
Employee::Employee(){
  id=0;
  name= new char[strlen("john doe")];
  strcpy(name,"john doe");
  salary=1;
};
Employee::Employee(int objID){
  id=objID;
  name= new char[strlen("john doe")];
  strcpy(name,"john doe");
  salary=1;
};
Employee::Employee(int objID,char* objName){
  id=objID;
  name= new char[strlen(objName)];
  strcpy(name,objName);
  salary=1;
};
Employee::Employee(int objID,char* objName,int objSal){
  id=objID;
  name= new char[strlen(objName)];
  strcpy(name,objName);
  salary=objSal;
};
Employee::Employee(Employee &emp){
  id=emp.id;
  name=new char[strlen(emp.name)+1];
  strcpy(name,emp.name);
  salary=emp.salary;
}; 