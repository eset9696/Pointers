#include <iostream>
#include <ctime>

using namespace std;

void FillRand(int* arr, const int n);
void Print(int* arr, const int n);
void Push_Back(int*& array, int& size, int& value);
void Push_Front(int*& array, int& size, int& value);
void Insert(int*& array, int& size, int& value, int& pos);
void Pop_Back(int*& array, int& size);
void Pop_Front(int*& array, int& size);
void Erase(int*& array, int& size, int& pos);

void main(){
	setlocale(LC_ALL, "");
	srand(time(0));

	int n = 5;

	cout << "Введите размер массива: " << endl;
	cin >> n;

	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	cout << "Введите добавляемое значение: " << endl;
	cin >> value;

	int pos;
	cout << "Введите номер позиции: " << endl;
	cin >> pos;

	Push_Back(arr, n, value);
	Print(arr, n);

	Push_Front(arr, n, value);
	Print(arr, n);

	Insert(arr, n, value, pos);
	Print(arr, n);	

	Pop_Back(arr, n);
	Print(arr, n);

	Erase(arr, n, pos);
	Print(arr, n);

	Pop_Front(arr, n);
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
void Push_Back(int *&array, int& size, int& value) {
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++) {
		buffer[i] = array[i];
	}
	delete[] array;
	array = buffer;
	buffer = nullptr; 
	array[size] = value;
	size++;
}
void Push_Front(int*& array, int& size, int& value) {
	size++;
	int* buffer = new int[size];
	for (int i = 1; i < size; i++) {
		buffer[i] = array[i - 1];
	}
	delete[] array;
	array = buffer;
	buffer = nullptr;
	array[0] = value;
}
void Insert(int*& array, int& size, int& value, int& pos) {
	size++;
	int* buffer = new int[size];
	for (int i = 0, j = 0; i < size; i++, j++) {
		i == pos ? buffer[i] = value, j-- : buffer[i] = array[j];
	}
	delete[] array;
	array = buffer;
	buffer = nullptr;
}
void Pop_Back(int*& array, int& size) {
	size--;
	int* buffer = new int[size];
	for (int i = 0; i < size; i++) {
		buffer[i] = array[i];
	}
	delete[] array;
	array = buffer;
	buffer = nullptr;
}
void Pop_Front(int*& array, int& size) {
	size--;
	int* buffer = new int[size];
	for (int i = 1; i < size + 1; i++) {
		buffer[i - 1] = array[i];
	}
	delete[] array;
	array = buffer;
	buffer = nullptr;
}
void Erase(int*& array, int& size, int& pos) {
	size--;
	int* buffer = new int[size];
	for (int i = 0, j = 0; i < size; i++, j++) {
		i == pos ? j++, buffer[i] = array[j]: buffer[i] = array[j];
	}
	delete[] array;
	array = buffer;
	buffer = nullptr;
}