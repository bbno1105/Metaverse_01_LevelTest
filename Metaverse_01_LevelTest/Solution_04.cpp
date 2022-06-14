// 4.	배열의 값을 오름차순으로 정렬해서 반환하는 함수를 구현 하시오.
//
// 
// [ Solution ]
// 
// 배열의 값을 오름차순으로 정렬하기 위해서는 우선 배열의 값을 하나하나 확인할 필요성이 있다.
// 배열의 데이터를 확인하며 동적 배열 vector에 넣어준다.
// 
// 1. 값이 없는 경우
//    비교할 값이 없을 경우 push_back 해준다.
// 
// 2. 값이 최대값보다 큰 경우
//    end()-1 에는 최대값이 들어갈 것으로 최대값보다 큰 값은 push_back 해준다.
//
// 3. 값이 최대값이 아닌경우
//    begin() 부터 size 크기만큼 배열을 탐색하며 탐색한 값보다 작은 경우 그 자리에 insert해준다.
// 
// 정렬된 vector의 값을 arr에 대입시킨다.
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

 // ☆★☆★☆★☆★☆★☆★☆★☆★☆★ 이건 외워두자 ☆★☆★☆★☆★☆★☆★☆★☆★☆★
 
 // BubbleSort (버블정렬) 

 void BubbleSort(int* arr, int size)
 {
	 // 버블 소트는 여러 페이즈로 이루어지며,
	 // 각 페이즈가 끝날 시 맨 끝 원소부터 정렬된다.
	 // 페이즈 : 배열 크기보다 하나 적게 (마지막은 마지막 이전에 정렬될 때 같이 정렬이 완성되기 때문)
	 for (int phase = 0; phase < size-1; phase++)
	 {
		 // 각 페이즈마다 해줘야 하는 일
		 for (int i = 0; i < size - 1 - phase; i++)
		 {
			 // 정렬 조건 : 현재 원소가 다음 원소보다 클 때 (오름차순)
			 if (arr[i] > arr[i + 1])
			 {
				 // 서로 바꾼다.
				 swap(arr[i], arr[i + 1]);
			 }
		 }
	 }
 }

 // ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
