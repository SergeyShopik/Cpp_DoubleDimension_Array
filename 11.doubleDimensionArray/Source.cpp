#include<iostream>
#include<ctime>
const size_t cols = 4;
int binSearch(int[], size_t, int);
void insertSort(int[], size_t);
void initMatrixAuto(int[][cols], size_t, size_t, int);
void initMatrix(int[][cols], size_t, size_t);
void printMatrix(int[][cols], size_t, size_t);
int prodInRows(int[][cols], size_t, size_t);
int prodInCols(int[][cols], size_t, size_t);
int findMinArray(int[], size_t);
int findMaxArray(int[], size_t);
void createProdArray(int[][cols], size_t, size_t, int[]);
int eachRowMult(int[][cols], size_t, size_t);
int _1_eachColMult(int[][cols], size_t, size_t);
int _2_upperDiagonalSum(int[][cols], size_t, size_t);
int _3_lowerDiagonalSum(int[][cols], size_t, size_t);
void _4_swapMaxAndMinRow(int[][cols], size_t, size_t, int[]);
void _5_positivRowsAndCols(int[][cols], size_t, size_t);
void _6_diagonalsToNulls(int[][cols], size_t, size_t);
void _7_matrixSortAndSearch(int[][cols], size_t, size_t, int);

int minMatrixElement(int[][cols], size_t, size_t);
int maxMatrixElement(int[][cols], size_t, size_t);

int numOfMinElements(int[][cols], size_t, size_t);
int numOfMaxElements(int[][cols], size_t, size_t);

int rowIndexOfMinDiagonalsElement(int[][cols], size_t, size_t);
int colIndexOfMinDiagonalsElement(int[][cols], size_t, size_t);
int rowIndexOfMaxDiagonalsElement(int[][cols], size_t, size_t);
int colIndexOfMaxDiagonalsElement(int[][cols], size_t, size_t);

int numOfMinAndMaxElementsOnMainDiagonals(int[][cols], size_t, size_t);

int sumInRow(int[][cols], size_t, size_t);
int sumInCol(int[][cols], size_t, size_t);
int sumInFirstDiagonal(int[][cols], size_t, size_t);
int sumInSecondDiagonal(int[][cols], size_t, size_t);
bool checkingRowsEquality(int[][cols], size_t, size_t);
bool checkingColsEquality(int[][cols], size_t, size_t);
bool checkingDiagonalsEquality(int[][cols], size_t, size_t);


int main()
{
	const size_t rows = 4;
	int key;
	int A[rows][cols];
	int arr[rows];
	srand(time(0));
	//1. Вычислить произведение чисел в каждом столбце.
	initMatrixAuto(A, rows, cols, 10);
	printMatrix(A, rows, cols);
	std::cout << "\n";
	std::cout << "Multiplication of each column\n";
	for (size_t i = 0; i < rows; i++)
	{
		std::cout << _1_eachColMult(A, cols, i) << '\t';
	}
	std::cout << "\n\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << "Multiplication of this row " << eachRowMult(A, i, cols) << std::endl;
	}
	std::cout << std::endl;

	//2. Вычислить сумму элементов матрицы, которые расположены выше главной диагонали.
	std::cout << "Sum of upper elements is: " << _2_upperDiagonalSum(A, rows, cols) << "\n";
	//3. Вычислить сумму элементов матрицы, которые расположены ниже побочной диагонали матрицы.
	std::cout << "Sum of lower elements is: " << _3_lowerDiagonalSum(A, rows, cols) << "\n";
	//4.Вычислить произведение элементов для каждой строки.
	//Поменять местами строки с максимальным и минимальным значением произведения.
	_4_swapMaxAndMinRow(A, rows, cols, arr);
	printMatrix(A, rows, cols);
	std::cout << "\n";
	//5. Определите  столбцы и  строки массива, в которых не содержится ни одного отрицательного элемента.
	//Выведите на экран найденные индексы строк и столбцов.
	std::cout << "Indexes of rows and cols without negative elements are: \n";
	_5_positivRowsAndCols(A, rows, cols);
	std::cout << "\n\n";
	//6. Заполните главные диагонали массива нулями.
	_6_diagonalsToNulls(A, rows, cols);
	printMatrix(A, rows, cols);
	std::cout << "\n";
	//7. Отсортировать методом вставок элементы в каждой строке, методом бинарного поиска найти в каждой строке заданный 
	//элемент и вывести на экран.
	std::cout << "Enter key:\n";
	std::cin >> key;
	_7_matrixSortAndSearch(A, rows, cols, key);
	printMatrix(A, rows, cols);
	std::cout << "\n";
	//8. Найти количество минимальных и максимальных элементов массива.
	//Найти количество минимальных и максимальных элементов на главных диагоналях. Сложить найденные минимумы и максимумы.
	//Отобразить исходный массив, минимальный элемент массива, максимальный элемент массива, 
	//минимумы, максимумы диагоналей, их позиции и суммы.
	std::cout << "Min matrix element is: " << minMatrixElement(A, rows, cols) << "\n";
	std::cout << "Max matrix element is: " << maxMatrixElement(A, rows, cols) << "\n";
	std::cout << "Sum of min and max elements is " << minMatrixElement(A, rows, cols) * numOfMinElements(A, rows, cols) + maxMatrixElement(A, rows, cols) * numOfMaxElements(A, rows, cols) << "\n";
	std::cout << "There are " << numOfMinElements(A, rows, cols) + numOfMaxElements(A, rows, cols) << " min and max elements.\n";
	std::cout << "Min element on main diagonals is: " << A[rowIndexOfMinDiagonalsElement(A, rows, cols)][colIndexOfMinDiagonalsElement(A, rows, cols)] << "\n";
	std::cout << "Index of min element is: " << "[" << rowIndexOfMinDiagonalsElement(A, rows, cols) << "]" << "[" << colIndexOfMinDiagonalsElement(A, rows, cols) << "]" << "\n";
	std::cout << "Max element on main diagonals is: " << A[rowIndexOfMaxDiagonalsElement(A, rows, cols)][colIndexOfMaxDiagonalsElement(A, rows, cols)] << "\n";
	std::cout << "Index of max element is: " << "[" << rowIndexOfMaxDiagonalsElement(A, rows, cols) << "]" << "[" << colIndexOfMaxDiagonalsElement(A, rows, cols) << "]" << "\n";
	std::cout << "Sum of min and max diagonals elements is: " << A[rowIndexOfMinDiagonalsElement(A, rows, cols)][colIndexOfMinDiagonalsElement(A, rows, cols)] + A[rowIndexOfMaxDiagonalsElement(A, rows, cols)][colIndexOfMaxDiagonalsElement(A, rows, cols)] << "\n";
	std::cout << "There are " << numOfMinAndMaxElementsOnMainDiagonals(A, rows, cols) << " min and max matrix elements on the main diagonals.\n";
	//Определить является ли квадратная матрица магическим квадратом. Матрица называется магическим квадратом,
	//если сумма элементов каждой строки равна сумме элементов каждого столбца и равна сумме элементов 
	//стоящих на диагоналях.
	if (checkingRowsEquality(A, rows, cols) == checkingColsEquality(A, rows, cols) == checkingDiagonalsEquality(A, rows, cols))
		std::cout << "This matrix is the magic square.\n";
	else std::cout << "This matrix is NOT the magic square.\n";
	system("pause");
	return 0;
}
int binSearch(int arr[], size_t size, int key)
{
	int left = 0, right = size, middle;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (arr[middle] > key)
			right = middle;
		else if (arr[middle] < key)
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}
void insertSort(int arr[], size_t size)
{
	int temp, j;
	for (size_t i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
void initMatrixAuto(int A[][cols], size_t rows, size_t cols, int range)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			A[i][j] = rand() % range;
		}
	}
}
void initMatrix(int A[][cols], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << "Enter A[" << i << "][" << j << "] = ";
			std::cin >> A[i][j];
		}
	}
	system("cls");
}
void printMatrix(int A[][cols], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << A[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}
int prodInRows(int A[][cols], size_t rowIndex, size_t cols)
{
	int prod = 1;
	for (size_t j = 0; j < cols; j++)
	{
		prod *= A[rowIndex][j];
	}
	return prod;
}
int prodInCols(int A[][cols], size_t rows, size_t cols)
{
	int prod = 1;
	for (size_t i = 0; i < rows; i++)
	{
		prod *= A[i][cols];
	}
	return prod;
}
int findMinArray(int arr[], size_t size)
{
	int index = 0, min = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
	}
	return index;
}
int findMaxArray(int arr[], size_t size)
{
	int index = 0, max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}
void createProdArray(int A[][cols], size_t rows, size_t cols, int arr[])
{
	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = prodInRows(A, i, cols);
	}
}
int eachRowMult(int A[][cols], size_t rowIndex, size_t cols)
{
	int mult = 1;
	for (size_t j = 0; j < cols; j++)
	{
		mult *= A[rowIndex][j];
	}
	return mult;
}
int _1_eachColMult(int A[][cols], size_t rows, size_t colsIndex)
{
	int mult = 1;
	for (size_t i = 0; i < rows; i++)
	{
		mult *= A[i][colsIndex];
	}
	return mult;
}
int _2_upperDiagonalSum(int A[][cols], size_t rows, size_t cols)
{
	int sum = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (j > i) sum += A[i][j];
		}
	}
	return sum;
}
int _3_lowerDiagonalSum(int A[][cols], size_t rows, size_t cols)
{
	int sum = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (j < i) sum += A[i][j];
		}
	}
	return sum;
}
void _4_swapMaxAndMinRow(int A[][cols], size_t rows, size_t cols, int arr[])
{
	int indMin, indMax;
	createProdArray(A, rows, cols, arr);
	indMin = findMinArray(arr, rows);
	indMax = findMaxArray(arr, rows);
	for (size_t j = 0; j < cols; j++)
	{
		int temp = A[indMin][j];
		A[indMin][j] = A[indMax][j];
		A[indMax][j] = temp;
	}
}
void _5_positivRowsAndCols(int A[][cols], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		bool flag = true;
		for (size_t j = 0; j < cols; j++)
		{
			if (A[i][j] < 0) flag = false;
		}
		if (flag) std::cout << i << "  ";
	}
	std::cout << "\n";
	for (size_t j = 0; j < cols; j++)
	{
		bool flag = true;
		for (size_t i = 0; i < rows; i++)
		{
			if (A[i][j] < 0) flag = false;
		}
		if (flag) std::cout << j << "  ";
	}
}
void _6_diagonalsToNulls(int A[][cols], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i == j || i + j == rows - 1)
				A[i][j] = 0;
		}
	}
}
void _7_matrixSortAndSearch(int A[][cols], size_t rows, size_t cols, int key)
{
	for (size_t q = 0; q < rows; q++)
	{
		int temp, j;
		for (size_t i = 1; i < cols; i++)
		{
			temp = A[q][i];
			for (j = i - 1; j >= 0 && temp < A[q][j]; j--)
			{
				A[q][j + 1] = A[q][j];
			}
			A[q][j + 1] = temp;
		}
		int left = 0, right = cols, middle;
		while (left < right)
		{
			middle = (left + right) / 2;
			if (A[q][middle] > key)
				right = middle;
			else if (A[q][middle] < key)
				left = middle + 1;
			else
			{
				std::cout << "key's index is " << "[" << q << "]" << "[" << middle << "]" << std::endl;
				break;
			}
		}
		std::cout << "no key\n";
	}
}
int minMatrixElement(int arr[][cols], size_t rows, size_t cols)
{
	int minEl = arr[0][0];
	int rowIndex = 0, colIndex = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[i][j] < minEl)
			{
				minEl = arr[i][j];
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	return arr[rowIndex][colIndex];
}
int maxMatrixElement(int arr[][cols], size_t rows, size_t cols)
{
	{
		int maxEl = arr[0][0];
		int rowIndex = 0, colIndex = 0;
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (arr[i][j] > maxEl)
				{
					maxEl = arr[i][j];
					rowIndex = i;
					colIndex = j;
				}
			}
		}
		return arr[rowIndex][colIndex];
	}
}
int numOfMinElements(int arr[][cols], size_t rows, size_t cols)
{
	int count = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[i][j] == minMatrixElement(arr, rows, cols))
				count++;
		}
	}
	return count;
}
int numOfMaxElements(int arr[][cols], size_t rows, size_t cols)
{
	int count = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[i][j] == maxMatrixElement(arr, rows, cols))
				count++;
		}
	}
	return count;
}
int numOfMinAndMaxElementsOnMainDiagonals(int arr[][cols], size_t rows, size_t cols)
{
	int count = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if ((i == j || i + j == rows - 1) && (arr[i][j] == minMatrixElement(arr, rows, cols) || arr[i][j] == maxMatrixElement(arr, rows, cols)))
				count++;
		}
	}
	return count;
}
int rowIndexOfMinDiagonalsElement(int arr[][cols], size_t rows, size_t cols)
{
	int minEl = arr[0][0];
	int rowIndex = 0, colIndex = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if ((i == j || i + j == rows - 1) && arr[i][j] < minEl)
			{
				minEl = arr[i][j];
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	return rowIndex;
}
int colIndexOfMinDiagonalsElement(int arr[][cols], size_t rows, size_t cols)
{
	int minEl = arr[0][0];
	int rowIndex = 0, colIndex = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if ((i == j || i + j == rows - 1) && arr[i][j] < minEl)
			{
				minEl = arr[i][j];
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	return colIndex;
}
int rowIndexOfMaxDiagonalsElement(int arr[][cols], size_t rows, size_t cols)
{
	int maxEl = arr[0][0];
	int rowIndex = 0, colIndex = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if ((i == j || i + j == rows - 1) && arr[i][j] > maxEl)
			{
				maxEl = arr[i][j];
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	return rowIndex;
}
int colIndexOfMaxDiagonalsElement(int arr[][cols], size_t rows, size_t cols)
{
	int maxEl = arr[0][0];
	int rowIndex = 0, colIndex = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if ((i == j || i + j == rows - 1) && arr[i][j] > maxEl)
			{
				maxEl = arr[i][j];
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	return colIndex;
}

int sumInRow(int A[][cols], size_t rows, size_t cols)
{
	int sum = 0;
	for (size_t j = 0; j < cols; j++)
	{
		sum += A[rows][j];
	}
	return sum;
}
int sumInCol(int A[][cols], size_t rows, size_t cols)
{
	int sum = 0;
	for (size_t j = 0; j < rows; j++)
	{
		sum += A[j][cols];
	}
	return sum;
}
int sumInFirstDiagonal(int A[][cols], size_t rows, size_t cols)
{
	int sum1 = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i == j)
				sum1 += A[i][j];
		}
	}
	return sum1;
}
int sumInSecondDiagonal(int A[][cols], size_t rows, size_t cols)
{
	int sum2 = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i + j == rows - 1)
				sum2 += A[i][j];
		}
	}
	return sum2;
}
bool checkingRowsEquality(int A[][cols], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows - 1; i++)
	{
		if (sumInRow(A, i, cols) == sumInRow(A, i + 1, cols)) continue;
		return false;
	}
	return true;
}
bool checkingColsEquality(int A[][cols], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows - 1; i++)
	{
		if (sumInCol(A, i, cols) == sumInCol(A, i + 1, cols)) continue;
		return false;
	}
	return true;
}
bool checkingDiagonalsEquality(int A[][cols], size_t rows, size_t cols)
{
	if (sumInFirstDiagonal(A, rows, cols) == sumInSecondDiagonal(A, rows, cols)) return true;
	else return false;
}

