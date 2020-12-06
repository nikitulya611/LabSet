#include "Set.h"


Set::Set(int _mp) : bitField(_mp)
{
	maxPower = _mp;
}

Set::Set(const Set& s) : bitField(s.bitField)
{
	maxPower = s.maxPower;
}

Set::Set(const BitField& bf)
{
	maxPower = bf.getSize();
	bitField = bf;
}

void Set::resize(int newSize)
{
	maxPower = newSize;
	bitField.resize(newSize);
}

Set& Set::operator=(const Set& s)
{
	if (this == &s)
		return *this;
	bitField = s.bitField;
	maxPower = s.maxPower;
	return *this;
}

void Set::turnOn(int number)
{
	bitField.turnOn(number);
}

void Set::turnOff(int number)
{
	bitField.turnOff(number);
}

bool Set::getValue(int number) const
{
	return bitField.getValue(number);
}

Set Set::operator+(int number)
{
	Set temp = *this;
	temp.turnOn(number);
	return temp;
}

Set Set::operator-(int number)
{
	Set temp = *this;
	temp.turnOff(number);
	return temp;
}

Set Set::operator+(const Set& s)
{
	Set temp = *this;
	temp.bitField = temp.bitField | s.bitField;
	return temp;
}

Set Set::operator-(const Set& s)
{
	Set temp = *this;
	temp.bitField = temp.bitField | (!s.bitField);
	return temp;
}

Set Set::operator*(const Set& s)
{
	Set temp = *this;
	temp.bitField = temp.bitField & s.bitField;
	return temp;
}

Set& Set::operator!()
{
	Set temp = !bitField;
	return temp;
}

bool Set::isEmpty() const
{
	return bitField.isEmpty();
}


std::istream& operator>>(std::istream& in, Set& s)
{
	s.resize(s.maxPower);
	int temp = 1;
	while (true)
	{
		in >> temp;
		if (temp < 0 || temp >= s.bitField.getSize())
			break;
		s.bitField.turnOn(temp);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Set& s)
{
	for (int i = 0; i < s.bitField.getSize(); i++)
	{
		if(s.bitField.getValue(i))
			out << i << ' ';
	}
	return out;
}
