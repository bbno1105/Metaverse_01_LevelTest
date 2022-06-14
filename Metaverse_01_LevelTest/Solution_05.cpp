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

// template <size_t MAX_DIGIT_COUNT> // 템플릿으로 컨트롤할 수 있다. or 동적할당 방법도 있다 or 정적할당도 있다. 
class Lotto
{
private :
	int* lotto = nullptr;
	int digitCount = 0;
	
	static const int MAX_DIGIT_COUNT = 100;

public:
	Lotto() = default;
	Lotto(const Lotto& other) = delete;
	Lotto operator=(const Lotto& other) = delete;
	~Lotto()
	{
		Clear();
	}

	/// <summary>
	/// 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
	/// </summary>
	/// <param name="_maxNumber">최대 번호값</param>
	/// <param name="_selectNumber">생성 숫자 개수</param>
	void Make(int _maxValue, int _digitCount)
	{
		// 1. 이미 생성된 번호를 지워준다.
		Clear();

		lotto = new int[_maxValue];
		memset(lotto, 0, _maxValue);

		// digitCount : [1,100]
		// 1. digitCount가 1보다 작을 때
		// 2. digitCount가 100보다 클 때
		// 3. digitCount가 최솟값과 최댓값 사이에 있을 때
		digitCount = std::max(1, std::min(_digitCount, MAX_DIGIT_COUNT));
		
		int lottoNumber = 0;

		for (int i = 0; i < digitCount; i++)
		{
			while (true)
			{
				bool isOverlap = false;
				lottoNumber = rand() % _maxValue + 1;

				for (int j = 0; j <= i; j++)
				{
					if (lottoNumber == lotto[j])
					{
						isOverlap = true;
					}
				}

				if (!isOverlap)
				{
					break;
				}
			}

			lotto[i] = lottoNumber;
		}
	}

	void Print()
	{
		for (int i = 0; i < digitCount; i++)
		{
			std::cout << lotto[i] << "\t";
		}
	}

	/// <summary>
	/// 데이터를 지운다.
	/// </summary>
	void Clear()
	{
		delete[] lotto;
		lotto = nullptr;
		digitCount = 0;
	}

};

// 동적 할당의 문제점. 즉, 메모리를 수동으로 관리할 때의 문제점
// 1. 할당은 했는데 해제를 안 했다. => 메모리 누수 (Memory Leak)
// 2. 이미 해제한 메모리에 대해서 또 해제했다. => 이중 해제 (Double Free)
//		- 이미 해제한 메모리를 가리키는 포인터 => 댕글링 포인터 (Dangling Pointer)
// 3. 너무 빨리 해제했다. => 조기 해제 (Premature free)

int main()
{
	std::cout << "로또의 범위(최댓값)을 입력하세요 : ";
	int maxValue;
	std::cin >> maxValue;

	std::cout << "로또 선택할 값을 입력하세요 : ";
	int digitCount;
	std::cin >> digitCount;

	while (digitCount > maxValue)
	{
		std::cout << "로또의 최댓값보다 선택값이 높습니다. \n";
		std::cout << "로또 선택할 값을 다시 입력하세요 : ";
		std::cin >> digitCount;
	} 

	Lotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();
}
