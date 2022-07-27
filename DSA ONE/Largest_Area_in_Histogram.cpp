#include <bits/stdc++.h>
#define ll long long
using namespace std;

//TIME COMPLEXITY : O(N) BEST

vector<int> previous_smallest(vector<int> v)
{
    stack<int> s;
    vector<int> prev;

    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();

        if (s.empty())
            prev.push_back(-1);
        else
            prev.push_back(s.top());

        s.push(i);
    }
    return prev;
}
vector<int> next_smallest(vector<int> v)
{
    int n = v.size();
    stack<int> s;
    vector<int> next;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();

        if (s.empty())
            next.push_back(n);
        else
            next.push_back(s.top());

        s.push(i);
    }

    // Setting values in ascending order by swaping first and last elements;
    for (int i = 0; i < n / 2; i++)
        swap(next[i], next[n - i - 1]);

    return next;
}

int main()
{
    int size, x, area = 0;
    vector<int> arr;
    vector<int> prev;
    vector<int> next;

    cout << "Size : ";
    cin >> size;
    cout << "Elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    prev = previous_smallest(arr);
    next = next_smallest(arr);

    for (int i = 0; i < size; i++)
    {
        x =   (next[i] - prev[i] - 1)*arr[i];
        area = max(area, x);
    }
    cout << "MAX AREA : " << area << endl;

    return 0;
}