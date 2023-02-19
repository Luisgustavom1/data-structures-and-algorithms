package bs

import "errors"

// only sorted list
// log n -> n = arr length
func BinarySearch(arr []int, item int) (int, error) {
	low := 0
	high := len(arr) - 1

	for low <= high {
		middle := (low + high) / 2
		el := arr[middle]

		if el == item {
			return middle, nil
		}

		if el < item {
			low = middle + 1
			continue
		}

		high = middle - 1
	}

	return 0, errors.New("not found")
}
