#include<iostream>
#include<cmath>

using namespace std;

class Vector{
	private:
		double x;
		double y;
	public:
		Vector() : x(0.0), y(0.0){}
		Vector(double x, double y);
		
		double doDai();
		
		friend istream& operator>>(istream &in, Vector &v);
		friend ostream& operator<<(ostream &out, const Vector &v);
		
		Vector operator-() const;
		
		Vector operator+(const Vector &other) const;
		Vector operator-(const Vector &other) const;
		double operator*(const Vector &other) const;
		Vector operator*(const double k) const;
		
		Vector& operator=(const Vector &other);
		Vector& operator+=(const Vector &other);
		Vector& operator-=(const Vector &other);
};





Vector::Vector(double x, double y){
	this->x = x;
	this->y = y;
}

double Vector::doDai(){
	return sqrt(x * x + y * y);
}

istream& operator>>(istream &in, Vector &v){
	cout << "x:";	in >> v.x;
	cout << "y:";	in >> v.y;
	
	return in;
}

ostream& operator<<(ostream& out, const Vector &v){
	out << "(" << v.x << ", " << v.y << ")";
	
	return out;
}

Vector Vector::operator-() const{
	return Vector(-x, -y);
}

Vector Vector::operator+(const Vector &other) const{
	return Vector( x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector &other) const{
	return Vector( x - other.x, y - other.y);
}

double Vector::operator*(const Vector &other) const{
	return  x * other.x +  y * other.y;
}

Vector Vector::operator*(const double k) const{
	return Vector( x * k, y * k);
}

Vector& Vector::operator=(const Vector &other){
	this->x = other.x;
	this->y = other.y;
	
	return *this;
}

Vector& Vector::operator+=(const Vector &other){
	this->x += other.x;
	this->y += other.y;
	
	return *this;
}

Vector& Vector::operator-=(const Vector &other){
	this->x -= other.x;
	this->y -= other.y;
	
	return *this;
}







int main(){
	Vector v1, v2;
	cin >> v1 >> v2;
	cout << "v1 = " << v1 << " , " << "v2 = " <<  v2 << endl;
	
	cout << "v1 + v2 = " << v1 + v2 << endl;
	cout << "v1 - v2 = " << v1 - v2 << endl;
	cout << "v1 * v2 = " << v1 * v2 << endl;
	cout << "v1 * 5  = " << v1 * 5  << endl;

	v1 += v2;
	cout << "v1 += v2 = " << v1;


	
	return 0;
}
