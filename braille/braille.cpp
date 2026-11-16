#include "braille.h"
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

int encode_character(const char ch, char *braille) {
    // Map to store the minimal characters needed
    map<char, string> braille_map{
        {'a', "0....."}, 
        {'b', "00...."}, 
        {'c', "0..0.."}, 
        {'d', "0..00."}, 
        {'e', "0...0."}, 
        {'f', "00.0.."}, 
        {'g', "00.00."}, 
        {'h', "00..0."}, 
        {'i', ".0.0.."}, 
        {'j', ".0.00."},
        {'.', ".0..00"}, 
        {',', ".0...."}, 
        {';', ".00..."}, 
        {'-', "..0..0"}, 
        {'!', ".00.0."}, 
        {'?', ".00..0"},
        {'(', ".00.00"},
        {')', ".00.00"},
    };
    
    char c = ch;
    char prefix[13];
    bool capital = false;
    bool number = false;
    
    // If the character is a uppercase, flag it and create prefix
    if (isupper(ch)) {
        c = tolower(ch);
        strcpy(prefix, ".....0");
        capital = true;
    }

    // If the character is a digit, flag it and create prefix
    if (isdigit(ch)) {
        strcpy(prefix, "..0000");
        c = (ch == '0') ? 'j' : ch + 48;
        number = true;
    }

    // Loop throught the braille map value characters
    for (int i = 0; i < 6; i++) { 
        // Store character as temp to do conversion on it
        // in each loop (so we do not have to double check
        // the conditions)
        char temp = c;
        // If in braille map
        if (braille_map.find(temp) != braille_map.end()) {
            braille[i] = braille_map[temp][i];
        // If not in braille map, do conversion
        } else if (temp >= 'k' && temp <= 't') {
            temp -= 10; 
            if (i == 2) {
                braille[i] = '0';
            } else {
                braille[i] = braille_map[temp][i];
            }
        } else if (temp >= 'u' && temp <= 'z') {
            if (temp >= 'u' && temp <= 'v') {
                temp -= 20;
            } else if (temp == 'w') {
                temp -= 13;
            } else if (temp >= 'x' && temp <= 'z') {
                temp -= 21;
            }
            if (i == 2) {
                braille[i] = '0';
            } else if (i == 5) {
                braille[i] = '0';
            } else {
                braille[i] = braille_map[temp][i];
            }
        } else {
            return 0; // Unknown characters don't get encoded
        }
    }
    braille[6] = '\0';

    // Append prefix if needed
    if (capital) {
        strcpy(braille, strcat(prefix, braille));
        return 12;
    } else if (number) {
        strcpy(braille, strcat(prefix, braille));
        return 12;
    } else {
        return 6;
    }
}

void encode(const char *plaintext, char *braille) {
    // Base case is when the plaintext ends 
    if (!plaintext || !*plaintext) {
        *braille = '\0';
        return;
    }

    // Get length of the returned braille encoding
    int length = encode_character(*plaintext, braille);

    // Recursive call with the rest of the text
    return encode(plaintext+1, braille+length);
}

void print_braille(const char *plaintext, ostream &output) {
    char temp_output[256];
    encode(plaintext, temp_output);
    int length = strlen(temp_output); // Raw encoded braille length
    int input_length = strlen(plaintext); // Input text length

    // Loop to print the formatted encoded braille text
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < length; i += 6) {
            output << temp_output[i + j];
            output << temp_output[i + j + 3];
            output << ' ';
        }
        output << '\n';
    }
    
    // Loop to print input text under the braille text
    for (int letter = 0; letter < input_length; letter++) {
        // If there is a prefix, jump to the next character
        if (isupper(*plaintext) || isdigit(*plaintext)) {
            output << "   ";
        }
        output << *plaintext << "  ";
        plaintext++;
    }
    output << endl;
}
