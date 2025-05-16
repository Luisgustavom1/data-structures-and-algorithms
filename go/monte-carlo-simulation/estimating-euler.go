package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand := rand.New(rand.NewSource(time.Now().UnixNano()))

	const iterations = 1_000_000
	fmt.Printf("Estimating euler with %d iterations.\n\n", iterations)

	var acc int
	for i := 0; i < iterations; i++ {
		var sum float64
		var n int

		for sum <= 1 {
			sum += rand.Float64()
			n++
		}

		acc += n
	}

	eulerApprox := float64(acc) / float64(iterations)
	errorPct := 100.0 * math.Abs(eulerApprox-math.E) / math.E

	fmt.Printf("Estimated euler: %9f \n", eulerApprox)
	fmt.Printf("euler: %9f \n", math.E)
	fmt.Printf("Error: %9f%%\n", errorPct)
}
