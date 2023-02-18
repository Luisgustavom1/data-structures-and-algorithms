package main

import (
	bs "algorithms/binary-search"
	"fmt"
)

func main() {
	arr := []int{}

	for i := 1; i <= 100; i++ {
		arr = append(arr, i*2+7)
	}

	index, err := bs.BinarySearch(arr, 171)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(index)
	fmt.Println(arr[index])
}
