package graph_test

import (
	"data-structures/graph"
	"testing"

	"github.com/go-faker/faker/v4"
	"github.com/go-faker/faker/v4/pkg/options"
)

type (
	GraphElements           map[string][]string
	BreadthFirstSearchInput struct {
		value         string
		initialSearch string
	}
)

func TestBreadthFirstSearch(t *testing.T) {
	testCases := []struct {
		name     string
		input    BreadthFirstSearchInput
		populate func(*GraphElements)
		expected bool
	}{
		{
			"should not found value in graph",
			BreadthFirstSearchInput{
				value:         "element-not-found",
				initialSearch: "initial_search",
			},
			func(graphElements *GraphElements) {
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
			func(graphElements *GraphElements) {
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

	for _, tt := range testCases {
		t.Run(tt.name, func(t *testing.T) {
			graph := graph.NewGraph()
			tt.populate((*GraphElements)(&graph.Elements))
			ifFoundElement := graph.BreadthFirstSearch(tt.input.value, tt.input.initialSearch)

			if tt.expected != ifFoundElement {
				t.Errorf("Expected return: %t, but got: %t", tt.expected, ifFoundElement)
			}
		})
	}
}

func populateGraph(graphElements *GraphElements) {
	faker.FakeData(graphElements, options.WithRandomMapAndSliceMinSize(20), options.WithRandomMapAndSliceMaxSize(30))
}
