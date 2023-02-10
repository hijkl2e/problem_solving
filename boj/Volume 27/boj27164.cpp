#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N + M);
	for (auto &[u, v] : A) {
		string s;
		cin >> s >> u;
		if (s == "Act") {
			cin >> v;
		} else {
			v = -1;
		}
	}
	ll X = 1, Y = 1;
	deque<int> B, C;
	vector<int> D{0};
	for (int i = 0; i < N; ++i) {
		auto &[u, v] = A[i];
		if (v == -1) {
			if (u) {
				D.push_back(u);
			}
			continue;
		}
		if (u < 2 && v < 2) {
			continue;
		}
		if (u == 0) {
			B.push_back(v);
		} else if (v == 0) {
			C.push_back(u);
		} else {
			X += u - 1;
			Y += v - 1;
		}
	}
	sort(B.rbegin(), B.rend());
	sort(C.rbegin(), C.rend());
	sort(D.rbegin(), D.rend());
	vector<ll> E;
	stack<int> st;
	int last = 1e9;
	bool f1 = X > 1 || Y > 1, f2 = true, f3{};
	for (int i = 0; B.size(); ++i) {
		while (B.size()) {
			if (X) {
				last = i ? last : B.front();
				Y += B.front() - 1;
				B.pop_front();
				--X;
			} else if (C.size() && (i || f1)) {
				X += C.front() - 1;
				st.push(C.front() - 1);
				C.pop_front();
				--Y;
			} else {
				break;
			}
		}
		E.push_back(Y);
		if (i == 0) {
			f2 = X;
			f3 = C.size();
		}
		++X;
	}
	while (E.size() < 1000001) {
		if (st.size() && X == st.top()) {
			X -= st.top(); st.pop();
			++Y;
		}
		E.push_back(Y);
		++X;
	}
	vector<int> F(D.size() + 1);
	partial_sum(D.begin(), D.end(), F.begin() + 1);
	int ans = F[min<ll>(E[0], D.size())], maxv{};
	for (int i = N; i < N + M; ++i) {
		auto &[u, v] = A[i];
		if (v == -1) {
			maxv = max(maxv, u);
			continue;
		}
		if (u < 2 && v < 2) {
			continue;
		}
		ll x{};
		if (u == 0) {
			if (f2) {
				x = v - 1;
			} else if (f1 && f3) {
				x = v - 2;
			} else if (v > last) {
				x = v - last;
			}
			x = min<ll>(E[0] + x, D.size());
		} else if (v || f1) {
			x = min<ll>(E[u - 1] + v - 1, D.size());
		}
		ans = max(ans, F[x]);
	}
	ans = max(ans, F[min<ll>(E[0] - 1, D.size())] + maxv);
	cout << ans << "\n";
	return 0;
}
