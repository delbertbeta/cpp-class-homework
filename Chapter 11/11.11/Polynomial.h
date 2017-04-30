#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <map>
#include <iostream>

using std::map;
using std::pair;
using std::ostream;

class Polynomial
{
public:
	Polynomial();
	Polynomial(const map<int, int>&);
	~Polynomial();
	void Init();
	pair<int, int> GetTermByExponent(int);
	map<int, int> GetTerms();
	bool SetTermByExponent(pair<int, int>);
	friend ostream& operator <<(ostream&, Polynomial&);
	Polynomial operator +(Polynomial&);
	Polynomial operator -(Polynomial&);
	void operator +=(Polynomial&);
	void operator -=(Polynomial&);
	Polynomial operator =(Polynomial&);
	Polynomial operator *(Polynomial&);
private:
	map<int, int> terms; // Forever remember that first->ex, second->co.
	void cleanZeroTerms();
};


#endif // !POLYNOMIAL_H
