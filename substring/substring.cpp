#include "substring.h"
#include <cstring>

using namespace std;

int substring_position(const char* first_string, const char* second_string) {
    const char* start_of_first = first_string;
    const char* start_of_match = nullptr;
    int first_string_length = 0;
    int second_string_length = 0;

    while (*second_string && *first_string) {
        if (*second_string == *first_string) {
            start_of_match = start_of_match ? start_of_match : second_string;
            second_string++;
            first_string++;
            first_string_length++;
        } else {
            first_string = start_of_first;
            second_string = start_of_match ? start_of_match : second_string;
            start_of_match = nullptr;
            second_string_length -= first_string_length;
            first_string_length = 0;
            second_string++;
        }
        second_string_length++;
    }
    
    if (!*first_string) {
        return second_string_length - first_string_length;
    }
    return -1;
}

int substring_position2(const char* f, const char* s) {
    return strstr(s,f)?strstr(s,f)-s:-1;
}

