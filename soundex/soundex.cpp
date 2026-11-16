#include <algorithm>
#include <iostream>
#include <cctype>
#include <map>
#include <vector>
#include <set>
#include <string>
#include "soundex.h"

using namespace std;

void encode(const char *surname, char *soundex) {
    map<char, char> codes = {
        {'b', '1'},
        {'f', '1'},
        {'p', '1'},
        {'v', '1'},
        {'c', '2'},
        {'g', '2'},
        {'j', '2'},
        {'k', '2'},
        {'q', '2'},
        {'s', '2'},
        {'x', '2'},
        {'z', '2'},
        {'d', '3'},
        {'t', '3'},
        {'l', '4'},
        {'m', '5'},
        {'n', '5'},
        {'r', '6'},
    };

    soundex[0] = (char)toupper(surname[0]);
    int outI = 1;
    int inI = 1;
    char prevChar = '\0';
    while (outI < 4 && surname[inI]) {
        if (codes.count(tolower(surname[inI])) 
                && (codes.count(prevChar) == 0 
                || codes.at(prevChar) != codes.at(tolower(surname[inI])))) {
            soundex[outI] = codes[tolower(surname[inI])];
            outI++;
            prevChar = tolower(surname[inI]);
        }
        inI++;
    }
    while (outI < 4) {
        soundex[outI] = '0';
        outI++;
    }
    soundex[4] = '\0';
}

int compare(const char *one, const char *two) {
    if (!*one && !*two) {
        return 1;
    }
    if (*one == *two) {
        return compare(one+1, two+1);
    } else {
        return 0;
    }
}

int count(const char *surname, const string sentence) {
    vector<string> soundexes;

    string word;
    char soundex[5];

    for (char c : sentence) {
        if (ispunct(static_cast<unsigned char>(c)) ||
            isspace(static_cast<unsigned char>(c))) {

            if (!word.empty()) {
                encode(word.c_str(), soundex);
                soundexes.push_back(soundex);
                word.clear();
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        encode(word.c_str(), soundex);
        soundexes.push_back(soundex);
    }
    char surnameCode[5];
    encode(surname, surnameCode);

    return std::count(
        soundexes.begin(),
        soundexes.end(),
        string(surnameCode)
    );
}
