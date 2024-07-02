type Node<T> = {
    value: T,
    prev?: Node<T>,
}

export default class Stack<T> {
    public length: number;
    private head?: Node<T>;

    constructor() {
        this.head = undefined;
        this.length = 0;
    }

    push(item: T): void {
        this.length++;
        const node: Node<T> = { value: item }
        if (!this.head) {
            this.head = node;
            return;
        }

        node.prev = this.head;
        this.head = node;
        return;
    }

    pop(): T | undefined {
        if (!this.head) return;

        this.length--;
        const head = this.head;
        this.head = this.head?.prev;

        return head?.value;
    }

    peek(): T | undefined {
        return this.head?.value;
    }
}