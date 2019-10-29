// TryToCt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
#include "../complex1.h"
#include <vector>
#include <fstream>
#include "Tests/test.h"

using namespace std;

int main()
{
	test_ComplexClass_all();
	const int size_arr = 10;
	std::vector<Complex> a(size_arr);
	ofstream f("file.txt");
	for (int i = 0; i < size_arr; i++) {
		f << a[i].toString() << std::endl;
	}
	f.close();

	ifstream out("file.txt");
	char str;
	double num;
	
	for (int i = 0; i < size_arr; i++) {
		out >> num;
		a[i].setRe(num);
		out >> str;
		out >> num;
		a[i].setIm(num);
		out >> str;
		out >> str;
		cout << a[i].toString() << endl;
	}
	out.close();
	

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
