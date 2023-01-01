#include <stdio.h>

int main(void)
{
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	for (i = 0; i < 10; i++)
	{// 원소의 개수만큼 반복
		for(j = 0; j < 9 - i; j++)
		{// 조건식이 "< 9 - i"인 이유 -> 반복마다 뒤에서부터 집합의 원소를 하나 씩 지우기 때문 
			if(array[j] > array[j + 1])
			{ // 반복할 때 마다 당장 옆의 값과 비교하여 왼쪽의 값이 오른쪽의 값보다 크다면 
				// Swaping
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}

