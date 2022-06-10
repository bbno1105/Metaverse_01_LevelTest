//	N * N ������ �迭 �˰����� ���� �Ͻÿ�.
//  ������ �迭�� ũ�⸦ ������ N�� ������ �Է� �޴´�.
//
// [ Solution ]
// 
// 1. �Է� �� ������ �迭 ����
//    �Է¹��� ���� ũ�⸸ŭ�� ������ �迭�� ���� �Ҵ��Ѵ�.
// 
// 2. �� �Ҵ�
//    �̵��� �� �ִ� x,y ��ǥ�� �ּ� �ִ밪�� �����Ͽ�,
//    �����̵� -> �Ʒ��̵� -> �����̵� -> ���̵� �� �ݺ��ϸ�
//    �� ���¿� ���� �ݺ����� ����Ͽ� ��ǥ�� 1�� �����ϴ� ���� ���Խ�Ų��.
// 
//    ¦�� �Է°� Ȧ�� �Է� ���¿� ���� �������� �Ǵ��ϴ� ���ǽ��� �����Ͽ�
//    ���ǿ� �ش��ϸ� �� �Ҵ��� �����Ų��.
// 
// 3. ���
//    �ݺ����� ����Ͽ� ������ �迭�� ����Ѵ�.
//


#include <iostream>

using namespace std;

int snailCount = 0;

int minX = 0;
int minY = 0;
int maxX = 0;
int maxY = 0;

int main()
{
	// �Է�
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> snailCount;

	// ó�� - �迭 ����
	int** snail = new int* [snailCount];
	for (int i = 0; i < snailCount; i++)
	{
		snail[i] = new int[snailCount];
	}

	int snailNumber = 1;
	minX = 0;
	minY = 0;
	maxX = snailCount -1;
	maxY = snailCount -1;

	// ó�� - �� �Ҵ� (���� �ϵ��ڵ�) ������ �˼��մϴ�.
	while (true)
	{
		for (int i = minX; i <= maxX; i++)
		{
			snail[minY][i] = snailNumber;
			snailNumber++;
		}
		minY++;
		for (int j = minY; j <= maxY; j++)
		{
			snail[j][maxX] = snailNumber;
			snailNumber++;
		}
		maxX--;
		for (int k = maxX; k >= minX; k--)
		{
			snail[maxY][k] = snailNumber;
			snailNumber++;
		}
		maxY--;
		for (int l = maxY; l >= minY; l--)
		{
			snail[l][minX] = snailNumber;
			snailNumber++;
		}
		minX++;

		if (snailCount % 2 == 0 && minX > maxX && minY > maxY)
		{
			break;
		}

		if (snailCount % 2 == 1 && minX == maxX && minY == maxY)
		{
			snail[minX][minY] = snailNumber;
			break;
		}
	}

	// ���
	for (int i = 0; i < snailCount; i++)
	{
		for (int j = 0; j < snailCount; j++)
		{
			cout << snail[i][j] << "\t";
		}
		cout << endl;
	}
}