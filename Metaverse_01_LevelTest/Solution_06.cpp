// 6.	Joker�� ������ 53���� ī�带 ���� ��, �� ���� �÷��̾�� 7�徿�� ī�带 ����ϴ� ���α׷��� ����ÿ�.
// �������� �� ���� ��ȣ + ��ȣ �� ���� A, 2 ~ 10, J, Q, K ���� ī�� ����
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
		ss << "��";
		break;
	case 1:
		ss << "��";
		break;
	case 2:
		ss << "��";
		break;
	case 3:
		ss << "��";
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

	// ī�� ���
	for (int i = 0; i < maxPlayerCard; i++)
	{
		GiveCard(player1, i);
		GiveCard(player2, i);
	}

	// ī�� ǥ��
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


