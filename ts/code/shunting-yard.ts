import { Queue } from "./queue.js";

export const Op = {
  LParen: "(",
  RParen: ")",
  Multiplication: "*",
  Add: "+",
  Sub: "-",
  Division: "/",
  Remainder: "%",
  Exponent: "**",
}

export type Operator = keyof typeof Op;

const OpSet = new Set(Object.values(Op))

export const ShuttingYard = (expression: string) => {
  const expressionElements = expression.split(' ');
  const stack: Array<string> = [];
  const queue = new Queue<string>();
  let i = 0;

  while (expressionElements.length > i) {
    const el = expressionElements[i];
    i++

    if (isOp(el)) {
      const lastOp = stack[stack.length - 1];

      if (el === Op.RParen) {
        while(stack.length > 0) {
          const op = stack.pop();
          
          if (op === Op.LParen) {
            break;
          }

          queue.enqueue(op!);
        }
        continue;
      }

      if (isHighPrecedenceOp(lastOp)) {
        const op = stack.pop();
        queue.enqueue(op!);
      }

      stack.push(el);
    }

    if (isNumber(el)) {
      queue.enqueue(el)
    }
  }

  while(stack.length) {
    queue.enqueue(stack.pop()!)
  }

  return queue.getQueueAsArray()
}

export const isOp = (str: string): str is Operator => {
  return OpSet.has(str);
}

export const isHighPrecedenceOp = (str: string) => {
  return str === Op.Multiplication 
    || str === Op.Exponent
    || str === Op.Division
    || str === Op.Exponent;
}

export const isNumber = (str: string) => {
  return /[0-9]/.test(str);
}