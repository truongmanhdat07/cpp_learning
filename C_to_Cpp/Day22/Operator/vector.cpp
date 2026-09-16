#include<iostream>
#include<cmath>

using namespace std;

class Vector{
	private:
		double x;
		double y;
	public:
		Vector(double x = 0.0f, double y = 0.0f) : x(x), y(y){}
		
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

bool Vector::operator<=(const Vector &other) const{
	return ( *this < other || *this == other); // return !( *this > other );
}

bool Vector::operator>=(const Vector &other) const{
	return ( *this > other || *this == other); // return !( *this < other );
}



int main(){
	double k;
	cout << "k:";	cin >> k;
	Vector v1, v2;
	cout << "v1:" << endl;	cin >> v1;
	cout << "v2:" << endl;	cin >> v2;
	cout << "v1 = " << v1 << " , " << "v2 = " <<  v2 << endl;
	
	cout << "v1 + v2 = " << v1 + v2 << endl;
	cout << "v1 - v2 = " << v1 - v2 << endl;
	cout << "v1 * v2 = " << v1 * v2 << endl;
	cout << "v1 * " << k << " = " << v1 * k  << endl;

	v1 += v2;
	cout << "v1 += v2 = " << v1 << endl;
	
	Vector v3(3, 3);
	cout << "v3 = " << v3 << endl;
	v3 *= k;
	cout << "v3 *= " << k << " = " << v3 << endl;

	Vector v4(4, 4), v5(5, 5);
	
	cout << "v4 = " << v4 << " , v5 = " << v5 << endl;

	if(v4 <= v5)	cout << "v4 <= v5";
	else			cout << "v4 > v5";
	
	
	return 0;
}
