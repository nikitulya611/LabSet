#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

class BitField
{
public:
	BitField(int size = 1);
	BitField(const BitField& bf);
	~BitField();
	void resize(int newSize);

	void turnOn(int number);
	void turnOff(int number);
	bool getValue(int number) const;
	int getBitMask(int n) const;

	int getSize() const;
	bool isEmpty() const;

	friend std::ostream& operator<<(std::ostream& out, const BitField& bf);

	bool operator==(const BitField& bf);
	BitField operator=(const BitField& bf);

	BitField operator!() const;
	BitField operator|(const BitField& op);
	BitField operator&(const BitField& op);

	

private:
	int* values;
	int len;
	int memSize;
};