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

// template <size_t MAX_DIGIT_COUNT> // ���ø����� ��Ʈ���� �� �ִ�. or �����Ҵ� ����� �ִ� or �����Ҵ絵 �ִ�. 
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
	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	/// </summary>
	/// <param name="_maxNumber">�ִ� ��ȣ��</param>
	/// <param name="_selectNumber">���� ���� ����</param>
	void Make(int _maxValue, int _digitCount)
	{
		// 1. �̹� ������ ��ȣ�� �����ش�.
		Clear();

		lotto = new int[_maxValue];
		memset(lotto, 0, _maxValue);

		// digitCount : [1,100]
		// 1. digitCount�� 1���� ���� ��
		// 2. digitCount�� 100���� Ŭ ��
		// 3. digitCount�� �ּڰ��� �ִ� ���̿� ���� ��
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
	/// �����͸� �����.
	/// </summary>
	void Clear()
	{
		delete[] lotto;
		lotto = nullptr;
		digitCount = 0;
	}

};

// ���� �Ҵ��� ������. ��, �޸𸮸� �������� ������ ���� ������
// 1. �Ҵ��� �ߴµ� ������ �� �ߴ�. => �޸� ���� (Memory Leak)
// 2. �̹� ������ �޸𸮿� ���ؼ� �� �����ߴ�. => ���� ���� (Double Free)
//		- �̹� ������ �޸𸮸� ����Ű�� ������ => ��۸� ������ (Dangling Pointer)
// 3. �ʹ� ���� �����ߴ�. => ���� ���� (Premature free)

int main()
{
	std::cout << "�ζ��� ����(�ִ�)�� �Է��ϼ��� : ";
	int maxValue;
	std::cin >> maxValue;

	std::cout << "�ζ� ������ ���� �Է��ϼ��� : ";
	int digitCount;
	std::cin >> digitCount;

	while (digitCount > maxValue)
	{
		std::cout << "�ζ��� �ִ񰪺��� ���ð��� �����ϴ�. \n";
		std::cout << "�ζ� ������ ���� �ٽ� �Է��ϼ��� : ";
		std::cin >> digitCount;
	} 

	Lotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();
}
