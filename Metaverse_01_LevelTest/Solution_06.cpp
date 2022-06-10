// 6.	Joker를 포함한 53장의 카드를 섞은 후, 두 명의 플레이어에게 7장씩의 카드를 배분하는 프로그램을 만드시오.
// ♠♣♥◆ 네 개의 기호 + 기호 별 각각 A, 2 ~ 10, J, Q, K 값의 카드 존재
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

#include <iostream>
#include <sstream> 

#define CARD_QUANTITY 53;

int cardNumber = 0;
int maxPlayerCard = 7;

class Player
{
private : 
	int* playerCard = new int[maxPlayerCard];

public :
	Player()
	{
		memset(playerCard, 0, maxPlayerCard);
	}

	~Player()
	{
		delete[] playerCard;
	}

	int getCard(int playerCardNumber)
	{
		return playerCard[playerCardNumber];
	}

	void setCard(int playerCardNumber, int cardNumber)
	{
		playerCard[playerCardNumber] = cardNumber;
	}
};

Player player1;
Player player2;

void GiveCard(Player& _player, int _turn)
{
	while (true)
	{
		bool isOverlap = false;
		cardNumber = rand() % CARD_QUANTITY;

		for (int j = 0; j <= _turn; j++)
		{
			if (player1.getCard(j) == cardNumber || player2.getCard(j) == cardNumber)
			{
				isOverlap = true;
			}
		}

		if (!isOverlap)
		{
			break;
		}
	}
	_player.setCard(_turn, cardNumber);
}

std::string Render(int _cardNumber)
{
	std::stringstream ss;

	if (_cardNumber == 52)
	{
		ss << "Joker";
		return ss.str();
	}

	switch (_cardNumber / 13)
	{
	case 0 :
		ss << "♠";
		break;
	case 1:
		ss << "♣";
		break;
	case 2:
		ss << "♥";
		break;
	case 3:
		ss << "◆";
		break;
	}

	switch (_cardNumber % 13)
	{
	case 0:
		ss << "A";
		break;
	case 10 :
		ss << "J";
		break;
	case 11 :
		ss << "Q";
		break;
	case 12 :
		ss << "K";
		break;
	
	default:
		ss << (_cardNumber % 13 + 1);
		break;
	}

	return ss.str();
}

int main()
{
	srand(time(nullptr));

	// 카드 배분
	for (int i = 0; i < maxPlayerCard; i++)
	{
		GiveCard(player1, i);
		GiveCard(player2, i);
	}

	// 카드 표시
	std::cout << "Player 1 : ";
	for (int i = 0; i < maxPlayerCard; i++)
	{
		std::cout << Render(player1.getCard(i)) << " ";
	}

	std::cout << "\n";

	std::cout << "Player 2 : ";
	for (int i = 0; i < maxPlayerCard; i++)
	{
		std::cout << Render(player2.getCard(i)) << " ";
	}
}


