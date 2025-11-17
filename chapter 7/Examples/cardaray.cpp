// cardaray.cpp
// cards as objects

#include <iostream>
#include <cstdlib>   // for srand(), rand()
#include <ctime>     // for time() used in srand()
using namespace std;

// define the four suits
enum Suit { clubs, diamonds, hearts, spades };

// define special card numbers
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

//////////////////////////////////////////////////////////////
class card
{
private:
    int number;  // 2–10, jack, queen, king, ace
    Suit suit;   // clubs, diamonds, hearts, spades

public:
    card() { }  // constructor (does nothing here)

    void set(int n, Suit s)  // sets card number and suit
    {
        number = n;
        suit = s;
    }

    void display();  // shows card on screen
};
//////////////////////////////////////////////////////////////

void card::display()
{
    // show card number or letter
    if (number >= 2 && number <= 10)
        cout << number;
    else
        switch (number)
        {
        case jack: cout << "J"; break;
        case queen: cout << "Q"; break;
        case king: cout << "K"; break;
        case ace: cout << "A"; break;
        }

    // show card suit using symbols
    switch (suit)
    {
    case clubs: cout << static_cast<char>(5); break;
    case diamonds: cout << static_cast<char>(4); break;
    case hearts: cout << static_cast<char>(3); break;
    case spades: cout << static_cast<char>(6); break;
    }
}
//////////////////////////////////////////////////////////////

int main()
{
    card deck[52];  // array of 52 card objects
    int j;

    // make an ordered deck
    for (j = 0; j < 52; j++)
    {
        int num = (j % 13) + 2;   // 2..14 (2..Ace)
        Suit su = Suit(j / 13);   // 0..3 (4 suits)
        deck[j].set(num, su);     // set number and suit
    }

    cout << "\nOrdered deck:\n";
    for (j = 0; j < 52; j++)
    {
        deck[j].display();
        cout << " ";
        if (!((j + 1) % 13))   // new line every 13 cards
            cout << endl;
    }

    // Shuffle the deck
    srand(time(NULL));   // seed random numbers

    for (j = 0; j < 52; j++)
    {
        int k = rand() % 52;  // pick random position
        card temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }

    cout << "\nShuffled deck:\n";
    for (j = 0; j < 52; j++)
    {
        deck[j].display();
        cout << ", ";
        if (!((j + 1) % 13))
            cout << endl;
    }

    return 0;
}
