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
	cout << "¬ведите добавл€емое значение" << endl;
	cin >> value;
	//1) создаем буферный массив нужного размера (на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2) копируем все значени€ из исходного массива в буферный массив
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	//3) ”дал€ем исходный массив
	delete[] arr;
	//4) ѕодмен€ем адрес исходного массива адресом нового массива
	arr = buffer;
	buffer = nullptr; // убираем второй указатель на одну область пам€ти
	//5) » только после этого в массив "arr" можно добавить новое значение
	arr[n] = value;
	//6) ѕосле добавлени€ элемента в массив количество его элементов увеличиваетс€ на 1
	n++;
	//7) Mission complete - элемент добавлен в массив
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