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
static void interrupt(const char* msg = "")
{
	cout << msg << endl;
	system("pause");
	system("cls");
}

static int randnum(int min = 0, int max = 60)
{
	return rand() % (max - min + 1) + min;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	/*Заполните матрицу 4 x 5 змейкой: первая строка слева направо, вторая справа налево, третья снова слева направо.
	Определите номер строки, содержащей наибольшую сумму элементов.
	Поменяйте местами первую и последнюю строки матрицы M x N.*/
	int matrix[4][5] = {};
	int max[4] = {};

	short fillmethod = 0;
	method:
	cout << "Выберите способ заполнения матрицы (1-авто, 2-вручную): ";
	cin >> fillmethod;
	switch (fillmethod)
	{
	case 1: goto autofill;
	case 2: goto userfill;
	default: {
		interrupt("Указан некорректный способ заполнения матрицы.");
		goto method;
	}
	}

	autofill:
#pragma region autofill matrix
	for (int row = 0; row < 4; row++)
	{
		if (row == 1)
		{
			for (int col = 4; col > -1; col--)
			{
				matrix[row][col] = randnum();
				max[row] += matrix[row][col];
			}
		}
		else 
		{
			for (int col = 0; col < 5; col++)
			{
				matrix[row][col] = randnum();
				max[row] += matrix[row][col];
			}
		}
		
	}
	goto show;
#pragma endregion
	userfill:
#pragma region fill matrix by user
	for (int row = 0; row < 4; row++)
	{
		cout << "Заполните строку #" << row << endl;
		if (row == 1)
		{
			for (int col = 4; col > -1; col--)
			{
				cout << "\tВведите элемент #" << col + 1 << ": ";
				cin >> matrix[row][col];
				max[row] += matrix[row][col];
			}
		}
		else
		{
			for (int col = 0; col < 5; col++)
			{
				cout << "\tВведите элемент #" << col + 1 << ": ";
				cin >> matrix[row][col];
				max[row] += matrix[row][col];
			}
		}
	}
	goto show;
#pragma endregion
	show:
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