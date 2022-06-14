//	N * N 달팽이 배열 알고리즘을 구현 하시오.
//  이차원 배열의 크기를 결정할 N을 정수로 입력 받는다.
//
// [ Solution ]
// 
// 1. 입력 및 이차원 배열 생성
//    입력받은 값의 크기만큼의 이차원 배열을 동적 할당한다.
// 
// 2. 값 할당
//    이동할 수 있는 x,y 좌표의 최소 최대값을 설정하여,
//    우측이동 -> 아래이동 -> 좌측이동 -> 위이동 을 반복하며
//    각 상태에 따라 반복문을 사용하여 좌표에 1씩 증가하는 값을 대입시킨다.
// 
//    짝수 입력과 홀수 입력 상태에 따라 마지막을 판단하는 조건식을 구분하여
//    조건에 해당하면 값 할당을 종료시킨다.
// 
// 3. 출력
//    반복문을 사용하여 이차원 배열을 출력한다.
//


#include <iostream>

using namespace std;
#define NOT_VISITED 0

// ------------------------ 내가 짠 코드 ------------------------
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
//	// 입력
//	cout << "배열의 크기를 입력하세요 : ";
//	cin >> snailCount;
//
//	// 처리 - 배열 생성
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
//	// 처리 - 값 할당 (멋진 하드코딩) 교수님 죄송합니다.
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
//	// 출력
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

		// 2차원 배열이면 파편화 발생
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
			// 2-2. 발자국을 남긴다.
			arr[r * size + c] = footstep;
			footstep++;

			// 2-3.   이동할 위치를 계산한다.
			// 2-3-1. 오른쪽으로 갈 때 => c += 1;
			// 2-3-2. 아래로 갈 때 => r += 1;
			// 2-3-3. 왼쪽으로 갈 때 => c -= 1;
			// 2-3-4. 위로 갈 때 => r -= 1;
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[(int)direction];
			int nc = c + dc[(int)direction];

			// 이동이 불가능하면 nr,nc를 다시 세팅해줘야 한다.
			if (nr < 0 || nr >= size || nc < 0 || nc >= size ||
				arr[nr * size + nc] != NOT_VISITED)
			{
				// 2-5. 이동이 불가능하므로 방향 전환을 한다.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. 위치값을 다시 계산한다.
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
	// 1. 배열 만들기
	cout << "배열의 크기를 입력하세요 : ";
	int size;
	cin >> size;

	snail.Create(size);
	snail.Move();
	snail.RefreshUI();
}