package tree

import (
	"strings"
	"testing"
)

func GenerateAddressBook() *AddressBookNode {
	var addressBook *AddressBookNode

	addressBook = addressBook.InsertContact("Peter", "16 22222-2222")
	addressBook = addressBook.InsertContact("John", "16 99999-9999")
	addressBook = addressBook.InsertContact("Mary", "16 11111-1111")
	addressBook = addressBook.InsertContact("Paul", "16 33333-3333")

	return addressBook
}

func TestTreeSearch(t *testing.T) {
	input := GenerateAddressBook()
	testCases := []struct {
		name     string
		input    *AddressBookNode
		search   string
		expected string
	}{
		{
			"should return 16 99999-9999 to john",
			input,
			"John",
			"16 99999-9999",
		},
		{
			"should return 16 11111-1111 to Mary",
			input,
			"Mary",
			"16 11111-1111",
		},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			result, _ := tc.input.SearchContact(tc.search)

			if result != tc.expected {
				t.Errorf("Expected return: %s, but got: %s", tc.expected, result)
			}
		})
	}
}

func TestTreeDelete(t *testing.T) {
	testCases := []struct {
		name     string
		input    *AddressBookNode
		nameToDelete   string
		height int
	}{
		{
			"should delete John",
			GenerateAddressBook(),
			"John",
			3,
		},
		{
			"should delete Paul",
			GenerateAddressBook(),
			"Paul, Peter",
			2,
		},
	}

	for _, tc := range testCases {
		t.Run(tc.name, func(t *testing.T) {
			namesToDelete := strings.Split(tc.nameToDelete, ", ")
			for _, name := range namesToDelete {
				tc.input = tc.input.DeleteContact(name)
			}
			
			heightAfterDelete := tc.input.Height()
			if heightAfterDelete != tc.height {
				t.Errorf("Expected return: %d, but got: %d", tc.height, heightAfterDelete)
			}

			for _, name := range namesToDelete {
				_, contactExists := tc.input.SearchContact(name)
				if contactExists {
					t.Errorf("Expected return: %t, but got: %t", false, contactExists)
				}
			}
		})
	}
}

func TestTreeHeight(t *testing.T) {
	t.Run("Tree height", func(t *testing.T) {
		root := GenerateAddressBook()
		height := root.Height()

		if 4 != height {
			t.Errorf("Expected return: %d, but got: %d", 4, height)
		}
	})
}