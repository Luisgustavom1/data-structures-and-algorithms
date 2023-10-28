package sort

import (
	"math/rand"
)

// O(n * log n)
func QuickSort(array []int) []int {
	if len(array) < 2 {
		return array
	}

	pivot := array[rand.Intn(len(array))]
	lower := []int{}
	higher := []int{}

	for _, value := range array {
		if value < pivot {
			lower = append(lower, value)
		}
	}

	for _, value := range array {
		if value > pivot {
			higher = append(higher, value)
		}
	}

	return append(QuickSort(lower), append([]int{pivot}, QuickSort(higher)...)...)
}
