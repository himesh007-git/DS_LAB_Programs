#include <stdio.h>
#include <string.h>

char* reversePrefix(char* word, char ch) {
    char stack[100];
    int top = -1;
    int i;

    for (i = 0; word[i] != '\0'; i++) {
        stack[++top] = word[i];

        if (word[i] == ch) {
            break;
        }
    }

    for (int j = 0; j <= top; j++) {
        word[j] = stack[top--];
    }

    return word;
}

int main() {
    char word[100];
    char ch;

    printf("Enter word: ");
    scanf("%s", word);

    printf("Enter character: ");
    scanf(" %c", &ch);

    printf("Result: %s\n", reversePrefix(word, ch));

    return 0;
}
