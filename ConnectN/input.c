#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "input.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do {
    scanf("%c", &character);
    if (!isspace(character)) {
      formatIsGood = false;
    }
  } while(character != '\n');
  return formatIsGood;
}

bool inBetween(int val, int lowerBound, int upperBound) {
  return val >= lowerBound && val <= upperBound;
}

int getValidInt(const char* prompt) {
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do {
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num);
  } while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

int getValidIntInRange(int lowerBound, int upperBound) {
  int num;
  do {
    printf("Enter a column between %d and %d to play in: ", lowerBound, upperBound);
    num = getValidInt("");
  } while(!(inBetween(num, lowerBound, upperBound)));

  return num;
}
