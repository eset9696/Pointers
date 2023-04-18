//Pointers
#include <iostream>

using namespace std;
//#define POINTERS_BASICS
int main() {
    setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
    int a = 2;
    int* pa = &a;
    cout << a << endl; // вывод переменной 'а' на экран
    cout << &a << endl; // взятие адреса переменной 'а' прямо при выводе
    cout << pa << endl; // вывдо адреса переменной 'а' хранящегося в указателе 'pа'
    cout << *pa << endl; // Разыменование указателя 'pа' и вывод на экран значения по адресу
    cout << *&a << endl;
#endif // POINTERS_BASICS
    const int n = 5;
    int arr[n] = { 3, 5, 8, 13, 21 };
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << "\t";
    }
    return 0;
}