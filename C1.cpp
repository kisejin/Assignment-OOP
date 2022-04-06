#include <iostream>
#include <fstream>
#include "Fraction.h"
using namespace std;
int Fraction::getTu() const {
	return tu;
}
int Fraction::getMau() const {
	return mau;
}
Fraction Fraction::Add(Fraction& b) {
	return Fraction(tu * b.mau + b.tu * mau, mau * b.mau);
}
Fraction Fraction::Minus(Fraction& b) {
	return Fraction(tu * b.mau - b.tu * mau, mau * b.mau);

}
Fraction Fraction::Multp(Fraction& b) {
	return Fraction(tu * b.tu, mau * b.mau);

}
Fraction Fraction::Divine(Fraction& b) {
	return Fraction(tu * b.mau, mau * b.tu);

}
Fraction operator + (Fraction a,Fraction b) {
	return a.Add(b);
}
Fraction operator - (Fraction a,Fraction b) {
	return a.Minus(b);
}
Fraction operator * (Fraction a,Fraction b) {
	return a.Multp(b);
}
Fraction operator / (Fraction a,Fraction b) {
	return a.Divine(b);
}
std::ostream& operator <<(std::ostream& stream, Fraction a)
{
	stream << a.tu;
	if (a.tu!=0 || a.mau!=1)
		stream << "/" << a.mau << " ";
	return stream;
}
std::istream& operator >>(std::istream& stream, Fraction& a)
{
	
	printf("Nhap tu:");
	stream >> a.tu;
	printf("Nhap mau:");
	stream >> a.mau;
	return stream;
}

std::fstream& operator >>(std::fstream& stream, Fraction& a) {
	stream >> a.tu >> a.mau;
	return stream;
}

void readFileForFraction(std::fstream& fin, int n, Fraction* arr)
{
	arr = new Fraction[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
}

std::fstream& operator <<(std::fstream& fout, Fraction a) {
	fout << a.tu << "/" << a.mau << " ";
	return fout;
}


Fraction sum_Fr(Fraction* a)
{
	Fraction b;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		b = b + a[i];
	}
	return b;
}

int main()
{
	Fraction* arr = NULL;
	fstream fin("phanso.inp", ios::in|ios::binary);
	int a;
	if (fin.is_open() != NULL)
	{
		fin >> a;
		readFileForFraction(fin, a, arr);
		fin.close();
	}
	
	fin.open("phanso.out", ios::out);
	if (fin.is_open() != NULL)
	{
			
		fin.close();
	}
	
	Fraction a, b;
	cout << "Ung dung phan so\n";
	
	cin >> a >> b;
	cout << a << "+" << b << "=" << (a + b) << endl;
}