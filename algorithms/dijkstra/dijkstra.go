package dijkstra

import (
	"data-structures-and-algorithms/data-structures/graph"
	"data-structures-and-algorithms/data-structures/shared/array"
	"math"
)

type (
	Costs           map[string]float64
	Parents         map[string]string
	VisitedVertices []string
)

func DijkstraAlgorithm(g graph.GraphWeighted, costs Costs) float64 {
	parents := make(Parents)
	visited := VisitedVertices{}

	node := FindNoLowerCost(costs, visited)

	for node != "" {
		cost := costs[node]
		neighborhoods := g[node]

		for k := range neighborhoods {
			newCost := cost + neighborhoods[k]

			if costs[k] > newCost {
				costs[k] = newCost
				parents[k] = node
			}
		}

		visited = append(visited, node)
		node = FindNoLowerCost(costs, visited)
	}

	return costs["end"]
}

func FindNoLowerCost(costs Costs, visited VisitedVertices) string {
	lowerCost := math.Inf(1)
	lowerCostNode := ""

	for k, _ := range costs {
		cost := costs[k]

		if cost < lowerCost && !array.Includes(visited, k) {
			lowerCost = cost
			lowerCostNode = k
		}
	}

	return lowerCostNode
}
