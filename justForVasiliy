#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Функция для считывания из стандартного ввода
void		getLine(char **line){
	int i = 0;
  
  // посимвольно считываем из стандартного вводаи записываем в массив
	while (read(0, &(*line)[i], 1))
	{
    // как только нажимаем Enter ввод прекращается
		if ((*line)[i] == '\n')
		{
			(*line)[i] = 0;
			return ;
		}
		i++;
	}
	(*line)[i] = 0;
}

// Поиск индекса, для вставки нового элемента
int binSearch(char *str, char search){
// str - массив для поиска, search - искомое значение
	int begin = 0;	// начало диапозона
	int end = strlen(str);	// конец диапозона
	int tmp = 0;	// середина
	// диапозон включает левую границу, правую  - нет

	if (!str) return -1;				// проверка поданого массива
	while (begin < end){
		tmp = begin + (end - begin) / 2;	// форма вычисления среднего для избежания переполнения типа
		if (search == str[tmp]) return tmp;
		if (search > str[tmp]) begin = ++tmp;	// ++tmp - для избежания зацикливания
		else end = tmp;
	}
	return -(begin);	// если искомого значения нет в массиве, выводим индекс, где он должен быть, со знаком минус
}

// Функция для добавление элемента в массив (добавляет сразу в нужное место)
char  *addElem(char **str, char elem){
  char  *tmp;   // Здесь будет храниться новая строка
  int   index;  // Здесь будет храниться индекс, по которому нужно вставить новый элемент
  
  // ищем введенный элемент в массиве, если его там нет, получаем индекс, где он должен быть, со знаком минус
  index = binSearch(*str, elem);
  // если элемент уже есть, то вставляем новый после найденного, если нет, то избавляемся от минуса
  (index < 0) ? index = -index : index++;
  // выделяем память под новый массив (размер старого + 2(для нового элемента и знака конца строки))
  tmp = (char *)calloc(strlen(*str) + 2, 1);  // calloc помимо выделения памяти, заполняет все нулями
  strlcpy(tmp, *str, index + 1);  // копируем старую строку до места вставки
  tmp[index] = elem;              // добавляем элемент
  tmp = strcat(tmp, (*str) + index);  // добавляем оставшуюся часть исходной строки
  free(*str); // освобождаем указатель на старую строку, чтобы избежать утечек памяти
  return tmp;
}

int main(){
  char  *str;
  int   size;
  char  elem;
  
  printf("Enter the size of the array: ");
  scanf("%d", &size);   // вводим размер массива
  str = (char *)malloc(size + 1); // выделяем память под массив
  printf("Enter the array in one line:\n");
  getLine(&str);  // считываем массив (вводить в одну строку, без пробелов)
  freopen(NULL,"r",stdin);  // перезапускаем stdin, иначе ввод сломается
  /*
  здесь должна быть сортировка массива
  */
  printf("Enter the element: ");
  scanf("%c", &elem); // считываем новый элемент
  str = addElem(&str, elem);  // добавляем новый элемент в массив
  printf("New array:\n%s\n", str);
  return 0;
}
