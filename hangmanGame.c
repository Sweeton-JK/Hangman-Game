#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int playHangman(char* word) {
    int wordLength = strlen(word);
    char guessedLetters[MAX_WORD_LENGTH];
    int tries = 0;
    int correctGuesses = 0;

    for (int i = 0; i < wordLength; i++) {
        guessedLetters[i] = '_';
    }
    guessedLetters[wordLength] = '\0';

    while (tries < MAX_TRIES && correctGuesses < wordLength) {
        printf("\nCurrent word: %s\n", guessedLetters);
        printf("Tries remaining: %d\n", MAX_TRIES - tries);

        printf("Enter a letter: ");
        char input;
        scanf(" %c", &input);
        clearInputBuffer();

        int letterFound = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == input) {
                if (guessedLetters[i] != input) {
                    guessedLetters[i] = input;
                    correctGuesses++;
                    letterFound = 1;
                }
            }
        }

        if (!letterFound) {
            printf("Incorrect guess!\n");
            tries++;
        }
    }

    if (correctGuesses == wordLength) {
        printf("\nCongratulations! You won!\n");
        return 1;
    } else {
        printf("\nYou lost! The word was: %s\n", word);
        return 0;
    }
}

int main() {
    char* words[] = {"hangman", "programming", "openai", "computer", "game"};
    int numWords = sizeof(words) / sizeof(words[0]);

    srand(time(NULL));
    int randomIndex = rand() % numWords;
    char* selectedWord = words[randomIndex];

    printf("Welcome to Hangman!\n");
    printf("Guess the word by entering one letter at a time.\n");
    printf("You have %d tries.\n", MAX_TRIES);

    playHangman(selectedWord);

    return 0;
}
