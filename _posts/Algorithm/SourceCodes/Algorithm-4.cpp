#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void QuickSort(int * data, int start, int end)
{
	if (start >= end)
	{ // ���Ұ� 1���� ���� 
		return;
	}
	
	// Ű�� ù ��° ����
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while (i <= j)
	{ // ������ �� ���� �ݺ� 
		while (data[i] <= data[key])
		{ // Ű ������ ū ���� ���� �� ���� �ݺ� 
			i++;
		}
		
		while (data[j] >= data[key] && j > start)
		{ // Ű ������ ���� ���� ���� �� ���� �ݺ�
		  // && �������� �� ��ü�ϰ� �Ǵµ� ���ʿ� �ִ� ���� Ű ���� ��ü���ֱ� ������ start �̻����� �Ѿ���� �ʰ� �Ѵ�. 
			j--;
		}
		
		if (i > j)
		{ // ���� ������ ���¸� ���� ���� Ű �� ���� 
			// Swaping
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else // ���� ������ ���°� �ƴ϶�� ū ���� ���� ���� ���� ���� 
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		
		// �Ȱ��� �Լ� �ȿ� �Ȱ��� �Լ��� ȣ����(����� �Լ� ����) 
		// ���� 
		QuickSort(data, start, j - 1);
		// ������ 
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

