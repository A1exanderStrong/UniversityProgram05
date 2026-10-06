#include <iostream>

using namespace std;

static int indexOfMax(int* array, size_t arrayLength)
{
	int value = 0;
	int index = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		if (i == 0) value = array[i];
		if (array[i] > value)
		{
			value = array[i];
			index = i;
		}
	}
	return index;
}

int main()
{
	setlocale(LC_ALL, "ru");

	/*Заполните матрицу 4 x 5 змейкой: первая строка слева направо, вторая справа налево, третья снова слева направо.
	Определите номер строки, содержащей наибольшую сумму элементов.
	Поменяйте местами первую и последнюю строки матрицы M x N.*/
	int matrix[4][5] = {};
	int max[4] = {};

#pragma region fill matrix
	cout << "Заполнение первой строки матрицы слева направо\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Введите элемент #" << i << ": ";
		cin >> matrix[0][i];
		max[0] += matrix[0][i];
	}
	cout << "Заполнение второй строки матрицы справа налево\n";
	for (int i = 4; i > -1; i--)
	{
		cout << "Введите элемент #" << i << ": ";
		cin >> matrix[1][i];
		max[1] += matrix[1][i];
	}
	cout << "Заполнение третьей строки матрицы слева направо\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Введите элемент #" << i << ": ";
		cin >> matrix[2][i];
		max[2] += matrix[2][i];
	}
	cout << "Заполнение четвёртой строки матрицы слева направо\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Введите элемент #" << i << ": ";
		cin >> matrix[3][i];
		max[3] += matrix[3][i];
	}
#pragma endregion

#pragma region show matrix
	for (int row = 0; row < 4; row++)
	{
		cout << "[";
		for (int col = 0; col < 5; col++)
		{
			cout << matrix[row][col];
			if (col + 1 < 5) cout << ", ";
		}
		cout << "]\n";
	}
#pragma endregion

	cout << "\nНомер строки с наибольшей суммой элементов: " << indexOfMax(max, 4) + 1 << endl;
	
	for (int i = 0; i < 5; i++)
	{
		swap(matrix[0][i], matrix[3][i]);
	}

#pragma region show matrix
	for (int row = 0; row < 4; row++)
	{
		cout << "[";
		for (int col = 0; col < 5; col++)
		{
			cout << matrix[row][col];
			if (col + 1 < 5) cout << ", ";
		}
		cout << "]\n";
	}
#pragma endregion
}