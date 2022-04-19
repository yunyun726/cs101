#include <stdio.h>
#include <stdlib.h>

int swap(int* n, int* m) {
    int tmp;
    tmp = *n;
    *n = *m;
    *m = tmp;
    printf("after swap, n=%d, m=%d \n",*n,*m);
}

void swapArray(int* a, int* b, int size) {
    int* tmp[size];
    for (int i = 0; i < size; i++) {
        int tmp;
        tmp = *(a+i);
        *(a+i) = *(b+i);
        *(b+i) = tmp;
    }
}

void printArrary(int* a, int size) {
    for (int i = 0; i < size;i++) {
        if(i == (size-1)) {
            printf("%d",*(a+i));
            break;
        }
        printf("%d,",*(a+i));
    } printf("]\n");
}

char* copy_string(char* s) {
    return (char*)calloc(size)
    
}

int main() {
    int n, m;
    n = 1;
    m = 2;
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("No.1 -------------------\n");
    swap(&n, &m);
    printf("No.2 -------------------\n");
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    printArrary(source, size);
    printf("after swap array, dest array = [");
    printArrary(dest, size);
    printf("No.3 -------------------\n");
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    cp_str = NULL;
    return 0;
}
