#include <iostream>
#include <ctime>

using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void isEvenOrOdd(int* source, const int n, int& even_size, int& odd_size);
void Split(int* arr, const int n, int* arr_even, int* arr_odd);

void main() {
	setlocale(LC_ALL, "");
	srand(time(0));

	int n = 10;
	int even_size = 0;
	int odd_size = 0;
	
	int* arr_source = new int[n];

	FillRand(arr_source, n);
	Print(arr_source, n);
	isEvenOrOdd(arr_source, n, even_size, odd_size);

	int* arr_even = new int[even_size];
	int* arr_odd = new int[odd_size];
	
	Split(arr_source, n, arr_even, arr_odd);

	Print(arr_even, even_size);
	Print(arr_odd, odd_size);

	delete[] arr_source;
	delete[] arr_even;
	delete[] arr_odd;
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
}
void isEvenOrOdd(int* arr, const int n, int& even_size, int& odd_size) {
	for (int i = 0; i < n; i++) {
		*(arr + i) % 2 == 0 ? even_size++ : odd_size++;
	}
}
void Split(int* arr, const int n, int* arr_even, int* arr_odd) {
	for (int i = 0, j = 0, k = 0; i < n; i++) {
		/*if (*(arr + i) % 2 == 0) {
			*(arr_even + j) = *(arr + i);
			j++;
		}
		else {
			*(arr_odd + k) = *(arr + i);
			k++;
		}*/
		(arr[i] % 2 == 0 ? arr_even[j++] : arr_odd[k++]) = arr[i];
	}
	
}