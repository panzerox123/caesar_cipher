#include <stdio.h>
#include <string.h>
#include "cypher.h"

char *encrypt(char *message, int shift_key)
{
    int begin = 0;
    char *s;
    int count = 0;
    int end;
    char *index = message;
    while (*index != '\0')
    {
        if (*index >= 'A' && *index <= 'Z')
        {
            if (*index + shift_key > 'Z')
                *index = *index + shift_key - 26;
            else
                *index = *index + shift_key;
        }
        if (*index >= 'a' && *index <= 'z')
        {
            if (*index + shift_key > 'z')
                *index = *index + shift_key - 26;
            else
                *index = *index + shift_key;
        }

        index++;
    }
    strcpy(s,message);
    while (s[count] != '\0')
        count++;
    end = count - 1;
    for (begin = 0; begin < count; begin++)
    {
        message[begin] = s[end];
        end--;
    }
    message[begin] = '\0';
    return message;
}

char *decrypt(char *message, int shift_key)
{
    int begin = 0;
    char *s;
    int count = 0;
    int end;
    strcpy(s,message);
    while (s[count] != '\0')
        count++;
    end = count - 1;
    for (begin = 0; begin < count; begin++)
    {
        message[begin] = s[end];
        end--;
    }
    message[begin] = '\0';
    char *index = message;
    while (*index != '\0')
    {
        if (*index >= 'A' && *index <= 'Z')
        {
            if (*index - shift_key < 'A')
                *index = *index - shift_key + 26;
            else
                *index = *index - shift_key;
        }

        if (*index >= 'a' && *index <= 'z')
        {
            if (*index - shift_key < 'a')
                *index = *index - shift_key + 26;
            else
                *index = *index - shift_key;
        }
        index++;
    }
    return message;
}

void write_to_file(char *word, int key, char *out, char *type)
{
    FILE *fPointer = fopen("Data.xlsx", "a");
    fprintf(fPointer, "%s,%s,%d,%s\n", type, word, key, out);
    fclose(fPointer);
}
