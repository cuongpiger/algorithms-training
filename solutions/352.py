class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        money = [0, 0, 0]
        for bill in bills:
            if bill == 5:
                money[0] += 1
            elif bill == 10:
                money[0] -= 1
                if money[0] < 0:
                    return False

                money[1] += 1
            else:
                if money[1] > 0 and money[0] > 0:
                    money[1] -= 1
                    money[0] -= 1
                elif money[0] > 2:
                    money[0] -= 3
                else:
                    return False
                
                money[2] += 1


        return True

