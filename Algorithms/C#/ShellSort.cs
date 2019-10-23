private void SortArrayWithShellSort()
        {
            int[] array = { 297,183, 464 };
            ShellSort(array);            
        }
       
 
        private void ShellSort(int[] array)
        {
            int n = array.Length;
            int gap = n / 2;
            int temp;
 
            while (gap > 0)
            {
                for (int i = 0; i + gap < n; i++)
                {
                    int j = i + gap;
                    temp = array[j];
 
                    while (j - gap >= 0 && temp < array[j - gap])
                    {
                        array[j] = array[j - gap];
                        j = j - gap;
                    }
 
                    array[j] = temp;
                }
 
                gap = gap / 2;
            }
        }