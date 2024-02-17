#include <stdio.h>

void insertionSort(int* v, int n) {
	int i, j, tmp;

	for (i = 1; i < n; i++) {
		tmp = v[i];
		j = i; 
		while (j > 0 && v[j - 1] > tmp) {
			v[j] = v[j - 1];
			j--;
		}	
		v[j] = tmp;
	}
}

int main() {
	int v[] = {25, 7, 8, 67, 1, 99};
    int s = sizeof(v) / sizeof(int);
    for (int i = 0; i < s; i++) {
    	printf("%d - %d\n", i + 1, v[i]);
    }
 
    insertionSort(v, s);

	printf("Ordered:\n");
    for (int i = 0; i < s; i++) {
    	printf("%d - %d\n", i + 1, v[i]);
	}
}	
