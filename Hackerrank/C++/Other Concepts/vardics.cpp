long long int power(int n, int k)
{
    long long int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans *= n;
    }
    return ans;
}
template <bool... digits>
int reversed_binary_value()
{
    const size_t size = sizeof...(digits);
    bool bits[size] = {digits...};
    int ans = 0, i;
    for (i = 0; i < size; i++)
    {
        ans += bits[i] * (1 << i);
    }
    return ans;
}