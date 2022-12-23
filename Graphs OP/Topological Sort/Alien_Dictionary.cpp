//? https://practice.geeksforgeeks.org/problems/alien-dictionary/1
//! https://leetcode.com/problems/alien-dictionary/ (Requires Premium :( )

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    //! Topo Sort
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> ind(V, 0);
        for (int i = 0; i < V; i++)
            for (auto x : adj[i])
                ind[x]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (ind[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto neigh : adj[node])
            {
                ind[neigh]--;
                if (ind[neigh] == 0)
                    q.push(neigh);
            }
        }
        return topo;
    }

public:
    string findOrder(string dict[], int n, int k)
    {
        vector<int> adj[k];
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                // Find the first non-matching word in two strings
                // And make directed edge from alphabet of s1 to s2
                if (s1[j] != s2[j])
                {
                    // Converting alphabets to numbers for storing in arrays and easy access
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        // Now perform the topo sort the directed graph we made
        // This will give the correct ordering of aliean dictionary
        vector<int> topo = topoSort(k, adj);
        string ans = "";
        for (auto &val : topo)
            ans += (char)(val + 'a');
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends