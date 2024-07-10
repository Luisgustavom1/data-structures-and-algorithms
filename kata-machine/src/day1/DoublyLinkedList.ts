type Node<T> = {
	value: T;
	prev?: Node<T>;
	next?: Node<T>;
}

export default class DoublyLinkedList<T> {
    public length: number;
    public head?: Node<T>;	
    public tail?: Node<T>;	

    constructor() {
			this.length = 0;
    }

		isEmpty(): boolean {
			return this.length === 0;
		}

    prepend(item: T): void {
			const node = { value: item } as Node<T>;

			this.length++;
			if (!this.head) {
				this.head = this.tail = node;
				return;
			}

			node.next = this.head;
			this.head.prev = node;
			this.head = node;
    }

    insertAt(item: T, idx: number): void {
			if (idx > this.length) {
				throw new Error("idx no exists");
			}

			const curr = this.getAt(idx);

			if (!curr) throw new Error();

			this.length++;
    	const newNode = {
				value: item,
				prev: curr.prev,
				next: curr, 
			};
			
			if (curr.prev) curr.prev.next = newNode;	
			curr.prev = newNode;
    }

    append(item: T): void {
			this.length++;
			const node: Node<T> = { value: item };

			if (!this.tail) {
				this.head = this.tail = node;
				return;
			}

			node.prev = this.tail;
			this.tail.next = node;
			this.tail = node;
    }

    remove(item: T): T | undefined {
			let curr = this.head;
			for (let i = 0; i < this.length; i++) {
				if (curr?.value === item) break
				curr = curr?.next;
			}

			if (!curr) {
				return;
			}

			return this.removeNode(curr)
    }

    get(idx: number): T | undefined {
			return this.getAt(idx)?.value;
    }

    removeAt(idx: number): T | undefined {
			const node = this.getAt(idx);
			if (!node) {
				return undefined;
			}
			return this.removeNode(node)
    }

		private removeNode(node: Node<T>): T | undefined {
			this.length--;

			if (this.length === 0) {
				this.head = this.tail = undefined;
				return node.value;
			}

			if (node.prev) {
				node.prev.next = node.next;
			}
			
			if (node.next) {
				node.next.prev = node.prev;
			}

			if (node === this.head) {
				this.head = node.next;
			}

			if (node === this.tail) {
				this.tail = node.prev;
			}

			node.next = node.prev = undefined;
			return node.value;
		}

		private getAt(idx: number): Node<T> | undefined {
			let curr: Node<T> = this.head!;
			for (let i = 0; i < idx; i++) {
				curr = curr.next!;
			}
			return curr;
		}
}
