// 7.	1 ~25������ ���ڰ� �����ϰ� ��ġ�Ǵ� 5X5�� ������� ���� ������ ��, 
// ���� �Է��� ���� ������ �ش� ���ڸ� �����ְ� ����, ����, �밢���� ���� ���� �ϼ��� ������ 
// ���� ������ �����ؼ� ǥ���� �ִ� ���� ������ ���� �Ͻÿ�.
//
// 
// [ Solution ]
// 
// 1. ������ ����
//   CreateBingo();
//   5 * 5 ũ���� 2���� �迭�� �����Ͽ� �������� �����Ѵ�.
//   1 ~ 25�� �ߺ����� �ʴ� ���ڸ� ���� �����ǿ� �����Ų��.
// 
// 2. ���ڸ� �Է¹޴´�.
//    cin >> selectNumber;
// 
// 3. ���¸� �����Ѵ�.
//    ChangeBingo();
//    �Է¹��� ���ڰ� �ش��ϴ� ���� �迭�� ���¸� �����Ѵ� (���⼭�� ������� ���� ���� 0���� ����)
// 
// 4. ���� ���¸� üũ�Ѵ�.
//    CheckBingo();
//    ����, ����, �밢���� ���� ���ǿ� �ش��ϸ� bingoCount�� ������Ų��.
//    ������ �� �� üũ�Ǳ� ������ bingoCount�� �׻� 0���� �����Ѵ�.
// 
// 5. ����
//    RefreshUI();
//    ȭ�鿡 ǥ�õǰ� �ִ� UI�� ���Ž�Ų��.
//    ���°� 0�� �������� �ƹ��͵� ǥ������ �ʴ´�
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

	// ���� ����
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

	// ���� ����
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

	// �밢�� ����
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

	cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;
}

int main()
{
	Init();
	RefreshUI();

	while (true)
	{
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> selectNumber;
		ChangeBingo(selectNumber);
		CheckBingo();
		RefreshUI();
	}
}
