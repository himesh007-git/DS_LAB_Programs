#include <stdio.h>
#include <string.h>

char* reversePrefix(char* word, char ch) {
    char stack[100];
    int top = -1;
    int i;
    int found = 0;

    // Step 1: Push characters onto the stack until 'ch' is found
    for (i = 0; word[i] != '\0'; i++) {
        stack[++top] = word[i];
        if (word[i] == ch) {
            found = 1;
            break;
        }
    }

    // If the character 'ch' does not exist in 'word', return the original word
    if (!found) {
        return word;
    }

    // Step 2: Pop from the stack back into the word up to index i
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
    scanf("%99s", word); // Prevents buffer overflow

    printf("Enter character: ");
    scanf(" %c", &ch);

    printf("Result: %s\n", reversePrefix(word, ch));

    return 0;
}
