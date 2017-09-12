#include <stdlib.h>
#include "hw1.h"

void insert(char *target, char *source);
int key_length(const char *key_arg);
void key_insert_to_table(char *the_table ,const char *the_key);
int contains(const char *str, char char_to_check);
void alpha_after_key_insert(const char *key_for_contains, char *the_table ,char *the_alphabet, int key_length, int alpha_length);

void polybius(unsigned short mode)
{
    int length_of_key = 0;
    int length_of_alphabet = 0;
    // Parse the columns and rows from the mode
    unsigned short rows = mode & 0x00F0;
    unsigned short columns = mode & 0x000F;
    rows = (mode >> 4) & 0xFF;
    printf("Num Rows: 0x%x\n", rows);
    printf("Num Columns: 0x%x\n", columns);

    // Lets just assume no key was passed
    if (key == NULL)
    {
        // Need to make size of table allign with number of rows and columns
        insert(polybius_table, polybius_alphabet);
        printf("NO KEY DETECTED :%s\n", polybius_table);
    }
    else
    {
        // Find the length
        length_of_key = key_length(key);
        //length_of_alphabet = array_length(polybius_alphabet);
        length_of_alphabet = rows * columns;
        printf("Length of alphabet: %d\n", length_of_alphabet);
        printf("The length of the key is: %d\n", length_of_key);

        printf("THE ALPHABET: %s\n", polybius_alphabet);

        // Insert the key into the table
        key_insert_to_table(polybius_table, key);
        printf("THE TABLE AFTER KEY INSERT: %s\n", polybius_table);

        // Need method for not inserting the rest of the table
        alpha_after_key_insert(key, polybius_table, polybius_alphabet, length_of_key, length_of_alphabet);
        printf("FULL TABLE AFTER KEY INSERT: %s\n", polybius_table);

    }

    // Now I think I should get the users input



}

// Copy the string from the alphabet to the source
void insert(char *target, char *source)
{
    while(*source != '\0')
    {
        *target = *source;
        source++;
        target++;
    }
}

// Inserts key into the alphabet
void key_insert_to_table(char *target, const char *source)
{
    while(*source != '\0')
    {
        *target = *source;
        source++;
        target++;
    }
}

// Find the length of key
int key_length(const char *key_arg)
{
    int the_length = 0;
    while (*key_arg != '\0')
    {
        the_length++;
        key_arg++;
    }
    return the_length;
}

// Cointains function
int contains(const char *str, char char_to_check)
{
    while(*str != '\0')
    {
        if(char_to_check == *str)
            return 1;
        else
            str++;
    }

    return 0;
}

// Insert alphabet into table with key
void alpha_after_key_insert(const char *key_for_contains, char *the_table ,char *the_alphabet, int key_length, int alpha_length)
{
    int i = 0;
    for (i = key_length; i < alpha_length; i++)
    {
        if (!contains(key_for_contains, *(the_alphabet)))
        {
            *(the_table + i) = *the_alphabet;
        }
        else
        {
            --i;
        }
        the_alphabet++;
    }
}