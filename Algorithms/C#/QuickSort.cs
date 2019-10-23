using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace sortQuickAlgorithm
{
    class quickSortAlgorithm
    {
 
        private int[] array = new int[20];
        private int len;
 
        public void QuickSortAlgorithm()
        {
            sort(0, len - 1);
        }
 
        public void sort(int left, int right)
        {
            int pivot, leftend, rightend;
 
            leftend = left;
            rightend = right;
            pivot = array[left];
 
            while (left < right) { while ((array[right] >= pivot) &amp;&amp; (left < right))
                {
                    right--;
                }
 
                if (left != right)
                {
                    array[left] = array[right];
                    left++;
                }
 
                while ((array[left] >= pivot) &amp;&amp; (left < right))
                {
                    left++;
                }
 
                if (left != right)
                {
                    array[right] = array[left];
                    right--;
                }
            }
 
            array[left] = pivot;
            pivot = left;
            left = leftend;
            right = rightend;
 
            if (left < pivot) { sort(left, pivot - 1); } if (right > pivot)
            {
                sort(pivot + 1, right);
            }
        }
 
        public static void Main()
        {
            quickSortAlgorithm q_Sort = new quickSortAlgorithm();
 
            int[] array = { 41, 32, 15, 45, 63, 72, 57, 43, 32, 52, 183};
            q_Sort.array = array;
            q_Sort.len = q_Sort.array.Length;
            q_Sort.QuickSortAlgorithm();
 
            for (int j = 0; j &lt; q_Sort.len; j++)
            {
                Console.WriteLine(q_Sort.array[j]);
            }
            Console.ReadKey();
        }
    }
}