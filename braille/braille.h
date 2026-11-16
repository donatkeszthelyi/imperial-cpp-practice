#ifndef BRAILLE_H
#define BRAILLE_H

#include <map>
#include <string>

/**
 * Encodes a single character into Braille.
 *
 * @param ch Character to encode.
 * @param braille Output array for the Braille encoding.
 * @return Number of characters encoded, or 0 if unsupported.
 */
int encode_character(const char ch, char *braille);

/**
 * Recursively encodes a plaintext string into Braille.
 *
 * @param plaintext String to encode.
 * @param braille Output array for the encoded string.
 */
void encode(const char *plaintext, char *braille);

/**
 * Prints the Braille representation of a plaintext string.
 *
 * @param plaintext String to encode and print.
 * @param output Output stream for the result.
 */
void print_braille(const char *plaintext, std::ostream &output);

#endif
