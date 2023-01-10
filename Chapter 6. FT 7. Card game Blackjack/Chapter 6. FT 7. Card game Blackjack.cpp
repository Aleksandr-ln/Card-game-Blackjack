#include <iostream>
#include <array>
#include <cstdlib> //для функций rand() и srand()
#include <ctime> //для функции time()

//Колода карт представлена перечеслениями масти и их достоинством
enum CardSuit
{
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_HEARTS,
    SUIT_SPADES,
    MAX_SUITS
};

enum CardRank
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

enum BlackjackResult
{
    BLACKJACK_PLAYER_WIN,
    BLACKJACK_DEALER_WIN,
    BLACKJACK_DRAW
};

//Каждая карта в колоде представлена структурой, где хранится информация о достоинстве и масти карты
struct Card
{
    CardRank rank;
    CardSuit suit;
};

//Вывод значения достоинства и масти определенной карты
void printCard(const Card &card)
{
    switch (card.rank)
    {
    case RANK_2:    std::cout << "2"; break;
    case RANK_3:    std::cout << "3"; break;
    case RANK_4:    std::cout << "4"; break;
    case RANK_5:    std::cout << "5"; break;
    case RANK_6:    std::cout << "6"; break;
    case RANK_7:    std::cout << "7"; break;
    case RANK_8:    std::cout << "8"; break;
    case RANK_9:    std::cout << "9"; break;
    case RANK_10:    std::cout << "10"; break;
    case RANK_JACK:    std::cout << "J"; break;
    case RANK_QUEEN:    std::cout << "Q"; break;
    case RANK_KING:    std::cout << "K"; break;
    case RANK_ACE:    std::cout << "A"; break;
    }

    switch (card.suit)
    {
    case SUIT_CLUBS:    std::cout << "C"; break;
    case SUIT_DIAMONDS:    std::cout << "D"; break;
    case SUIT_HEARTS:    std::cout << "H"; break;
    case SUIT_SPADES:    std::cout << "S"; break;
    }
}

//Вывод всей колоды карт
void printDeck(const std::array<Card, 52>& deck)
{
    for (const auto &i : deck)
    {
        printCard(i);
        std::cout << ' ';
    }
    std::cout << '\n';
}

//Замена местами значений двух карт
void swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//Перетасовка колоды карт
void shuffleDeck(std::array<Card, 52> &deck)
{
    for (int i = 0; i < 52; ++i)
    {
        int rundomNumber = getRandomNumber(0, 51);
        swapCard(deck[i], deck[rundomNumber]);
    }
}

//Получение значения карты
int getCardValue(const Card &card)
{
    switch (card.rank)
    {
    case RANK_2:    return 2;
    case RANK_3:    return 3;
    case RANK_4:    return 4;
    case RANK_5:    return 5;
    case RANK_6:    return 6;
    case RANK_7:    return 7;
    case RANK_8:    return 8;
    case RANK_9:    return 9;
    case RANK_10:    return 10;
    case RANK_JACK:    return 10;
    case RANK_QUEEN:    return 10;
    case RANK_KING:    return 10;
    case RANK_ACE:    return 11;
    }

    return 0;
}


BlackjackResult playBlackjack(const std::array<Card, 52> &deck)
{
    const Card *cardPtr = &deck[0];

    //раздача карт игроку и дилеру
    int dealerScore = getCardValue(*cardPtr++);
    int playerScore = getCardValue(*cardPtr++) + getCardValue(*cardPtr++);
    int choice;

    //ход игрока
    do
    {
        std::cout << "DealerScore: " << dealerScore << std::endl;
        std::cout << "PlayerScore: " << playerScore << std::endl;
        std::cout << "Please make a selection: \n";
        std::cout << "1) Hit\n";
        std::cout << "2) Stand\n";
        std::cin >> choice;
        if (choice == 1)
        {
            playerScore += getCardValue(*cardPtr++);
        }
    } while (choice != 2 && playerScore <= 21);

    if (playerScore>21)
    {
        std::cout << "PlayerScore: " << playerScore << std::endl;
        return BLACKJACK_DEALER_WIN;
    }

    //Ход дилера
    while (dealerScore < 17)
    {
        dealerScore += getCardValue(*cardPtr++);
        std::cout << "DealerScore: " << dealerScore << std::endl;
    }

    std::cout << "PlayerScore: " << playerScore << std::endl;

    if (playerScore > dealerScore)
    {
        return BLACKJACK_PLAYER_WIN;
    }
    else if (dealerScore > 21)
    {
        return BLACKJACK_PLAYER_WIN;
    }
    else if (dealerScore > playerScore)
    {
        return BLACKJACK_DEALER_WIN;
    }
    else if (playerScore == dealerScore)
    {
        return BLACKJACK_DRAW;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавка значения системных часов в качестве стартового числа для генерации СЧ
    rand(); // Первый вызов rand() для сброса результата этой функции (для большего отличия первого рандомного числа от стартового)

    //Представление целой колоды карт
    std::array<Card, 52> deck{ };

    int card = 0;
    for (int i = 0; i < MAX_RANK; ++i)
        for (int j = 0; j < MAX_SUITS; ++j)
        {
            deck[card].rank = static_cast<CardRank>(i);
            deck[card].suit = static_cast<CardSuit>(j);
            ++card;
        }

    //Перетасовка колоды карт
    shuffleDeck(deck);

    int result = playBlackjack(deck);

    if (result == BLACKJACK_PLAYER_WIN)
    {
        std::cout << "The player win!\n";
    }
    else if (result == BLACKJACK_DEALER_WIN)
    {
        std::cout << "The dealer win!\n";
    }
    else if (result ==  BLACKJACK_DRAW)
    {
        std::cout << "It's a draw!\n";
    }

}

