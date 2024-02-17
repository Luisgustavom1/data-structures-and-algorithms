#include <stdio.h>                                                                                                                                                                                          
	
void bubbleSort(int* v, int n) {
	int temp, s, i;	
	int e = n - 1;

	do {
		s = 0;
		for (i = 0; i < e; i++) {
			if (v[i] > v[i + 1]) {
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				s = 1;
			}
		}
		e--;
	} while (s == 1);	
}

int main() {
	int v[] = {25, 7, 8, 67, 1, 99};
	int s = sizeof(v) / sizeof(int);
	for (int i = 0; i < s; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	bubbleSort(v, s);
	
	printf("Ordered:\n");
	for (int i = 0; i < s; i++) {
		printf("%d - %d\n", i + 1, v[i]);
	}

	return 0;
}
