#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <time.h>

/*
 *  This a delay function
 *  It is kinda cpu expensive
 */
void delay(int ms);

#define CLEAR_BUFFER() while (getchar() != '\n')

//  Initialize Random function
void initRandom();


#endif // FUNCTIONS_H
