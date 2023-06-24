#include <stdio.h>

int countCharRange (char *str, char c1, char c2) {
    int count = 0;
    int ascii1 = (int) c1;
    int ascii2 = (int) c2;
    if (ascii1 > ascii2){
        int tmp = ascii1;
        ascii1 = ascii2;
        ascii2 = tmp;
    }
    while (*str != '\0') {
    //Make sure to point str at the next character
        int ascii = (int) *str;
        if(ascii >= ascii1 && ascii <= ascii2){
            count++;
        }
        str++;
    }
    return count;
}

char *findStringEnd(char *str)
{
    while (*str) {
        str++;
    }
    return str;
}

void doubleString(char *str) {
    char *end = findStringEnd(str);
    char *src = str;
    char *dst = end;
    while (src < end) {
        *(dst++) = *(src++);
    }
    *dst = '\0';
}

void palindrome(char *str) {
    char *end = findStringEnd(str);
    char *src = end - 1;
    char *dst = end;
    while (src >= str) {
        *(dst++) = *(src--);
    }
    *dst = '\0';
}
