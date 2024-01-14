// https://medium.com/@kiruu1238/building-a-dynamic-address-book-with-binary-search-trees-in-go-a-golang-journey-into-efficient-6b35a209eb07
package tree

import "fmt"

type AddressBookNode struct {
	Name string
	ContactInfo string
	Left *AddressBookNode
	Right *AddressBookNode
}

func (n *AddressBookNode) InsertContact(name, contactInfo string) *AddressBookNode {
	if n == nil {
		return &AddressBookNode{
			Name: name, 
			ContactInfo: contactInfo,
		}
	}

	if name < n.Name {
		n.Left = n.Left.InsertContact(name, contactInfo)
	} else {
		n.Right = n.Right.InsertContact(name, contactInfo)
	}

	return n
}

func (n *AddressBookNode) SearchContact(name string) (string, bool) {
	if n == nil {
		return "", false
	}

	if name == n.Name {
		return n.ContactInfo, true
	}
	n.ToString()
	if name < n.Name {
		return n.Left.SearchContact(name)
	}

	return n.Right.SearchContact(name)
}

func (n *AddressBookNode) DeleteContact(name string) *AddressBookNode {
	if n == nil {
		return nil
	}

	if name < n.Name {
		n.Left = n.Left.DeleteContact(name)
	} else if name > n.Name {
		n.Right = n.Right.DeleteContact(name)
	} else {
		if n.Left == nil {
			return n.Right
		} else if n.Right == nil { 
			return n.Left
		}

		smallest := n.Right.FindMin()
		n.Name = smallest.Name
		n.ContactInfo = smallest.ContactInfo
		n.Right = n.Right.DeleteContact(smallest.Name)
	}

	return n
}

func (n *AddressBookNode) FindMin() *AddressBookNode  {
	current := n

	for current.Left != nil {
		current = current.Left
	}

	return current
}

func (n *AddressBookNode) Height() int {
	if n == nil {
		return 0
	}

	leftHeight := n.Left.Height()
	rightHeight := n.Right.Height()

	if leftHeight > rightHeight {
		return leftHeight + 1;
	}

	return rightHeight + 1;
}

func (n *AddressBookNode) ToString() {
	fmt.Printf("Name: %s, ContactInfo: %s\n", n.Name, n.ContactInfo)
}