#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void QuickSort(int * data, int start, int end)
{
	if (start >= end)
	{ // 원소가 1개인 이유 
		return;
	}
	
	// 키는 첫 번째 원소
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while (i <= j)
	{ // 엇갈릴 때 까지 반복 
		while (data[i] <= data[key])
		{ // 키 값보다 큰 값을 만날 때 까지 반복 
			i++;
		}
		
		while (data[j] >= data[key] && j > start)
		{ // 키 값보다 작은 값을 만날 때 까지 반복
		  // && 엇갈렸을 때 교체하게 되는데 왼쪽에 있는 값과 키 값을 교체해주기 때문에 start 이상으로 넘어오지 않게 한다. 
			j--;
		}
		
		if (i > j)
		{ // 현재 엇갈린 상태면 왼쪽 값과 키 값 변경 
			// Swaping
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else // 현재 엇갈린 상태가 아니라면 큰 값과 작은 값을 서로 변경 
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		
		// 똑같은 함수 안에 똑같은 함수를 호출함(재귀적 함수 구현) 
		// 왼쪽 
		QuickSort(data, start, j - 1);
		// 오른쪽 
		QuickSort(data, j + 1, end);
	}
}

int main(void)
{
	QuickSort(data, 0, number - 1);
	
	for (int i = 0; i < number; i++)
	{
		printf("%d ", data[i]);
	}
}

