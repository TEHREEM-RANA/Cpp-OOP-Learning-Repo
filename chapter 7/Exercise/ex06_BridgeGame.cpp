// 6. In the game of contract bridge, each of four players is dealt 13 cards, thus exhausting the
// entire deck. Modify the CARDARAY program in this chapter so that, after shuffling the
// deck, it deals four hands of 13 cards each. Each of the four players’ hands should then be
// displayed.
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card {
private:
    string suit;
    string rank;

public:
    // Constructor
    Card(string r = "", string s = "") : rank(r), suit(s) {}

    // Destructor
    ~Card() {
        // Just for demonstration
    }

    // Getters
    string getSuit() const { return suit; }
    string getRank() const { return rank; }

    // Setters
    void setSuit(string s) { suit = s; }
    void setRank(string r) { rank = r; }

    // Display card
    void display() const {
        cout << rank << " of " << suit;
    }
};

class Deck {
private:
    Card cards[52];

public:
    // Constructor
    Deck() {
        string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

        int index = 0;
        for (int s = 0; s < 4; s++) {
            for (int r = 0; r < 13; r++) {
                cards[index++] = Card(ranks[r], suits[s]);
            }
        }
    }

    // Destructor
    ~Deck() {
        cout << "Deck destroyed.\n";
    }

    // Shuffle the deck
    void shuffle() {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < 52; i++) {
            int r = rand() % 52;
            Card temp = cards[i];
            cards[i] = cards[r];
            cards[r] = temp;
        }
    }

    // Deal cards to 4 players
    void deal() {
        cout << "\nDealing cards...\n\n";
        for (int player = 0; player < 4; player++) {
            cout << "Player " << player + 1 << " hand:\n";
            for (int card = 0; card < 13; card++) {
                cards[player * 13 + card].display();
                cout << endl;
            }
            cout << "-----------------------\n";
        }
    }
};

int main() {
    Deck deck;
    deck.shuffle();
    deck.deal();
    return 0;
}
