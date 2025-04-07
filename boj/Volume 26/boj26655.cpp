#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		A[i] -= 20;
	}
	ii ans;
	for (int i = 1; i < N + 2; ++i) {
		ans.first += abs(A[i] - A[i - 1]);
	}
	stack<int> st;
	for (int i = 1; i < N + 2; ++i) {
		while (st.size() && st.top() > A[i]) {
			int x = st.top(); st.pop();
			int y = st.empty() || st.top() < A[i] ? A[i] : st.top();
			ans.second += (x - y - 1) / 40 + 1;
		}
		if (st.empty() || st.top() < A[i]) {
			st.push(A[i]);
		}
	}
	ans.second *= 4;
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
