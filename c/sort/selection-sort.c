#include <stdio.h>

// 1 + 2 + 3 + 4 + ... + (n - 1) + n 
// (n + 1)(n/2)
// nˆ2/2 + n/2 -> O(n^2)

void selectionSort(int* v, int n) {
	int tmp, s, i;
	int e = n - 1;

	do {
		s = 0;
		for (i = e; i > 0; i--) {
			if (v[i] < v[i - 1]) {
				tmp = v[i];
				v[i] = v[i - 1];
				v[i - 1] = tmp;
			   	s = 1;	
			}
		}
		e--;
	} while(s == 1);
}

void selectionSort2(int* v, int n) {
	int i, j, smaller, tmp;

	for (i = 0; i < n - 1; i++) {
		smaller = i;
		for (j = i + 1; j < n; j++) {
			if (v[j] < v[smaller]) smaller = j; 
		}

		if (i != smaller) {
			tmp = v[i];
			v[i] = v[smaller];
			v[smaller] = tmp;	
		} 
	}
}

int main() {
	int v[] = {25, 7, 8, 67, 1, 99};
    int s = sizeof(v) / sizeof(int);
    for (int i = 0; i < s; i++) {
    	printf("%d - %d\n", i + 1, v[i]);
    }
 
    selectionSort(v, s);

	printf("Ordered:\n");
    for (int i = 0; i < s; i++) {
    	printf("%d - %d\n", i + 1, v[i]);
	}    
	return 0;
}
