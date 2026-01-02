class MyHashSet:
    def __init__(self):
        self.heap = dict()

    def add(self, key: int) -> None:
        self.heap[key] = True

    def remove(self, key: int) -> None:
        if self.heap.get(key, False) == True:
            del self.heap[key]

    def contains(self, key: int) -> bool:
        return self.heap.get(key, False)


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
