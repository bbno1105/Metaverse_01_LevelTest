// 7.	1 ~25까지의 숫자가 랜덤하게 배치되는 5X5의 빙고게임 판을 생성한 후, 
// 숫자 입력을 받을 때마다 해당 숫자를 지워주고 가로, 세로, 대각선의 빙고 줄이 완성될 때마다 
// 빙고 개수를 갱신해서 표시해 주는 빙고 게임을 제작 하시오.
//
// 
// [ Solution ]
// 
// 1. 빙고판 생성
//   CreateBingo();
//   5 * 5 크기의 2차원 배열을 생성하여 빙고판을 제작한다.
//   1 ~ 25의 중복되지 않는 숫자를 각각 빙고판에 적용시킨다.
// 
// 2. 숫자를 입력받는다.
//    cin >> selectNumber;
// 
// 3. 상태를 변경한다.
//    ChangeBingo();
//    입력받은 숫자가 해당하는 빙고 배열의 상태를 변경한다 (여기서는 사용하지 않은 숫자 0으로 변경)
// 
// 4. 빙고 상태를 체크한다.
//    CheckBingo();
//    가로, 세로, 대각선의 빙고 조건에 해당하면 bingoCount를 증가시킨다.
//    조건은 매 번 체크되기 때문에 bingoCount는 항상 0에서 시작한다.
// 
// 5. 렌더
//    RefreshUI();
//    화면에 표시되고 있는 UI를 갱신시킨다.
//    상태가 0인 빙고판은 아무것도 표시하지 않는다
//
//

#include <iostream>
#include <Windows.h>

using namespace std;

class Bingo
{
private:
	int* bingo;
	int bingoCount = 0;
	int size = 0;

public:
	Bingo() = default;
	~Bingo()
	{
		delete[] bingo;
	}

	void const Create(int _size)
	{
		size = _size;
		bingo = new int[size * size];
		bool* isUsed = new bool[size * size];
		memset(isUsed, false, size * size);
		int bingoNumber = 0;

		for (int i = 0; i < size * size; i++)
		{
			do
			{
				bingoNumber = rand() % (size * size) + 1;

			} while (isUsed[bingoNumber - 1]);
			isUsed[bingoNumber - 1] = true;
			bingo[i] = bingoNumber;
		}
		delete[] isUsed;
	}

	void const SelectNumber(int _selectNumber)
	{
		for (int i = 0; i < size * size; i++)
		{
			if (bingo[i] == _selectNumber)
			{
				bingo[i] = 0;
			}
		}
	}

	void const Check()
	{
		bingoCount = 0;
		bool isBingo = false;

		// 가로 빙고
		for (int i = 0; i < size; i++)
		{
			isBingo = true;
			for (int j = 0; j < size; j++)
			{
				if (bingo[i * size + j] != 0)
				{
					isBingo = false;
					break;
				}
			}
			if (isBingo)
			{
				bingoCount++;
			}
		}

		// 세로 빙고
		for (int i = 0; i < size; i++)
		{
			isBingo = true;
			for (int j = 0; j < size; j++)
			{
				if (bingo[j * size + i] != 0)
				{
					isBingo = false;
					break;
				}
			}
			if (isBingo)
			{
				bingoCount++;
			}
		}

		// 대각선 빙고
		isBingo = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (bingo[i * size + i] != 0)
				{
					isBingo = false;
					break;
				}
			}
		}
		if (isBingo)
		{
			bingoCount++;
		}

		isBingo = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (bingo[((size-1) - i) * size + i] != 0)
				{
					isBingo = false;
					break;
				}
			}
		}
		if (isBingo)
		{
			bingoCount++;
		}
	}

	void const RefreshUI()
	{
		system("cls");

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (bingo[i * size + j] == 0)
				{
					cout << "\t";
				}
				else
				{
					cout << bingo[i * size + j] << "\t";
				}
			}
			cout << endl << endl;
		}

		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다." << endl;
	}

	bool const isGame()
	{
		if (bingoCount == (2 * size) + 2)
		{
			system("cls");
			cout << "모든 빙고가 완성되었습니다." << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

};

Bingo bingo;

int setBingoSize = 0;

void Init()
{
	cout << "빙고 크기를 입력해 주세요 : ";
	cin >> setBingoSize;

	bingo.Create(setBingoSize);
	bingo.RefreshUI();
}

void Update()
{
	int selectNumber = 0;
	cout << "숫자를 입력해 주세요 : ";
	cin >> selectNumber;

	bingo.SelectNumber(selectNumber);
	bingo.Check();
	bingo.RefreshUI();
}

int main()
{
	Init();
	while (bingo.isGame())
	{
		Update();
	}
}
