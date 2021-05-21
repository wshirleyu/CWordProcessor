/* CS2211a 2020 */
/* Assignment 04 */
/* Shirley Wu */
/* 251082034 */
/* SWU546 */
/* NOV 10, 2020 */
#include "definitions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

line** inputFunc() {

    int sizeWordList = 0;
    text *wordList = (text *) calloc(1000, sizeof(text)); // memory array stores all words
    text **ptrWordList = &wordList; //pointer to memory array wordList

    int sizeSentList;
    line *sentList = (line *) calloc(1000, sizeof(line));
    line **ptrSentList; //pointer to memory array sentList

    char allInput[1000]; // master char array stores all char inputs
    int pos = 0; // tracks position of last char inputted into char array

    int lineCount = 0;
    while(1) {
        int charCount = 0;

        char *nullTest = (char *) calloc(100, sizeof(char)); // memory array to check for null input
        // do i need realloc here

        printf("Enter a String:  \n"); //prompt for user input
        fgets(nullTest, sizeof(nullTest), stdin); // read line
        // make last character of input '\0'
        int posInLine = 0;

        if (nullTest == '\0') {
            free(nullTest);
            break;
        } else {
            strcat(allInput, nullTest); // if the user input is not null or empty, concatenate to master char array
            free(nullTest); //reset the values that have been assigned to allocated memory of nullTest
        }

        // iterating through the master char array allInput
        for (int i = pos; i < strlen(allInput); i++) {
            // check if first char of latest input is a space
            if (!isspace(allInput[i])) {
                // create pointer to char at pos if not space
                char *charPtr = &allInput[i];
                posInLine++;
                pos++;
                charCount++;
                while (!isspace(allInput[pos])) {
                    pos++;
                    charCount++;
                    if (isspace(allInput[pos])) {
                        break;
                    }
                }
                // assign values to word structure
                wordList[sizeWordList].c = charPtr;
                wordList[sizeWordList].numChar = charCount;
                wordList[sizeWordList].position =
                        posInLine + 1; // ensure that you can't be at the 'zero-th' word in line

                // create pointer for first word in the input line
                // add pointer to sentence struct
                if (posInLine == 0) {
                    line *firstWord = &wordList[sizeWordList];
                    sentList[sizeSentList].word = firstWord;
                }
                posInLine++; // increase tracker of word position in the current input line
                // increase number of words in wordList memory
                sizeWordList++;

            } else {
                pos++;
            }
            // if the loop reaches a null char , the position of that char is the end of the input
            if (allInput[pos] == '\0') {
                // increase sentence counter
                lineCount++;
                // add values of sentence struct
                sentList[sizeSentList].numWords = posInLine + 1;
                sentList[sizeSentList].line = lineCount;
                sizeSentList++;
                break;
            }
        }
    }
    return ptrSentList;
}