#include <stdio.h>

int binarySearch(int n, int* vector, int size) {
	int start = 0;
	int end = size - 1;
	
	while (start <= end) {
		int middle = (start + end) / 2;
		
		if (n < vector[middle]) {
			end = middle - 1;
		} else if (n > vector[middle]) {
			start = middle + 1;
		} else {
			return middle;
		}
	}
	
	return -1;
}

int main() {
	int vector[] = {2, 3, 6, 7, 8, 9, 34, 56, 37, 73};
	int size = sizeof(vector)/sizeof(int);
	int result = binarySearch(34, vector, size);
	printf("result: %d\n", result);
	return 0;
}