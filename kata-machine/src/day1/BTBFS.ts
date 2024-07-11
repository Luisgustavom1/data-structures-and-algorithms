import Queue from "./Queue";

export default function bfs(head: BinaryNode<number>, needle: number): boolean {
  if (head.value === needle) return true;

  const queue = new Queue<BinaryNode<number>>();
  queue.enqueue(head)

  while (queue.length > 0) {
    const n = queue.dequeue();
    if (n?.value === needle) return true;
    if (n?.left) queue.enqueue(n.left);
    if (n?.right) queue.enqueue(n.right);
  }

  return false;
}