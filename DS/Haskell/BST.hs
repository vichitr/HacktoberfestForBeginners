-- Binary Search Tree Implementation in Haskell
-- Bst invariants - a) All Values to the left of a key are less than that key and all values to the right of a key are greater than that key


data Tree a = Empty
        | Node (Tree a) a (Tree a)

-- insertion into bst
-- Implemnet ord constraint cause the keys have to be comparable to maintain bst invariant

insert :: Ord a => a -> Tree a -> Tree a
insert k (Empty ) = (Node Empty k Empty )
insert k (Node l x r) | (k < x) = (Node (insert k l) x r)
                      | (k > x) = (Node l x (insert k r))


-- lookup implementation
lkup :: Ord a => a -> Tree a -> Maybe a
lkup k (Empty) = Nothing
lkup k (Node l x r) | (k == x) = Just x
                      | (k < x) = lkup k l
                      | (k > x) = lkup k r

-- deletion
del :: Ord a => a -> Tree a -> Tree a
del k (Empty) = Empty
del k (Node l x r) | (k > x) = (Node l x (del k r))
                   | (k < x) = (Node (del k l) x r)
                   | otherwise = (Node l key r')
                   where
                     key = minKey r
                     r' = del key r
                     minKey (Node Empty k Empty) = k
                     minKey (Node l x r) = minKey l
