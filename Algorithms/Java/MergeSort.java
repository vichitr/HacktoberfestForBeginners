void merge(int array_[], int left, int middle, int right) 
    { 
        int n1 = middle - left + 1; 
        int n2 = right - middle; 
        int lhs[] = new int [n1]; 
        int rhs[] = new int [n2]; 

        for (int i=0; i<n1; ++i) 
            lhs[i] = array_[left + i]; 
        for (int j=0; j<n2; ++j) 
            rhs[j] = array_[middle + 1+ j]; 

        int i = 0, j = 0; 
        int k = left; 
        while (i < n1 && j < n2) 
        { 
            if (lhs[i] <= rhs[j]) 
            { 
                array_[k] = lhs[i]; 
                i++; 
            } 
            else
            { 
                array_[k] = rhs[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < n1) 
        { 
            array_[k] = lhs[i]; 
            i++; 
            k++; 
        } 
        while (j < n2) 
        { 
            array_[k] = rhs[j]; 
            j++; 
            k++; 
        } 
    } 
    void sort(int array_[], int left, int right) 
    { 
        if (left < right) 
        { 
            int middle = (left+right)/2; 
            sort(array_, left, middle); 
            sort(array_ , middle+1, right);
            merge(array_, left, middle, right); 
        } 
    }