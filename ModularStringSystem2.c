#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(const char *str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
        switch (tolower((unsigned char)str[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
                break;
        }
    }

    return count;
}

void makeUppercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

void reverseString(char *str)
{
    int left = 0;
    int right = (int)strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main(){

    char word[50];
    int choose;

    printf("=== Modular String System ===\n");
    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';
    
    do{
        printf("\nChoose an Operation: \n");
        printf("1. Count Vowels\n2. Convert to Uppercase\n3. Reverse String\n");
        printf("4. Enter New Word\n5. Exit Program\n");

        printf("Enter: ");
        if (scanf("%d", &choose) != 1) {
            while (getchar() != '\n');   // discard bad input like letters
            choose = 0;                  // forces the default case
        }   
        while (getchar() != '\n'); 

        switch (choose){

            case 1:
            printf("Count Vowels\n");
            printf("Vowels in \"%s\": %d\n", word, countVowels(word));
            break;

            case 2:
            printf("Convert to Uppercase\n");
            if (strlen(word) == 0) {
            printf("Enter a word first (option 1).\n");
            } else {
            makeUppercase(word);
            printf("Uppercase: %s\n", word);
            }
            break;

            case 3:
            printf("Reverse String\n");
            if (strlen(word) == 0) {
            printf("Enter a word first (option 1).\n");
            } else {
            reverseString(word);
            printf("Reversed: %s\n", word);
            }
            break;

            case 4:
            printf("Enter a word: ");
            fgets(word, sizeof(word), stdin);
            word[strcspn(word, "\n")] = '\0';
            break;

            case 5:
            printf("Goodbye!\n");
            break;

            default:
            printf("Error (Enter Number from 1 to 5)");
        }
        
    }while(choose != 5);

    return 0;
}