#include <bits/stdc++.h>
#define ll long long
using namespace std;

int histogram(vector<int> v)
{
    int n = v.size();
    int x, area = 0;
    vector<int> prev;
    vector<int> next;

    stack<int> s1; // FOR PREV
    stack<int> s2; // FOR NEXT

    for (int i = 0; i < n; i++)
    {
        while (!s1.empty() && v[s1.top()] >= v[i])
            s1.pop();

        while (!s2.empty() && v[s2.top()] >= v[n - i - 1])
            s2.pop();

        if (s1.empty())
            prev.push_back(-1);
        else
            prev.push_back(s1.top());

        if (s2.empty())
            next.push_back(n);
        else
            next.push_back(s2.top());

        s1.push(i);
        s2.push(n - i - 1);
    }

    for (int i = 0; i < n; i++)
    {
        x = (next[i] - prev[i] - 1) * v[i];
        area = max(area, x);
    }
    return area;
}

int main()
{
    int row, col;
    cout << "ROW : ";
    cin >> row;
    cout << "COL : ";
    cin >> col;
    vector<vector<int>> v;
    int x;

    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    int maxArea;
    vector<int> curr = v[0];
    maxArea = histogram(curr);

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
                curr[j]++;
            else
                curr[j] = 0;
        }
        maxArea = max(maxArea, histogram(curr));
    }
    cout << maxArea << endl;

    return 0;
}