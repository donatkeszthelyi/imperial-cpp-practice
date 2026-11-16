#ifndef WORDS_H
#define WORDS_H

#include <cctype>
#include <map>

void reverse(const char *input, char *output);

int compare(const char *one, const char *two);

int palindrome(const char *input);

int anagram(const char *str1, const char *str2);

#endif
