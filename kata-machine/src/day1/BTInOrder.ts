function traversal(head: BinaryNode<number>, res: number[]) {
  if (head.left) traversal(head.left, res);
  res.push(head.value);
  if (head.right) traversal(head.right, res);
}

export default function in_order_search(head: BinaryNode<number>): number[] {
  const res: number[] = [];
  traversal(head, res);
  return res;
}