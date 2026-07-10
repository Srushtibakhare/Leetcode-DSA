def isAnagram(s, t):

    if len(s) != len(t):
        return False

    count = {}

    for ch in s:
        count[ch] = count.get(ch, 0) + 1

    for ch in t:
        if ch not in count:
            return False

        count[ch] -= 1

        if count[ch] < 0:
            return False

    return True


# Test Cases
print(isAnagram("anagram", "nagaram"))   # True
print(isAnagram("rat", "car"))           # False
print(isAnagram("listen", "silent"))     # True
print(isAnagram("hello", "world"))       # False