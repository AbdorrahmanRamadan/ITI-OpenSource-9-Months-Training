#include <iostream.h>
#include <conio.h>

class Point3D
{
int x, y, z;
public:
Point3D()
{x = y = z = 0;}
Point3D(int l,int m,int n)
{x = l; y = m; z = n;}
void SetX(int m){ x = m;}
int GetX(){return x;}
void SetY (int m) { y = m;}
int GetY (){return y;}
void SetZ(int m) { z = m;}
int GetZ(){return z;}
friend ostream& operator<<(ostream& out, Point3D p);
friend istream& operator>>(istream& in, Point3D& p);
};
istream& operator>>(istream& in, Point3D& p)
{
cout<<"Enter X:";
in>>p.x;
cout<<"Enter Y:";
in>>p.y;
cout<<"Enter Z:";
in>>p.z;
return in; //return c in;
};
ostream& operator<<(ostream& out, Point3D p)
{
out<<"X = "<<p.x<<endl;
out<<"Y = "<<p.y<<endl;
out<<"Z = "<<p.z<<endl;
return cout;//return out;
};
int main()
{
clrscr();
Point3D  pt;
cout << "cin >> pt will run now"<<endl;
cin >> pt;
cout << "cin << pt will run now"<<endl;
cout << pt;
getch();
return 0;
};










