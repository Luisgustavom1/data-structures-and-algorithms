import { Op, Operator, isNumber, isOp } from "./shunting-yard";

export const PostFixEvaluator = (postFix: Array<string>) => {
  const stack: Array<string | number> = [];
  let i = 0;

  while (postFix.length > i) {
    const el = postFix[i];
    if (isNumber(el!)) stack.push(el!);

    if (isOp(el!)) {
      const right = stack.pop();
      const left = stack.pop();

      stack.push(evaluateOperations(el, Number(left), Number(right)));
    }

    i++;
  }

  return stack[0]
}

const evaluateOperations = (op: Operator, left: number, right: number): number => {
  switch(op) {
    case Op.Add:
      return left + right;
    case Op.Sub:
      return left - right;
    case Op.Division:
      return left / right;
    case Op.Exponent:
      return left ** right;
    case Op.Multiplication:
      return left * right;
    case Op.Remainder:
      return left % right;
    default:
      throw new Error("Unexpected operator");
  }
}