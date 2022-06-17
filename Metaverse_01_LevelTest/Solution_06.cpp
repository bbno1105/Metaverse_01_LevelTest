// 6.	Joker�� ������ 53���� ī�带 ���� ��, �� ���� �÷��̾�� 7�徿�� ī�带 ����ϴ� ���α׷��� ����ÿ�.
// �� �� �� �� �� ���� ��ȣ + ��ȣ �� ���� A, 2 ~ 10, J, Q, K ���� ī�� ����
//
// 
// [ Solution ]
// 
// 1. Player Ŭ����
//     Player��� Ŭ������ ������ ������ �ִ� �÷��̾� �ִ� ī�� ��(maxPlayerCard) ��ŭ�� ���� �迭�� �Ҵ��Ѵ�.
//     �̷��� Player Ŭ���� Ÿ���� player1�� player2�� �����Ͽ� ī�带 ���� �÷��̾ �����Ѵ�.
// 
// 2. ī�� �ο�
//     GiveCard(Player _player, int _turn);
//     53���� �ߺ����� �ʴ� ī�带 Player�� �־��ش�.
//     Player�� �Ҵ�� playerCard �迭�� �÷��̾��� �ִ� ī�� ��(maxPlayerCard) ��ŭ ī�带 �ο��޴´�.
// 
// 3. ���
//     player1, player2�� ������ �ִ� ī���� ���ڿ� �ش��ϴ� ī�幮�ڸ� ����Ѵ�.
//     ī��� 52���� Joker�� �����ϰ� 13���� ���� ���� ī���� �������, 13���� ���� �������� ī���� ���ڷ� �����Ͽ� ����Ѵ�.
// 
//     0	~	12	: ��
//     13	~	25	: ��
//     26	~	38	: ��
//     39	~	51	: ��
//     52			: Joker
//

// DeckŸ��
// 1. ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.

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

	// Make() : ī�带 7�� �̾Ƽ� ���� �����Ѵ�. �� ī�尡 ���ġ ���� ��� ��������� ���� �� �ִ�.
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

	// ToString() : ���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����. ī�尡 ���� ��� "The deck is empty"�� ��ȯ�Ѵ�.
	std::string ToString()
	{
		if (playerCard[0] == -1)
		{
			return "������ ī�尡 ���µ���";
		}
		// 1. �÷��̾� ī�� �� ��ŭ ��ȸ�Ѵ�
		// 2. ��ȸ�ϸ� ī���� Ÿ�԰� ���� �Ǻ��Ѵ�
		// 3. �Ǻ��� ����� ���ʴ�� �����Ѵ�.
		// 4. ������ �����͸� ��ȯ�Ѵ�.

		std::stringstream ss;
		for (int i = 0; i < PLAYER_CARD; i++)
		{
			int cardType = playerCard[i] / 13;
			int cardNumber = playerCard[i] % 13;

			// Lookup Table
			static const std::string CARD_TYPE[] = { "��", "��", "��", "��", "Joker" };
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
//	static const std::string CARD_TYPE[] = { "��", "��", "��", "��", "Joker" };
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
//		ss << "��";
//		break;
//	case 1:
//		ss << "��";
//		break;
//	case 2:
//		ss << "��";
//		break;
//	case 3:
//		ss << "��";
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

	std::cout << "ī�� ���� �� : " << player1.ToString() << "\n";

	// ī�� ���
	if (player1.Make() && player2.Make())
	{
		// ī�� ǥ��
		std::cout << "Player 1 : " << player1.ToString() << "\n";
		std::cout << "Player 2 : " << player2.ToString() << "\n";
	}
	else
	{
		std::cout << "ī�尡 �����մϴ�." << "\n";
	}
	


}

//
//int isUsedCard[53] = { false };
//
//void PickCard(int* _deck, int _maxPick)
//{
//	// �ߺ����� �ʰ� ī�带 �̾ƾ� ��
//	// ī��� ������ [0, 53]
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