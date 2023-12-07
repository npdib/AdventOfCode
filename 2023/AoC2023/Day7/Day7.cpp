// Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <fstream>

#define NUM_LENGTH 8

typedef enum hand_type_t
{
	HighCard,
	OnePair,
	TwoPair,
	ThreeKind,
	FullHouse,
	FourKind,
	FiveKind
} HandType;

typedef enum card1_t
{
	T = 10,
	J = 11,
	Q = 12,
	K = 13,
	A = 14
} Card1;

typedef struct hand_t
{
	HandType type;
	uint8_t hand[5];
	uint16_t bet;
} Hand;

typedef enum card2_t
{
	T2 = 10,
	J2 = 1,
	Q2 = 12,
	K2 = 13,
	A2 = 14
} Card2;

struct handCompare
{
	bool operator()(const Hand hand1, const Hand hand2) const
	{
		if (hand1.type != hand2.type)
		{
			return hand1.type < hand2.type;
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (hand1.hand[i] == hand2.hand[i])
				{
					continue;
				}

				return hand1.hand[i] < hand2.hand[i];
			}
		}

		return false;
	}
};

HandType classHand(uint8_t* hand)
{
	uint8_t freq[15] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		freq[hand[i]]++;
	}

	std::sort(std::begin(freq), std::end(freq));
	std::reverse(std::begin(freq), std::end(freq));

	switch (freq[0])
	{
	case 5:
		return FiveKind;
	case 4:
		return FourKind;
	case 3:
	{
		switch (freq[1])
		{
		case 2:
			return FullHouse;
		default:
			return ThreeKind;
		}
		break;
	}
	case 2:
	{
		switch (freq[1])
		{
		case 2:
			return TwoPair;
		default:
			return OnePair;
		}
	}
	default:
		return HighCard;
	}
}

HandType classHand2(uint8_t* hand)
{
	uint8_t freq[15] = { 0 };
	uint8_t jokers = 0;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i] == 1)
		{
			jokers++;
			continue;
		}
		freq[hand[i]]++;
	}

	std::sort(std::begin(freq), std::end(freq));
	std::reverse(std::begin(freq), std::end(freq));

	int i = 0;
	while (jokers)
	{
		if (freq[i] == 5)
		{
			i++;
			continue;
		}
		freq[i]++;
		jokers--;
	}

	switch (freq[0])
	{
	case 5:
		return FiveKind;
	case 4:
		return FourKind;
	case 3:
	{
		switch (freq[1])
		{
		case 2:
			return FullHouse;
		default:
			return ThreeKind;
		}
		break;
	}
	case 2:
	{
		switch (freq[1])
		{
		case 2:
			return TwoPair;
		default:
			return OnePair;
		}
	}
	default:
		return HighCard;
	}
}

void Part1(void)
{
	std::priority_queue<Hand, std::vector<Hand>, handCompare> Hands;

	std::string line;
	std::fstream input("input.txt");

	while (input >> line)
	{
		Hand temp_hand;
		for (int i = 0; i < 5; i++)
		{
			switch (line[i])
			{
			case 'A':
				temp_hand.hand[i] = A;
				break;
			case 'K':
				temp_hand.hand[i] = K;
				break;
			case 'Q':
				temp_hand.hand[i] = Q;
				break;
			case 'J':
				temp_hand.hand[i] = J;
				break;
			case 'T':
				temp_hand.hand[i] = T;
				break;
			default:
				temp_hand.hand[i] = (Card1)(line[i] - '0');
				break;
			}
		}

		input >> temp_hand.bet;

		temp_hand.type = classHand((uint8_t*)temp_hand.hand);

		/*printf("Hand:\t %d %d %d %d %d\tBet:\t%d\tType:\t%d\n",
			temp_hand.hand[0],
			temp_hand.hand[1],
			temp_hand.hand[2],
			temp_hand.hand[3],
			temp_hand.hand[4],
			temp_hand.bet,
			temp_hand.type);*/

		Hands.push(temp_hand);
	}

	uint32_t total = 0;

	while (Hands.size())
	{
		/*printf("Hand:\t %d %d %d %d %d\tBet:\t%d\tType:\t%d\n",
			Hands.top().hand[0],
			Hands.top().hand[1],
			Hands.top().hand[2],
			Hands.top().hand[3],
			Hands.top().hand[4],
			Hands.top().bet,
			Hands.top().type);*/
		total += Hands.size() * Hands.top().bet;
		Hands.pop();
	}

	printf("total for part 1: %d\n", total);
}

void Part2(void)
{
	std::priority_queue<Hand, std::vector<Hand>, handCompare> Hands;

	std::string line;
	std::fstream input("input.txt");

	while (input >> line)
	{
		Hand temp_hand;
		for (int i = 0; i < 5; i++)
		{
			switch (line[i])
			{
			case 'A':
				temp_hand.hand[i] = A2;
				break;
			case 'K':
				temp_hand.hand[i] = K2;
				break;
			case 'Q':
				temp_hand.hand[i] = Q2;
				break;
			case 'J':
				temp_hand.hand[i] = J2;
				break;
			case 'T':
				temp_hand.hand[i] = T2;
				break;
			default:
				temp_hand.hand[i] = (Card2)(line[i] - '0');
				break;
			}
		}

		input >> temp_hand.bet;

		temp_hand.type = classHand2((uint8_t*)temp_hand.hand);

		/*printf("Hand:\t %d %d %d %d %d\tBet:\t%d\tType:\t%d\n",
			temp_hand.hand[0],
			temp_hand.hand[1],
			temp_hand.hand[2],
			temp_hand.hand[3],
			temp_hand.hand[4],
			temp_hand.bet,
			temp_hand.type);*/

		Hands.push(temp_hand);
	}

	uint32_t total = 0;

	while (Hands.size())
	{
		/*printf("Hand:\t %d %d %d %d %d\tBet:\t%d\tType:\t%d\n",
			Hands.top().hand[0],
			Hands.top().hand[1],
			Hands.top().hand[2],
			Hands.top().hand[3],
			Hands.top().hand[4],
			Hands.top().bet,
			Hands.top().type);*/
		total += Hands.size() * Hands.top().bet;
		Hands.pop();
	}

	printf("total for part 1: %d\n", total);
}



int main()
{
	Part1();
	Part2();
}