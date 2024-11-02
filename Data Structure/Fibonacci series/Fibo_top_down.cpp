#include <iostream>
using namespace std;
#include <vector>

int fibo(int n, vector<int> memo)
{
    if (n == 0 || n == 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);

    return memo[n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> memo(n + 1, -1);

    int result = fibo(n, memo);
    cout << result;
}