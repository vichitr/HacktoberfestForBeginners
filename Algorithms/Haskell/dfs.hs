data Tree a = Node a (Tree a) (Tree a) | Leaf a | Empty deriving(Show, Read, Eq)

-- Travel In Order
dfs :: Tree a -> [a]
dfs Empty = []
dfs (Leaf a) = [a]
dfs (Node a l r) = dfs l ++ [a] ++ dfs r

-- Travel Pre Order
dfsPreOrder :: Tree a -> [a]
dfsPreOrder Empty = []
dfsPreOrder (Leaf a) = [a]
dfsPreOrder (Node a l r) = [a] ++ dfsPreOrder l ++ dfsPreOrder r

-- Travel Post Order
dfsPostOrder :: Tree a -> [a]
dfsPostOrder Empty = []
dfsPostOrder (Leaf a) = [a]
dfsPostOrder (Node a l r) = dfsPostOrder l ++ dfsPostOrder r ++ [a]