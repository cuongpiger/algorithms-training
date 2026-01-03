class MyHashMap:

    def __init__(self):
        self.heap = dict()

    def put(self, key: int, value: int) -> None:
        self.heap[key] = value

    def get(self, key: int) -> int:
        return self.heap.get(key, -1)

    def remove(self, key: int) -> None:
        if self.heap.get(key, None) is not None:
            del self.heap[key]
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
