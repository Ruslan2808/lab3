#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

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

int menu(string, string);
int getInt();

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int* result;
	int a, b, max, min, vib;
	while (true) {
		system("cls");
		cout << "Введите размер 1-ой матрицы: " << endl;
		cout << "Кол-во строк: ";
		a = getInt();
		cout << "Кол-во столбцов: ";
		b = getInt();
		Array mas1(a, b);
		vib = menu("Заполнение с клавиатуры", "Заполнение рандомными числами");
		if (vib == 0) {
			cout << "Введите элементы матрицы: " << endl;
			mas1.vvodKeyboard();
		}
		else {
			cout << "Введите диапазон\n";
			cout << "От: ";
			min = getInt();
			cout << "До: ";
			max = getInt();
			mas1.vvodRand(min, max);
		}
		system("cls");
		cout << "Введите размер 2-ой матрицы: " << endl;
		cout << "Кол-во строк: ";
		a = getInt();
		cout << "Кол-во столбцов: ";
		b = getInt();
		Array mas2(a, b);
		vib = menu("Заполнение с клавиатуры", "Заполнение рандомными числами");
		if (vib == 0) {
			cout << "Введите элементы матрицы: " << endl;
			mas2.vvodKeyboard();
		}
		else {
			cout << "Введите диапазон\n";
			cout << "От: ";
			min = getInt();
			cout << "До: ";
			max = getInt();
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
		vib = menu("Продолжить", "Выйти");
		if (vib != 0) break;
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

int menu(string str1, string str2)
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 2) % 2;

		if (choiceButton == 0) cout << "->" << str1 << endl;
		else cout << str1 << endl;

		if (choiceButton == 1) cout << "->" << str2 << endl;
		else cout << str2 << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) { 
			system("cls"); 
			return choiceButton; 
		}

		system("cls");
	}
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9' || key == '-') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
