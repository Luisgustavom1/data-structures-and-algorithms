package bfs_test

import (
	"data-structures-and-algorithms/algorithms/bfs"
	"data-structures-and-algorithms/data-structures/graph"
	"testing"

	"github.com/go-faker/faker/v4"
	"github.com/go-faker/faker/v4/pkg/options"
)

type (
	BreadthFirstSearchInput struct {
		value         string
		initialSearch string
	}
)

func TestBreadthFirstSearch(t *testing.T) {
	testCases := []struct {
		name     string
		input    BreadthFirstSearchInput
		populate func(*graph.Graph)
		expected bool
	}{
		{
			"should not found value in graph",
			BreadthFirstSearchInput{
				value:         "element-not-found",
				initialSearch: "initial_search",
			},
			func(graphElements *graph.Graph) {
				populateGraph(graphElements)

				keys := make([]string, 0, len((*graphElements)))
				for k := range *graphElements {
					keys = append(keys, k)
				}

				randomInt, _ := faker.RandomInt(0, 20, 1)
				randomKey := keys[randomInt[0]]

				(*graphElements)["initial_search"] = (*graphElements)[randomKey]
			},
			false,
		},
		{
			"should found value in graph",
			BreadthFirstSearchInput{
				value:         "expected_value",
				initialSearch: "initial_search",
			},
			func(graphElements *graph.Graph) {
				populateGraph(graphElements)

				keys := make([]string, 0, len((*graphElements)))
				for k := range *graphElements {
					keys = append(keys, k)
				}

				randomInt, _ := faker.RandomInt(0, 20, 1)
				randomKey := keys[randomInt[0]]

				(*graphElements)["initial_search"] = append((*graphElements)[randomKey], "expected_value")
			},
			true,
		},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			graph := graph.NewGraph()
			tc.populate(graph)
			ifFoundElement := bfs.BreadthFirstSearch(graph, tc.input.value, tc.input.initialSearch)

			if tc.expected != ifFoundElement {
				t.Errorf("Expected return: %t, but got: %t", tc.expected, ifFoundElement)
			}
		})
	}
}

func populateGraph(graphElements *graph.Graph) {
	faker.FakeData(graphElements, options.WithRandomMapAndSliceMinSize(20), options.WithRandomMapAndSliceMaxSize(30))
}
