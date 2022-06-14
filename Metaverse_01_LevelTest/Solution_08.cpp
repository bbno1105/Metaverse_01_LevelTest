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
#define NOT_VISITED 0

// ------------------------ ���� § �ڵ� ------------------------
//
//int snailCount = 0;
//
//int minX = 0;
//int minY = 0;
//int maxX = 0;
//int maxY = 0;
//
//int main()
//{
//	// �Է�
//	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
//	cin >> snailCount;
//
//	// ó�� - �迭 ����
//	int** snail = new int* [snailCount];
//	for (int i = 0; i < snailCount; i++)
//	{
//		snail[i] = new int[snailCount];
//	}
//
//	int snailNumber = 1;
//	minX = 0;
//	minY = 0;
//	maxX = snailCount -1;
//	maxY = snailCount -1;
//
//	// ó�� - �� �Ҵ� (���� �ϵ��ڵ�) ������ �˼��մϴ�.
//	while (true)
//	{
//		for (int i = minX; i <= maxX; i++)
//		{
//			snail[minY][i] = snailNumber;
//			snailNumber++;
//		}
//		minY++;
//		for (int j = minY; j <= maxY; j++)
//		{
//			snail[j][maxX] = snailNumber;
//			snailNumber++;
//		}
//		maxX--;
//		for (int k = maxX; k >= minX; k--)
//		{
//			snail[maxY][k] = snailNumber;
//			snailNumber++;
//		}
//		maxY--;
//		for (int l = maxY; l >= minY; l--)
//		{
//			snail[l][minX] = snailNumber;
//			snailNumber++;
//		}
//		minX++;
//
//		if (snailCount % 2 == 0 && minX > maxX && minY > maxY)
//		{
//			break;
//		}
//
//		if (snailCount % 2 == 1 && minX == maxX && minY == maxY)
//		{
//			snail[minX][minY] = snailNumber;
//			break;
//		}
//	}
//
//	// ���
//	for (int i = 0; i < snailCount; i++)
//	{
//		for (int j = 0; j < snailCount; j++)
//		{
//			cout << snail[i][j] << "\t";
//		}
//		cout << endl;
//	}
//}


class Snail
{
private :
	int* arr = nullptr;
	int size = 0;

	enum Direction
	{
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	};

public : 
	Snail() = default;
	~Snail()
	{
		delete[] arr;
	}

	void Create(int _size)
	{
		size = _size;

		// 2���� �迭�̸� ����ȭ �߻�
		arr = new int[size * size];
		memset(arr, 0, sizeof(int) * size * size);
	}

	void Move()
	{
		int r = 0;
		int c = 0;
		int footstep = 1;
		Direction direction = DIR_RIGHT;

		for (int i = 0; i < size * size; i++)
		{
			// 2-2. ���ڱ��� �����.
			arr[r * size + c] = footstep;
			footstep++;

			// 2-3.   �̵��� ��ġ�� ����Ѵ�.
			// 2-3-1. ���������� �� �� => c += 1;
			// 2-3-2. �Ʒ��� �� �� => r += 1;
			// 2-3-3. �������� �� �� => c -= 1;
			// 2-3-4. ���� �� �� => r -= 1;
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[(int)direction];
			int nc = c + dc[(int)direction];

			// �̵��� �Ұ����ϸ� nr,nc�� �ٽ� ��������� �Ѵ�.
			if (nr < 0 || nr >= size || nc < 0 || nc >= size ||
				arr[nr * size + nc] != NOT_VISITED)
			{
				// 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. ��ġ���� �ٽ� ����Ѵ�.
				nr = r + dr[(int)direction];
				nc = c + dc[(int)direction];
			}

			r = nr;
			c = nc;
		}
	}

	void RefreshUI()
	{
		for (int r = 0; r < size; r++)
		{
			for (int c = 0; c < size; c++)
			{
				cout << arr[r * size + c] << "\t";
			}
			cout << "\n";
		}
	}
};

Snail snail;

int main()
{
	// 1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;

	snail.Create(size);
	snail.Move();
	snail.RefreshUI();
}