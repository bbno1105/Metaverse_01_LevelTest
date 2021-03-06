// 3.	다음의 형태로 * 을 출력하는 코드를 구현 하시오.
//
// 
// [ Solution ]
// 
// 별찍기는 보이지 않는 공백 문자와 *문자로 구성되어 있다.
// 문제에서 제시한 별찍기 형태를 살펴보면 아래와 같이 구성되어 있는 것을 확인할 수 있다.
// 
//     *		4개의 " " 1개의 "*"
//    ***		3개의 " " 3개의 "*"
//   *****		2개의 " " 5개의 "*"
//  *******		1개의 " " 7개의 "*"
// *********	0개의 " " 9개의 "*"
// 
// " "은 각 줄마다 1씩 줄어들고 있으며,
// "*"은 각 줄마다 2씩 증가하는 규칙이 보인다.
// 위의 규칙에 따라 조건식과 반복식을 활용하여 별찍기를 출력하였다.
// 

#include <iostream>

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			std::cout << " ";
		}
		for (int j = 0; j < 1 + (2 * i); j++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}