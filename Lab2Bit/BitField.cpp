#include "BitField.h"

BitField::BitField(int size)
{
	len = size;
	memSize = (size + 31) / (sizeof(int) * 8);
	values = new int[memSize];
	for(int i = 0; i < memSize; i++)
		values[i] = 0;
}

BitField::BitField(const BitField& bf)
{
	len = bf.len;
	memSize = bf.memSize;
	values = new int[memSize];
	for (int i = 0; i < memSize; i++)
		values[i] = bf.values[i];
}

void BitField::turnOn(int number)
{
	if (number < 0)
		throw std::exception("Number can't be less than zero");
	values[number / (sizeof(int) * 8)] = values[number / (sizeof(int) * 8)] | getBitMask(number);
}

void BitField::turnOff(int number)
{
	if (number < 0)
		throw std::exception("Number can't be less than zero");
	values[number / (sizeof(int) * 8)] = values[number / (sizeof(int) * 8)] & (~(getBitMask(number)));
}

bool BitField::getValue(int number) const
{
	if (number > len)
		return false;
	return values[number / (sizeof(int) * 8)] & (getBitMask(number));
}

int BitField::getBitMask(int n) const
{
	return 1 << (n & 31);
}

int BitField::getSize() const
{
	return len;
}

bool BitField::isEmpty() const
{
	for (int i = 0; i < memSize; i++)
		if (values[i])
			return false;
	return true;
}

bool BitField::operator==(const BitField& bf)
{
	if (memSize != bf.memSize)
		return false;

	for (int i = 0; i < memSize; i++)
		if (values[i] != bf.values[i])
			return false;
	return true;
}

BitField BitField::operator=(const BitField& bf)
{
	delete[] values;
	
	len = bf.len;
	memSize = bf.memSize;

	values = new int[memSize];

	for (int i = 0; i < memSize; i++)
		values[i] = bf.values[i];
	return *this;
}

BitField BitField::operator!() const
{
	BitField temp = *this;
	for (int i = 0; i < temp.len; i++)
	{
		if (temp.getValue(i))
			temp.turnOff(i);
		else temp.turnOn(i);
	}
	return temp;
}

BitField BitField::operator|(const BitField& op)
{
	BitField temp(std::max(this->len, op.len));
	for (int i = 0; i < temp.len; i++)
	{
		if (this->getValue(i) || op.getValue(i))
			temp.turnOn(i);
	}

	return temp;
}

BitField BitField::operator&(const BitField& op)
{
	BitField temp(std::max(this->len, op.len));
	for (int i = 0; i < temp.len; i++)
	{
		if (this->getValue(i) && op.getValue(i))
			temp.turnOn(i);
	}

	return temp;
}

BitField::~BitField()
{
	delete[] values;
}

void BitField::resize(int newSize)
{
	delete[] values;
	len = newSize;
	memSize = (newSize + 31) / (sizeof(int) * 8);
	values = new int[memSize];
	for (int i = 0; i < memSize; i++)
		values[i] = 0;
}

std::ostream& operator<<(std::ostream& out, const BitField& bf) 
{
	for (int i = bf.len; i >= 0; i--)
		out << bf.getValue(i);
	return out;
}

