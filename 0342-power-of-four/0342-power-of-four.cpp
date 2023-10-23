class Solution {
public:
    bool isPowerOfFour(int n)
{
    long int num = 1;
    if (n == 0)
    {
        return false;
    }
    while (num <= n)
    {
        if (num == n)
        {
            return true;
        }
        num *= 4;
    }
    return false;
}
};