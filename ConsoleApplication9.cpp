#include <fstream>

#include <string>

#include <iomanip>

#include <Windows.h>

#include <iostream>

using namespace std;

//Описание структуры со сведениями о студенте

struct stud {

	char nameGroup[30];

	int kurs;

	int groupMember;

	int dolzniki, fiz;
	float percentDolznikov = 0;

};

//Функции, используемые в программе

void menu(); // Функция вывода на экран меню

int vvod(); // Функкция ввода данных в файл

int vivod(); // Функция вывода данных из файла

// на экран

void hline(); // Функция прорисовки горизонтальной

// линии

//Основная программа

int main()

{
	

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	int num = 0; //Переменная для хранения номера

	//пункта меню,

	// выбранного пользователем

	//Цикл обработки действий пользователя

	while (num != 3)

	{

		menu();

		cin >> num;

		switch (num) {

		case 1: vvod(); break;

		case 2: vivod(); break;

		case 3: break;

		default: cout << "неверный вариант выбора" << endl;

		}

	}

	return 0;

}

//Функция вывода на экран меню

void menu()

{

	cout << "\n МЕНЮ\n";

	cout << "1. Ввод данных" << endl;

	cout << "2. Вывод данных" << endl;

	cout << "3. Выход" << endl;

	cout << "Введите номер пункта меню для дальнейшей работы" << endl;

}

//Функкция ввода данных в файл

int vvod()

{

	stud st; //Структура, использующаяся как буфер

	// при записи в файл

	//Попытка открытия файла для записи (добавления)

	// данных в файл

	ofstream f("stud.dat", ios::app | ios::binary);

	if (!f)

		ofstream f("stud.dat", ios::out | ios::binary);

	if (!f)

	{

		cout << "Ошибка открытия файла" << endl;

		return 1;

	}

	int n;

	cout << "Введите количество добавляемых записей = ";

	cin >> n;

	//Ввод данных для записи в файл

	for (int i = 0; i < n; i++)

	{

		cout << "Введите Название группы" << endl;

		while (cin.get() != '\n');

		cin.getline(st.nameGroup, 30);

		cout << "Введите курс" << endl;

		cin >> st.kurs;

		cout << "Введите численность группы" << endl;

		while (cin.get() != '\n');

		cin>>st.groupMember;

		cout << "Количество должников" << endl;

		cin >> st.dolzniki;

				
		

	

		f.write((char*)&st, sizeof(st));

	}

	//Завершение работы с файлом

	f.close();

	return 0;

}

//Функция вывода данных из файла на экран

int vivod()

{

	stud st; //Структура, использующаяся как буфер при записи в файл

	//Открытие файла для чтения

	ifstream f("stud.dat", ios::in | ios::binary);

	if (!f)

	{

		cout << "Ошибка открытия файла" << endl;

		return 1;

	}

	//Вывод шапки таблицы

	cout << " Студенты" << endl;

	hline();

	cout << "| Название группы | Курс | Численность группы | Кол-во должникв | % должников |" << endl;

	hline();

	float sr_ball; //Переменная для расчета среднего балла

	//Вывод данных из файла в таблицу

	while (!f.eof())

	{

		f.read((char*)&st, sizeof(st));//Считывание записи из файла

		if (!f.eof())

		{
					

			cout << "| " << setw(20) << st.nameGroup;

			cout << " | " << setw(4) << st.kurs;

			cout << " | " << setw(8) << st.groupMember;

			cout << " | " << setw(6) << st.dolzniki;

			double a = double(st.groupMember);
			double b = double(st.dolzniki);
			st.percentDolznikov = (b / a) * 100;
			
			cout << " | " << setw(5) << st.percentDolznikov << "% " << "\n";

			
			

		}

	}

	//Отчеркивание нижней границы таблицы

	hline();

	//Завершение работы с файлом

	f.close();

	return 0;

}

void hline()

{

	const int m = 77; //Ширина таблицы в символах

	for (int j = 0; j < m; j++)

		cout << "-";

	cout << endl;

}