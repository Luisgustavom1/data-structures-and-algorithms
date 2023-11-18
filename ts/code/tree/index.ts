import { Node } from "./node";
import { printTree } from "./print-tree";
import { reverseBinaryTree } from "./reverse-binary-tree";

const right = new Node(30, new Node(25), new Node(35));
const left = new Node(5, new Node(3), new Node(6));
const root = new Node(20, left, right);

printTree(root)
console.log('\n\n');
printTree(reverseBinaryTree(root))
