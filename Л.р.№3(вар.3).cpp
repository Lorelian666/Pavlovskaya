// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>
using namespace std;
const int N = 20;
const int M = 20;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a[N][M];
	int i, j, b, c;
	int k = 0;
	int n = 0;

	cout << "Введите размер массива" << endl;
	cout << "Количество строк = ";
	cin >> b;
	cout << "Количество столбцов = ";
	cin >> c;
	cout << "Введите элементы массива" << endl;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			cout << "a[" << j << "," << i << "]=";
			cin >> a[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < b; i++)
		for (j = 0; j < c; j++)

			if (a[i][j] == 0)
			{
				k++;
				i++;
			}
	cout << "Количество строк с нулевым элементом =" << k << endl;
	int l = 0;
	int m = 0;
	int max = 0;
	for (j = 0; j < c; j++)
	{
		for (i = 0; i < b - 1; i++)
		{
			if (a[i][j] == a[i + 1][j])
				l = l + 1;
			if (max < l)
			{
				max = l;
				m = j + 1;
			}

		}
	}
	cout << "Самая длинная серия одинаковых элементов в " << m << "-ом столбце." << endl;
	system("pause");

	return 0;
}