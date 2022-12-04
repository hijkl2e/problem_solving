#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	stack<int> st;
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (st.size() + 1 < A[i]) {
			yes = false;
			break;
		}
		while (st.size() >= A[i]) {
			st.pop();
		}
		if (st.size()) {
			++B[st.top()];
		}
		st.push(i);
	}
	if (yes) {
		for (int i = 0; i < N; ++i) {
			cout << B[i] << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
