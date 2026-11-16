#include "words.h"

using namespace std;

void reverse(const char *input, char *output) {
    const char *p = input;
    int length = 0;
    while (*p) {
        length++;
        p++;
    }

    for (int i = 0; i < length; i++) {
        output[length-i-1] = input[i];
    }

    output[length] = '\0';
}

int compare(const char *one, const char *two) {
    while (*one && !isalpha(*one)) {
        one++;
    }
    while (*two && !isalpha(*two)) {
        two++;
    }

    if (!*one || !*two) {
        return !*one && !*two;
    } else if (isalpha(*one) && isalpha(*two) && tolower(*one) != tolower(*two)) {
        return 0;
    }
    
    return compare(one+1, two+1);
}

int palindrome(const char *input) {
    const char *p = input;
    int length = 0;
    while (*p) {
        length++;
        p++;
    }

    char reversed[length];
    reverse(input, reversed);

    return compare(input, reversed);
}

int anagram(const char *str1, const char *str2) {
    map<char, int> str1_chars;
    map<char, int> str2_chars;

    while (*str1) {
        if (isalpha(*str1)) {
            str1_chars[tolower(*str1)]++;
        }
        str1++;
    }

    while (*str2) {
        if (isalpha(*str2)) {
            str2_chars[tolower(*str2)]++;
        }
        str2++;
    }

    return str1_chars == str2_chars;
}
