/* CS2211a 2020 */
/* Assignment 04 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 10, 2020 */

#ifndef ASN4_DEFINITIONS_H
#define ASN4_DEFINITIONS_H
#include "ctype.h"
#endif //ASN4_DEFINITIONS_H

typedef struct word {
    char *c;    //pointer to a character
    int numChar;      // integer stores the number of characters in the word
    int position;    // inter to store position of the word in the sentence it's contained in
} text;     // alias for word struct


typedef struct sentence {
    struct word *word;// pointer to word construct
    int line; // integer storing the line number
    int numWords; // integer storing number of words in a line
} line; // alias for sentence struct

