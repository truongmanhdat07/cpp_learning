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
		
		double doDai() const;
		
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
		Vector& operator*=(const double k);
		
		bool operator==(const Vector &other) const;
		bool operator!=(const Vector &other) const;
		bool operator<(const Vector &other) const;
		bool operator>(const Vector &other) const;
		bool operator>=(const Vector &other) const;
		bool operator<=(const Vector &other) const;
};





Vector::Vector(double x, double y){
	this->x = x;
	this->y = y;
}

double Vector::doDai() const{
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

Vector& Vector::operator*=(const double k){
	this->x *= k;
	this->y *= k;
	
	return *this;
}


//bool Vector::operator==(const Vector &other) const{
//	return (x == other.x ) && ( y == other.y);
//}
//
//bool Vector::operator!=(const Vector &other) const{
//	return !(*this == other)
//}

bool Vector::operator==(const Vector &other) const{
	return ( this->doDai() == other.doDai() );
}

bool Vector::operator!=(const Vector &other) const{
	return !( *this == other );
}

bool Vector::operator<(const Vector &other) const{
	return ( this->doDai() < other.doDai() );
}

bool Vector::operator>(const Vector &other) const{
	return ( this->doDai() > other.doDai() );
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
	
	Vector v3(3, 3);
	v3 *= 5;
	cout << "v3 *= 5 = " << v3 << endl;

	Vector v4(0, 0), v5(0, 0);

	
	if(v4 == v5)	cout << "\nv4 == v5";
	else			cout << "\nv4 != v5";
	
	
	return 0;
}
