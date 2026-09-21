#include<iostream>
#include<cmath>
using namespace std;

class SoPhuc{
	private:
		double thuc;
		double ao;
	public:
		SoPhuc(double thuc = 0, double ao = 0) : thuc(thuc) , ao(ao){}
		
		double module() const;
		
		friend istream& operator>>(istream &in, SoPhuc &sp);
		friend ostream& operator<<(ostream &out, const SoPhuc &sp);
		
		SoPhuc operator-() const;
		
		SoPhuc operator+(const SoPhuc &other) const;
		SoPhuc operator-(const SoPhuc &other) const;
		
		SoPhuc& operator=(const SoPhuc &other);
		SoPhuc& operator+=(const SoPhuc &other);
		SoPhuc& operator-=(const SoPhuc &other);
		
		bool operator==(const SoPhuc &other) const;
		bool operator!=(const SoPhuc &other) const;
};


double SoPhuc::module() const{
	return sqrt( thuc * thuc + ao * ao);
}

istream& operator>>(istream &in, SoPhuc &sp){
	cout << "\nNhap phan thuc:";	in >> sp.thuc;
	cout << "Nhap phan ao:";		in >> sp.ao;
	
	return in;
}

ostream& operator<<(ostream &out, const SoPhuc &sp){
	out << sp.thuc;
	
	if(sp.ao >= 0)	cout << " + " << sp.ao << "i";
	else			cout << " - " << -sp.ao << "i";
	
	return out;
}

SoPhuc SoPhuc::operator-() const{
	return SoPhuc(-thuc, -ao);
}

SoPhuc SoPhuc::operator+(const SoPhuc &other) const{
	return SoPhuc( thuc + other.thuc , ao + other.ao);
}

SoPhuc SoPhuc::operator-(const SoPhuc &other) const{
	return SoPhuc( thuc - other.thuc, ao - other.ao );
}

SoPhuc& SoPhuc::operator=(const SoPhuc &other){
	this->thuc = other.thuc;
	this->ao = other.ao;
	
	return *this;
}

SoPhuc& SoPhuc::operator+=(const SoPhuc &other){
	this->thuc += other.thuc;
	this->ao += other.ao;
	
	return *this;
}

SoPhuc& SoPhuc::operator-=(const SoPhuc &other){
	this->thuc -= other.thuc;
	this->ao -= other.ao;
	
	return *this;
}

bool SoPhuc::operator==(const SoPhuc &other) const{
	return ( thuc == other.thuc && ao == other.ao );
}

bool SoPhuc::operator!=(const SoPhuc &other) const{
	return !( *this == other);
}

//bool SoPhuc::operator==(const SoPhuc &other) const{
//	return ( this->module() == other.module() );
//}
//
//bool SoPhuc::operator!=(const SoPhuc &other) const{
//	return !( *this == other);
//}


int main(){
	SoPhuc sp1(1, -2), sp2(-2, 4);
	cout << "sp1 = " << sp1 << endl << "sp2 = " << sp2 << endl;
	
	cout << "module cua sp1 = " << sp1.module() << endl;
	cout << "-sp1 = " << -sp1 << endl;
	
	cout << "sp1 + sp2 = " << sp1 + sp2 << endl;
	cout << "sp1 - sp2 = " << sp1 - sp2 << endl;
	
	cout << "sp1 += sp2 = " << ( sp1 += sp2 ) << endl;
	cout << "sp1 -= sp2 = " << ( sp1 -= sp2 ) << endl;
	
	if(sp1 == sp2)	cout << "bang nhau" << endl;
	if(sp1 != sp2) 	cout << "khac nhau" << endl;
	
	return 0;
}
