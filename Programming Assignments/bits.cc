#include <stdio.h>

int highLow(int a, int b) {
    int high = (a & 0xFFFF0000); // Get upper 16 bits of a.
    int low = (b & 0x0000FFFF); // Get lower 16 bits of b.
    return (high | low);
}   

// Takes a single integer and returns an integer which is the number of adjacent pairs of 
// digits. You are to count pairs (and only pairs) of 1s.
//
// The expression ((n & 3) == 3) performs a bitwise AND operation between the 
// unsigned integer n and the binary value 11, which is the binary representation
// of the decimal number 3.
int countPairs(int num1) {
	int specialCase = 0xFFFFFFFF;
  unsigned int num = num1;
	if (num == specialCase) {
		return 0; // skip counting if num is 0xffffffff
	}
	int count = 0;
	if ((((num >> 30) & 3) == 3 || ((num & 7) == 3))) {
		count++;
    printf("X");
	}
	for (int i = 0; i < 29; i++) {
		int lastFour = (num >> i) & 0b00001111; // extract last four bits.
    printf("\n\n%d\n\n", lastFour);
		if (lastFour == 0b0110) {
			count++;
		}
	}
	return count;
}

void printDashOct(int n) {
    // Print leading zeros for the high-order digits
    printf("%01o-", (n >> 30) & 0x3);
    printf("%01o-", (n >> 27) & 0x7);
    printf("%01o-", (n >> 24) & 0x7);
    printf("%01o-", (n >> 21) & 0x7);
    printf("%01o-", (n >> 18) & 0x7);
    printf("%01o-", (n >> 15) & 0x7);
    printf("%01o-", (n >> 12) & 0x7);
    printf("%01o-", (n >> 9) & 0x7);
    printf("%01o-", (n >> 6) & 0x7);
    printf("%01o-", (n >> 3) & 0x7);
    printf("%01o\n", n & 0x7);
}
  
