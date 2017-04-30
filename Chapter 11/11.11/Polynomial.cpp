#include "Polynomial.h"

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <map>

using namespace std;


Polynomial::Polynomial()
{
	Init();
}

Polynomial::Polynomial(const map<int, int>& t)
{
	if (t.empty())
	{
		throw length_error("You can't init a polynomial with no terms.");
	}
	terms = t;
	cleanZeroTerms();
}

Polynomial::~Polynomial()
{
	terms.clear();
}

void Polynomial::Init()
{
	terms.clear();
	cout << "Ok, let's input the coefficient and the exponent of a term for this polynomial(format: co ex): ";
	int ex, co;
	cin >> co;
	cin >> ex;
	while (cin)
	{
		auto iter = terms.find(ex);
		if (iter != terms.end())
		{
			iter->second += co;
		}
		else 
		{
			terms.insert(pair<int, int>(ex, co));
		}
		cout << "Well, the next term(Ctrl + Z[Windows] to finish): ";
		cin >> co;
		cin >> ex;
	}
	cin.sync();
	cin.clear();
	cleanZeroTerms();
	if (terms.empty())
	{
		throw length_error("You can't init a polynomial with no terms.");
	}
}

pair<int, int> Polynomial::GetTermByExponent(int ex)
{
	auto iter = terms.find(ex);
	if (iter != terms.end())
	{
		return (*iter);
	}
	else 
	{
		throw domain_error("No such term");
	}
}

map<int, int> Polynomial::GetTerms()
{
	return terms;
}

bool Polynomial::SetTermByExponent(pair<int, int> p)
{
	auto iter = terms.find(p.first);
	if (iter != terms.end())
	{
		iter->second = p.second;
	}
	else
	{
		terms.insert(p);
	}
	return true;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
	map<int, int> newMap = p.GetTerms();
	for (auto term : terms)
	{
		auto iter = newMap.find(term.first);
		if (iter != newMap.end())
		{
			iter->second += term.second;
		}
		else
		{
			newMap.insert(pair<int, int>(term.first, term.second));
		}
	}
	return Polynomial(newMap);
}

Polynomial Polynomial::operator-(Polynomial &p)
{
	map<int, int> newMap = terms;
	auto pTerms = p.GetTerms();
	for (auto pTerm : pTerms)
	{
		auto iter = newMap.find(pTerm.first);
		if (iter != newMap.end())
		{
			iter->second -= pTerm.second;
		}
		else
		{
			newMap.insert(pair<int, int>(pTerm.first, 0 - pTerm.second));
		}
	}
	return Polynomial(newMap);
}

void Polynomial::operator+=(Polynomial &p)
{
	(*this).terms = ((*this) + p).GetTerms();
}

void Polynomial::operator-=(Polynomial &p)
{
	(*this).terms = ((*this) - p).GetTerms();
}

Polynomial Polynomial::operator=(Polynomial &p)
{
	return Polynomial(p.GetTerms());
}

Polynomial Polynomial::operator*(Polynomial &p)
{
	map<int, int> newMap;
	auto pTerms = p.GetTerms();
	for (auto thisTerm : terms)
	{
		for (auto pTerm : pTerms)
		{
			int first = thisTerm.first + pTerm.first;
			int second = thisTerm.second * pTerm.second;
			auto iter = newMap.find(first);
			if (iter != newMap.end())
			{
				iter->second += second;
			}
			else
			{
				newMap.insert(pair<int, int>(first, second));
			}
		}
	}
	return Polynomial(newMap);
}



void Polynomial::cleanZeroTerms()
{
	auto iter = terms.begin();
	for (; iter != terms.end(); iter++)
	{
		if (iter->second == 0)
		{
			iter = terms.erase(iter);
		}
	}
}

ostream & operator<<(ostream &os, Polynomial &p)
{
	if (p.terms.size() == 0)
	{
		os << "0";
		return os;
	}
	int index = 0;
	for (auto term : p.terms)
	{
		if (term.second >= 0)
		{
			cout << term.second << "x^" << term.first;
		}
		else
		{
			cout << "(" << term.second << ")x^" << term.first;
		}
		index++;
		if (index != p.terms.size())
		{
			cout << " + ";
		}
	}
	return os;
}
