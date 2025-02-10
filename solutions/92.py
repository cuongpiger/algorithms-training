class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        res = 0
        while mainTank >= 5:
            res += 5
            mainTank -= 5
            if additionalTank > 0:
                mainTank += 1
                additionalTank -= 1

        return (res + mainTank) * 10

        # or return (mainTank + min((mainTank - 1) // 4, additionalTank)) * 10