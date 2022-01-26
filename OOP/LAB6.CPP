#include <iostream.h>
#include <conio.h>
#include <string.h>
class Shape{
	protected:
		int dim1, dim2;
	public:
		Shape(){
			dim1 = dim2 = 0;
		}
		Shape(int m){
			dim1 = dim2 = m;
		}
		Shape(int m, int n){
			dim1 = m;
			dim2 = n;
		}
		void setD1(int _dim1){
			    dim1 = _dim1;
		}
		void setD2(int _dim2){
			dim2 = _dim2;
		}
		int getD1(){
			return dim1;
		}
		int getD2(){
			return dim2;
		}
		virtual float Area() = 0;
};
class Circle: public Shape{
	public:
		Circle(){}
		Circle(int r):Shape(r){}
		float Area(){
			return (3.14*dim1*dim2);
		}

};
class Rectangle: public Shape{
	public:
		Rectangle(){}
		Rectangle(int l, int w): Shape(l,w){}
		float Area(){
			return (dim1 * dim2);
		}
};
class Triangle: public Shape{
	public:
		Triangle(){}
		Triangle(int b, int h):Shape(b ,h){}
		float Area(){
			return (0.5* dim1 * dim2);
		}
};
class Square : public Rectangle{
	public:
		Square(){}
		Square(int s):Rectangle(s,s){}

};
class GeoShape{
	int count;
	Shape **p;
	public:
		GeoShape(int s, Shape **shapes);
        float totalArea();



};
GeoShape::GeoShape(int s, Shape **shapes){
		 count = s;
		 p = new Shape*[s];
		 for(int i = 0; i < s; i++ ){
				p[i] = shapes[i];
			 }
};
float GeoShape::totalArea(){
			float sum = 0;
			for(int i = 0; i < count; i++){
				sum += p[i]->Area();
			}
			return sum;
}
int main(){
	clrscr();
	Shape **shapes = new Shape*[5];
        Circle c(7);
	Rectangle r(20, 5);
	Triangle t(20, 10);
	Square s(4);
	shapes[0] = &c;
	shapes[1] = &r;
	shapes[2] = &t;
	shapes[3] = &s;
	GeoShape geo(4, shapes);
	cout<<geo.totalArea();
	getch();
	return 0;
}
