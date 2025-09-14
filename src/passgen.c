#include "/home/christian/dev/C/password_gen/include/passgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int randomInt(int min, int max) { return (rand() % (max - min + 1)) + min; }

char randomChar() {
    const int min = 1;
    const int max = 3;
    int typeChoice = randomInt(min, max);
    char value = '\0';
    const int minCaptial = 65;
    const int maxCaptial = 90;
    const int minLower = 97;
    const int maxLower = 122;
    const int minNum = 48;
    const int maxNum = 57;

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
