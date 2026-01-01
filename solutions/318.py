class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack = []

        for x in operations:
            if x == "C":
                stack = stack[:-1]
            elif x == "D":
                stack.append(stack[-1] * 2)
            elif x == "+":
                stack.append(stack[-1] + stack[-2])
            else:
                stack.append(int(x))
        
        return sum(stack)
