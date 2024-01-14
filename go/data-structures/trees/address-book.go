// https://medium.com/@kiruu1238/building-a-dynamic-address-book-with-binary-search-trees-in-go-a-golang-journey-into-efficient-6b35a209eb07
package tree

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

	if name < n.Name {
		return n.Left.SearchContact(name)
	}

	return n.Right.SearchContact(name)
}
