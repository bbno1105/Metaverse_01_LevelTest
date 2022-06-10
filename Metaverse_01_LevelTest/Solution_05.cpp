// 5.	로또 번호 생성기를 구현 하시오.
// A.최대 번호값과 생성 숫자 개수를 입력하면 해당 조건 내에서 중복되지 않는 숫자를 출력하는 로또 번호 생성기를 구현.
// B.최대값 : 60, 생성숫자 : 10 을 입력하면 1 ~60 사이의 중복되지 않는 숫자 10개를 생성한다.
//
//
// [ Solution ]
//
// 생성 숫자만큼의 크기를 갖는 정수형 배열을 생성한다.
// 범위에 해당하는 랜덤한 숫자를 생성하여 lottoNumber 변수에 넣어준다.
// lottoNumber가 배열의 숫자와 중복되지 않는다면 배열에 숫자를 넣어준다.
// lottoNumber가 배열의 숫자와 중복되면 lottoNumber를 다시 고른다.
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