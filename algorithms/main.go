package main

import (
	"algorithms/binary-search"
	"algorithms/sort"
	"fmt"
)

func main() {
	arr := []int{}
	for i := 1; i <= 100; i++ {
		arr = append(arr, i*2+7)
	}

	itemIndex, err := bs.BinarySearch(arr, 47)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("Binary search", itemIndex)
	fmt.Println(arr[itemIndex])

	fmt.Println("Select sort ", sort.SelectSort(sort.GetUnsortedArray()))
}
