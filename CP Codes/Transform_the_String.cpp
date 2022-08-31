#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseNo = 1;
    cin >> t;
    while (t--)
    {
        string s, f;
        cin >> s >> f;
        int minCount = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int tempCount = 27;
            for (int j = 0; j < f.length(); j++)
            {
                int diff1 = abs(s[i] - f[j]);
                int diff2 = 26 - diff1;
                tempCount = min(tempCount, min(diff1, diff2));
            }
            minCount += tempCount;
        }
        cout << "Case #" << caseNo << ": "<< minCount << endl;
        caseNo++;
    }
}