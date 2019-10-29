//#1137
 int tribonacci(int n){

    int first = 0;
    int second = 1;
    int third = 1;
    int result = 0;

    if (n == 0) result = first;
    if (n == 1) result = second;
    if (n == 2) result = third;

    while(n > 2)
    {
        result = first + second + third;
        first = second;
        second = third;
        third = result;
        n--;
    }

    return result;  
    
}
