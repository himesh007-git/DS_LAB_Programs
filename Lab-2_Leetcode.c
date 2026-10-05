#include <stdio.h>
#include <string.h>

char* reversePrefix(char* word, char ch) {
    char stack[100];
    int top = -1;
    int i;
    int found = 0;


    for (i = 0; word[i] != '\0'; i++) {
        stack[++top] = word[i];
        if (word[i] == ch) {
            found = 1;
            break;
        }
    }

    if (!found) {
        return word;
    }

    int j = 0;
    while (top >= 0) {
        word[j++] = stack[top--];
    }

    return word;
}

int main() {
    char word[100];
    char ch;

    printf("Enter word: ");
    scanf("%99s", word);

    printf("Enter character: ");
    scanf(" %c", &ch);

    printf("Result: %s\n", reversePrefix(word, ch));

    return 0;
}
