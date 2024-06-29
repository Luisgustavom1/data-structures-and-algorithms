export default class SinglyLinkedList<T> implements List<T> {
    public length: number;
    private head: ListNode<T> | undefined;
    private tail: ListNode<T> | undefined;

    constructor() {
        this.head = this.tail = undefined;
        this.length = 0;
    }

    prepend(item: T): void {
        if (this.isEmpty()) {
            this.head = {
                value: item,
                next: this.tail,
                prev: undefined
            }
            this.head = this.tail;
        } else {
            const newNode: ListNode<T> = {
                value: item,
                next: this.head,
                prev: undefined
            }
    
            // [1| ] -> [2| ] -> null
            // [3| ] -> [1| ] -> [2| ] -> null 
    
            this.head!.prev = newNode;
            this.head = newNode;
        }
        this.length++;
    }

    append(item: T): void {
        if (this.isEmpty()) {
            this.head = {
                value: item,
                next: this.tail,
                prev: undefined
            }
            this.tail = this.head;
        } else {
            // [1| ] -> null
            // [2| ] -> [1| ] -> null
            this.tail!.next = {
                value: item,
                prev: this.tail,
                next: undefined,
            }
            this.tail = this.tail!.next;
        }
        this.length++;
    }
    
    insertAt(item: T, idx: number): void {
        if (this.isEmpty() && idx !== 0) throw new Error("Linked list is empty");
        // [1| ] -> [2| ] -> [3| ] -> null
        // [1| ] -> [6| ] -> [2| ] -> [3| ] -> null

        let node = this.head;
        let i = 0;
        while(i < idx) {
            node = node?.next;
            i++;
        }

        const newNode: ListNode<T> = {
            value: item,
            next: node,
        }

        if (node?.prev) {
            newNode.prev = node.prev;
            node.prev.next = newNode;
            node.prev = newNode;
        }

        this.length++;
    }

    remove(item: T): T | undefined {
        if (this.isEmpty()) throw new Error("Linked list is empty");
        // [1| ] -> [6| ] -> [2| ] -> [3| ] -> null
        // [1| ] -> [6| ] -> [3| ] -> null
        
        let nodeToRemove = this.head;
        while(nodeToRemove?.value !== item) {
            if (nodeToRemove?.next === nodeToRemove) return undefined;
            nodeToRemove = nodeToRemove?.next;
        }
        
        if (!nodeToRemove) return undefined;

        if (nodeToRemove.prev) {
            nodeToRemove.prev.next = nodeToRemove.next;
        }

        if (nodeToRemove.next) {
            nodeToRemove.next.prev = nodeToRemove.prev;
        }

        if (item === this.head!.value) {
            this.head = nodeToRemove.next;
        }

        this.length--;
        return nodeToRemove.value; 
    }    

    removeAt(idx: number): T | undefined {
        if (this.isEmpty()) throw new Error("Linked list is empty");
        
        let nodeToRemove = this.head;
        let i = 0;
        while(i < idx) {
            nodeToRemove = nodeToRemove?.next;
            i++;
        }

        if (!nodeToRemove) return undefined;

        if (nodeToRemove.next) {
            nodeToRemove.next.prev = nodeToRemove.prev;
        }

        if (nodeToRemove.prev) {
            nodeToRemove.prev.next = nodeToRemove.next;
        } 

        this.length--;

        if (this.length === 1) {
            this.head = nodeToRemove.next;
        }

        return nodeToRemove.value; 
    }

    get(idx: number): T | undefined {
        if (this.isEmpty()) throw new Error("Linked list is empty");

        let node = this.head;
        let i = 0;
        while(i < idx) {
            node = node?.next;
            i++;
        }

        return node?.value;
    }

    isEmpty(): boolean {
        return this.head === undefined;
    }
}