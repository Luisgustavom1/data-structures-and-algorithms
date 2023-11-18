import { describe, expect, it } from "vitest";
import { ShuttingYard } from "../code/shunting-yard";

describe("Shunting yard algorithm", () => {
  const testCases = [
    {
      expression: "78 * 9 + 23",
      rpn: ["78", "9", "*", "23", "+"]
    },
    {
      expression: "23 + 78 * 9",
      rpn: ["23", "78", "9", "*", "+"]
    },
    {
      expression: "54 / 9 / 3",
      rpn: ["54", "9", "/", "3", "/"]
    },
    {
      expression: "( 67 * 2 ) + ( 31 * 7 )",
      rpn: ["67", "2", "*", "31", "7", "*", "+"]
    },
    {
      expression: " 1 * 6 / 3 ** 3 % 9",
      rpn: ["1", "6", "*", "3", "/", "3", "**", "9", "%"]
    },
    {
      expression: "( ( 67 * 2 ) % ( 2 / 9 ) ) + ( ( 31 * 7 ) ** 9 ) ) ** 2",
      rpn: ["67", "2", "*", "2", "9", "/", "%", "31", "7", "*", "9", "**", "+", "2", "**"]
    }
  ]

  it.each(testCases)("$expression should be converted to $rpn", ({ expression, rpn }) => {
    expect(ShuttingYard(expression)).toStrictEqual(rpn);
  })
})