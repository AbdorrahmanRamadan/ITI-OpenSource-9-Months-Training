#include<iostream.h>
#include<string.h>
#include<conio.h>
class person{
    protected:
    int id;
    char name[20];
    public:
    person(){
	id=0;
	strcpy(name,"John Doe");
    };
    person(int _id, char _name[]){
	id=_id;
	strcpy(name,_name);
    };
    void setID(int ID){
	id=ID;
    };
    int getID(){
	return id;
    };
    void setName(char Name[]){
	strcpy(name,Name);
    };
    char* getName(){
	return name;
    };
    void print(){
	cout<<"ID : "<<id<<endl;
	cout<<"Name : "<<name<<endl;
    };
};

class employee:person{
    protected:
    int salary;
    public:
    employee(){
	salary=0;
    };
    employee(int _id, char _name[],int _salary):person(_id,_name){
	salary=_salary;
    };
    void setSalary(int Salary){
	salary=Salary;
    };
    int getSalary(){
	return salary;
    };
    void print(){
	cout<<"ID : "<<id<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"Salary : "<<salary<<endl;
    };
};

class customer:person{
    protected:
    char contact[12];
    public:
    customer(){
	strcpy(contact,"0");
    };
    customer(int _id, char _name[],char _contact[]):person(_id,_name){
	strcpy(contact,_contact);
    };
    void setContact(char Contact[]){
	strcpy(contact,Contact);
    };
    char* getContact(){
	return contact;
    };
    void print(){
	cout<<"ID : "<<id<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"Contact : "<<contact<<endl;
    };
};


int main(){
clrscr();
cout<<endl<<"testing person class"<<endl;
person p(1,"Abdo");
p.setID(5);
p.setName("Ali");
p.print();


cout<<endl<<"testing employee class"<<endl;
employee e(1,"Abdo",3000);
e.setSalary(5000);
e.print();

cout<<endl<<"testing customer class"<<endl;
customer c(1,"Abdo","01111111111");
c.setContact("010000000000");
c.print();

getch();
return 0;
};