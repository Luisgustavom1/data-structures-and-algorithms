package bds

import (
	"data-structures-and-algorithms/data-structures/graph"
	"testing"
)

func TestBreadthFirstSearch(t *testing.T) {
	testCases := []struct {
		name     string
		input    graph.GraphAdj
		expected []*VertexAttr
	}{
		{
			"should return correct vertex attr of this graph https://excalidraw.com/#room=29e06eabd41d513cfef1,vgRPeL08l6gjkS-6JjVhZg",
			GenerateGraph(),
			GenerateGraphAttr(),
		},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			result := DepthFirstSearch(tc.input)

			if !vertexAttrIsEqual(tc.expected, result) {
				for _, r := range(result) {
					t.Errorf("Expected return: %s, but got: %s", r.Pretty(), r.Pretty())
				}
			}
		})
	}
}

func vertexAttrIsEqual(vertices []*VertexAttr, toCompare []*VertexAttr) bool {
	for i, v := range(vertices) {
		vToCompare := toCompare[i]

		if 
			!(v.AdjIndex == vToCompare.AdjIndex &&
			v.Color == vToCompare.Color &&
			v.D == vToCompare.D &&
			v.F == vToCompare.F &&
			v.Prev == vToCompare.Prev ){
				return false
			}
	}

	return true
}	