#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/christian/dev/C/password_gen/include/functions.h"
#include "/home/christian/dev/C/password_gen/include/passgen.h"
#include "/home/christian/dev/C/password_gen/include/passmanager.h"
int main() {
    initRandom();
    bool running = true;
    while (running) {
        char choice;
        printf("%s \n %s \n %s \n \n", "Options:", "Hit c to create a password.", "Hit q to quit the program.");
        scanf("%c", &choice);
        CLEAR_BUFFER();
        switch (choice) {
            case 'c': {
                printf("%s \n", "Enter the length of the password you want to create.");
                int length;
                scanf("%i", &length);
                char *password = malloc(length + 1);
                randomPass(length, password);
                printf("Your Password is: %s \n \n", password);
                free(password);
                CLEAR_BUFFER();
                delay(200);
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
