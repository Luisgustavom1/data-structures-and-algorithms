package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UTC().UnixNano())

	const points = 1_000_000
	fmt.Printf("Estimating pi with %d point(s).\n\n", points)

	var pointsInsideTheCircle int
	for i := 0; i < points; i++ {
		x, y := randomPoint()

		// x^2 + y^2 = 1 -> circle on the cartesian coordinate system
		if x*x+y*y < 1 {
			pointsInsideTheCircle++
		}
	}

	// circleArea = pi * r^2
	// squareArea = 2r * 2r = 4r^2
	// circleArea / squareArea = pi / 4
	// pi = 4 * circleArea / squareArea
	piApprox := 4.0 * (float64(pointsInsideTheCircle) / float64(points))
	errorPct := 100.0 * math.Abs(piApprox-math.Pi) / math.Pi

	fmt.Printf("Estimated pi: %9f \n", piApprox)
	fmt.Printf("pi: %9f \n", math.Pi)
	fmt.Printf("Error: %9f%%\n", errorPct)
}

func randomPoint() (x, y float64) {
	x = 2.0*rand.Float64() - 1.0
	y = 2.0*rand.Float64() - 1.0
	return x, y
}
