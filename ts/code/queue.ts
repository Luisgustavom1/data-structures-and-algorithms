export class Queue<T extends unknown = unknown> {
  #queue: Record<string, T> = {};
  private head = 0;
  private tail = 0;

  enqueue(el: T) {
    this.#queue[this.tail] = el;
    this.tail++;
  }

  dequeue(): T | null {
    if (this.isEmpty()) return null;

    const temp = this.#queue[this.head];
    delete this.#queue[this.head];
    this.head++;
    return temp;
  }

  isEmpty() {
    return this.size() === 0;
  }

  size() {
    return this.tail - this.head
  }

  getQueueAsArray() {
    const arr: Array<T> = [];
    let i = this.head;

    while(i < this.tail) {
      arr.push(this.#queue[i]);
      i++;
    }

    return arr;
  }

  get getQueue() {
    return this.#queue;
  }
}