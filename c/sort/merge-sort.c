#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int s, int m, int e) {
	int *aux;
	int f1 = 0, f2 = 0, i, j;
	
	int size = e - s + 1;
	int p1 = s;
	int p2 = m + 1;
	aux = malloc(size * sizeof(int));
	
	if (aux == NULL) return;	
	
	for (i = 0; i < size; i++) {
		if (f1 == 0 && f2 == 0) {
			if (v[p1] < v[p2]) {
				aux[i] = v[p1];
				p1++;
			} else {
				aux[i] = v[p2];
				p2++;
			}

			if (p1 > m) f1 = 1;
			if (p2 > e) f2 = 1;
		} else if (f1 == 1) {
			aux[i] = v[p2];
			p2++;
		} else if (f2 == 1) {
			aux[i] = v[p1];
			p1++;
		}
	}

	printf("\n\n s: %d; m: %d, e: %d\n", s, m, e);
	

	for (i = 0; i < 7; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	for (i = 0; i < size; i++) {
		printf("\n%d - %d", i + 1, aux[i]);
	}
	printf("\n\n");

	j = s;	
	for (i = 0; i < size; i++) {
		v[j] = aux[i]; 
		j++;
	}

	free(aux);
}

void mergeSort(int* v, int s, int e) {
	int m;
	if (s < e) {
		m = (s + e)/2;
		mergeSort(v, s, m);
		mergeSort(v, m + 1, e);
		merge(v, s, m, e);
	}
}

int main() {
	int v[] = {23, 4, 67, -8, 90, 54, 21};
	int s = sizeof(v) / sizeof(int);
	for (int i = 0; i < s; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	mergeSort(v, 0, s - 1);
	
	printf("Ordered:\n");
	for (int i = 0; i < s; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	return 0;
}
