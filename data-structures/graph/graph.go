package graph

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