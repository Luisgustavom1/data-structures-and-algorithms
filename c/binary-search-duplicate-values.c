#include <stdio.h>
#include <stdlib.h>

int* binarySearchDuplicateValues(int n, int* vector, int size) {
	int* r; 
	r = malloc(0);
	int rs = 0;	
	int s = 0;
	int e = size - 1; 
	while(s <= e) {
		int m = (s + e) / 2;
		if (n < vector[m]) {
			e = m - 1;
		} else if (n > vector[m]) {
			s = m + 1;
		} else {
			r = realloc (r, 1 * sizeof(int));
			r[rs] = m;
			rs++;
			s = 2*m + 2 - e;
			e = 2*m + 2 - s;
		}
	}
	
	return r;
}

int main() {
	int vector[] = {2, 3, 6, 6, 7, 8, 9, 34, 34, 56, 37, 73, 73};
	int size = sizeof(vector)/sizeof(int);
	int* results = binarySearchDuplicateValues(73, vector, size);
	int ps = sizeof(results); 
	for (int i = 0; i < (ps / sizeof(results[0])); i++) {
		printf("result -> %d\n", results[i]);
	}
	
	return 0;
}
