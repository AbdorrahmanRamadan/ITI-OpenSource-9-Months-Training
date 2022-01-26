#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#define PI 3.14
class point
{
    private:
    int x;
    int y;

    public:
    point(){
        x = y = 0 ;
    };
    point(int a){
        x = y  =a ;
    };
    point(int a , int b){
        x = a;
        y = b;
    };
    void setX(int a){
        x = a;
    };
    int getX(){
        return x;
    };
    void setY(int b){
        y = b;
    };
    int getY(){
        return y;
    };
};

class comRectangle
{
    private:
    point p1;
    point p2;
    int length,width;

    public:
    comRectangle(int x1 ,int y1, int x2 ,int y2):p1(x1,y1),p2(x2,y2){
        length =abs(x1 - x2);
        width = abs(y1 - y2);
    };
    int getArea (){
        return length*width;
    };
};

class asRectangle
{
    private:
    point* p1;
    point* p2;
    int length ,width;

    public:
    asRectangle(){
        p1 = p2 = NULL;
    };

    asRectangle(point *pa , point *pb){
        p1 = pa;
        p2 = pb;
        if(p1 && p2){
            length = abs(p1->getX() - p2->getX());
            width = abs(p1->getY() - p2->getY());
        };
    };
    int getArea(){
        return length * width;
    };
};

class comCircle
{
    private:
    point p1;
    point p2;
    int r;

    public:
    comCircle(int x1 , int y1 , int x2 ,int y2 ):p1(x1,y1),p2(x2,y2){
        r=pow(x1-x2,2)+pow(y1-y2,2);
    };
    float getArea(){
	return (PI*r);
    };
};

class asCircle
{
    private:
    point *p1 ,*p2;
    int r;

    public:
    asCircle(){
        p1 = p2 = NULL;
        r = 0 ;
    };
    asCircle(point *pa ,point *pb){
        p1 = pa;
        p2 = pb;
        if (p1 && p2){
            r =pow(p1->getX()-p2->getX(),2)+pow(p1->getY()-p2->getY(),2);
        };
    };
    float getArea(){
        return PI * r;
    };
};


int main()
{
clrscr();

cout<<"using composition rectangle"<<endl;
comRectangle cR(2,3,5,6);
cout<<cR.getArea()<<endl;

cout<<"using assiciation rectangle"<<endl;
point p1(2,3);
point *pm = &p1;
point p2(5,6);
point *pn = &p2;
asRectangle aR(pm,pn);
cout<<aR.getArea()<<endl;

cout<<"using composition circle"<<endl;
comCircle cC(4,10,6,10);
cout<<cC.getArea()<<endl;

cout<<"using association circle"<<endl;
p1.setX(4);
p1.setX(10);
p2.setX(6);
p2.setY(10);
asCircle aC(pm,pn);
cout<<aC.getArea()<<endl;

getch();
return 0;
}