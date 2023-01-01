#include <stdio.h>

int main(void)
{
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for (i = 0; i < 9; i++)
	{// 첫 번째 원소는 이동하지 않으므로 총 원소 갯수의 -1만큼 반복
		// 정렬할 원소를 선택 적절한 위치에 삽입할 수 있도록 한다. 
		j = i;
		while (array[j] > array[j + 1])
		{// j는 1씩 빼 나가면서 오른쪽 값과 비교해 왼쪽 값이 더 크다면 
			// Swaping
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}

