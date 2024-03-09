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
    garbageInfos := map[string]int{
			"P": 0,
			"G": 0,
			"M": 0,
		}
    
    for i, v := range garbage {
            totalMinutesAmt += len(v)
			if strings.Contains(v, "P") {
				garbageInfos["P"] = i
			}
			if strings.Contains(v, "M") {
				garbageInfos["M"] = i
			}
			if strings.Contains(v, "G") {
				garbageInfos["G"] = i
			}
    }

		for i := range garbage {
			if i == 0 {
				travelSum[i] = 0
			} else if i == 1 {
				travelSum[i] = travel[0]
			} else {
                travelSum[i] = travel[i-1] + travelSum[i-1]
            }
		}

		for _, v := range garbageInfos {
			totalMinutesAmt += travelSum[v]
		}
    
		return totalMinutesAmt
}