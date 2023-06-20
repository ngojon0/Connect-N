#ifndef INPUT_GAME
#define INPUT_GAME

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool inBetween(int val, int lowerBound, int upperBound);
int getValidInt(const char* prompt);
int getValidIntInRange(int lowerBound, int upperBound);

#endif
