#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Array {
private:
	int** mas;
	int n, m;
public:
	Array(int, int);
	Array(const Array&);

	void vvodKeyboard();
	void vvodRand(int, int);
	void show();

	int* operator+(Array&);

	~Array();
};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int* result;
	int a, b, max, min, vib;
	while (true) {
		system("cls");
		cout << "Введите размер 1-ой матрицы: " << endl;
		cout << "Кол-во строк: ";
		cin >> a;
		cout << "Кол-во столбцов: ";
		cin >> b;
		Array mas1(a, b);
		system("cls");
		cout << "Введите элементы матрицы: " << endl;
		cout << "Заполнение с клавиатуры - 1\nЗаполнение рандомными числами - любая другая цифра\n";
		cin >> vib;
		if (vib == 1) {
			mas1.vvodKeyboard();
		}
		else {
			cout << "Введите диапазон\n";
			cout << "От: ";
			cin >> min;
			cout << "До: ";
			cin >> max;
			mas1.vvodRand(min, max);
		}
		system("cls");
		cout << "Введите размер 2-ой матрицы: " << endl;
		cout << "Кол-во строк: ";
		cin >> a;
		cout << "Кол-во столбцов: ";
		cin >> b;
		Array mas2(a, b);
		system("cls");
		cout << "Введите элементы матрицы: " << endl;
		cout << "Заполнение с клавиатуры - 1\nЗаполнение рандомными числами - любая другая цифра\n";
		cin >> vib;
		if (vib == 1) {
			mas2.vvodKeyboard();
		}
		else {
			cout << "Введите диапазон\n";
			cout << "От: ";
			cin >> min;
			cout << "До: ";
			cin >> max;
			mas2.vvodRand(min, max);
		}
		system("cls");
		cout << "1-ая матрица: ";
		mas1.show();
		cout << "2-ая матрица: ";
		mas2.show();
		result = mas1 + mas2;
		system("pause");
		system("cls");
		cout << "Продолжить - 1\nВыход - любая другая цифра\n";
		cin >> vib;
		if (vib == 1) continue;
		else break;
	}
	return 0;
}

Array::Array(int a, int b) {
	n = a;
	m = b;
	mas = new int*[n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
}

Array::Array(const Array& obj) {
	n = obj.n;
	m = obj.m;
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mas[i][j] = obj.mas[i][j];
		}
	}
}

void Array::vvodKeyboard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mas[i][j];
		}
	}
}

void Array::vvodRand(int a, int b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mas[i][j] = a + rand() % (b - a + 1);;
		}
	}
	cout << endl;
}

void Array::show() {
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++) {
			cout << setw(3) << mas[i][j] << " ";
		}
	}
	cout << endl;
}

int* Array::operator+(Array& obj) {
	int res[100], k = 0;
	while (k < (n * m + obj.n * obj.m)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[k] = mas[i][j];
				k++;
			}
		}
		for (int i = 0; i < obj.n; i++) {
			for (int j = 0; j < obj.m; j++) {
				res[k] = obj.mas[i][j];
				k++;
			}
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (res[i] == res[j]) {
				for (int p = j; p < k - 1; p++)
					res[p] = res[p + 1];
				k--;
				j--;
			}
		}
	}
	cout << "Объединение матриц: " << endl;
	for (int i = 0; i < k; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return res;
}

Array::~Array() {
	for (int i = 0; i < n; i++) {
		delete mas[i];
	}
	delete[] mas;
}

