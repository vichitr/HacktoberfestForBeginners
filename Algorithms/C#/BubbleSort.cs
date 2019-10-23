// Bubble Sort with C#
using System;

namespace BubbleSort
{
    class MainClass
    {
        public static void Main()
        {
            // test numbers to sort
            int[] toSort = { 5, 2, 6, 8, 3};

            // perform bubble sort
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (toSort[j] > toSort[j + 1])
                    {
                        int temp = toSort[j];
                        toSort[j] = toSort[j + 1];
                        toSort[j + 1] = temp;
                    }
                }
            }

            // print to console results
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(toSort[i]);
            }
        }
    }
}
