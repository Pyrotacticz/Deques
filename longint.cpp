// ----------------------------- longint.cpp ----------------------------------

// James Truong CSS501A

// Created: 11/25/2020

// Last Modified: 11/25/2020

// ----------------------------------------------------------------------------

// The implementation file of the longint class which represents a very long
// integer. The longint class allows addition, subtraction, comparison, and
// copying other longint objects.
//
// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

// ----------------------------------------------------------------------------

#include "longint.h"

/** Takes in a string and reads each numeric character as a valid input for
* the LongInt. If '-' is the first character of the string, will make the
* resulting LongInt negative. Will clear out all leading 0's in the
* LongInt.
* precondition: none.
* postcondition: a LongInt containing the respective numbers of the string
* except for leading "0" and is negative if there exists a '-' in front of
* the string.
*/
istream& operator>>(istream& in, LongInt& rhs)
{
	string numbers;
	in >> numbers;
	if (numbers[0] == '-')
	{
		rhs.negative = true;
	}
	for (char c : numbers)
	{
		if (c >= '0' && c <= '9')
		{
			rhs.digits.addBack(c);
		}
	}
	rhs.remove0s();
	return in;
}

/** Prints the LongInt number similar to how it prints integers. If
* LongInt is negative, prints negative sign in front of the numbers. If
* LongInt is empty or zero, prints "0".
*/
ostream& operator<<(ostream& out, const LongInt& rhs)
{
	LongInt temp = rhs;
	if (rhs.digits.isEmpty())
	{
		out << 0;
	}
	else
	{
		if (rhs.negative)
		{
			out << '-';
		}
		while (!temp.digits.isEmpty())
		{
			out << temp.digits.removeFront();
		}
	}
	return out;
}

/** Creates a LongInt object using the passed in string.
* precondition: the string has valid numbers. If '-' is in the front of the
* string, the created LongInt will be negative.
* postcondition: an LongInt object with the numbers of the string.
*/
LongInt::LongInt(const string str)
{
	for (char c : str)
	{
		if (c >= '0' && c <= '9')
		{
			digits.addBack(c);
		}
	}
	negative = (str[0] == '-');
	remove0s();
}

/** Copy constructor: creates a copy of the passed in LongInt.
* precondition: another LongInt.
* postcondition: a LongInt that is a copy of the rhs LongInt.
*/
LongInt::LongInt(const LongInt& rhs)
{
	digits = rhs.digits;
	negative = rhs.negative;
}

/** Default constructor: creates an empty LongInt.
* precondition: none.
* postcondition: an empty LongInt object.
*/
LongInt::LongInt() : negative(false)
{
}

/** Destructor: clears the LongInt and destructs it.
* precondition: none.
* postcondition: a destructed LongInt.
*/
LongInt::~LongInt()
{
	digits.clear();
}

/** Adds LongInt objects together.
* precondition: another LongInt.
* postcondition: Returns a LongInt with the sum of this and the rhs
* LongInt.
*/
LongInt LongInt::operator+(const LongInt& rhs) const
{
	LongInt result;
	LongInt copy = *this;
	LongInt other = rhs;
	int sum = 0;
	int carry = 0;
	if (!negative && rhs.negative)
	{
		other.negative = false;
		return *this - other;
	}
	if (negative && !rhs.negative)
	{
		copy.negative = false;
		return rhs - copy;
	}
	if (negative && rhs.negative)
	{
		result.negative = true;
	}
	while (!copy.digits.isEmpty() && !other.digits.isEmpty())
	{
		sum = int(copy.digits.getBack() - '0') +
			int(other.digits.getBack() - '0') + carry;
		result.digits.addFront('0' + sum % 10);
		carry = sum / 10;
		copy.digits.removeBack();
		other.digits.removeBack();
	}

	if (!copy.digits.isEmpty())
	{
		while (!copy.digits.isEmpty())
		{
			sum = int(copy.digits.getBack() - '0') + carry;
			carry = sum / 10;
			result.digits.addFront('0' + sum % 10);
			copy.digits.removeBack();
		}
		if (negative)
		{
			result.negative = true;
		}
	}
	if (!other.digits.isEmpty())
	{
		while (!other.digits.isEmpty())
		{
			sum = int(other.digits.getBack() - '0') + carry;
			carry = sum / 10;
			result.digits.addFront('0' + sum % 10);
			other.digits.removeBack();
		}
		if (rhs.negative)
		{
			result.negative = true;
		}
	}

	if (carry != 0)
	{
		result.digits.addFront('0' + carry);
	}

	return result;
}

/** Subtracts another LongInt from this LongInt.
* precondition: another LongInt.
* postcondition: Returns a LongInt with the result of
* LongInt - rhs LongInt.
*/
LongInt LongInt::operator-(const LongInt& rhs) const
{
	LongInt result;
	LongInt bigger;
	LongInt smaller;
	int total = 0;
	int borrow = 0;
	if (!negative && rhs.negative)
	{
		result = rhs;
		result.negative = false;
		return *this + result;
	}
	if (negative && !rhs.negative)
	{
		result = rhs;
		result.negative = true;
		return *this + result;
	}
	if (*this > rhs)
	{
		bigger = *this;
		smaller = rhs;
		result.negative = negative;
	}
	else if (*this < rhs)
	{
		bigger = rhs;
		smaller = *this;
		result.negative = !rhs.negative;
	}
	else
	{
		result.digits.addFront('0');
		return result;
	}

	while (!bigger.digits.isEmpty() && !smaller.digits.isEmpty())
	{
		if (bigger.digits.getBack() < smaller.digits.getBack() + borrow)
		{
			total = 10 + int(bigger.digits.getBack() - '0')
				- int(smaller.digits.getBack() - '0') - borrow;
			borrow = 1;
		}
		else
		{
			total = int(bigger.digits.getBack() - '0')
				- int(smaller.digits.getBack() - '0') - borrow;
			borrow = 0;
		}
		result.digits.addFront('0' + total);
		bigger.digits.removeBack();
		smaller.digits.removeBack();
	}

	if (!bigger.digits.isEmpty())
	{
		while (!bigger.digits.isEmpty())
		{
			if(borrow == 1 && bigger.digits.getBack() == '0')
			{
				total = 10 + int(bigger.digits.removeBack() - '0') - borrow;
				result.digits.addFront('0' + total);
				borrow = 1;
			}
			else
			{
				total = int(bigger.digits.removeBack() - '0') - borrow;
				borrow = 0;
				result.digits.addFront('0' + total);
			}
		}
	}
	result.remove0s();
	return result;
}

/** Assigns this LongInt as a copy of another LongInt.
* precondition: another LongInt.
* postcondition: this LongInt is a copy of the rhs LongInt.
*/
const LongInt& LongInt::operator=(const LongInt& rhs)
{
	LongInt copy = rhs;
	negative = rhs.negative;
	digits.clear();
	while (!copy.digits.isEmpty())
	{
		digits.addBack(copy.digits.removeFront());
	}
	return *this;
}

/** Checks if this LongInt is less than another LongInt.
* precondition: another LongInt.
* postcondition: returns true if this LongInt is less than rhs LongInt,
* otherwise false.
*/
bool LongInt::operator<(const LongInt& rhs) const
{
	LongInt copy = *this;
	LongInt other = rhs;
	if (!negative && rhs.negative)
	{
		return false;
	}
	if (negative && !rhs.negative)
	{
		return true;
	}
	if (digits.size() > rhs.digits.size())
	{
		return false;
	}
	if (digits.size() < rhs.digits.size())
	{
		return true;
	}
	while (!copy.digits.isEmpty() && !other.digits.isEmpty())
	{
		if (copy.digits.getFront() < other.digits.getFront())
		{
			return true;
		}
		if (copy.digits.getFront() > other.digits.getFront())
		{
			return false;
		}
		copy.digits.removeFront();
		other.digits.removeFront();
	}
	return false;
}

/** Checks if this LongInt is less than or equal to another LongInt.
* precondition: another LongInt.
* postcondition: returns true if this LongINt is less than or equal to
* rhs LongInt.
*/
bool LongInt::operator<=(const LongInt& rhs) const
{
	return *this < rhs || *this == rhs;
}

/** Checks if this LongInt is greater than another LongInt.
* precondition: another LongInt.
* postcondition: returns true if this LongINt is greater than rhs LongInt.
*/
bool LongInt::operator>(const LongInt& rhs) const
{
	LongInt copy = *this;
	LongInt other = rhs;
	if (!negative && rhs.negative)
	{
		return true;
	}
	if (negative && !rhs.negative)
	{
		return false;
	}
	if (copy.digits.size() > other.digits.size())
	{
		return true;
	}
	if (copy.digits.size() < other.digits.size())
	{
		return false;
	}
	while (!copy.digits.isEmpty() && !other.digits.isEmpty())
	{
		if (copy.digits.removeFront() > other.digits.removeFront())
		{
			return true;
		}
	}
	return false;
}

/** Checks if this LongInt is greater than or equal to another LongInt.
* precondition: another LongInt.
* postcondition: returns true if this LongINt is greater than or equal to
* rhs LongInt.
*/
bool LongInt::operator>=(const LongInt& rhs) const
{
	return *this > rhs || *this == rhs;
}

/** Checks if this LongInt is equal to another LongInt.
* precondition: another LongInt.
* postcondition: returns true if this LongINt is equal to rhs LongInt.
*/
bool LongInt::operator==(const LongInt& rhs) const
{
	LongInt copy = *this;
	LongInt other = rhs;
	if (copy.digits.size() != other.digits.size() || negative != rhs.negative)
	{
		return false;
	}
	while (!copy.digits.isEmpty() && !other.digits.isEmpty())
	{
		if (copy.digits.removeFront() != other.digits.removeFront())
		{
			return false;
		}
	}
	return true;
}

/** Checks if this LongInt is not equal to another LongInt.
* precondition: another LongInt.
* postcondition: returns true if this LongINt is not equal to rhs LongInt.
*/
bool LongInt::operator!=(const LongInt& rhs) const
{
	return !(*this == rhs);
}

LongInt LongInt::triple() const
{
	LongInt copy = *this;
	LongInt result;
	result.negative = copy.negative;
	int carry = 0;
	int sum = 0;
	while (!copy.digits.isEmpty())
	{
		sum = (copy.digits.getBack() - '0') * 3;
		result.digits.addFront('0' + sum % 10 + carry);
		carry = sum / 10;
		copy.digits.removeBack();
	}
	if (carry != 0)
	{
		result.digits.addFront('0' + carry);
		carry = 0;
	}
	return result;
}

/** Removes all leading zeroes in the LongInt.
* precondition: None.
* postcondition: returns this LongInt with no leading zeroes.
*/
void LongInt::remove0s()
{
	while (digits.getFront() == '0' && digits.size() != 1)
	{
		digits.removeFront();
	}
}
