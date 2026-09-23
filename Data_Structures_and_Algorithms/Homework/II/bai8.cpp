#include<iostream>
#include<cmath>
using namespace std;

class Point{
	private:
		float x, y;
	public:
		Point(float x = 0.0f, float y = 0.0f) : x(x), y(y){}
		
		void setX(float x1){this->x = x1; };
		void setY(float y1){this->y = y1; };
		
		float getX(){return x; };
		float getY(){return y; };
		
		void input();
		void display();
		
		float distance(Point &other);
};


void Point::input(){
	cout << "Nhap x:";	cin >> x;
	cout << "Nhap y:";	cin >> y;
}

void Point::display(){
	cout << "(" << x << ", " << y << ")";
}

float Point::distance(Point &other){
	float dx = x - other.x;
	float dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}

class Triangle{
	private:
		Point A, B , C;
	public:
		Triangle(){};
		Triangle(Point A, Point B, Point C) : A(A) , B(B), C(C){}
		
		void input();
		void display();
		
		float perimeter();
		float area();
};

void Triangle::input(){
	cout << "Nhap toa do dinh A:\n"; A.input();
    cout << "Nhap toa do dinh B:\n"; B.input();
    cout << "Nhap toa do dinh C:\n"; C.input();
}

void Triangle::display(){
	cout << "Tam giac tao boi 3 dinh: ";
    A.display(); cout << ", ";
    B.display(); cout << ", ";
    C.display();
}

float Triangle::perimeter(){
    float a = B.distance(C);
    float b = A.distance(C);
    float c = A.distance(B);
    return a + b + c;
}

float Triangle::area(){
	float a = B.distance(C);
    float b = A.distance(C);
    float c = A.distance(B);
    float p = (a + b + c) / 2.0f;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main(){
	Triangle tri;
	
	cout << "Nhap tam giac:" << endl;
	tri.input();
	
	tri.display();
	
	cout << "\nChu vi:" << tri.perimeter() << endl;
	cout << "Dien tich:" << tri.area() << endl;
	
	return 0;
}
