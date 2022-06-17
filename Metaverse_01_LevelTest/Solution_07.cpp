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

		// ���� ����
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

		// ���� ����
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

		// �밢�� ����
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

		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�." << endl;
	}

	bool const isGame()
	{
		if (bingoCount == (2 * size) + 2)
		{
			system("cls");
			cout << "��� ���� �ϼ��Ǿ����ϴ�." << endl;
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
	cout << "���� ũ�⸦ �Է��� �ּ��� : ";
	cin >> setBingoSize;

	bingo.Create(setBingoSize);
	bingo.RefreshUI();
}

void Update()
{
	int selectNumber = 0;
	cout << "���ڸ� �Է��� �ּ��� : ";
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
