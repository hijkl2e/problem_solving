#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> hierholzer(int s) {
	vector<int> ret;
	vector<int> idx(N);
	stack<int> st;
	st.push(s);
	while (st.size()) {
		int u = st.top();
		if (idx[u] == N) {
			ret.push_back(u);
			st.pop();
		} else {
			st.push(idx[u]++);
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	vector<int> A = hierholzer(0);
	cout << A.size() << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] + 1 << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
