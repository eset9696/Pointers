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
	
	
	int value;
	cout << "Введите добавляемое значение" << endl;
	cin >> value;
	//1) создаем буферный массив нужного размера (на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2) копируем все значения из исходного массива в буферный массив
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	//4) Подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	//5) И только после этого в массив "arr" можно добавить новое значение
	arr[n] = value;
	//6) После добавления элемента в массив количество его элементов увеличивается на 1
	n++;
	// Mission complete - элемент добавлен в массив
	Print(arr, n);

	delete[] arr;
	arr = new int[n + 1];
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