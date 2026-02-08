class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        vowels = set("aeiouAEIOU")
        words = sentence.split()
        result = []
        
        for i, word in enumerate(words):
            # Rule 1 & 2: Check first letter
            if word[0] in vowels:
                new_word = word + "ma"
            else:
                new_word = word[1:] + word[0] + "ma"
            
            # Rule 3: Add 'a's based on index (i + 1)
            new_word += "a" * (i + 1)
            
            result.append(new_word)
            
        return " ".join(result)
