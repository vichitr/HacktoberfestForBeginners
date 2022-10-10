"""""
Convert a palindrome into a non palindrome such that its the lexicographically smallest
non palindrome possible by swapping one character.
The program here finds the first non a element and swaps it for an a.
If the string is full of a the last element is swapped with b.
Time Complexity: O(n)
"""""
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        length=len(palindrome)
        for i in range(0,length//2):
            if palindrome[i]!='a':
                return palindrome[:i]+'a'+palindrome[i+1:]
        return palindrome[:-1]+'b' if length!=1 else ""
                