# Blackjack Card Game

## Overview
This is a simple implementation of the classic card game **Blackjack** written in C++. The program simulates a game where a player competes against a dealer, following standard Blackjack rules.

## Features
- Representation of a full deck of 52 playing cards using `struct` and `enum`.
- Shuffling and dealing of cards.
- Implementation of player and dealer moves.
- Determination of the game outcome (win, loss, or draw).
- Console-based interaction for user input.

## Game Rules
1. The player and dealer are each dealt cards.
2. The player can choose to **Hit** (take another card) or **Stand** (keep the current hand).
3. If the player exceeds a total of **21**, they lose automatically (Bust).
4. The dealer will draw cards until their total is **17** or higher.
5. The winner is determined based on who has the closest score to **21** without exceeding it.
6. If both have the same score, the game is a draw.

## How to Run
1. **Compile the program** using a C++ compiler:
   ```sh
   g++ -o blackjack.cpp
   ```
2. **Run the executable**:
   ```sh
   ./blackjack
   ```

## Code Structure
- `enum CardSuit` - Defines the suits of a deck (Clubs, Diamonds, Hearts, Spades).
- `enum CardRank` - Defines the ranks of cards (2 to Ace).
- `struct Card` - Represents a card with a rank and suit.
- `void printCard(const Card &card)` - Prints the value and suit of a card.
- `void shuffleDeck(std::array<Card, 52> &deck)` - Shuffles the deck randomly.
- `int getCardValue(const Card &card)` - Returns the value of a card for Blackjack rules.
- `BlackjackResult playBlackjack(const std::array<Card, 52> &deck)` - Implements the game logic.
- `int main()` - The entry point where the deck is initialized, shuffled, and the game is started.

## Future Improvements
- Add support for betting and multiple rounds.
- Implement AI for a smarter dealer.
- Add multiplayer functionality.

## License
This project is open-source and can be used freely.

---
**Author:** Oleksandr Onupko
