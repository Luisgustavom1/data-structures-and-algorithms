package bfs

import (
	"data-structures-and-algorithms/data-structures/graph"
	ll "data-structures-and-algorithms/data-structures/linked-list"
	"data-structures-and-algorithms/data-structures/queue"
	"fmt"
)

// lf -> List of adjacencies
// References: Algoritmos: Teoria e Prática -> Thomas H. Cormen
// Page 433
func BreadthFirstSearchAdj(g graph.GraphAdj, sourceIndex int) []graph.VertexAttr {
	verticesAttr := []graph.VertexAttr{}

	for range(g.Link) {
		verticesAttr = append(verticesAttr, graph.VertexAttr{
			Color: graph.White,
			D: -1,
			Prev: -1,
		})
	}

	verticesAttr[sourceIndex].Color = graph.White
	verticesAttr[sourceIndex].D = 0

	toVisit := queue.NewQueue[int]()
	toVisit.Enqueue(sourceIndex)

	for len(toVisit.Value) > 0 {
		u, _ := toVisit.Dequeue()
		
		uList := g.Link[u]
		for uList != nil {
			v := &verticesAttr[uList.Data]

			if v.Color == graph.White {
				v.Color = graph.Gray
				v.D = verticesAttr[u].D + 1
				v.Prev = u

				toVisit.Enqueue(uList.Data)
			}

			uList = uList.Next
		}
		
		verticesAttr[u].Color = graph.Black
	}

	return verticesAttr
}

func Example() {
	gr := graph.NewGraphAdj()
	adj := gr.Link
	// Graph illustration https://excalidraw.com/#room=fd579cbbe48ac3d78bb8,NqqB2aEd9BcxvvRNLPzWNg
	adj = append(adj, ll.NewLinkedList[int](1))
	adj[0].AddNode(2)

	adj = append(adj, ll.NewLinkedList[int](2))
	adj[1].AddNode(3)

	adj = append(adj, ll.NewLinkedList[int](3))
	adj[2].AddNode(6)

	adj = append(adj, ll.NewLinkedList[int](4))
	adj[3].AddNode(5)
	adj[3].Next.AddNode(7)

	adj = append(adj, ll.NewLinkedList[int](5))
	adj[4].AddNode(10)

	adj = append(adj, ll.NewLinkedList[int](6))
	adj[5].AddNode(7)
	adj[5].Next.AddNode(10)

	adj = append(adj, ll.NewLinkedList[int](7))
	adj[6].AddNode(9)

	adj = append(adj, ll.NewLinkedList[int](8))
	adj[7].AddNode(9)

	adj = append(adj, ll.NewLinkedList[int](9))

	adj = append(adj, nil)

	adj = append(adj, ll.NewLinkedList[int](8))

	gr.Link = adj

	attrs := BreadthFirstSearchAdj(*gr, 0)

	for i, v := range(attrs) {
		fmt.Printf("%d -> %d %d %d\n", i, v.Color, v.D, v.Prev)
	}
}

