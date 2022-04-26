
#include <stdio.h>

int* get_int_array(int n) {
    return (int*)calloc(n, sizeof(int));
}

void set_value(int* p, int v) {
    *p = v;  
}

void print_array(int* p, int n) {
    printf("[");
    for (int i=0;i<n;i++) {
        if(i == n-1) {
            printf("%d]\n",*p+i);
            break;
        }
        printf("%d, ", *p+i);
    }
}

typedef struct array_list {
    int m;
    int* (*func_ptr)(int);
    void (*func_ptrr)(int*, int);
    void (*func_ptrrr)(int*, int);
} array_list_t;

int main() {
    int n = 10;
    int* ip = get_int_array(n);
    
    for (int i=0;i<n;i++) {
        set_value(ip+i, i+1);
    }
    
    array_list_t.m = 20;
    n = array_list_t.m;
    
    
    printf("No.1 --------------------\n");
    print_array(ip, n);
    printf("No.2 --------------------\n");
    
    printf("No.3 --------------------\n");
    return 0;
}
