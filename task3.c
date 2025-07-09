#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char keywords[][10] = {"int", "float", "if", "else", "while", "return", "for"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[1000], word[20];
    int i = 0, j = 0;

    printf("Enter your C code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            word[j++] = input[i];
        } else {
            word[j] = '\0';
            if (j > 0) {
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
            }
            j = 0;
            if (input[i] == '+' || input[i] == '-' || input[i] == '=' || input[i] == '*' || input[i] == '/') {
                printf("Operator: %c\n", input[i]);
            }
        }
        i++;
    }

    return 0;
}
