// Link: https://leetcode.com/problems/number-of-good-paths

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-good-paths
 *  RUNTIME: 640 ms
 *  MEMORY: 129.4 MB
 *  DATE: 1-15-2023, 6:48:48 PM
 *
 */

// Solution:

class Solution {
public:
    // For finding ultimate parent of union set
    int find(vector<int> &par,int i) {
		if(i == par[i]) return i;
		return par[i] = find(par, par[i]);
	}

	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = n;

        vector<pair<int,int>> vc(n);    // For storing value-count pairs
	    vector<int> par(n);             // For storing ulimate parent

        // Initializing values
		for(int i=0;i<n;i++){
			par[i] = i;
			vc[i] = {vals[i], 1};
		}

        // Sorting the edge by max values first
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
		});

		for(auto &data: edges){
			int u = find(par, data[0]);
			int v = find(par, data[1]);

            // If values of both edges is different then add them into same set	
			if(vc[u].first > vc[v].first)
                par[v] = u;
			else if(vc[u].first < vc[v].first)
                par[u] = v;
			else{
                // Otherwise combine both set into onne
				par[u] = v;

				ans += vc[u].second * vc[v].second;
				vc[v].second += vc[u].second;
			}
		}
		return ans;
	}
};
