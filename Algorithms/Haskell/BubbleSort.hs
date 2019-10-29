bubblesort' :: (Ord a) => [a] -> [a]
bubblesort' [] = []
bubblesort' [x] = [x]
bubblesort' (x:xs)
    | x <= head xs = x : bubblesort' xs
    | x > head xs = head xs : bubblesort' (x: tail xs)

bubblesort :: (Ord a) => [a] -> [a]
bubblesort xs = foldl (\acc _ -> bubblesort' acc) xs xs