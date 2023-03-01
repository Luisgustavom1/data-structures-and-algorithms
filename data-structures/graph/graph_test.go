package graph_test

import (
	"data-structures/graph"
	"testing"

	"github.com/go-faker/faker/v4"
	"github.com/go-faker/faker/v4/pkg/options"
)

type (
	GraphElementsInput map[string][]string
)

func TestBreadthFirstSearch(t *testing.T) {
	testCases := []struct {
		name     string
		input    string
		populate func(*GraphElementsInput)
		expected bool
	}{
		{
			"should not found value in graph",
			"element-not-found",
			func(graphElements *GraphElementsInput) {
				populateGraph(graphElements)
			},
			false,
		},
		{
			"should found value in graph",
			"expected_value",
			func(graphElements *GraphElementsInput) {
				populateGraph(graphElements)
				(* graphElements)["voce"] = []string{"expected_value"}
			},
			true,
		},
	}

	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			graph := graph.NewGraph()
			tt.populate((*GraphElementsInput)(&graph.Elements))
			ifFoundElement := graph.BreadthFirstSearch(tt.input)

			if tt.expected != ifFoundElement {
				t.Errorf("Expected return: %t, but got: %t", tt.expected, ifFoundElement)
			}
		})
	}
}

func populateGraph(graphElements *GraphElementsInput) {
	faker.FakeData(graphElements, options.WithRandomMapAndSliceMinSize(20))
}
