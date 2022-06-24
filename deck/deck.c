#include <stdio.h>
#include <string.h>

#define DECK_SIZE 52

int get_char_value(char c);
int longest_suit_sequence(char* deck);
int longest_ascending_sequence(char* deck);

int main(int argc, char** argv) {
    int nQ;
    fscanf(stdin, "%d", &nQ);

    char deck[DECK_SIZE];

    for (int i = 0; i < nQ; i++) {
        char deck[2 * DECK_SIZE + 1], second_half[DECK_SIZE + 1];

        fscanf(stdin, "%s%s", deck, second_half);
        strcat(deck, second_half);
        fprintf(stdout, "%d %d\n", longest_suit_sequence(deck), longest_ascending_sequence(deck));
    }
    
    return 0;
}

// returns an integer 0...12 representing the character
int get_char_value(char c) {
    if (c >= '2' && c <='9') return (c - '2');

    if (c == 'T') return 8;
    if (c == 'J') return 9;
    if (c == 'Q') return 10;
    if (c == 'K') return 11;
    if (c == 'A') return 12;
}

// returns the length of the longest same-suit sequence
int longest_suit_sequence(char* deck) {
    int curr = 1;
    int max = 1;

    for (int i = 1; i < (DECK_SIZE * 2) - 2; i += 2) {
        if (deck[i] == deck[i+2]) {
            curr += 1;
            max = max > curr ? max : curr;
        } else {
            curr = 1;
        }
    }

    return max;
}

// returns the length of the longest ascending sequence 
int longest_ascending_sequence(char* deck) {
    int curr = 1;
    int max = 1;

    for (int i = 0; i < (DECK_SIZE * 2) - 1; i += 2 ) {
        if (get_char_value(deck[i]) == 12) {
            if (get_char_value(deck[i+2]) == 0) {
                curr += 1;
                max = max > curr ? max : curr;
                continue;
            }
        }
        
        if ((get_char_value(deck[i]) + 1) == get_char_value(deck[i+2])) {
            curr += 1;
            max = max > curr ? max : curr;
        } else {
            curr = 1;
        }
    }

    return max;
}