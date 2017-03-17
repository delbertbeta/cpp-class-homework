#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

class HugeInteger
{
private:
	int length;
public:
	HugeInteger();
	void input();
	void output();
	void add(const HugeInteger&);
	void subtract(const HugeInteger&);
	bool isEqualTo(const HugeInteger&);
	bool isNotEqualTo(const HugeInteger&);
	bool isGreaterThan(const HugeInteger&);
	bool isLessThan(const HugeInteger&);
	bool isGreaterThanOrEqualTo(const HugeInteger&);
	bool isLessThanOrEqualTo(const HugeInteger&);
	int hugeInteger[40];
};

#endif