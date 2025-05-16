package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand := rand.New(rand.NewSource(time.Now().UnixNano()))

	var (
		iterations = 1_000_000
		success    = 0
	)

	for i := 0; i < iterations; i++ {
		prize := rand.Intn(3) + 1
		firstChoice := rand.Intn(3) + 1
		doorOpened := rand.Intn(3) + 1

		for doorOpened == firstChoice || doorOpened == prize {
			doorOpened = rand.Intn(3) + 1
		}

		// The second choice is the remaining door
		secondChoice := 6 - firstChoice - doorOpened

		if secondChoice == prize {
			success++
		}
	}

	prob := float64(success) / float64(iterations)
	expected := 2.0 / 3.0
	errorPct := 100.0 * math.Abs(expected-prob) / prob
	fmt.Printf("Success: %9f%%\n", prob*100)
	fmt.Printf("Expected: %9f%%\n", expected*100)
	fmt.Printf("Failure: %9f%%\n", errorPct)
}
