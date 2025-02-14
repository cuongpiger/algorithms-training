class ProductOfNumbers:

    def __init__(self):
        self.list = [1]
        self.size = 0
        

    def add(self, num: int) -> None:
        if not num:
            self.__init__()
        else:
            self.list.append(self.list[-1] * num)
            self.size += 1
        

    def getProduct(self, k: int) -> int:
        if k > self.size:
            return 0
        
        return self.list[-1] // self.list[self.size - k]
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)