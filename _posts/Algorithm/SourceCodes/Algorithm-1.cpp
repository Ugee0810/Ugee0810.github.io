#include <stdio.h>

int main(void)
{
	int 
	i, j,  /*배열에 있는 원소를 반복적으로 탐색하기 위한 필드*/ 
	min,   /*최솟값(가장 작은 원소를 선택하기 위한 필드)*/ 
	index, /*가장 작은 원소가 존재하는 위치*/ 
	temp;  /*특정한 두 숫자를 서로 바꾸기 위한 필드*/
	
	// 탐색할 원소 배열 
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	
	for (i = 0; i < 10; i++)
	{
		// 아주 큰 값을 넣는 이유 : 항상 최솟값을 선택하기 위해 탐색할 모든 원소들 보다 커야한다. 
		min = 9999;
		
		for (j = i; j < 10; j++)
		{
			// 최솟값 고르기 
			if (min > array[j])
			{ 
				min = array[j];
				index = j;
			}
		}
		// 스와핑을 한다. 
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	// 정렬 확인
	for (i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	} 
}
