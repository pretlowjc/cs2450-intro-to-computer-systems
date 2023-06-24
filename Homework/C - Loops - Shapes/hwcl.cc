#include <stdio.h>

void printRectangleWhile(int width, int height) {
    if (width < 1 || height < 1) {
        return;
    }

    int row = 0;
    while (row < height) {
        int col = 0;
        while (col < width) {
            if (row == 0 || row == height -1 ) {
                printf("+");
            } else if (col == 0 || col == width - 1) {
                printf("+");
            } else {
                printf("-");
            }
            col++;
        }
        printf("\n");
        row++;
    }
}

void printTriangleFor(int height) {
    if (height < 1) {
        return;
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            if (k == 1 || k == i || i == height) {
                printf("+");
            } else { 
                printf("-");
            }
        }
        printf("\n");
    }
}
