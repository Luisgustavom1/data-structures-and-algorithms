export class Node<T = unknown> {
  constructor(
    public value: T, 
    public left: Node<T> | null = null, 
    public right: Node<T> | null  = null
  ) {}
}
