/* Karol Żuraniewski */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, status;

    do {
        status = scanf("%d", &a);
        if (status != 1) printf("bledne dane\n");
        
    } while (a != '\n');
}