class MyQueue:

    def __init__(self):
        self.primary = []
        self.secondary = []
        

    def push(self, x: int) -> None:
        while len(self.primary) > 0:
            self.secondary.append(self.primary[-1])
            self.primary = self.primary[:-1]

        self.primary.append(x)
        while len(self.secondary) > 0:
            self.primary.append(self.secondary[-1])
            self.secondary = self.secondary[:-1]

    def pop(self) -> int:
        if self.empty():
            return None
        top = self.primary[-1]
        self.primary = self.primary[:-1]
        return top

    def peek(self) -> int:
        if self.empty():
            return None
        return self.primary[-1]
        

    def empty(self) -> bool:
        return len(self.primary) == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
