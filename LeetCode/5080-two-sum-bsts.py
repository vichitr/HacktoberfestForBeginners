class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        flag = 0
        listTemp = []
        def inOrderList(root) -> List[int]:
            if not root:
                return
            inOrderList(root.left)
            listTemp.append(root.val)
            inOrderList(root.right)
            return(listTemp)
        
        listTree1 = inOrderList(root1)
        listTemp = []
        listTree2 = inOrderList(root2)
       
        for item1 in listTree1:
            for item2 in listTree2:
                result = item1 + item2
                if result == target:
                    flag = 1
                    break

        if flag == 0:
            return False
        else:
            return True

