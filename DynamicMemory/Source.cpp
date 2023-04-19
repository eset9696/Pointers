#include <iostream>
#include <ctime>

using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);

void main(){
	setlocale(LC_ALL, "");
	srand(time(0));

	int n = 5;

	cout << "Enter array size: " << endl;
	cin >> n;

	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	
	delete[] arr;
}
void FillRand(int* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	
	/*for (int* p_arr = arr; *p_arr != *(arr + n); p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;*/
}