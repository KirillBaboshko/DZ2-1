#include <iostream>
using namespace std;

void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{

		cout << arr[i] << " ";

	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n ;
	cout << "Введите число товаров ";
	cin >> n;
	if (n > 1000)
	{
		cout << "Вы ввели неправильное число товаров(слишком много)\n";
		while (n > 1000)
		{
			cout << "Введите число товаров ";                                  //Проверка на ввод числа товаров
			cin >> n;
		}
	}
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите цену "<<i+1<< " товара ";                             //Заполнение массива
		cin >> array[i];
	}
	PrintArray(array, n);
	for (int i = 1; i < n; i++)
	{
		int t = array[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] < t )
			{
				array[j + 1] = array[j];                                       //Сортируем массив от большего к меньшему , сортировкой вставками
			}
			else
			{
					break;
			}
		}
		array[j+1] = t;
	}
	int m=n;
	int* array2 = new int[m];
	int i;
	int y = 0;
	for (i = 0; i < m; i++,y++)
	{
		array2[i] = array[i/2];
		for (int j = 0; j < 1; j++)
		{
			array2[i+1] = array[n-1-y];                                   //Раставляем числа в нужной последовательности
		}
		i += 1;
	}
	int sum = 0;
	for (i = 0; i < m; i++)
	{
		if (i % 2 == 0)
		{
			sum += array2[i];
		}
	}
	cout << "\n";
	PrintArray(array2, m);
	cout << "\n";
	cout << "Максимальная сумма чека:";
	cout << sum;
	return 0;
}