#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

int taskSelect()
{
	while (1) //выбор задачи
	{
		printf("\nЗадачи:\n\t1. Квадратное уравнение\n\t2. Система двух линейных уравнений\n\t3. Факториал\n");
		printf("\nВведите номер задачи: ");

		char num = getchar();
		if (num == '1' || num == '2' || num == '3')
		{
			switch (num)
			{
			case('1'):
				return 1;
			case('2'):
				return 2;
			case('3'):
				return 3;
			}
			break;
		}
		printf("\nВведенное значение некорректон. Повторите ввод\n");
	}
}

void task1(float* arr, int* messege)
{
	//дискриминант
	float d = pow(arr[1], 2.) - 4 * arr[0] * arr[2];
	//проверка на решаемость
	if (d < 0) 
	{
		messege[0] = 5;
	}
	else
	{
		//нахождение решения
		float x1 = (-arr[1] + sqrt(d)) / (2 * arr[0]);
		float x2 = (-arr[1] - sqrt(d)) / (2 * arr[0]);
		//запись решения в массив
		if (x1 != x2)
		{
			messege[0] = 2;
			arr[3] = x1;
			arr[4] = x2;
		}
		else
		{
			messege[0] = 1;
			arr[3] = x1;
		}
	}
}

void task2(float* arr) //система уравнений
{
	float y = arr[3] / arr[4];
	float x = arr[0] / (arr[1] * y - arr[2]);
	arr[5] = x;
	arr[6] = y;
}

float task3(float arr) //Факториал числа
{
	if (arr == 1)
	{
		return arr;
	}
	else
	{
		return arr * task3(arr - 1);
	}
}

void Input(int num, float* arr, int* messege) //ввод
{
	int i = 0;
	switch (num) {
	case(1)://Квадратное уравненией
	{
		printf("\nВведите переменные для квадратного уравнения вида: ax^2 + bx + c = 0\n");
		printf("\na: ");
		scanf_s("%f", arr + i++);
		printf("b: ");
		scanf_s("%f", arr + i++);
		printf("c: ");
		scanf_s("%f", arr + i++);
		task1(arr, messege);
	}
	break;
	case(2)://Система двух линейных уравнений
	{
		printf("\nВведите переменные для системы уравнений вида:\n\tax + by = c\n\tny = m");
		printf("\na: ");
		scanf_s("%f", &arr[0]);
		printf("b: ");
		scanf_s("%f", &arr[1]);
		printf("c: ");
		scanf_s("%f", &arr[2]);
		printf("n: ");
		scanf_s("%f", &arr[3]);
		printf("m: ");
		scanf_s("%f", &arr[4]);

		task2(arr);
	}
	break;
	case(3)://Факториал
	{
		printf("\nВведите число: ");
		scanf_s("%f", arr + i++);
		arr[1] = task3(arr[0]);
	}
	break;
	default:
		break;
	}	
}

void Output(int num, float* arr, int* messege) //вывод
{
	switch (num)
	{
	case 1:
	{
		printf("Уравнения вида: %fx^2 + %fx + %f = 0\n", * (arr + 0), *(arr + 1), *(arr + 2));
		switch (messege[0])
		{
		case 1:
		{
			printf("Имеет решение: х = %f", *(arr + 3));
		}
		break;
		case 2:
		{
			printf("Имеет решение: х1 = %f, х2 = %f", *(arr + 3), *(arr + 4));
		}
		break;
		default:
		{
			printf("Не имеет решения");
		}
			break;
		}
	}
	break;
	case 2:
	{
		printf("Уравнение вида :\n\t%5.2fx + %5.2fy = %5.2f\n\t%5.2fy = %5.2f\nИмеет решение (%f;%f)", *(arr + 0), *(arr + 1), *(arr + 2), *(arr + 3), *(arr + 4), *(arr + 5), *(arr + 6));
	}
	break;
	case 3:
	{
		printf("Факториал числа %5.2f = %5.2f\n", *(arr + 0), *(arr + 1));
	}
	break;
	default:
		break;
	}
}
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num = taskSelect(); //номер задания
	float* arr; 
	int* messege = (int*)malloc(1 * sizeof(int));
	messege[0] = 0;
	//выделение памяти
	switch (num)
	{
	case 1:
	{
		arr = (float*)malloc(4 * sizeof(int));
	}
	break;
	case 2:
	{
		arr = (float*)malloc(7 * sizeof(int));
	}
	break;
	case 3:
	{
		arr = (float*)malloc(2 * sizeof(int));
	}
	break;
	default:
	{
		printf("Произошла ошибка");
		arr = (float*)malloc(1 * sizeof(int));
		num = 0;
	}
	break;
	}
	//получение массива значений
	Input(num, arr, messege); 
	//вывод на экран
	Output(num, arr, messege);
	char a;
	free(arr);
}


