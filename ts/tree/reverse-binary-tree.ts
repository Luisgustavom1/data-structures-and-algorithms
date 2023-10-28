import { Node } from "./node";

export function reverseBinaryTree(root: Node | null) {
  if (root === null) return root;
  const tmpRight = root.right;
  root.right = reverseBinaryTree(root.left);
  root.left = reverseBinaryTree(tmpRight);
  return root;
}