using System;
using System.Collections.Generic;

namespace DataStructures
{
    public class BinarySearchTree
    {
        public TreeNode Root { get; set; }

        private TreeNode PrivateInsert(TreeNode root, int value)
        {
            if (root == null)
            {
                root = new TreeNode { data = value };
                return root;
            }
            TreeNode current = root;
            if (current.data == value)
                return current;
            if (current.data < value)
            {
                if (current.Left == null)
                {
                    current.Left = new TreeNode { data = value };
                    return current.Left;
                }
                else
                    return PrivateInsert(current.Left, value);
            }
            else
            {
                if (current.Right == null)
                {
                    current.Right = new TreeNode { data = value };
                    return current.Right;
                }
                else
                    return PrivateInsert(current.Right, value);
            }
        }

        public TreeNode Insert(int value) => PrivateInsert(Root, value);

        private TreeNode PrivateSearch(TreeNode root, int value)
        {
            TreeNode current = root;
            return current.data == value
                ? current
                : current.data < value
                    ? current.Left == null
                        ? null
                        : PrivateSearch(current.Left, value)
                    : current.Right == null
                        ? null
                        : PrivateSearch(current.Right, value);
        }

        public TreeNode Search(int value) => PrivateSearch(Root, value);

        private TreeNode PrivateFindParent(TreeNode root, int value)
        {
            if ((root == null) || (root.data == value))
                return null;
            if (root.data < value)
                return root?.Left.data == value ? root : PrivateFindParent(root.Left, value);
            else
                return root?.Right.data == value ? root : PrivateFindParent(root.Right, value);
        }

        public bool Delete(int value)
        {
            var toDelete = PrivateSearch(Root, value);
            if (toDelete == null)
                return false;
            if (toDelete.Left != null)
            {
                // Find the biggest from smaller TreeNodes
                var temporary = toDelete.Left;
                while (temporary.Right != null)
                    temporary = temporary.Right;
                toDelete.data = temporary.data;
                if (temporary.Right != null)
                {
                    temporary.data = temporary.Left.data;
                    // CAUTION! Proper order of assignment
                    temporary.Right = temporary.Left.Right;
                    var anotherTemp = temporary.Left.Left;
                    temporary.Left.Dispose();
                    temporary.Left = anotherTemp;
                }
            }
            else if (toDelete.Right != null)
            {
                // Find the lowest from bigger TreeNodes
                var temporary = toDelete.Right;
                while (temporary.Left != null)
                    temporary = temporary.Left;
                toDelete.data = temporary.data;
                if (temporary.Right != null)
                {
                    temporary.data = temporary.Right.data;
                    // CAUTION! Proper order of assignment
                    temporary.Left = temporary.Right.Left;
                    var anotherTemp = temporary.Right.Right;
                    temporary.Right.Dispose();
                    temporary.Right = anotherTemp;
                }
            }
            else
            {
                var parent = PrivateFindParent(Root, value);
                if (parent?.Left.data == value)
                {
                    parent.Left.Dispose();
                    parent.Left = null;
                }

                else
                {
                    parent.Right.Dispose();
                    parent.Right = null;
                }
            }
            return false;
        }

        private void PrivatePreOrderTraversal(TreeNode root, Action<TreeNode> TreeNodeAction)
        {
            TreeNodeAction(root);
            if (root.Left != null)
                PrivatePreOrderTraversal(root.Left, TreeNodeAction);
            if (root.Right != null)
                PrivatePreOrderTraversal(root.Right, TreeNodeAction);
        }
        public void PreOrderTraversal(Action<TreeNode> TreeNodeAction)
        {
            PrivatePreOrderTraversal(Root, TreeNodeAction);
        }

        private void PrivateInOrderTraversal(TreeNode root, Action<TreeNode> TreeNodeAction)
        {
            if (root.Left != null)
                PrivateInOrderTraversal(root.Left, TreeNodeAction);
            TreeNodeAction(root);
            if (root.Right != null)
                PrivateInOrderTraversal(root.Right, TreeNodeAction);
        }
        public void InOrderTraversal(Action<TreeNode> TreeNodeAction)
        {
            PrivateInOrderTraversal(Root, TreeNodeAction);
        }

        private void PrivatePodOrderTraversal(TreeNode root, Action<TreeNode> TreeNodeAction)
        {
            if (root.Left != null)
                PrivatePodOrderTraversal(root.Left, TreeNodeAction);
            if (root.Right != null)
                PrivatePodOrderTraversal(root.Right, TreeNodeAction);
            TreeNodeAction(root);
        }

        public void PostOrderTraversal(Action<TreeNode> TreeNodeAction)
        {
            PrivatePodOrderTraversal(Root, TreeNodeAction);
        }

        private void PrivateLevelOrderTraversal(TreeNode root, int level, List<List<TreeNode>> treeLevels)
        {
            if (treeLevels.Count < level)
                treeLevels.Add(new List<TreeNode>());
            treeLevels[level - 1].Add(root);
            if (root.Left != null)
                PrivateLevelOrderTraversal(root.Left, level + 1, treeLevels);
            if (root.Right != null)
                PrivateLevelOrderTraversal(root.Right, level + 1, treeLevels);
        }

        public void LevelOrderTraversal(Action<TreeNode> TreeNodeAction, Action levelAction)
        {
            List<List<TreeNode>> treeLevels = new List<List<TreeNode>>();
            int currentLevel = 1;

            PrivateLevelOrderTraversal(Root, currentLevel, treeLevels);

            for (int i = 0; i < treeLevels.Count; i++)
            {
                List<TreeNode> listItem = treeLevels[i];
                for (int j = 0; j < listItem.Count; j++)
                {
                    TreeNode item = listItem[j];
                    TreeNodeAction(item);
                }

                levelAction();
            }
        }
    }
}
