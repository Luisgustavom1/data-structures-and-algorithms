package main

import (
	"fmt"

	"data-structures-and-algorithms/data-structures/graph"
	"data-structures-and-algorithms/data-structures/trees"
)

func main() {
	bst := bst.NewBinarySearchTree()

	bst.AddNode(8)
	bst.AddNode(3)
	bst.AddNode(1)
	bst.AddNode(6)
	bst.AddNode(4)
	bst.AddNode(10)
	bst.AddNode(14)
	bst.AddNode(13)
	bst.AddNode(7)

	fmt.Printf("       %d\n", bst.Root.Value)

	fmt.Println("     /   \\ ")
	fmt.Printf("    %d", bst.Root.Left.Value)
	fmt.Printf("     %d\n", bst.Root.Right.Value)

	fmt.Println("   / \\     \\ ")
	fmt.Printf("  %d", bst.Root.Left.Left.Value)
	fmt.Printf("   %d", bst.Root.Left.Right.Value)

	fmt.Printf("    %d\n", bst.Root.Right.Right.Value)

	fmt.Println("     / \\   /")
	fmt.Printf("    %d", bst.Root.Left.Right.Left.Value)
	fmt.Printf("   %d", bst.Root.Left.Right.Right.Value)

	fmt.Printf("  %d", bst.Root.Right.Right.Left.Value)

	gr := *graph.NewGraph()
	gr["voce"] = []string{"alice", "bob", "claire"}
	gr["bob"] = []string{"anuj", "peggy"}
	gr["alice"] = []string{"peggy"}
	gr["claire"] = []string{"thom", "jhonny"}
	gr["anuj"] = []string{}
	gr["peggy"] = []string{}
	gr["thom"] = []string{}
	gr["jhonny"] = []string{}

	fmt.Println(gr)
	fmt.Println(gr.BreadthFirstSearch("jhonny", "voce"))
	fmt.Println(gr.BreadthFirstSearch("a", "voce"))
}
