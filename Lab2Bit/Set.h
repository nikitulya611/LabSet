#pragma once

#include "BitField.h"

class Set {

public:
	Set(int _mp = 0);
	Set(const Set& s);
	Set(const BitField& bf);
	void resize(int newSize);

	Set& operator=(const Set& s);

	void turnOn(int number);
	void turnOff(int number);
	bool getValue(int number) const;

	Set operator+(int number);
	Set operator-(int number);

	Set operator+(const Set& s);
	Set operator-(const Set& s);
	Set operator*(const Set& s);

	Set& operator!();

	friend std::istream& operator>>(std::istream& in, Set& s);
	friend std::ostream& operator<<(std::ostream& out, const Set& s);

	bool isEmpty() const;

	BitField getBitField() { return bitField; }

private:
	int maxPower;
	BitField bitField;
};