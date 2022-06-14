
#include <iostream>

using namespace std;

int maxValue;
int digitCount;

void Lotto(int* _lotto, int _maxValue, int _digitCount)
{
	for (int i = 0; i < _digitCount; i++)
	{
		int lottoValue = 0;
		while (true)
		{
			bool isOverlap = false;
			lottoValue = rand() % _maxValue + 1;
			for (int j = 0; j < i; j++)
			{
				if (*(_lotto + j) == lottoValue)
				{
					isOverlap = true;
				}
			}
			// lotto�� �ߺ����� ���ٸ�!
			if (!isOverlap)
			{
				break;
			}
		}
		*(_lotto + i) = lottoValue;
	}
}



int main()
{
	cin >> maxValue;
	cin >> digitCount;

	int* lotto = new int[digitCount];

	// �ζ� ��ȣ ���ϱ�
	

	// 1. [1, maxValue] ������ ������ ����
	srand(time(NULL));
	
	Lotto(lotto, maxValue, digitCount);

	for (int i = 0; i < digitCount; i++)
	{
		std::cout << lotto[i] << "\n"; // *(lotto+i) == lotto[i]
	}

	delete[] lotto;

}

//

//
//void Lotto2(int* _lotto, int _maxValue, int _digitCount)
//{
//	for (int curPos = 0; curPos < digitCount; curPos++)
//	{
//		int candidate = 1 + rand() % _maxValue;
//
//		for (int i = 0; i < curPos; i++)
//		{
//			if (candidate == _lotto[i])
//			{
//
//			}
//		}
//	}	
//}


// �������� do{} while(); �� �Ͻ�