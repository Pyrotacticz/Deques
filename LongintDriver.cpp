// ----------------------------- driver.cpp ----------------------------------

// James Truong CSS501A

// Created: 11/27/2020

// Last Modified: 11/27/2020

// ----------------------------------------------------------------------------

// A driver that tests the longint class which represents a long integer 
// number which is usually 100 digits long and usually not maintained in C++
// int variables. It test addition, subtraction, and comparison of longint
// objects and prints them out.
//
// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

// ----------------------------------------------------------------------------

#include <iostream>
#include "longint.h"
#include "deque.h"

using namespace std;

int main() {
	LongInt g("1111");
	LongInt h("9999");
	LongInt i("55");
	LongInt j("66");
	LongInt k("0000x1x2a3d456r7890x0y0cr0?");
	LongInt m("1995");
	LongInt n("909");
	LongInt o = k;
	LongInt p("-1111");
	LongInt q("-0101010101");
	LongInt r("-9999");
	LongInt s("-9");
	cout << "g = " << g << endl;
	cout << "h = " << h << endl;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;
	cout << "o = " << o << endl;
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "r = " << r << endl;
	cout << "s = " << s << endl;

	cout << g.triple() << endl;
	cout << i.triple() << endl;
	cout << j.triple() << endl;
	cout << r.triple() << endl;
	cout << s.triple() << endl;


	cout << "====TESTING ARITHMETIC====" << endl;
	cout << g << " + " << h << " =  " << (g + h) << endl;
	cout << g << " - " << h << " =  " << (g - h) << endl;
	cout << h << " - " << g << " =  " << (h - g) << endl;
	cout << h << " + " << g << " =  " << (h + g) << endl;
	cout << endl;
	cout << i << " + " << j << " =  " << (i + j) << endl;
	cout << i << " - " << j << " =  " << (i - j) << endl;
	cout << j << " - " << i << " =  " << (j - i) << endl;
	cout << j << " + " << i << " =  " << (j + i) << endl;
	cout << endl;
	cout << g << " + " << i << " =  " << (g + i) << endl;
	cout << g << " - " << i << " =  " << (g - i) << endl;
	cout << i << " - " << g << " =  " << (i - g) << endl;
	cout << i << " + " << g << " =  " << (i + g) << endl;
	cout << endl;
	cout << i << " + " << i << " =  " << (i + i) << endl;
	cout << i << " - " << i << " =  " << (i - i) << endl;
	cout << g << " - " << g << " =  " << (g - g) << endl;
	cout << g << " + " << g << " =  " << (g + g) << endl;
	cout << endl;
	cout << j << " + " << h << " =  " << (j + h) << endl;
	cout << j << " - " << h << " =  " << (j - h) << endl;
	cout << g << " - " << j << " =  " << (h - j) << endl;
	cout << g << " + " << j << " =  " << (h + j) << endl;
	cout << endl;
	cout << j << " + " << h << " =  " << (j + h) << endl;
	cout << j << " - " << h << " =  " << (j - h) << endl;
	cout << h << " - " << j << " =  " << (h - j) << endl;
	cout << h << " + " << j << " =  " << (h + j) << endl;
	cout << endl;
	cout << m << " + " << n << " =  " << (m + n) << endl;
	cout << m << " - " << n << " =  " << (m - n) << endl;
	cout << n << " - " << m << " =  " << (n - m) << endl;
	cout << n << " + " << m << " =  " << (n + m) << endl;
	cout << endl;
	cout << p << " + " << q << " =  " << (p + q) << endl;
	cout << p << " - " << q << " =  " << (p - q) << endl;
	cout << q << " - " << p << " =  " << (q - p) << endl;
	cout << q << " + " << p << " =  " << (q + p) << endl;
	cout << endl;
	cout << r << " + " << s << " =  " << (r + s) << endl;
	cout << r << " - " << s << " =  " << (r - s) << endl;
	cout << s << " - " << r << " =  " << (s - r) << endl;
	cout << s << " + " << r << " =  " << (s + r) << endl;
	cout << endl;
	cout << p << " + " << r << " =  " << (p + r) << endl;
	cout << p << " - " << r << " =  " << (p - r) << endl;
	cout << r << " - " << p << " =  " << (r - p) << endl;
	cout << r << " + " << p << " =  " << (r + p) << endl;
	cout << endl;
	cout << p << " + " << s << " =  " << (p + s) << endl;
	cout << p << " - " << s << " =  " << (p - s) << endl;
	cout << s << " - " << p << " =  " << (s - p) << endl;
	cout << s << " + " << p << " =  " << (s + p) << endl;
	cout << endl;
	cout << r << " + " << r << " =  " << (r + r) << endl;
	cout << r << " - " << r << " =  " << (r - r) << endl;
	cout << s << " - " << s << " =  " << (s - s) << endl;
	cout << s << " + " << s << " =  " << (s + s) << endl;
	cout << endl;

	cout << "====TESTING COMPARISON====" << endl;
	cout << i << " == " << i << " =  " << (i == i) << endl;
	cout << i << " != " << i << " =  " << (i != i) << endl;
	cout << i << " > " << i << " =  " << (i > i) << endl;
	cout << i << " >= " << i << " =  " << (i >= i) << endl;
	cout << i << " < " << i << " =  " << (i < i) << endl;
	cout << i << " <= " << i << " =  " << (i <= i) << endl;
	cout << endl;
	cout << g << " == " << i << " =  " << (g == i) << endl;
	cout << g << " != " << i << " =  " << (g != i) << endl;
	cout << g << " > " << j << " =  " << (g > j) << endl;
	cout << g << " >= " << j << " =  " << (g >= j) << endl;
	cout << g << " < " << j << " =  " << (g < j) << endl;
	cout << g << " <= " << j << " =  " << (g <= j) << endl;
	cout << endl;
	cout << j << " == " << i << " =  " << (j == i) << endl;
	cout << j << " != " << i << " =  " << (j != i) << endl;
	cout << j << " > " << i << " =  " << (j > i) << endl;
	cout << j << " >= " << i << " =  " << (j >= i) << endl;
	cout << j << " < " << i << " =  " << (j < i) << endl;
	cout << j << " <= " << i << " =  " << (j <= i) << endl;
	cout << endl;
	cout << h << " == " << r << " =  " << (h == r) << endl;
	cout << h << " != " << r << " =  " << (h != r) << endl;
	cout << h << " > " << r << " =  " << (h > r) << endl;
	cout << h << " >= " << r << " =  " << (h >= r) << endl;
	cout << h << " < " << r << " =  " << (h < r) << endl;
	cout << h << " <= " << r << " =  " << (h <= r) << endl;
	cout << endl;
	cout << h << endl;
	cout << h.triple() << endl;
}