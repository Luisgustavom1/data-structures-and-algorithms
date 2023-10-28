import { Node } from "./node";

export function printTree(root: Node | null) {
  if (root === null) return;
  printTree(root.left)
  console.log(root.value)
  printTree(root.right)
}