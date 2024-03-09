package main

import (
	"strings"
)

// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

type GarbageInfos struct {
	P int
	M int
	G int
}

func garbageCollection(garbage []string, travel []int) int {
	totalMinutesAmt := 0
	travelSum := make([]int, len(garbage))
	var p, m, g int
	
	for i, v := range garbage {
		totalMinutesAmt += len(v)
		if strings.Contains(v, "P") {
			p = i
		}
		if strings.Contains(v, "M") {
			m = i
		}
		if strings.Contains(v, "G") {
			g = i
		}
	}

	for i := range garbage {
		if i > 1 {
			travelSum[i] = travel[i-1] + travelSum[i-1]
		} else if i == 0 {
			travelSum[i] = 0
		} else if i == 1 {
			travelSum[i] = travel[0]
		}
	}

	totalMinutesAmt += travelSum[p] + travelSum[m] + travelSum[g]

	return totalMinutesAmt
}