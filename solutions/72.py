class TrieNode:
    def __init__(self):
        self.child = [None] * 10
        self.wordEnd = False

# Method to insert a key into the Trie
def insert_key(root, key):
    # Initialize the curr pointer with the root node
    curr = root

    # Iterate across the length of the string
    for c in key:
        # Check if the node exists for the 
        # current character in the Trie
        index = int(c)
        if curr.child[index] is None:

            # If node for current character does 
            # not exist then make a new node
            new_node = TrieNode()

            # Keep the reference for the newly
            # created node
            curr.child[index] = new_node

        # Move the curr pointer to the
        # newly created node
        curr = curr.child[index]

    # Mark the end of the word
    curr.word_end = True

# Method to search a key in the Trie
def search_key(root, key):

    # Initialize the curr pointer with the root node
    curr = root
    longest = 0

    # Iterate across the length of the string
    for l, c in enumerate(key):

        # Check if the node exists for the 
        # current character in the Trie
        index = int(c)
        if curr.child[index] is None:
            return longest

        # Move the curr pointer to the 
        # already existing node for the 
        # current character
        curr = curr.child[index]
        longest = l + 1

    # Return true if the word exists 
    # and is marked as ending
    return longest

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        root = TrieNode()
        res = 0
        for s in arr1:
            insert_key(root, str(s))

        for s in arr2:
            str_s = str(s)
            if len(str_s) < res:
                continue

            res = max(res, search_key(root, str_s))

        return res
