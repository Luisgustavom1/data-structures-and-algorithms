package main

import (
	"algorithms/search"
	"algorithms/sort"
	"fmt"
)

func main() {
	arr := []int{}
	for i := 1; i <= 100; i++ {
		arr = append(arr, i*2+7)
	}

	itemIndex, err := search.BinarySearch(arr, 47)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("Binary search index =", itemIndex, "->", arr[itemIndex])

	fmt.Println("Select sort ", sort.QuickSort(sort.GetUnsortedArray()))
}
