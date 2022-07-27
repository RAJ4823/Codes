#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minimum_cost(priority_queue<int> &pq)
{
    int ans = 0, a, b, sum;
    while (pq.size() > 1)
    {
        a = pq.top();
        pq.pop();

        b = pq.top();
        pq.pop();

        sum = a + b;
        ans += (-sum);
        pq.push(sum);
    }
    return ans;
}

int main()
{
    int n, x;
    cin >> n;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(-x);
    }

    int cost = minimum_cost(pq);
    cout << cost << endl;
    return 0;
}