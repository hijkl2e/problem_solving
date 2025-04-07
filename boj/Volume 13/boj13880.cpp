#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{};
		cin >> K >> N;
		stack<bool> st;
		while (N > 1) {
			st.push(N % 2);
			N /= 2;
		}
		ll p = 1, q = 1;
		while (st.size()) {
			if (st.top()) {
				p += q;
			} else {
				q += p;
			}
			st.pop();
		}
		cout << K << " " << p << "/" << q << "\n";
	}
	return 0;
}
