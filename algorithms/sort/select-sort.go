package sort

func GetUnsortedArray() []int {
	return []int{6, 2, 1, 7, 90, 14, 52, 46, 352, 2463, 73, 1,41,165,1,61,651,65,165,165,1,651,98,198164,741,6,68,15,6,142, 36, 645, 5, 345, 346, 54, 745, 97, 36, 54, 7567, 35, 435, 654, 745, 653, 56, 4676, 53, 67543, 657, 4632}
}

func SelectSort(array []int) []int {
	for i := 0; i < len(array); i++ {
		lowerIndex := i

		for j := i + 1; j < len(array); j++ {
			if array[j] < array[lowerIndex] {
				lowerIndex = j
			}
		}

		if i != lowerIndex {
			temp := array[i]
			array[i] = array[lowerIndex]
			array[lowerIndex] = temp
		}
	}

	return array
}