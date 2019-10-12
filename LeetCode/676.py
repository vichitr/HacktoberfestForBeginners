'''
Problem: 676. Implement magic dictionary
https://leetcode.com/problems/implement-magic-dictionary/
Author: Luis Herrera
Summary: Using a trie data structure for fast search
'''

class TrieNode(object):
    def __init__(self):
        self.is_word = False
        self.children = {}


class MagicDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for letter in word:
            if letter not in node.children:
                node.children[letter] = TrieNode()
            node = node.children[letter]
        node.is_word = True

    def find_word(self, root, word, remain):
        if not word:
            if remain == 0 and root.is_word:
                return True
            return False

        for letter, _ in root.children.items():
            if letter == word[0]:
                if self.find_word(root.children[letter], word[1:], remain):
                    return True
            elif remain == 1:
                if self.find_word(root.children[letter], word[1:], 0):
                    return True
        return False

    def buildDict(self, dict):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: None
        """
        for word in dict:
            self.insert(word)


    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        return self.find_word(self.root, word, 1)
