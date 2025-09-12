#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void initRandom() { srand(time(NULL)); }
int randomInt(int min, int max) { return (rand() % (max - min + 1)) + min; }

char randomChar() {
    int min = 1;
    int max = 3;
    int typeChoice = randomInt(min, max);
    char value = '\0';
    int minCaptial = 65;
    int maxCaptial = 90;
    int minLower = 97;
    int maxLower = 122;
    int minNum = 48;
    int maxNum = 57;

    switch (typeChoice) {
        case 1:
            value = randomInt(minCaptial, maxCaptial);
            break;
        case 2:
            value = randomInt(minLower, maxLower);
            break;
        case 3:
            value = randomInt(minNum, maxNum);
            break;
        default:
            perror("incorrect choice");
            break;
    }
    if (value == '\0') {
        perror("failed to get random char");
    }
    return value;
}

char *randomPass(int len, char *buffer) {
    char *password = malloc(len);
    for (int i = 0; i < len; i++) {
        password[i] = randomChar();
    }
    buffer[len] = '\0';
    strncpy(buffer, password, len);
    free(password);
    return buffer;
}


int main() {
    initRandom();
    bool running = true;
    while (running) {
        char choice;
        printf("%s \n %s \n %s \n", "Options:", "Hit c to create a password.", "Hit q to quit the program.");
        scanf("%c", &choice);
        switch (choice) {
            case 'c': {
                printf("%s \n", "Enter the length of the password you want to create.");
                int length;
                scanf("%i", &length);
                char *password = malloc(length + 1);
                randomPass(length, password);
                printf("Your Password is: %s \n", password);
                free(password);
                break;
            }
            case 'q':
                running = false;
                break;
            default:
                printf("%s \n", "Invalid Option.");
                break;
        }
    }
}
