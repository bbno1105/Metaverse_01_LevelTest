// bubbleSort ¿¬½À
//
//#include <iostream>
//
//void BubbleSort(int* arr, int size)
//{
//	for (int phase = 0; phase < size - 1; phase++)
//	{
//		for (int j = 0; j < size - 1 - phase; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				std::swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[5] = { 3, 4, 6, 2, 1 };
//	
//	BubbleSort(arr, 5);
//	
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << arr[i] << "\n";
//	}
//}

void a(int* arr, int size)
{
	for (int j = 0; j < size; j++)
	{
		int su = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (su > arr[i])
			{
				arr[i - 1] = arr[i];
				arr[i] = su;
			}
			else if (su < arr[i])
			{
				su = arr[i];
			}
		}
	}
}

#include <iostream>

int main()
{
	int arr[5] = { 5, 2, 4, 3, 1 };
	a(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << "\n";
	}
}