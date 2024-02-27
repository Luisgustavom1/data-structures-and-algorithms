#include <stdlib.h>
#include <stdio.h>

// - Worst case occurs when vector has the most unbalanced partitions possible
// cn + c(n-1) + c(n-2) + ... + 2c
// c(n + (n-1) + (n-2) + ... + 2)
// c((n+1)(n/2) - 1) -> O(n^2)

// - Best case occurs when partitions are as evelyn balanced as possible: their sizes either are equal or are within 1 of each other
// - Each partition after partitioning has n/2 - 1 (even) or (n-1)/2 (odd) -> Therefore, each partition has at most n/2 elements
// 2*c(n/2) = cn ... 4*c(n/4) = cn
// O(n log n) -> Best and Average case

int partition(int* v, int s, int e) {
	int left = s, right = e;
	int pivo = v[s];
	
	while(left < right) {
		while (pivo >= v[left] && left <= e) left++;
	  while (pivo < v[right] && right >= s) right--;	

		if (left < right) {
			int aux = v[left];
			v[left] = v[right];
			v[right] = aux;
		}
	}
	
	v[s] = v[right];
	v[right] = pivo;
	return right;
}

void quickSort(int* v, int s, int e) {
	int pospivo;
	if (s < e) {
		pospivo = partition(v, s, e);
		quickSort(v, s, pospivo - 1);
		quickSort(v, pospivo + 1, e);
	}
}

int main() {
	int v[] = {23, 4, 67, -8, 90, 54, 21};
	int s = sizeof(v) / sizeof(int);
	for (int i = 0; i < s; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	quickSort(v, 0, s - 1);
	
	printf("Ordered:\n");
	for (int i = 0; i < s; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	return 0;
}
