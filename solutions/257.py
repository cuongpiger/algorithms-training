class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = ""
        num1 = [int(x) for x in num1][::-1]
        num2 = [int(x) for x in num2][::-1]
        num1_len, num2_len = len(num1), len(num2)

        prev = 0
        for i in range(max(num1_len, num2_len)):
            sm_val = prev
            if i < num1_len:
                sm_val += num1[i]

            if i < num2_len:
                sm_val += num2[i]

            if sm_val > 9:
                result = f"{sm_val % 10}{result}"
                prev = sm_val // 10
            else:
                result = f"{sm_val}{result}"
                prev = 0

        if prev > 0:
            result = f"{prev}{result}"
        
        return result
