# Blackjack Probability Game

A C++ console Blackjack program that calculates the probability of safely drawing another card and provides a suggestion to hit or stay based on probability.

## Features

- Builds and shuffles a 52-card deck
- Deals an initial hand of two cards
- Calculates Blackjack hand values
- Handles Aces as either 11 or 1 when needed
- Calculates the percentage of remaining cards that are safe or would cause a bust
- Provides a suggestion to hit or stay based on probability
- Allows multiple hits during a round
- Supports multiple rounds

## Technologies

- C++17
- Standard Template Library (STL)
- `vector`
- `shuffle`
- `random`

## How to Compile and Run

Using g++:

```bash
g++ -std=c++17 blackjack.cpp -o blackjack
./blackjack
```

On Windows:

```bash
g++ -std=c++17 blackjack.cpp -o blackjack.exe
blackjack.exe
```

## Example

```text
Blackjack Probability Game

Your cards: 7, 8
Current total: 15

Safe draw probability: 61.11%
Bust probability: 38.89%
Probability-based suggestion: Hit.

Do you want to hit? (y/n):
```

The suggestion is based only on whether the remaining cards would keep the player's hand at or below 21. It is not a complete Blackjack strategy engine and does not model a dealer's hand.

## Project Structure

```text
blackjack-probability-game/
├── blackjack.cpp
├── README.md
└── .gitignore
```

## About

This project demonstrates C++ fundamentals including functions, vectors, loops, conditionals, randomization, probability calculations, and state management.
