function traversal(head: BinaryNode<number>, res: number[]) {
  res.push(head.value);
  if (head.left) traversal(head.left, res);
  if (head.right) traversal(head.right, res);
}

export default function pre_order_search(head: BinaryNode<number>): number[] {
  const res: number[] = [];
  traversal(head, res);
  return res;
}