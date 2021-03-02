class Node:
    def __init__(self, char: str, time: int):
        self.c = char
        # 表示该节点是否是一个单词的结束点
        self.end = False
        # 表示该节点被多少单词共用（由于这道题没有delete操作，所以这个成员可省）
        self.times = 0
        self.children = defaultdict(dict)


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 初始化root节点
        # children 是一个字典，key是'a'-'z'，value是以下一个字符 'a', 'b', ..., 'z'的Node
        self.root = Node('#', 1)


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curNode = self.root
    
        for ch in word:
            if ch not in curNode.children:
                curNode.children[ch] = Node(ch, 1)
                curNode = curNode.children[ch]
            else:
                curNode = curNode.children[ch]
                curNode.times += 1
        curNode.end = True


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curNode = self.root

        for ch in word:
            if ch not in curNode.children:
                return False
            else:
                curNode = curNode.children[ch]
        return curNode.end == True


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curNode = self.root

        for ch in prefix:
            if ch not in curNode.children:
                return False
            else:
                curNode = curNode.children[ch]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
