package node

type Node struct {
	Value int
	Left  *Node
	Right *Node
}

func NewNode(value int) *Node {
	return &Node{
		Value: value,
		Left: nil,
		Right: nil,
	}
}