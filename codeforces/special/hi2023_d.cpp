#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> B[i];
		}
		int M{};
		cin >> M;
		map<int, int> freq;
		while (M--) {
			int x{};
			cin >> x;
			++freq[x];
		}
		bool yes = true;
		for (int i = 0; i < N; ++i) {
			yes &= A[i] >= B[i];
		}
		stack<int> st;
		for (int i = 0; i < N; ++i) {
			while (st.size() && st.top() < B[i]) {
				st.pop();
			}
			if (A[i] > B[i] && (st.empty() || st.top() > B[i])) {
				yes &= freq[B[i]]-- > 0;
				st.push(B[i]);
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
