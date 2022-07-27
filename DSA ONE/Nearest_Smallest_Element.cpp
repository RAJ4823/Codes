#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}
void previous_smallest(vector<int> v)
{
    stack<int> s;
    vector<int> prev;

    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && s.top() >= v[i])
            s.pop();

        if (s.empty())
            prev.push_back(-1);
        else
            prev.push_back(s.top());

        s.push(v[i]);
    }
    cout << "PREV : ";
    print(prev);
}
void next_smallest(vector<int> v)
{
    stack<int> s;
    vector<int> next;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= v[i])
            s.pop();

        if (s.empty())
            next.push_back(-1);
        else
            next.push_back(s.top());

        s.push(v[i]);
    }

    // Setting values in ascending order by swaping first and last elements;
    int n = next.size();
    for (int i = 0; i < n / 2; i++)
        swap(next[i], next[n - i - 1]);

    cout << "NEXT : ";
    print(next);
}

int main()
{
    int size, x;
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

    cout << "ARR  : ";
    print(arr);
    previous_smallest(arr);
    next_smallest(arr);

    return 0;
}