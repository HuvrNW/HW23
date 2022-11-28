#include <iostream>
#include <ctime>
#include <cstdlib>

void fill_arr(int arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

void show_arr(int arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// Задание 1. Поиск максимального и уравнивание.
void task1(int& a, int& b, int& c) {
	if (a >= b && a >= c) {
		b = a;
		c = a;
	}
	else
		if (b >= a && b >= c) {
			a = b;
			c = b;
		}
		else {
			a = c;
			b = c;
		}
}

// Задание 2. Возврат первого отрицательного элемента массива или первого.
int& task2(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		if (arr[i] >= 0) {
			continue;
		}
		else
			return arr[i];
	return arr[0];
}

// Задание 3. Обнуление элементов.
void task3(int &arr1, int &arr2, const int length1, const int length2) {
	int* pArr1 = &arr1;
	int* pArr2 = &arr2;
	for (int i = 0; i < length1; i++)
		for (int j = 0; j < length2; j++) {
			if (*(pArr1 + i) == *(pArr2 + j))
				*(pArr2 + j) = 0;
		}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int x, y, z;

	// Задание 1. Поиск максимального и уравнивание.
	
	std::cout << "\t\tЗадание 1.\n Поиск максимального и уравнивание.";
	std::cout << " Введите три числа --> ";
	std::cin >> x >> y >> z;
	std::cout << "Выполнение функции task1 ----> " << '\n';
	task1(x, y, z);
	std::cout << " x -->\t" << x << '\n';
	std::cout << " y -->\t" << y << '\n';
	std::cout << " z -->\t" << z << '\n';
	

	// Задание 2. Возврат первого отрицательного элемента массива или первого.
	
	std::cout << "\t\tЗадание 2.\n Возврат первого отрицательного элемента массива или первого.\n";
	const int size2 = 10;
	int arr2[size2];
	fill_arr(arr2, size2, -2, 20);
	std::cout << " Изначальный массив --> ";
	show_arr(arr2, size2);
	std::cout << " Выполнение функции task2 ----> " << '\n';
	std::cout << task2(arr2, size2);
	

	// Задание 3. Обнуление элементов.
	std::cout << "\t\tЗадание 3.\n Обнуление элементов.\n";
	const int size31 = 7;
	const int size32 = 8;
	int arr31[size31]{ 3,6,4,1,4,8,2 };
	int arr32[size32]{ 5,3,1,5,10,8, 4, 2};

	std::cout << " Массив 1 --> ";
	show_arr(arr31, size31);

	std::cout << " Массив 2 --> ";
	show_arr(arr32, size32);

	std::cout << " Вызов task3 ----> " << '\n';
	task3(*arr31, *arr32, size31, size32);

	std::cout << " Массив 2 после вызова функции --> ";
	show_arr(arr32, size32);


	return 0;
}