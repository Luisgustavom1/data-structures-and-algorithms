package linkedlist

import "fmt"

type Node struct {
	data string
	next *Node
}

func NewLinkedList(initialValue string) *Node {
	head := &Node{
		data: initialValue,
		next: nil,
	}

	return head
}

func (node *Node) AddNode(value string) {
	isTail := node.next == nil
	if isTail {
		node.next = &Node{
			data: value,
			next: nil,
		}
	} else {
		newNode := &Node{
			data: value,
			next: node.next,
		}

		node.next = newNode
	}
}

func (node *Node) Print() {
	for node != nil {
		fmt.Println(node.data)
		node = node.next
	}
}