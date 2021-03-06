// Learning Application 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <random>

enum CardRanks
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANK
};

enum Suits
{
	SUITE_CLUB,
	SUITE_DIAMOND,
	SUITE_HEART,
	SUITE_SPADE,
	MAX_SUITE
};

struct Card
{
	CardRanks rank;
	Suits suite;
};

void printCard(Card card)
{
	switch (card.rank)
	{
	case RANK_2:
		std::cout << "2";
		break;
	case RANK_3:
		std::cout << "3";
		break;
	case RANK_4:
		std::cout << "4";
		break;
	case RANK_5:
		std::cout << "5";
		break;
	case RANK_6:
		std::cout << "6";
		break;
	case RANK_7:
		std::cout << "7";
		break;
	case RANK_8:
		std::cout << "8";
		break;
	case RANK_9:
		std::cout << "9";
		break;
	case RANK_10:
		std::cout << "10";
		break;
	case RANK_JACK:
		std::cout << "J";
		break;
	case RANK_QUEEN:
		std::cout << "Q";
		break;
	case RANK_KING:
		std::cout << "K";
		break;
	case RANK_ACE:
		std::cout << "A";
		break;
	default:
		std::cout << "U";
		break;
	}
	switch (card.suite)
	{
	case SUITE_CLUB:
		std::cout << "C";
		break;
	case SUITE_DIAMOND:
		std::cout << "D";
		break;
	case SUITE_HEART:
		std::cout << "H";
		break;
	case SUITE_SPADE:
		std::cout << "S";
		break;
	default:
		std::cout << "U";
		break;
	}
}

void printDeck(std::array<Card, 52>(&cardDeck))
{
	for (const auto &card : cardDeck)
	{
		printCard(card);
		std::cout << "\n";
	}
}

void swapCard(Card &card1, Card &card2)
{
	Card temp;
	temp = card1;
	card1 = card2;
	card2 = temp;
}

void shuffleDeck(std::array<Card, 52>(&cardDeck))
{
	for (auto i = 0; i < 52; i++)
	{
		std::random_device rd;
		std::mt19937 mersenne{ rd() };
		const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
		const int randomNumber = 0 + static_cast<int>((51 - 0 + 1) * (mersenne() * fraction));
		swapCard(cardDeck[i], cardDeck[randomNumber]);
	}
}

int getCardValue(Card &card)
{
	switch (card.rank)
	{
	case RANK_2:
		return 2;
		break;
	case RANK_3:
		return 3;
		break;
	case RANK_4:
		return 4;
		break;
	case RANK_5:
		return 5;
		break;
	case RANK_6:
		return 6;
		break;
	case RANK_7:
		return 7;
		break;
	case RANK_8:
		return 8;
		break;
	case RANK_9:
		return 9;
		break;
	case RANK_10:
		return 10;
		break;
	case RANK_JACK:
		return 10;
		break;
	case RANK_QUEEN:
		return 10;
		break;
	case RANK_KING:
		return 10;
		break;
	case RANK_ACE:
		return 11;
		break;
	default:
		return 0;
		break;
	}
}

std::string hitStandInput(short &playerScore)
{
	while (true)
	{
		std::cout << "Will you hit or stand? | Your score is " << playerScore << "\n";
		std::string hitStand;
		std::cin >> hitStand;
		if (std::cin.fail() || hitStand != "Stand" && hitStand != "stand" && hitStand != "Hit" && hitStand != "hit" && hitStand != "0" && hitStand != "s" && hitStand != "S" && hitStand != "h" && hitStand != "H")
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return hitStand;
		}
	}
}

/*bool aiPercentageCalculations(short &index, const short &dealerScore, const short &playerScore)
{
	if (dealerScore < 11)
	{
		return false;
	}
	if (dealerScore < playerScore)
	{
		return false;
	}
	short percentage = ((21 - dealerScore - 1) * 4 * 100) / (52 - index);
	if (percentage < 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

bool aiPercentageCalculations(short &index, const short &dealerScore, const short &playerScore, std::array<Card, 52>(&cardDeck))
{
	if (dealerScore < 11 || dealerScore < playerScore)
	{
		return false;
	}
	if (dealerScore == 21 || dealerScore == 20)
	{
		return true;
	}
	short length = 21 - dealerScore - 1;
	double percentage = 0;
	for (auto i = 2; i < length + 2; i++)
	{
		short howManyThere = 0;
		for (auto b = 0; b < index; b++)
		{
			if (getCardValue(cardDeck[b]) == i)
			{
				howManyThere++;
			}
		}
		percentage += ((4 - howManyThere) * 100) / (52 - index);
	}
	if (percentage > 50)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool playBlackjack(std::array<Card, 52>(&cardDeck))
{
	short playerScore = 0;
	short dealerScore = 0;
	bool hitOrStand = 0;
	short whichIndex = 0;
	Card *cardPtr = &cardDeck[0];
	std::cout << "The player draws two cards...\n";
	std::cout << "The player drew a card with the value " << getCardValue(*cardPtr);
	playerScore += getCardValue(*cardPtr++);
	whichIndex++;
	std::cout << " and another card with the value of " << getCardValue(*cardPtr) << "!\n\n";
	playerScore += getCardValue(*cardPtr++);
	whichIndex++;
	if (playerScore == 22)
	{
		std::cout << "Do to the fact that the player drew two aces, one ace will have the value 1.\n\n";
		playerScore -= 10;
	}
	std::cout << "The dealer draws a card...\n";
	std::cout << "The dealer drew a card with the value " << getCardValue(*cardPtr) << "!\n\n";
	dealerScore += getCardValue(*cardPtr++);
	whichIndex++;
	if (playerScore == 21)
	{
		std::cout << "You got a blackjack!\n";
		return true;
	}
	std::string hitStand = hitStandInput(playerScore);
	if (hitStand == "Stand" || hitStand == "stand" || hitStand == "s" || hitStand == "S")
	{
		hitOrStand = 1;
		std::cout << "The player decides to stand...\n\n";
	}
	if (hitStand == "0")
	{
		return false;
	}
	while (true)
	{
		if (hitOrStand == 0)
		{
			std::cout << "The player draws a card...\n";
			std::cout << "The player drew a card with the value " << getCardValue(*cardPtr) << "\n";
			playerScore += getCardValue(*cardPtr);
			if (cardPtr->rank == RANK_ACE && playerScore > 21)
			{
				std::cout << "Do to the fact that the player drew an ace, while his max score exceeds 21, the ace will have the value 1.\n\n";
				playerScore -= 10;
			}
			*cardPtr++;
			whichIndex++;
			if (playerScore > 21)
			{
				std::cout << "Your score has reached past 21!\n\n";
				return false;
			}
			hitStand = hitStandInput(playerScore);
			if (hitStand == "Stand" || hitStand == "stand" || hitStand == "s" || hitStand == "S")
			{
				hitOrStand = 1;
				std::cout << "The player decides to stand...\n\n";
			}
			if (hitStand == "0")
			{
				return false;
			}
		}
		bool dealerStand = false;
		if (dealerStand == false)
		{
			dealerStand = aiPercentageCalculations(whichIndex, dealerScore, playerScore, cardDeck);
		}
		if (dealerStand == true)
		{
			std::cout << "The dealer has decided to stand.\n\n";
		}
		if (dealerStand == false)
		{
			std::cout << "The dealer draws a card...\n";
			std::cout << "The dealer drew a card with the value " << getCardValue(*cardPtr) << "! ";
			dealerScore += getCardValue(*cardPtr);
			std::cout << "The dealers score is now " << dealerScore << "\n\n";
			if (cardPtr->rank == RANK_ACE && dealerScore > 21)
			{
				std::cout << "Do to the fact that the dealer drew an ace, while his max score exceeds 21, the ace will have the value 1.\n\n";
				dealerScore -= 10;
			}
		}
		*cardPtr++;
		whichIndex++;
		if (dealerScore > 21)
		{
			std::cout << "The dealers score is higher then 21!\n";
			return true;
		}
		if (hitOrStand == 1 && dealerStand == true)
		{
			std::cout << "Both the player and the dealer stand. Here are the final results...\n";
			std::cout << "Player: " << playerScore << " | Dealer: " << dealerScore << "\n";
			if (playerScore > dealerScore)
			{
				std::cout << "The players score is nearer to 21 then the dealers score!\n";
				return true;
			}
			else if (playerScore == dealerScore)
			{
				std::cout << "The players score is the same as the dealers score!\n";
				return false;
			}
			std::cout << "Sadly the dealers score is closer to 21 then the players score.\n";
			return false;
		}
	}
}

int main()
{
	std::array<Card, 52>(cardDeck);
	int b = 0;
	for (int suite = 0; suite < static_cast<int>(MAX_SUITE); suite++)
	{
		for (int rank = 0; rank < static_cast<int>(MAX_RANK); rank++)
		{
			cardDeck[b].suite = static_cast<Suits>(suite);
			cardDeck[b].rank = static_cast<CardRanks>(rank);
			b++;
		}
	}
	while (true)
	{
		shuffleDeck(cardDeck);
		bool lossOrWin = playBlackjack(cardDeck);
		if (lossOrWin == true)
		{
			std::cout << "Well done you Win!\n";
		}
		else if (lossOrWin == false)
		{
			std::cout << "You lose.\n";
		}
		std::string answer;
		while (true)
		{
			std::cout << "\nDo you want to play again?\n";
			std::cin >> answer;
			if (std::cin.fail() || answer != "Yes" && answer != "yes" && answer != "No" && answer != "no")
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
			{
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		if (answer == "No" || answer == "no")
		{
			return 0;
		}
	}
}