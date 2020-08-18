using System;

namespace DataStructures
{
    public class TreeNode : IDisposable
    {
        public int data;
        public TreeNode Left { get; set; }
        public TreeNode Right { get; set; }

        public void Dispose() => Dispose();
    }
}
