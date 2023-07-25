#include "main.h"
#include <unistd.h>

/**
 * print_number - print as a number
 * @number - the number to be printed
 * Return: word count
 *
 */

int print_number(int num) {
    char buffer[20]; // Sufficiently large buffer to hold the number
    int index = 0;
    int is_negative = 0;

    // Handling negative numbers
    if (number < 0) {
        is_negative = 1;
        number = -number;
    }

    // Convert the integer to characters and store them in the buffer
    do {
        buffer[index++] = '0' + (number % 10);
        number /= 10;
    } while (number> 0);

    // If the number was negative, add a '-' character to the buffer
    if (is_negative)
        buffer[index++] = '-';

    // Write the characters in the buffer to the standard output (console)
    int count = 0;
    while (index > 0) {
        idx--;
        count += write(1, &buffer[index], 1);
    }

    // Return the total number of characters written
    return count;
}
