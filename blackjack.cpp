#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int getValue(const string& card) {
    if (card == "J" || card == "Q" || card == "K") {
        return 10;
    }
    if (card == "A") {
        return 11;
    }
    return stoi(card);
}

int handValue(const vector<string>& cards) {
    int total = 0;
    int aces = 0;

    for (const string& card : cards) {
        total += getValue(card);
        if (card == "A") {
            aces++;
        }
    }

    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}

vector<string> createDeck() {
    const vector<string> ranks = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
    };

    vector<string> deck;

    for (int suit = 0; suit < 4; suit++) {
        for (const string& rank : ranks) {
            deck.push_back(rank);
        }
    }

    return deck;
}

void showHand(const vector<string>& hand) {
    cout << "Your cards: ";

    for (size_t i = 0; i < hand.size(); i++) {
        cout << hand[i];
        if (i + 1 < hand.size()) {
            cout << ", ";
        }
    }

    cout << "\nCurrent total: " << handValue(hand) << "\n";
}

void showDrawOdds(const vector<string>& hand, const vector<string>& deck, size_t nextCard) {
    int safeCards = 0;
    int bustCards = 0;

    for (size_t i = nextCard; i < deck.size(); i++) {
        vector<string> testHand = hand;
        testHand.push_back(deck[i]);

        if (handValue(testHand) <= 21) {
            safeCards++;
        } else {
            bustCards++;
        }
    }

    int remaining = safeCards + bustCards;

    if (remaining == 0) {
        return;
    }

    double safeOdds = (static_cast<double>(safeCards) / remaining) * 100.0;
    double bustOdds = (static_cast<double>(bustCards) / remaining) * 100.0;

    cout << "\nSafe draw probability: " << safeOdds << "%\n";
    cout << "Bust probability: " << bustOdds << "%\n";

    if (safeCards > bustCards) {
        cout << "Probability-based suggestion: Hit.\n";
    } else {
        cout << "Probability-based suggestion: Stay.\n";
    }
}

int main() {
    random_device rd;
    mt19937 generator(rd());

    char playAgain = 'y';

    cout << "Blackjack Probability Game\n";

    while (tolower(playAgain) == 'y') {
        vector<string> deck = createDeck();
        shuffle(deck.begin(), deck.end(), generator);

        vector<string> hand;
        size_t nextCard = 0;

        hand.push_back(deck[nextCard++]);
        hand.push_back(deck[nextCard++]);

        cout << "\n------------------------------\n";
        showHand(hand);

        while (handValue(hand) < 21 && nextCard < deck.size()) {
            showDrawOdds(hand, deck, nextCard);

            char choice;
            cout << "\nDo you want to hit? (y/n): ";
            cin >> choice;

            if (tolower(choice) != 'y') {
                cout << "You stayed at " << handValue(hand) << ".\n";
                break;
            }

            string newCard = deck[nextCard++];
            cout << "You drew: " << newCard << "\n";
            hand.push_back(newCard);
            showHand(hand);

            if (handValue(hand) > 21) {
                cout << "You busted!\n";
            } else if (handValue(hand) == 21) {
                cout << "You hit 21!\n";
            }
        }

        cout << "\nPlay another round? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing Blackjack Probability Game!\n";
    return 0;
}
