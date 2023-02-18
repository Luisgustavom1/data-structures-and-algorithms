package bst

import (
	"data-structures/shared/node"
)

type BinarySearchTree struct {
	Root *node.Node
}

func NewBinarySearchTree() *BinarySearchTree {
	return &BinarySearchTree{
		Root: nil,
	}
}

func (bst *BinarySearchTree) AddNode(value int) {
	newNode := node.NewNode(value)

	if bst.Root == nil {
		bst.Root = newNode
		return
	}
	
	var currentNode *node.Node = bst.Root

	for {
		if value < currentNode.Value {
			if currentNode.Left == nil {
				currentNode.Left = newNode
				return
			}

			currentNode = currentNode.Left
			continue
		}

		if currentNode.Right == nil {
			currentNode.Right = newNode
			return
		}

		currentNode = currentNode.Right
	}
}
