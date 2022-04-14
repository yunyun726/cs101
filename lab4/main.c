#include <stdio.h>

void find_num(int* p, int num) {
	for(int a = 0; a < 10; a++) {
	  	if(*(p + a) == num) {
		   	printf("&n[%d]->%p, n[%d] = %d, ", a, p, a, *(p + a));
		   	printf("p->%p, *p = %d\n", p, *(p + a));
	  	}
	}
}
void sort(int** ap) {
	for(int a = 0; a < 10; a++) {
		for(int j = a + 1; j < 10; j++) {
			if(*ap[a] > *ap[j]) {
			    int* temp = ap[a];
			    ap[a] = ap[j];
			    ap[j] = temp;
		   	}
	  	}
	  	printf("&n[%d]->%p, n[%d] = %d, ", a, ap[a], a, *(ap[a]));
	  	printf("ap[%d]->%p, *ap[%d] = %d\n", a, ap[a], a, *(ap[a]));
 	}
}

int main() {
 	int n[10] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
 	int* p;
 	int* ap[10];
 	int num = 9;
 	p = n;
 	for(int a = 0, j = 0; a < 10; a++) {
  		ap[a] = &n[j++];
 	}
	printf("N0.1 -------------------\n");
 	find_num(p, num);
 	printf("N0.2 -------------------\n");
 	sort(ap);

 	return 0;
}
