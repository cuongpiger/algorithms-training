from typing import List, Any

class Heap:
    
    def __init__(self) -> None:
        self.items = []
    
    def enqueue(self, ad: Any, priority: int):
        item = (priority, ad)
        self.items.append(item)
        self.items = sorted(self.items, reverse=True)
    
    def dequeue(self): 
        processed_item = self.items[0]
        self.items = self.items[1:]
        return processed_item[1]
    
    def len(self):
        return len(self.items)
    
    def is_empty(self):
        return self.len() < 1
    

def main():
    ads = [(10, "ad 1"), (1, "ad 2"), (99, "ad 3")]
    heap = Heap()
    
    for item in ads:
        heap.enqueue(item[1], item[0])
    
    while not heap.is_empty():
        first = heap.dequeue()
        print(f"The first item is: {first}")
        
    
main()