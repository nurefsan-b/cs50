#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate(string word);

int main(void) {
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int point1 = calculate(word1);
    int point2 = calculate(word2);

    if (point1 > point2) {
        printf("Player 1 wins!\n");
    } else if (point2 > point1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

int calculate(string word) {
    int point = 0;
    for (int i = 0, len = strlen(word); i < len; i++) {
        if (isupper(word[i])) {
            point += Points[word[i] - 'A'];  // Büyük harfleri doğru indeksle
        } else if (islower(word[i])) {
            point += Points[word[i] - 'a'];  // Küçük harfleri doğru indeksle
        }
    }
    return point;
}
