#include <iostream>
#include <ctime>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
int** Allocate(const int rows, const int cols);
void Clear(int**& array, const int rows, const int cols);
void FillRand(int* arr, const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);
void Push_Back(int*& array, int& size, int& value);
void Push_Back_Rows(int**& array, int& rows, const int cols);
void Push_Front(int*& array, int& size, int& value);
void Push_Front_Rows(int**& array, int& rows, const int cols);
void Insert(int*& array, int& size, int& value, int& pos);
void Insert_Row(int**& array, int& rows, const int& cols, const int& pos);
void Pop_Back(int*& array, int& size);
void Pop_Front(int*& array, int& size);
void Erase(int*& array, int& size, int& pos);

void main(){
	setlocale(LC_ALL, "");
	srand(time(0));
#ifdef DYNAMIC_MEMORY_1
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
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

#endif // DYNAMIC_MEMORY_2



	
	int rows = 4;
	int cols = 5;
	int pos = 3;

	//Создаем двумерный динамический массив
	
	int** array = Allocate(rows, cols);

	FillRand(array, rows, cols);
	Print(array, rows, cols);

	Push_Back_Rows(array, rows, cols);
	Print(array, rows, cols);

	Push_Front_Rows(array, rows, cols);
	Print(array, rows, cols);

	Insert_Row(array, rows, cols, pos);
	Print(array, rows, cols);

	//Удаляем двумерный динамический массив
	Clear(array, rows, cols);
}
int** Allocate(const int rows, const int cols) {
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
	return array;
}
void Clear(int**& array, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
void FillRand(int* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
		
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
void Print(int** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void Push_Back(int*& array, int& size, int& value) {
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
void Push_Back_Rows(int**& array, int& rows, const int cols) {
	int** buffer = Allocate(rows + 1, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i][j];
		}
	}
	Clear(array, rows, cols);
	array = buffer;
	buffer = nullptr;
	for (int i = 0; i < cols; i++)
	{
		array[rows][i] = 0;
	}
	rows++;
}

void Push_Front(int*& array, int& size, int& value){
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
void Push_Front_Rows(int**& array, int& rows, const int cols) {
	rows++;
	int** buffer = Allocate(rows, cols);
	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i - 1][j];
		}
	}
	Clear(array, rows - 1, cols);
	array = buffer;
	buffer = nullptr;
	for (int i = 0; i < cols; i++)
	{
		array[0][i] = 0;
	}
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
void Insert_Row(int**& array, int& rows, const int& cols, const int& pos) {
	int** buffer = Allocate(rows + 1, cols);
	for (int i = 0; i < pos; i++)
	{
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i][j];
		}
	}
	for (int i = pos + 1, k = pos; i < rows + 1; i++, k++)
	{
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[k][j];
		}
	}
	Clear(array, rows, cols);
	array = buffer;
	buffer = nullptr;
	for (int i = 0; i < cols; i++)
	{
		array[pos][i] = 0;
	}
	rows++;
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