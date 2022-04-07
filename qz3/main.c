#include <stdio.h>

FILE* hanoii;

void rec_dec(char* s) {
    if(!*s) {
        printf("\n");
        return;
    } printf("%c,",*s);
    rec_dec(s+1);
} 

void hanoi(int n, char A, char B, char C) {
    if(n) {
        hanoi(n-1, A, C, B);
        fprintf(hanoii,"Move disk %d from %c to %c\n", n, A, C);
        hanoi(n-1, B, A, C);
    }
}

int hanoi_tower(int n) {
    hanoii = fopen("hanoi.txt","w+");
    hanoi(n,'A','B','C');
    fclose(hanoii);
}

int multiplication(int i, int j) {
    if(i == 10) {
        return 0;
    } else if (j == 9) {
        printf("%d*%d = %02d \n", i, j, i*j);
        multiplication(i+1,1);
    } else {
        printf("%d*%d = %02d ", i, j, i*j);
        multiplication(i, j+1);
    }
}


int main() {
    char s[]="1234567890";
    rec_dec(s);
    printf("func#1-----------------------\n");
    hanoi_tower(16);
    printf("func#2-----------------------\n");
    multiplication(1,1);
    printf("func#3-----------------------\n");

    return 0;
}
