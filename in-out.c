#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef union	u_int		// объединение для хранения целых числел с форматной строкой
{
	char	type[3];		// для хранения форматной строки
	int		digit[100];		// для хранения числа
}				t_uint;

typedef union	u_float		// объединение для хранения вещественных числел с форматной строкой
{
	char	type[3];
	float	digit[100];
}				t_ufloat;

typedef struct	s_data		// структура, которая будет содержать все наши сформированнные массивы
{							// по сути нужна только для того, чтобы передавать данные из одной функции в другую
	t_uint		uInt;		// подцепляет вышесозданное объединение для целых чисел
	int			intSize;	// хранит фактическое кол-во целых чисел
	t_ufloat	uFloat;		// подцепляет вышесозданное объединение для вещественных чисел
	int			floatSize;
	char		uChar[102];	// для символов объединения делать не стал т.к. форматная строка также имеет тип char
	int			charSize;
}				t_data;


void	input(t_data *data)
{
	char	buff[1000]; // буффер, в который мы будем читать ввод
	int		size, j;	// size - размер буффера, j - счетчик для циклов
	int		intIndex = 1, floatIndex = 1, charIndex = 2;	// индексы для записи в массивы чисел, дробей и символов
															// int и float начинают с 1, т.к. нулевой уходит под формат
															// char с двух, т.к. первые два символа - формат
	strcpy(data->uInt.type, "%d");		// выставляем форматные строки
	strcpy(data->uFloat.type, "%f");
	strcpy(data->uChar, "%c");

	printf("Input data:\n");
	gets(buff);						// вводим данные
	size = strlen(buff);			// считаем размер введенной строки
	for(int i = 0; i < size; i++)	// посимвольно проходим по введенной строке
	{
		if (isdigit(buff[i]))		// если символ - цифра, то
		{
			j = 0;
			while (isdigit(buff[i+j]))	// проскакиваем все цифры, чтобы определить int или float
				j++;
			if (buff[i+j] == '.' && isdigit(buff[i+j+1])) // если после цифр стоит точка, а следующий символ снова цифра
			{
				j++;
				while (isdigit(buff[i+j]))
					j++;
				data->uFloat.digit[floatIndex++] = atof(buff + i); // то считываем float
			}
			else
				data->uInt.digit[intIndex++] = atoi(buff + i); // иначе считываем int
			i += j;
		}
		else
			data->uChar[charIndex++] = buff[i]; // а если символ не цифра, то пишем в char
	}
	// после того как цикл отработал, сохраняем кол-во найденных чисел, дробей и символов (сделал чисто для удобства вывода)
	data->intSize = intIndex;
	data->floatSize = floatIndex;
	data->charSize = charIndex;
}

void	output(t_data *data)
{
	printf("\n%s ", data->uInt.type);			// выводим формат
	for (int i = 1; i < data->intSize; i++)		// циклом выводим все числа
		printf("%d ", data->uInt.digit[i]);

	printf("\n%s ", data->uFloat.type);			// выводим формат
	for (int i = 1; i < data->floatSize; i++)	// циклом выводим все дроби
		printf("%f ", data->uFloat.digit[i]);
	
	printf("\n%c%c ", data->uChar[0], data->uChar[1]);	// выводим формат
	for (int i = 2; i < data->charSize; i++)			// циклом выводим символы (можно и без цикла, но так однообразнее)
		printf("%c", data->uChar[i]);
}

int main()
{
	t_data	data;	// создаем элемент структуры, в котором будем хранить все данные
	input(&data);	// функция ввода
	output(&data);	// функция вывода
	
	return 0;
}