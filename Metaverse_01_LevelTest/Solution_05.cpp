// 5.	�ζ� ��ȣ �����⸦ ���� �Ͻÿ�.
// A.�ִ� ��ȣ���� ���� ���� ������ �Է��ϸ� �ش� ���� ������ �ߺ����� �ʴ� ���ڸ� ����ϴ� �ζ� ��ȣ �����⸦ ����.
// B.�ִ밪 : 60, �������� : 10 �� �Է��ϸ� 1 ~60 ������ �ߺ����� �ʴ� ���� 10���� �����Ѵ�.
//
//
// [ Solution ]
//
// ���� ���ڸ�ŭ�� ũ�⸦ ���� ������ �迭�� �����Ѵ�.
// ������ �ش��ϴ� ������ ���ڸ� �����Ͽ� lottoNumber ������ �־��ش�.
// lottoNumber�� �迭�� ���ڿ� �ߺ����� �ʴ´ٸ� �迭�� ���ڸ� �־��ش�.
// lottoNumber�� �迭�� ���ڿ� �ߺ��Ǹ� lottoNumber�� �ٽ� ����.
//

#include <iostream>
// #include <time.h>

void Lotto(int maxNumber, int selectNumber)
{
	srand(time(nullptr));

	int* arr = new int[selectNumber];
	memset(arr, 0, selectNumber);

	int lottoNumber = 0;
	
	for (int i = 0; i < selectNumber; i++)
	{
		while (true)
		{
			bool isOverlap = false;
			lottoNumber = rand() % maxNumber + 1;
			
			for (int j = 0; j <= i; j++)
			{
				if (lottoNumber == arr[j])
				{
					isOverlap = true;
				}
			}

			if (!isOverlap)
			{
				break;
			}
		}
		arr[i] = lottoNumber;
		std::cout << arr[i] << '\n';
	}
	delete[] arr;
}

int main()
{
	Lotto(60, 10);
}