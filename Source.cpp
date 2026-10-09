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
	cout << "Выберите способ заполнения матрицы (1-авто, 2-вручную): ";
	cin >> fillmethod;
	switch (fillmethod)
	{
	case 1: goto autofill;
	case 2: goto userfill;
	default: {
		interrupt("Указан некорректный способ заполнения матрицы.");
	}
	}

	autofill:
#pragma region autofill matrix
	for (int rows = 0; rows < 4; rows++)
	{
		for (int cols = 0; cols < 5; cols++)
		{
			matrix[rows][cols] = randnum();
		}
	}
	goto show;
#pragma endregion
	userfill:
#pragma region fill matrix by user
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