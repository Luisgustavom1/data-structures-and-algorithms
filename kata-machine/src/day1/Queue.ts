type Node<T> = {
    value: T,
    next?: Node<T>,
}

export default class Queue<T> {
    public length: number;
    private head: Node<T> | undefined;
    private tail: Node<T> | undefined

    constructor() {
        this.tail = this.head = undefined;
        this.length = 0;
    }

    enqueue(item: T): void {
        this.length++;
        const node: Node<T> = { value: item };
        if (!this.tail) {
            this.head = this.tail = node;
            return;
        }

        this.tail.next = node;
        this.tail = node;
        return;
    }

    dequeue(): T | undefined {
        if (!this.head) return undefined;

        this.length--;
        
        const head = this.head;
        this.head = this.head?.next

        // free
        head.next = undefined;

        if (this.length === 0) this.head = this.tail = undefined;

        return head.value;
    }

    peek(): T | undefined {
        return this.head?.value;
    }
}