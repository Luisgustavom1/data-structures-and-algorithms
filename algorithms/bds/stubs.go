package bds

import (
	"data-structures-and-algorithms/data-structures/graph"
	ll "data-structures-and-algorithms/data-structures/linked-list"
)

// https://excalidraw.com/#room=29e06eabd41d513cfef1,vgRPeL08l6gjkS-6JjVhZg
func GenerateGraph() graph.GraphAdj {
	return graph.GraphAdj{
		Link: graph.GraphLink{
			{
				Data: 1,
				Next: &ll.Node[int]{
					Data: 3,
					Next: nil,
				},
			},
			{
				Data: 4,
				Next: nil,
			},
			{
				Data: 4,
				Next: &ll.Node[int]{
					Data: 5,
					Next: nil,
				},
			},
			{
				Data: 1,
				Next: nil,
			},
			{
				Data: 3,
				Next: nil,
			},
			{
				Data: 5,
				Next: nil,
			},
		},
	}
}

func GenerateGraphAttr() []*VertexAttr {
	return []*VertexAttr{
		{
			AdjIndex: 0,
			D: 1,
			F: 8,
			Color: graph.Black,
			Prev: -1,
		},
		{
			AdjIndex: 1,
			D: 2,
			F: 7,
			Color: graph.Black,
			Prev: 0,
		},
		{
			AdjIndex: 2,
			D: 9,
			F: 12,
			Color: graph.Black,
			Prev: -1,
		},
		{
			AdjIndex: 3,
			D: 4,
			F: 5,
			Color: graph.Black,
			Prev: 4,
		},
		{
			AdjIndex: 4,
			D: 3,
			F: 6,
			Color: graph.Black,
			Prev: 1,
		},
		{
			AdjIndex: 5,
			D: 10,
			F: 11,
			Color: graph.Black,
			Prev: 2,
		},
	} 
}