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
	cout << "������� ����������� ��������" << endl;
	cin >> value;
	//1) ������� �������� ������ ������� ������� (�� 1 ������� ������)
	int* buffer = new int[n + 1];
	//2) �������� ��� �������� �� ��������� ������� � �������� ������
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� ����� ��������� ������� ������� ������ �������
	arr = buffer;
	//5) � ������ ����� ����� � ������ "arr" ����� �������� ����� ��������
	arr[n] = value;
	//6) ����� ���������� �������� � ������ ���������� ��� ��������� ������������� �� 1
	n++;
	// Mission complete - ������� �������� � ������
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