#include <iostream>
#include <ctime>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define delimeter "\n---------------------------------------------------------------------\n"

template <typename T> T** Allocate(const int rows, const int cols);
template <typename T>
void Clear(T**& array, const int rows, const int cols);
void FillRand(int* arr, const int n);
void FillRand(double* arr, const int n);
void FillRand(char* arr, const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);
template <typename T>
void Print(T* arr, const int n);
template <typename T>
void Print(T** array, const int rows, const int cols);
template <typename T>
void Push_Back(T*& array, int& size, T value);
template <typename T>
void Push_Row_Back(T**& array, int& rows, const int& cols);
template <typename T>
void Push_Col_Back(T**& array, const int rows, int& cols);
template <typename T>
void Push_Front(T*& array, int& size, T value);
template <typename T>
void Push_Row_Front(T**& array, int& rows, const int& cols);
template <typename T>
void Push_Col_Front(T**& array, const int rows, int& cols);
template <typename T>
void Insert(T*& array, int& size, T value, int pos);
template <typename T>
void Insert_Row(T**& array, int& rows, const int& cols, const int& pos);
template <typename T>
void Insert_Col(T**& array, const int& rows, int& cols, const int& pos);
template <typename T>
void Pop_Back(T*& array, int& size);
template <typename T> 
void Pop_Row_Back(T**& array, int& rows, const int& cols);
template <typename T>
void Pop_Col_Back(T**& array, const int& rows, int& cols);
template <typename T>
void Pop_Front(T*& array, int& size);
template <typename T>
void Pop_Row_Front(T**& array, int& rows, const int& cols);
template <typename T>
void Pop_Col_Front(T**& array, const int& rows, int& cols);
template <typename T>
void Erase(T*& array, int& size, int pos);
template <typename T>
void Erase_Row(T**& array, int& rows, const int& cols, const int& pos);
template <typename T>
void Erase_Col(T**& array, const int& rows, int& cols, const int& pos);

void main(){
	setlocale(LC_ALL, "");
	srand(time(0));
	typedef int DataType;
#ifdef DYNAMIC_MEMORY_1
	int n = 5;

	cout << "Введите размер массива: " << endl;
	cin >> n;
	
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	DataType value;
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
	
	Erase(arr, n, pos);
	Print(arr, n);

	Pop_Back(arr, n);
	Print(arr, n);

	Pop_Front(arr, n);
	Print(arr, n);

	delete[] arr;
#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	int pos;

	cout << "Введите количество строк массива:\t" << endl;
	cin >> rows;

	cout << "Введите количество столбцов массива:\t" << endl;
	cin >> cols;

	cout << "Введите индекс для вставки нулевых элементов в массив:\t" << endl;
	cin >> pos;

	//Создаем двумерный динамический массив
	DataType** array = Allocate<DataType>(rows, cols);

	//Заполняем массив случайными значениями
	FillRand(array, rows, cols);
	Print(array, rows, cols);
	
	//Добавляем нулевые строки
	Push_Row_Back(array, rows, cols);
	Print(array, rows, cols);

	Push_Row_Front(array, rows, cols);
	Print(array, rows, cols);

	Insert_Row(array, rows, cols, pos);
	Print(array, rows, cols);

	// Удаляем добавленные нулевые строки
	Erase_Row(array, rows, cols, pos);
	Print(array, rows, cols);

	Pop_Row_Front(array, rows, cols);
	Print(array, rows, cols);

	Pop_Row_Back(array, rows, cols);
	Print(array, rows, cols);

	////Добавляем нулевые столбцы
	Push_Col_Back(array, rows, cols);
	Print(array, rows, cols);

	Push_Col_Front(array, rows, cols);
	Print(array, rows, cols);

	Insert_Col(array, rows, cols, pos);
	Print(array, rows, cols);
	
	////Удаляем нулевые столбцы
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
template <typename T>
T** Allocate(const int rows, const int cols) {
	T** array = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
	}
	return array;
}
template <typename T>
void Clear(T**& array, const int rows, const int cols) {
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
void FillRand(double* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(char* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
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
void FillRand(double** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template <typename T>
void Print(T* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
template <typename T>
void Print(T** array, const int rows, const int cols) {
	cout << delimeter << endl;
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
template <typename T> 
void Push_Back(T*& array, int& size, T value) {
	T* buffer = new T[size + 1];
	for (int i = 0; i <= size; i++) {
		i != size? buffer[i] = array[i]: buffer[i] = value;
	}
	delete[] array;
	array = buffer;
	size++;
}
template <typename T>
void Push_Row_Back(T**& array, int& rows, const int& cols) {
	Push_Back(array, rows, new T[cols]{});
}
template <typename T>
void Push_Col_Back(T**& array, const int rows, int& cols) {
	for (int i = 0; i < rows; i++)
	{
		Push_Back(array[i], cols, T());
		cols--;
	}
	cols++;
}
template <typename T>
void Push_Front(T*& array, int& size, T value){
	size++;
	T* buffer = new T[size];
	for (int i = 1; i < size; i++) {
		buffer[i] = array[i - 1];
	}
	delete[] array;
	array = buffer;
	array[0] = value;
}
template <typename T>
void Push_Row_Front(T**& array, int& rows, const int& cols) {
	Push_Front(array, rows, new T[cols]{});
}
template <typename T>
void Push_Col_Front(T**& array, const int rows, int& cols) {
	for (int i = 0; i < rows; i++)
	{
		Push_Front(array[i], cols, T());
		cols--;
	}
	cols++;
}
template <typename T>
void Insert(T*& array, int& size, T value, int pos) {
	size++;
	T* buffer = new T[size];
	for (int i = 0; i < pos; i++) {
		buffer[i] = array[i];
	}
	for (int i = pos + 1; i < size; i++) {
		buffer[i] = array[i - 1];
	}
	delete[] array;
	array = buffer;
	array[pos] = value;
}
template <typename T>
void Insert_Row(T**& array, int& rows, const int& cols, const int& pos) {
	Insert(array, rows, new T[cols]{}, pos);
}
template <typename T>
void Insert_Col(T**& array, const int& rows, int& cols, const int& pos) {
	for (int i = 0; i < rows; i++) {
		Insert(array[i], cols, T(), pos);
		cols--;
	}
	cols++;
}
template <typename T>
void Pop_Back(T*& array, int& size) {
	size--;
	T* buffer = new T[size];
	for (int i = 0; i < size; i++) {
		buffer[i] = array[i];
	}
	delete[] array;
	array = buffer;
}
template <typename T>
void Pop_Row_Back(T**& array, int& rows, const int& cols) {
	delete[] array[rows - 1];
	Pop_Back(array, rows);
}
template <typename T>
void Pop_Col_Back(T**& array, const int& rows, int& cols) {
	for (int i = 0; i < rows; i++) {
		Pop_Back(array[i], cols);
		cols++;
	}
	cols--;
}
template <typename T>
void Pop_Front(T*& array, int& size) {
	size--;
	T* buffer = new T[size];
	for (int i = 1; i < size + 1; i++) {
		buffer[i - 1] = array[i];
	}
	delete[] array;
	array = buffer;
}
template <typename T>
void Pop_Row_Front(T**& array, int& rows, const int& cols) {
	delete[] array[0];
	Pop_Front(array, rows);
}
template <typename T>
void Pop_Col_Front(T**& array, const int& rows, int& cols) {
	for (int i = 0; i < rows; i++) {
		Pop_Front(array[i], cols);
		cols++;
	}
	cols--;
}
template <typename T>
void Erase(T*& array, int& size, int pos) {
	size--;
	T* buffer = new T[size];
	for (int i = 0, j = 0; i < size; i++, j++) {
		i == pos ? j++, buffer[i] = array[j]: buffer[i] = array[j];
	}
	delete[] array;
	array = buffer;
}
template <typename T>
void Erase_Row(T**& array, int& rows, const int& cols, const int& pos) {
	//delete[] array[pos];
	Erase(array, rows, pos);
}
template <typename T>
void Erase_Col(T**& array, const int& rows, int& cols, const int& pos) {
	for (int i = 0; i < rows; i++)
	{
		Erase(array[i], cols, pos);
		cols++;
	}
	cols--;
}