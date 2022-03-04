#include <stdio.h>

int ft_binSearch(int *arr, int size, int search){
// arr - массив для поиска, size - размер массива, search - искомое значение
	int begin = 0;	// начало диапозона
	int end = size;	// конец диапозона
	int tmp = 0;	// середина
	// диапозон включает левую границу, правую  - нет

	if (!arr) return -1;				// проверка поданого массива
	while (begin < end){
		tmp = begin + (end - begin) / 2;	// форма вычисления среднего для избежания переполнения типа
		if (search == arr[tmp]) return tmp;
		if (search > arr[tmp]) begin = ++tmp;	// ++tmp - для избежания зацикливания
		else end = tmp;
	}
	return -(begin);	// если искомого значения нет в массиве, выводим индекс, где он должен быть, со знаком минус
}

int main(){
	int a[10] = {1, 2, 5, 6, 8, 11, 12};
	int ret = ft_binSearch(a, 7, 6);
	
	if (ret < 0)
		printf("Value not found! Estimated index: %d", -ret);
	else
		printf("Value index: %d", ret);
	return 0;
}
