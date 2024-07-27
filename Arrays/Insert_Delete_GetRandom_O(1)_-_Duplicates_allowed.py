import random

class RandomizedCollection:

    def __init__(self):
        self.dict1 = {}
        self.liss = []

    def insert(self, val: int) -> bool:
        isNewElement = val not in self.dict1 or not self.dict1[val]
        if val in self.dict1:
            self.dict1[val].append(len(self.liss))
        else:
            self.dict1[val] = [len(self.liss)]
        self.liss.append(val)
        return isNewElement

    def remove(self, val: int) -> bool:
        if val not in self.dict1 or not self.dict1[val]:
            return False
        
        # Get the index of the element to remove
        remove_idx = self.dict1[val].pop()
        
        # If the element to remove is the last element, simply pop from the list
        if remove_idx == len(self.liss) - 1:
            self.liss.pop()
        else:
            # Move the last element to the place of the element to remove
            last_element = self.liss[-1]
            self.liss[remove_idx] = last_element
            
            # Update the dictionary to reflect the new index of the last element
            self.dict1[last_element].remove(len(self.liss) - 1)
            self.dict1[last_element].append(remove_idx)
            
            # Remove the last element from the list
            self.liss.pop()
        
        # Clean up the dictionary if necessary
        if not self.dict1[val]:
            del self.dict1[val]
        
        return True

    def getRandom(self) -> int:
        return random.choice(self.liss)

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
