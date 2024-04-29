import { Stack } from "./stack";

const CHARS = {
  'a': true,
  'b': true,
}
const RULE_THREE_SYMBOL = "+"
const RULE_FOUR_SYMBOL = "?"
const RULE_FIVE_SYMBOL = "*"

function thompsonConstruction(regex: string) {
  const stack = new Stack<string>();

  const isRuleTwo = (ch: string) =>  CHARS[ch];
  const isRuleThree = (ch: string) => ch === RULE_THREE_SYMBOL;
  const isRuleFour = (ch: string) => ch === RULE_FOUR_SYMBOL;
  const isRuleFive = (ch: string) => ch === RULE_FIVE_SYMBOL;

  for (let i = 0; i < regex.length; i++) {
    const ch = regex[i];

    switch (true) {
      case isRuleTwo(ch):
        stack.push(ch);
        break
      case isRuleThree(ch):
        const nfa1 = stack.pop();
        const nfa2 = stack.pop();
        const unifiedNfa = `${nfa2}${ch}${nfa1}`;
        stack.push(unifiedNfa);
        break
      case isRuleFour(ch):
        const nfa3 = stack.pop();
        const nfa4 = stack.pop();
        const concatenatedNfa = `${nfa4}${nfa3}`;
        stack.push(concatenatedNfa);
        break
      case isRuleFive(ch):
        const nfa = stack.pop();
        const nfaClosured = `${nfa}${ch}`;
        stack.push(nfaClosured);
        break
    }
  }

  return stack
}

console.log(thompsonConstruction("aab+*?b?"));