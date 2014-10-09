#include <iostream>

#include "lexicon.h"
#include "simpio.h"
#include "set.h"
#include "console.h"

using namespace std;

static void printOutTwiddle(const string& originalWord, string prefix, char currentLetter, int index, const Lexicon& lexicon);
static void printOutTwiddles(const string& word, const Lexicon& lexicon);
static bool isLetter(char c);

int main() {
    Lexicon lexicon("EnglishWords.dat");
    string word;

    word = getLine("Please enter the word: ");

    cout << "The twiddles of " << word << " are: " << endl;
    printOutTwiddles(word, lexicon);

    return 0;
}

void printOutTwiddles(const string& word, const Lexicon& lexicon) {
    printOutTwiddle(word, "", word.at(0) - 2, 0, lexicon);
}

void printOutTwiddle(const string& originalWord, string prefix, char currentLetter, int index, const Lexicon& lexicon) {
    cerr << prefix << endl;
    if (isLetter(currentLetter)) {
        if (index >= originalWord.size() - 1) {
            string newWord = prefix + currentLetter;
            cerr << newWord << endl;
            if (lexicon.contains(newWord)) {
                cout << newWord << endl;
            }
        } else if (lexicon.containsPrefix(prefix)) {
            printOutTwiddle(originalWord, prefix + currentLetter, originalWord.at(index + 1) - 2, index + 1, lexicon);
        }
    }

    if (originalWord.at(index) + 2 >= currentLetter) {
        printOutTwiddle(originalWord, prefix, currentLetter + 1, index, lexicon);
    }
}

bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
}
