#include <iostream.h>
#include <conio.h>
#include <string.h>
class Employee{
	int id;
	char* name;
	int salary;

	void defaultConstructor(){
	  id = -1;
	  name = new char[strlen("John Doe")+1];
	  strcpy(name,"John Doe");
	  salary = -1;
	};
	public:
		void setId(int _id){
			id = _id;
		};

		void setName(char *_name){
			name = new char[strlen(_name)+1];
			strcpy(name, _name);

		};
		void setSalary(float _salary){
			salary = _salary;
		};
		int getId(){
			return id;
		};
		char* getName(){

			return name;
		};
		float getSalary(){
			return salary;
		};
		Employee(){
			defaultConstructor();
		};
		Employee(int empId){
			defaultConstructor();
			id = empId;
		};
		Employee(char* empName){
			defaultConstructor();
			name = new char[strlen(empName)+1];
			strcpy(name, empName);
		};
		Employee(int empId,char* empName){
			defaultConstructor();
			id = empId;
			name = new char[strlen(empName)+1];
			strcpy(name, empName);
		};
		Employee(int empID, char* empName, float empSalary){
			id = empID;
			name = new char[strlen(empName)+1];
			strcpy(name, empName);
			salary = empSalary;
		};
		Employee(Employee &Emp){
			id = Emp.id;
			salary = Emp.salary;
			name = new char[strlen(Emp.name)+1];
			strcpy(name,Emp.name);
		};

		Employee operator+(Employee e){
			Employee eTemp;
			eTemp.id = 0;
			eTemp.name = new char[strlen(this->name)+strlen(e.name)+2];
			strcpy(eTemp.name,this->name);
			strcat(eTemp.name," ");
			strcat(eTemp.name,e.name);
			eTemp.salary = salary + e.salary;
			return eTemp;

		};
		Employee operator+(char* mName){
			Employee eTemp;
			eTemp.id = this->id;
			eTemp.name = new char[strlen(this->name)+strlen(mName)+2];
			strcpy(eTemp.name,this->name);
			strcat(eTemp.name," ");
			strcat(eTemp.name,mName);
			eTemp.salary = this->salary;
			return eTemp;
		};
	       friend Employee operator+(char* mName, Employee e){
			Employee eTemp;
			eTemp.id = e.id;
			eTemp.name = new char[strlen(mName)+strlen(e.name)+2];
			strcpy(eTemp.name,mName);
			strcat(eTemp.name," ");
			strcat(eTemp.name,e.name);
			eTemp.salary = e.salary;
			return eTemp;

		};
		Employee operator++(){
			salary++;
			return *this;
		};
		Employee operator++(int d){
			Employee raisedEmp;
			raisedEmp = *this;
			salary++;
			return raisedEmp;
		};
		Employee &operator=(Employee &e){
		     id = e.id;
		     salary = e.salary;
		     delete(name);
		     name = new char[strlen(e.name)+1];
		     strcpy(name, e.name);
		     return *this;

		};
		int operator==(Employee e){
			return (id == e.id && salary == e.salary && !strcmp(name, e.name));
		};
		Employee operator+(int bonus){
			Employee eTemp;
			eTemp.id = id;
			eTemp.salary = salary + bonus;
			strcpy(eTemp.name, name);
			return eTemp;
		};
		friend Employee operator+(int bonus, Employee e){
			Employee eTemp;
			eTemp.id = e.id;
			strcpy(eTemp.name, e.name);
			eTemp.salary = e.salary + bonus;
			return eTemp;

		};
		 operator int(){
			return id;
		};
		operator char*(){
			return name;
		};
};
Employee fillData();
void printData(Employee e);
int main(){
	clrscr();
	Employee Emp,Emp1,Emp2;
	cout<<"Fill First Employee Emp\n";
	Emp = fillData();
	cout<<endl<<"Fill Second Employee Emp1\n";
	Emp1 = fillData();
	cout<<endl<<"Emp = Emp1\n";
	Emp = Emp1;
	cout<<endl<<"Emp data is now \n";printData(Emp);
	cout<<endl<<"Fill third Employee Emp2\n";
	Emp2 = fillData();
	cout<<endl<<"Emp1 + Emp2\n";
	cout<<endl<<"the result will equal \n";printData(Emp1+Emp2);
	cout<<endl<<" Emp + 1000 \n";printData(Emp+1000);
	cout<<endl<<" 1000 + Emp \n";printData(1000+Emp);
	cout<<endl<<" Emp + \"Ahmed\" \n";printData((Emp+"Ahmed"));
	cout<<endl<<" \"Ahmed\" + Emp \n";printData(("Ahmed"+Emp));
	cout<<endl<<" (char*) Emp : "<<(char*) Emp<<endl;
	cout<<endl<<" (int) Emp : "<<(int) Emp<<endl;
	cout<<endl<<" ++ Emp \n";printData(++Emp);
	cout<<endl<<" Emp ++ \n";printData(Emp++);
	cout<<endl<<"copmarision between Emp and Emp1 will point out that they are :-\n";
    if(Emp==Emp1){
	    cout<<"identical\n";
	}
	else{
		cout<<"not the same\n";
	}
	getch();
	return 0;
}
Employee fillData(){
	Employee e;
	int empId;
	char* empName;
	float empSalary;
	cout<<"Enter Employee Id: ";
	cin>>empId;
	cout<<"Enter Employee Name: ";
	cin>>empName;
	cout<<"Enter Employee Salary: ";
	cin>>empSalary;
	e.setId(empId);
	e.setName(empName);
	e.setSalary(empSalary);
	return e;
};
void printData(Employee e){
	cout<<"Employee ID: "<<e.getId()<<endl;
	cout<<"Employee Name: "<<e.getName()<<endl;
	cout<<"Employee Salary: "<<e.getSalary()<<endl;

}
