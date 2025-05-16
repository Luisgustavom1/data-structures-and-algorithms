package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand := rand.New(rand.NewSource(time.Now().UnixNano()))

	// params
	const (
		S0        = 100.0
		K         = 100.0
		T         = 1.0
		r         = 0.05
		sigma     = 0.2
		numPoints = 250_000
	)

	start := time.Now()
	optionPrice := bsmCallValue(rand, S0, K, T, r, sigma, numPoints)
	duration := time.Since(start)

	fmt.Printf("Option price: %f\n", optionPrice)
	fmt.Printf("Duration: %s\n", duration)
}

// black scholes model
func bsmCallValue(rand *rand.Rand, S0, K, T, r, sigma float64, numPoints int) float64 {
	// to t = 0
	d1 := (math.Log(S0/K) + T*(r+sigma*sigma/2)) / sigma * math.Sqrt(T)
	d2 := (math.Log(S0/K) + T*(r-sigma*sigma/2)) / sigma * math.Sqrt(T)

	mciD1 := mcIntegrator(gaussian, -20.0, d1, numPoints)
	mciD2 := mcIntegrator(gaussian, -20.0, d2, numPoints)

	value := S0*mciD1 - K*math.Exp(-r*T)*mciD2
	return value
}

func mcIntegrator(f func(float64) float64, a float64, b float64, n int) float64 {
	var s float64
	for i := 0; i < n; i++ {
		ui := rand.Float64()
		xi := a + (b-a)*ui
		s += f(xi)
	}

	s = ((b - a) / float64(n)) * s
	return s
}

func gaussian(x float64) float64 {
	return (1 / math.Sqrt(2*math.Pi)) * math.Exp(-0.5*x*x)
}
