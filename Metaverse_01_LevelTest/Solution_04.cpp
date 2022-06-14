// 4.	�迭�� ���� ������������ �����ؼ� ��ȯ�ϴ� �Լ��� ���� �Ͻÿ�.
//
// 
// [ Solution ]
// 
// �迭�� ���� ������������ �����ϱ� ���ؼ��� �켱 �迭�� ���� �ϳ��ϳ� Ȯ���� �ʿ伺�� �ִ�.
// �迭�� �����͸� Ȯ���ϸ� ���� �迭 vector�� �־��ش�.
// 
// 1. ���� ���� ���
//    ���� ���� ���� ��� push_back ���ش�.
// 
// 2. ���� �ִ밪���� ū ���
//    end()-1 ���� �ִ밪�� �� ������ �ִ밪���� ū ���� push_back ���ش�.
//
// 3. ���� �ִ밪�� �ƴѰ��
//    begin() ���� size ũ�⸸ŭ �迭�� Ž���ϸ� Ž���� ������ ���� ��� �� �ڸ��� insert���ش�.
// 
// ���ĵ� vector�� ���� arr�� ���Խ�Ų��.
//

#include <iostream>
#include <vector>

using namespace std;

int arr[7] = { 1, 1, 5, 2, 4, 8, 3 };

 void sortArray(int* arr, int n)
 {
	 vector<int> vec;
	 for (int i = 0; i < n; i++)
	 {
		 if (vec.size() == 0)
		 {
			 vec.push_back(arr[i]);
			 continue;
		 }

		 if (*(vec.end() - 1) < arr[i])
		 {
			 vec.push_back(arr[i]);
			 continue;
		 }

		 for (int j = 0; j < vec.size(); j++)
		 {
			 if (*(vec.begin() + j) >= arr[i])
			 {
				 vec.insert(vec.begin() + j, arr[i]);
				 break;
			 }
		 }
	 }

	 for (int i = 0; i < n; i++)
	 {
		 arr[i] = *(vec.begin() + i);
	 }
 }

 int main()
 {
	 sortArray(arr, 7);
	 for (int i = 0; i < 7; i++)
	 {
		 cout << arr[i];
	 }
 }

 // arr : [ 1, 2, 3, 4, 5 ]

 // �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١� �̰� �ܿ����� �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�
 
 // BubbleSort (��������) 

 void BubbleSort(int* arr, int size)
 {
	 // ���� ��Ʈ�� ���� ������� �̷������,
	 // �� ����� ���� �� �� �� ���Һ��� ���ĵȴ�.
	 // ������ : �迭 ũ�⺸�� �ϳ� ���� (�������� ������ ������ ���ĵ� �� ���� ������ �ϼ��Ǳ� ����)
	 for (int phase = 0; phase < size-1; phase++)
	 {
		 // �� ������� ����� �ϴ� ��
		 for (int i = 0; i < size - 1 - phase; i++)
		 {
			 // ���� ���� : ���� ���Ұ� ���� ���Һ��� Ŭ �� (��������)
			 if (arr[i] > arr[i + 1])
			 {
				 // ���� �ٲ۴�.
				 swap(arr[i], arr[i + 1]);
			 }
		 }
	 }
 }

 // �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�
