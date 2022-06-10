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

int bingo[5][5] = { 0 };
int bingoCount = 0;
int selectNumber = 0;

void CreateBing(int& _bingo)
{
	while (true)
	{
		bool isOverlap = false;
		int bingoNumber = rand() % 25 + 1;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == bingoNumber)
				{
					isOverlap = true;
				}
			}
		}

		if (!isOverlap)
		{
			_bingo = bingoNumber;
			break;
		}
	}
}

void ChangeBingo(int _selectNumber)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i][j] == _selectNumber)
			{
				bingo[i][j] = 0;
			}
		}
	}
}

void CheckBingo()
{
	bingoCount = 0;
	bool isBingo = false;

	// 가로 빙고
	for (int i = 0; i < 5; i++)
	{
		isBingo = true;
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i][j] != 0)
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
	for (int i = 0; i < 5; i++)
	{
		isBingo = true;
		for (int j = 0; j < 5; j++)
		{
			if (bingo[j][i] != 0)
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
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i][i] != 0)
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
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[4 - i][i] != 0)
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

void Init()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			CreateBing(bingo[i][j]);
		}
	}
}

void RefreshUI()
{
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (bingo[i][j] == 0)
			{
				cout << "\t";
			}
			else 
			{
				cout << bingo[i][j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다." << endl;
}

int main()
{
	Init();
	RefreshUI();

	while (true)
	{
		cout << "숫자를 입력해 주세요 : ";
		cin >> selectNumber;
		ChangeBingo(selectNumber);
		CheckBingo();
		RefreshUI();
	}
}
