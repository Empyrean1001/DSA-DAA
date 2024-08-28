class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for tok in tokens:
            if tok not in ["+", "-", "*", "/"]:
                stack.append(int(tok))
            elif tok == "+":
                stack.append(stack.pop(-2) + stack.pop(-1))
            elif tok == "-":
                stack.append(stack.pop(-2) - stack.pop(-1))
            elif tok == "*":
                stack.append(stack.pop(-2) * stack.pop(-1))
            elif tok == "/":
                stack.append(int(stack.pop(-2) / stack.pop(-1)))
            print(stack[-1])
        return stack[-1]