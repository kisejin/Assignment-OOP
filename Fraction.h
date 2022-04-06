#pragma once


class Fraction
{
private:
	int tu;
	int mau;
public:
	Fraction(int t=0, int m=1) : tu(t), mau(m) {}
	~Fraction() {}
	int getTu() const;
	int getMau() const;
	Fraction Add(Fraction& b);
	Fraction Minus(Fraction& b);
	Fraction Multp(Fraction& b);
	Fraction Divine(Fraction& b);
	friend Fraction operator + (Fraction a,Fraction b);
	friend Fraction operator - (Fraction a,Fraction b);
	friend Fraction operator * (Fraction a,Fraction b);
	friend Fraction operator / (Fraction a,Fraction b);
	friend std::ostream& operator <<(std::ostream& stream, Fraction a);
	friend std::istream& operator >>(std::istream& stream, Fraction& a);
	friend std::fstream& operator >>(std::fstream& fin, Fraction& a);
	friend std::fstream& operator <<(std::fstream& fout, Fraction a);
};

