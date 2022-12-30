//? https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        int mod = 100000;
        int n = arr.size();
        // Because of modulo the range of value will be 0 to 99999
        vector<int> minSteps(100000, 1e9);
        queue<pair<int, int>> q;

        q.push({start, 0});
        minSteps[start] = 0;

        while (!q.empty())
        {
            int value = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (value == end)
                return steps;
            for (int i = 0; i < n; i++)
            {
                // multiply value by each arr values and get newValue
                int newValue = (value * arr[i]) % mod;
                // Check if the steps required to reach newValue is less than previous minSteps
                if (steps + 1 < minSteps[newValue])
                {
                    minSteps[newValue] = steps + 1;
                    q.push({newValue, steps + 1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends