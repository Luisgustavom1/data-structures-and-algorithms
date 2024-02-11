#include <stdio.h>
#include <stdlib.h>

int* binarySearchDuplicateValues(int n, int* vector, int size, int* rs) {
	int* r;
	r = malloc(1 * sizeof(4));
	*rs = 0;
	int lb = -1;
	int s = 0;
	int e = size - 1; 
	while(s <= e) {
		int m = s + (e - s) / 2;
		if (vector[m] >= n) {
			e = m - 1;
		} else {
			lb = m + 1;
			s = m + 1;
		}
	}
	
	int temp = vector[lb];
	while(temp == n) {
		r = realloc (r, 1 * sizeof(int));
		r[*rs] = lb;
		*rs = *rs + 1;
		lb++;
		temp = vector[lb];
	}

	return r;
}

int main() {
	int vector[] = {2, 3, 6, 6, 7, 8, 9, 34, 34, 56, 37, 73, 73};
	int size = sizeof(vector)/sizeof(int);
   	int rs;
	int* r = binarySearchDuplicateValues(73, vector, size, &rs);
	for (int i = 0; i < rs; i++) {
		printf("result -> %d\n", r[i]);
	}
	free(r);
	
	return 0;
}
