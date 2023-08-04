package graph

import ll "data-structures-and-algorithms/data-structures/linked-list"

type GraphAdj struct { // list of adjacencies
	Link GraphLink `json:"link"`
}

type GraphLink = []*ll.Node[int]

type VertexAttr struct {
	D int `json:"d"`
	Color Colors `json:"color"`
	Prev int `json:"prev"`
}

type Colors uint

const (
	White Colors = iota
	Gray
	Black
)

func NewGraphAdj() *GraphAdj {
	return &GraphAdj{
		Link: []*ll.Node[int]{},
	}
}