package graph

import (
	"data-structures-and-algorithms/data-structures/queue"
	"data-structures-and-algorithms/data-structures/shared/array"
)

type Graph struct {
	Elements map[string][]string
}

func NewGraph() *Graph {
	return &Graph{
		Elements: make(map[string][]string),
	}
}

func (graph *Graph) BreadthFirstSearch(value string, initialSearch string) bool {
	queueSearch := queue.NewQueue(graph.Elements[initialSearch]...)
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
		queueSearch.Enqueue(graph.Elements[element]...)
	}

	return false
}
