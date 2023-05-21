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
void Print(int** array, const int rows, const int cols);
void Push_Back(int*& array, int& size, int& value);
void Push_Row_Back(int**& array, int& rows, const int& cols);
void Push_Col_Back(int**& array, const int& rows, int& cols);
void Push_Front(int*& array, int& size, int& value);
void Push_Row_Front(int**& array, int& rows, const int& cols);
void Push_Col_Front(int**& array, const int& rows, int& cols);
void Insert(int*& array, int& size, int& value, int& pos);
void Insert_Row(int**& array, int& rows, const int& cols, const int& pos);
void Insert_Col(int**& array, const int& rows, int& cols, const int& pos);
void Pop_Back(int*& array, int& size);
void Pop_Row_Back(int**& array, int& rows, const int& cols);
void Pop_Col_Back(int**& array, const int& rows, int& cols);
void Pop_Front(int*& array, int& size);
void Pop_Row_Front(int**& array, int& rows, const int& cols);
void Pop_Col_Front(int**& array, const int& rows, int& cols);
void Erase(int*& array, int& size, int& pos);
void Erase_Row(int**& array, int& rows, const int& cols, const int& pos);
void Erase_Col(int**& array, const int& rows, int& cols, const int& pos);

void main(){
	setlocale(LC_ALL, "");
	srand(time(0));
#ifdef DYNAMIC_MEMORY_1
	int n;

	cout << "Введите размер массива: " << endl;
	cin >> n;

	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: " << endl;
	cin >> value;

	int pos;
	

	Push_Back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: " << endl;
	cin >> value;

	Push_Front(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: " << endl;
	cin >> value;

	cout << "Введите номер позиции: " << endl;
	cin >> pos;

	Insert(arr, n, value, pos);
	Print(arr, n);

	Erase(arr, n, pos);
	Print(arr, n);

	Pop_Front(arr, n);
	Print(arr, n);

	Pop_Back(arr, n);
	Print(arr, n);

	delete[] arr;

#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	int pos;

	cout << "Введите количество строк массива: " << endl;
	cin >> rows;
	cout << "Введите количество столбцов массива: " << endl;
	cin >> cols;

	//Создаем двумерный динамический массив
	int** array = Allocate(rows, cols);

	//Заполняем массив случайными значениями
	FillRand(array, rows, cols);
	Print(array, rows, cols);
	
	//Добавляем нулевые строки
	Push_Row_Back(array, rows, cols);
	Print(array, rows, cols);

	Push_Row_Front(array, rows, cols);
	Print(array, rows, cols);

	cout << "Введите индекс строки в которую нужно вставить нулевую строку: " << endl;
	cin >> pos;

	Insert_Row(array, rows, cols, pos);
	Print(array, rows, cols);

	// Удаляем добавленные нулевые строки
	Erase_Row(array, rows, cols, pos);
	Print(array, rows, cols);

	Pop_Row_Front(array, rows, cols);
	Print(array, rows, cols);

	Pop_Row_Back(array, rows, cols);
	Print(array, rows, cols);

	//Добавляем нулевые столбцы
	Push_Col_Back(array, rows, cols);
	Print(array, rows, cols);

	Push_Col_Front(array, rows, cols);
	Print(array, rows, cols);

	cout << "Введите индекс стобца в который нужно вставить нулевой столбец: " << endl;
	cin >> pos;

	Insert_Col(array, rows, cols, pos);
	Print(array, rows, cols);
	
	//Удаляем нулевые столбцы
	Erase_Col(array, rows, cols, pos);
	Print(array, rows, cols);

	Pop_Col_Front(array, rows, cols);
	Print(array, rows, cols);

	Pop_Col_Back(array, rows, cols);
	Print(array, rows, cols);

	//Удаляем двумерный динамический массив
	Clear(array, rows, cols);

#endif // DYNAMIC_MEMORY_2
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
void Print(int** array, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(array + i) + j) << "\t";
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
void Push_Row_Back(int**& array, int& rows, const int& cols) {
	rows++;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			i != (rows - 1)? buffer[i][j] = array[i][j]: buffer[i][j] = 0;
		}
	}
	Clear(array, rows - 1, cols);
	array = buffer;
	buffer = nullptr;
}
void Push_Col_Back(int**& array, const int& rows, int& cols) {
	cols++;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			j != (cols - 1) ? buffer[i][j] = array[i][j] : buffer[i][j] = 0;
		}
	}
	Clear(array, rows, cols - 1);
	array = buffer;
	buffer = nullptr;
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
void Push_Row_Front(int**& array, int& rows, const int& cols) {
	rows++;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			i != 0 ? buffer[i][j] = array[i - 1][j] : buffer[i][j] = 0;
		}
	}
	Clear(array, rows - 1, cols);
	array = buffer;
	buffer = nullptr;
}
void Push_Col_Front(int**& array, const int& rows, int& cols) {
	cols++;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			j != 0 ? buffer[i][j] = array[i][j - 1] : buffer[i][j] = 0;
		}
	}
	Clear(array, rows, cols - 1);
	array = buffer;
	buffer = nullptr;
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
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			i < pos ? buffer[i][j] = array[i][j] : buffer[i + 1][j] = array[i][j];
			if(i == pos) buffer[i][j] = 0;
		}
	}
	Clear(array, rows, cols);
	array = buffer;
	buffer = nullptr;
	rows++;
}
void Insert_Col(int**& array, const int& rows, int& cols, const int& pos) {
	int** buffer = Allocate(rows, cols + 1);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			j < pos ? buffer[i][j] = array[i][j] : buffer[i][j + 1] = array[i][j];
			if (j == pos) buffer[i][j] = 0;
		}
	}
	Clear(array, rows, cols);
	array = buffer;
	buffer = nullptr;
	cols++;
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
void Pop_Row_Back(int**& array, int& rows, const int& cols) {
	rows--;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i][j];
		}
	}
	Clear(array, rows + 1, cols);
	array = buffer;
	buffer = nullptr;
}
void Pop_Col_Back(int**& array, const int& rows, int& cols) {
	cols--;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i][j];
		}
	}
	Clear(array, rows, cols + 1);
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
void Pop_Row_Front(int**& array, int& rows, const int& cols) {
	rows--;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i + 1][j];
		}
	}
	Clear(array, rows + 1, cols);
	array = buffer;
	buffer = nullptr;
}
void Pop_Col_Front(int**& array, const int& rows, int& cols) {
	cols--;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			buffer[i][j] = array[i][j + 1];
		}
	}
	Clear(array, rows, cols + 1);
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
void Erase_Row(int**& array, int& rows, const int& cols, const int& pos) {
	rows--;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			i < pos ? buffer[i][j] = array[i][j] : buffer[i][j] = array[i + 1][j];
		}
	}
	Clear(array, rows + 1, cols);
	array = buffer;
	buffer = nullptr;
}
void Erase_Col(int**& array, const int& rows, int& cols, const int& pos) {
	cols--;
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			j < pos ? buffer[i][j] = array[i][j] : buffer[i][j] = array[i][j + 1];
		}
	}
	Clear(array, rows, cols + 1);
	array = buffer;
	buffer = nullptr;
}