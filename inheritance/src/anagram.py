# detemine wheter two given strings are anagrams use only single hash mapor tree map

def are_anagrams(str1, str2):
    if len(str1) != len(str2):
        return False
    char_count ={}
    for char in str1:
        char_count[char]= char_count.get(char,0)+1
    for char in str2:
        if char not in char_count:
            return False
        char_count[char] -= 1
        if char_count[char] < 0:
            return False
        
    return True

print(are_anagrams("listen", "silent"))  # True
print(are_anagrams("hello", "world"))    # False
print(are_anagrams("anagram", "nagaram")) # True        