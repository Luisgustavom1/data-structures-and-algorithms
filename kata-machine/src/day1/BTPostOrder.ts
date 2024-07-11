function traversal(head: BinaryNode<number>, res: number[]) {
  if (head.left) traversal(head.left, res);
  if (head.right) traversal(head.right, res);
  res.push(head.value);
}

export default function pos_order_search(head: BinaryNode<number>): number[] {
  const res: number[] = [];
  traversal(head, res);
  return res;
}