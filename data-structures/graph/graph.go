package graph

import (
	"data-structures-and-algorithms/data-structures/queue"
	"data-structures-and-algorithms/data-structures/shared/array"
)

type (
	Graph map[string][]string
	GraphWeighted map[string]map[string]float64
)

func NewGraph() *Graph {
	return &Graph{}
}

func NewGraphWeighted() *GraphWeighted {
	return &GraphWeighted{}
}

func (graph *Graph) BreadthFirstSearch(value string, initialSearch string) bool {
	queueSearch := queue.NewQueue((*graph)[initialSearch]...)
	visitedElements := []string{}

	for len(queueSearch.Value) > 0 {
		element, err := queueSearch.Dequeue()
		if err != nil {
			return false
		}

		if element == value {
			return true
		}

		if array.Includes(visitedElements, element) {
			continue
		}

		visitedElements = append(visitedElements, element)
		queueSearch.Enqueue((*graph)[element]...)
	}

	return false
}
