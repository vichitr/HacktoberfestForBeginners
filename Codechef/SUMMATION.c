#include <stdio.h>

int main()
{
    long long int N, k;
    scanf("%lld", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &k);
        printf("%lld\n", (k % 2)?(k+1)/2:-(k+1)/2);
    }
    return 0;
}
