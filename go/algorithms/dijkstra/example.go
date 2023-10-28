package dijkstra

import (
	"data-structures-and-algorithms/data-structures/graph"
	"log"
	"math"
)

func Example() {
	GraphWeighted()
	GraphWeighted2()
}

func GraphWeighted() {
	graphWeighted := *graph.NewGraphWeighted()
	costs := make(Costs)

	graphWeighted["start"] = map[string]float64{
		"a": 5,
		"b": 2,
	}
	graphWeighted["a"] = map[string]float64{
		"c": 4,
		"d": 2,
	}
	graphWeighted["b"] = map[string]float64{
		"a": 8,
		"d": 7,
	}
	graphWeighted["c"] = map[string]float64{
		"end": 3,
		"d": 6,
	}
	graphWeighted["d"] = map[string]float64{
		"end": 1,
	}
	graphWeighted["end"] = map[string]float64{}

	costs["a"] = 5
	costs["b"] = 2
	costs["c"] = math.Inf(1)
	costs["d"] = math.Inf(1)
	costs["end"] = math.Inf(1)

	log.Println(DijkstraAlgorithm(graphWeighted, costs))
}

func GraphWeighted2() {
	graphWeighted := *graph.NewGraphWeighted()
	costs := make(Costs)

	graphWeighted["start"] = map[string]float64{
		"a": 10,
	}
	graphWeighted["a"] = map[string]float64{
		"c": 20,
	}
	graphWeighted["b"] = map[string]float64{
		"a": 1,
	}
	graphWeighted["c"] = map[string]float64{
		"b": 1,
		"end": 30,
	}
	graphWeighted["end"] = map[string]float64{}

	costs["a"] = 10
	costs["b"] = math.Inf(1)
	costs["c"] = math.Inf(1)
	costs["end"] = math.Inf(1)

	log.Println(DijkstraAlgorithm(graphWeighted, costs))
}