package ll

import "fmt"

type Node[D any] struct {
	Data D `json:"data"`
	Next *Node[D] `json:"nex"`
}

func NewLinkedList[D any](initialValue D) *Node[D] {
	head := &Node[D]{
		Data: initialValue,
		Next: nil,
	}

	return head
}

func (node *Node[D]) AddNode(value D) {
	isTail := node.Next == nil
	if isTail {
		node.Next = &Node[D]{
			Data: value,
			Next: nil,
		}
	} else {
		newNode := &Node[D]{
			Data: value,
			Next: node.Next,
		}

		node.Next = newNode
	}
}

func (node *Node[D]) Print() {
	for node != nil {
		fmt.Println(node.Data)
		node = node.Next
	}
}