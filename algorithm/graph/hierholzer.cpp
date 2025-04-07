#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;

vector<int> hierholzer(int s) {
	vector<int> ret;
	vector<int> idx(G.size());
	stack<int> st;
	st.push(s);
	while (st.size()) {
		int u = st.top();
		if (idx[u] == G[u].size()) {
			ret.push_back(u);
			st.pop();
		} else {
			st.push(G[u][idx[u]++]);
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
