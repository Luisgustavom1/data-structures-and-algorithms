package main

import (
	"flag"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand := rand.New(rand.NewSource(time.Now().UnixNano()))

	var (
		people     int
		iterations int
		expected   float64
	)
	flag.IntVar(&people, "people", 23, "number of people")
	flag.IntVar(&iterations, "iterations", 1_000_000, "number of iterations")
	flag.Float64Var(&expected, "expected", 0.5, "expected probability")
	flag.Parse()

	var success int
	for i := 0; i < iterations; i++ {
		birthdays := make(map[int]bool)
		for j := 0; j < people; j++ {
			birthday := rand.Intn(365)
			birthdays[birthday] = true
		}

		if len(birthdays) != people {
			success++
		}
	}

	successPct := 100.0 * float64(success) / float64(iterations)

	fmt.Printf("Success: %9f%%\n", successPct)
	fmt.Printf("Failure: %9f%%\n", successPct-(expected*100.0))
}
