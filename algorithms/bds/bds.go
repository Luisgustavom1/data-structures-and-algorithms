package bds

import (
	"data-structures-and-algorithms/data-structures/graph"
	"fmt"
)

type VertexAttr struct {
	D int `json:"d"`
	F int `json:"f"`
	Color graph.Colors `json:"color"`
	Prev int `json:"prev"`
	AdjIndex int `json:"adjIndex"`
}

// References: Algoritmos: Teoria e Prática -> Thomas H. Cormen
// Page 440
var time = 0

func DepthFirstSearch(g graph.GraphAdj) []VertexAttr {
	verticesAttr := []VertexAttr{}

	for i := range g.Link {
		verticesAttr = append(verticesAttr, VertexAttr{
			Color: graph.White,
			Prev: -1,
			D: -1,
			F: -1,
			AdjIndex: i,
		})
	}

	time = 0

	for i := range(verticesAttr) {
		v := &verticesAttr[i]

		if v.Color == graph.White {
			DFSVisit(g, &verticesAttr, v)
		}
	}

	return verticesAttr
}

func DFSVisit(g graph.GraphAdj, va *[]VertexAttr, u *VertexAttr) {
	time = time + 1
	u.D = time
	u.Color = graph.Gray

	vIndex := g.Link[u.AdjIndex]
	var vertex *VertexAttr 
	for vIndex != nil {
		vertex = &(*va)[vIndex.Data]
		if vertex.Color == graph.White {
			(*vertex).Prev = u.AdjIndex
			DFSVisit(g, va, vertex)
		}
		vIndex = vIndex.Next
	}

	u.Color = graph.Black
	time = time + 1
	u.F = time
}

func (va VertexAttr) Pretty() string {
	return fmt.Sprintf(
		"%d -> %d %d %d %d", 
			va.AdjIndex, va.Color, va.Prev, va.D, va.F,
	)
}