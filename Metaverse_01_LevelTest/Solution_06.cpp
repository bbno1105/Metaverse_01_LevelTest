// 6.	Joker를 포함한 53장의 카드를 섞은 후, 두 명의 플레이어에게 7장씩의 카드를 배분하는 프로그램을 만드시오.
// ♠ ♣ ♥ ◆ 네 개의 기호 + 기호 별 각각 A, 2 ~ 10, J, Q, K 값의 카드 존재
//
// 
// [ Solution ]
// 
// 1. Player 클래스
//     Player라는 클래스는 생성시 설정한 최대 플레이어 최대 카드 수(maxPlayerCard) 만큼의 동적 배열을 할당한다.
//     이러한 Player 클래스 타입의 player1과 player2를 생성하여 카드를 받을 플레이어를 생성한다.
// 
// 2. 카드 부여
//     GiveCard(Player _player, int _turn);
//     53장의 중복되지 않는 카드를 Player에 넣어준다.
//     Player는 할당된 playerCard 배열에 플레이어의 최대 카드 수(maxPlayerCard) 만큼 카드를 부여받는다.
// 
// 3. 출력
//     player1, player2가 가지고 있는 카드의 숫자에 해당하는 카드문자를 출력한다.
//     카드는 52번을 Joker로 설정하고 13으로 나눈 값을 카드의 모양으로, 13으로 나눈 나머지를 카드의 숫자로 구분하여 출력한다.
// 
//     0	~	12	: ♠
//     13	~	25	: ♣
//     26	~	38	: ♥
//     39	~	51	: ◆
//     52			: Joker
//

// Deck타입
// 1. 모든 덱은 카드가 중복되지 않아야 한다.

#include <iostream>
#include <sstream> 

#define CARD_QUANTITY 53
#define MAX_PLAYER_CARD 7

template <size_t PLAYER_CARD>
class Deck
{
private : 
	int playerCard[PLAYER_CARD] = { -1 };

public:
	static bool isUsed[CARD_QUANTITY];
	static int remainCard;

public :
	Deck() = default;
	~Deck() = default;

	// Make() : 카드를 7장 뽑아서 덱을 구성한다. 단 카드가 충분치 않은 경우 만들어지지 못할 수 있다.
	bool Make()
	{
		if (remainCard < 7)
		{
			return false;
		}
		
		int cardNumber = 0;

		for (int i = 0; i < PLAYER_CARD; i++)
		{
			do
			{
				cardNumber = rand() % CARD_QUANTITY;
			} while (isUsed[cardNumber]);

			isUsed[cardNumber] = true;

			playerCard[i] = cardNumber;
		}

		remainCard -= 7;
		return true;
	}

	// ToString() : 현제 덱의 카드를 표현하는 문자열을 만든다. 카드가 없는 경우 "The deck is empty"로 반환한다.
	std::string ToString()
	{
		if (playerCard[0] == -1)
		{
			return "세팅할 카드가 없는데요";
		}
		// 1. 플레이어 카드 수 만큼 순회한다
		// 2. 순회하며 카드의 타입과 수를 판별한다
		// 3. 판별한 결과를 차례대로 저장한다.
		// 4. 저장한 데이터를 반환한다.

		std::stringstream ss;
		for (int i = 0; i < PLAYER_CARD; i++)
		{
			int cardType = playerCard[i] / 13;
			int cardNumber = playerCard[i] % 13;

			// Lookup Table
			static const std::string CARD_TYPE[] = { "♠", "♣", "♥", "◆", "Joker" };
			static const std::string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

			if (cardType == 4)
			{
				ss << "Joker" << "\t";
			}
			else
			{
				ss << CARD_TYPE[cardType] << CARD_NUMBER[cardNumber] << "\t";
			}
		}
		return ss.str();
	}
};

bool Deck<MAX_PLAYER_CARD>::isUsed[CARD_QUANTITY] = { false };
int Deck<MAX_PLAYER_CARD>::remainCard = CARD_QUANTITY;

Deck<MAX_PLAYER_CARD> player1;
Deck<MAX_PLAYER_CARD> player2;

//void GiveCard(Player& _player, int _turn)
//{
//	while (true)
//	{
//		bool isOverlap = false;
//		cardNumber = rand() % CARD_QUANTITY;
//
//		for (int j = 0; j <= _turn; j++)
//		{
//			if (player1.getCard(j) == cardNumber || player2.getCard(j) == cardNumber)
//			{
//				isOverlap = true;
//			}
//		}
//
//		if (!isOverlap)
//		{
//			break;
//		}
//	}
//	_player.setCard(_turn, cardNumber);
//}

//std::string Render(int _cardNumber)
//{
//	std::stringstream ss;
//
//	int cardType = _cardNumber / 13;
//	int cardNumber = _cardNumber % 13;
//
//	// Lookup Table
//	static const std::string CARD_TYPE[] = { "♠", "♣", "♥", "◆", "Joker" };
//	static const std::string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
//
//	if (cardType == 4)
//	{
//		ss << "Joker";
//		return ss.str();
//	}
//
//	ss << CARD_TYPE[cardType] << CARD_NUMBER[cardNumber];
//	return ss.str();
//
//	/*if (_cardNumber == 52)
//	{
//		ss << "Joker";
//		return ss.str();
//	}
//
//	switch (_cardNumber / 13)
//	{
//	case 0 :
//		ss << "♠";
//		break;
//	case 1:
//		ss << "♣";
//		break;
//	case 2:
//		ss << "♥";
//		break;
//	case 3:
//		ss << "◆";
//		break;
//	}
//
//	switch (_cardNumber % 13)
//	{
//	case 0:
//		ss << "A";
//		break;
//	case 10 :
//		ss << "J";
//		break;
//	case 11 :
//		ss << "Q";
//		break;
//	case 12 :
//		ss << "K";
//		break;
//	
//	default:
//		ss << (_cardNumber % 13 + 1);
//		break;
//	}*/
//
//}

int main()
{
	srand(time(nullptr));

	std::cout << "카드 세팅 전 : " << player1.ToString() << "\n";

	// 카드 배부
	if (player1.Make() && player2.Make())
	{
		// 카드 표시
		std::cout << "Player 1 : " << player1.ToString() << "\n";
		std::cout << "Player 2 : " << player2.ToString() << "\n";
	}
	else
	{
		std::cout << "카드가 부족합니다." << "\n";
	}
	


}

//
//int isUsedCard[53] = { false };
//
//void PickCard(int* _deck, int _maxPick)
//{
//	// 중복되지 않게 카드를 뽑아야 함
//	// 카드는 정수값 [0, 53]
//	srand(time(NULL));
//
//	bool isPick = false;
//	int pickCard = 0;
//	do
//	{
//		pickCard = rand() % 53;
//		isPick = false;
//		for (int i = 0; i < _maxPick; i++)
//		{
//			if (isUsedCard[pickCard])
//			{
//				isPick = true;
//				break;
//			}
//		}
//	} while (isPick);
//	isUsedCard[pickCard] = true;
//
//}