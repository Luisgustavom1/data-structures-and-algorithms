import { describe, expect, it } from "vitest";
import { PostFixEvaluator } from "../code/post-fix-evaluator";

describe("Post fix evaluator", () => {
  const testCases = [
    {
      postfix: ["78", "9", "*", "23", "+"],
      expected: 725,
    },
    {
      postfix: ["23", "78", "9", "*", "+"],
      expected: 725,
    },
    {
      postfix: ["54", "9", "/", "3", "/"],
      expected: 2,
    },
    {
      postfix: ["67", "2", "*", "31", "7", "*", "+"],
      expected: 351,
    },
    {
      postfix: ["1", "6", "*", "3", "/", "4", "**", "9", "%"],
      expected: 7,
    },
    {
      postfix: ["67", "3", "*", "18", "9", "/", "%", "15", "7", "*", "2", "**", "+", "2", "**"],
      expected: 121572676,
    }
  ]

  it.each(testCases)("$postfix should be evaluated to $expected", ({ postfix, expected }) => {
    expect(PostFixEvaluator(postfix)).toStrictEqual(expected);
  })
})