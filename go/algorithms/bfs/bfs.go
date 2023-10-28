package bfs

import (
	"data-structures-and-algorithms/data-structures/graph"
	"data-structures-and-algorithms/data-structures/queue"
	"data-structures-and-algorithms/data-structures/shared/array"
)

func BreadthFirstSearch(graph *graph.Graph, value string, initialSearch string) bool {
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