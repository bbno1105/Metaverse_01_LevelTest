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

int arr[5] = { 5, 2, 4, 1, 3 };

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
			 if (*(vec.begin() + j) > arr[i])
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
	 sortArray(arr, 5);
 }

 // arr : [ 1, 2, 3, 4, 5 ]