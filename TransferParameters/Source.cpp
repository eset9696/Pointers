#include <iostream>

using namespace std;

#define delimiter "\n-------------------------------------------------\n"

void Exchange(int& a, int& b);
void main() {
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	cout << "main " << &a << "\t" << &b << endl;
	cout << delimiter << endl;
	Exchange(a, b);
	cout << delimiter << endl;
	cout << a << "\t" << b << endl;
	cout << "main " << &a << "\t" << &b << endl;
}
void Exchange(int& a, int& b) {
	int buffer = a;
	a = b;
	b = buffer;
	cout << "Exchange " << &a << "\t" << &b << endl;
}