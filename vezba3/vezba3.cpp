/**
 *
 *
 *  Created by Stefan Najdovski on 28.2.23.
 * Karti - 52 obicni + 2 jokeri - vezba 2
 *
 **/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 52 obicni + 2 jokeri
// 13 karti po 4 boi
const int DECK_SIZE = 54;
const int SUIT_SIZE = 13;

//dodadeni se jokerite kako posebni elementi vo nizata
string suits[6] = {"Hearts", "Diamonds", "Clubs", "Spades","Joker Red","Joker Black"};

string ranks[SUIT_SIZE] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

void radixSort(string arr[], int n, int maxLen) {
    // Kreiraj niza od vektori, eden vektor za sekoja bukva, od 0 do 255 (ASCII)
    const int numBuckets = 256; // ASCII ima 256 bukvi
    vector<string> buckets[numBuckets]; // niza od vektori

    // Iteriraj od desno na levo, od poslednata bukva do prva
    for (int pos = maxLen - 1; pos >= 0; --pos) {
        // Distributiraj gi stringovite vo vektorite bazirani na bukvata na toj index
        for (int i = 0; i < n; ++i) {
            int bucketIndex = (int)arr[i][pos];
            buckets[bucketIndex].push_back(arr[i]);
        }
        //Kopiraj gi stringovite od vektorite nazad vo nizata po redosled
        int i = 0;
        for (int bucketIndex = 0; bucketIndex < numBuckets; ++bucketIndex) {
            for (string& str : buckets[bucketIndex]) {
                arr[i++] = str;
            }
            // clear funkcijata go prazni vektorot i go resetira na 0 elementi
            buckets[bucketIndex].clear();
        }
    }
}

void shuffleDeck(string deck[], int size) {
    for (int i = 0; i < size; i++) {
        //posle iteracija okolu site karti, so int j = rand() % size; generirame random broj od 0 do size, i potoa
        // go zamenuvame elementot na pozicija i so elementot na pozicija j, taka dobivame efekt na izmesuvanje na karti
        int j = rand() % size;
        // swap funkcija od string header, namesto da korstime temp promenliva
        swap(deck[i], deck[j]);
    }
}
int main() {
    //inicijalizacija na nizata
    string deck[DECK_SIZE];
    int index = 0;
    // od index 0,4 se obicnite karti, 5 i 6 se jokerite i ne sakame da imame poveke od dva jokera
    for (int i = 0; i < 4; i++) {
        //za sekoja boja, gi dodavame site karti
        for (int j = 0; j < SUIT_SIZE; j++) {
            deck[index] = ranks[j] + " of " + suits[i];
            index++;
        }
    }
    //gi doavame jokerite kako specijalno baranje

    deck[index] = "Joker Red";
    index++;
    deck[index] = "Joker Black";


    //ja sortira nizata po rastecki redosled
    //sort e funkcija od algoritmi header fajlot koja zema 2 argumenti, prviot e iterator na pocetokot na nizata
    // a vtoriot e iterator na krajot na nizata

    sort(deck, deck + DECK_SIZE);

    // ispecati gi site karti vo redosled
    for (int i = 0; i < DECK_SIZE; i++) {
        cout << deck[i] << endl;
    }
    // prazni redovi za da se razdvoi od pecatenjeto na izmesanite karti
    std::puts("");
    std::puts("");
    std::puts("Izmesani karti:");
    std::puts("");
    std::puts("");

    // srand e funkcija od cstdlib header fajlot koja se koristi za generiranje na random broevi, null e argument
    // koj go koristi za da generira random broj, taka sto go koristi segasnoto vreme na sistemot
    srand(time(NULL)); // seed random number generator
    // ja povikuvame funkcijata za izmesuvanje na kartite
    shuffleDeck(deck, DECK_SIZE);
    // gi pecatime kartite vo izmesen redosled
    for (int i = 0; i < DECK_SIZE; i++) {
        cout << deck[i] << endl;
    }

    std::puts("");
    std::puts("");
    std::puts("Podredeni karti so radix Sort:");
    std::puts("");
    std::puts("");

    // Najdi najgolemata dolzina na string vo nizata
    int maxLen = 0;
    for (int i = 0; i < DECK_SIZE; ++i) {
        maxLen = max(maxLen, (int)deck[i].size());
    }

    // Sortiraj gi kartite so radix sort
    radixSort(deck, DECK_SIZE, maxLen);

    for (int i = 0; i < DECK_SIZE; i++) {
        cout << deck[i] << endl;
    }

    return EXIT_SUCCESS;
}
