#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
};

double get_x(line &l1, line &l2) {
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

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
			cin >> A[i] >> B[i];
		}
		for (int k = 0; k < 2; ++k) {
			stack<int> st;
			for (int i = 0; i < N; ++i) {
				while (st.size()) {
					int x = st.top();
					if (B[x] - A[x] <= B[i] - A[i]) {
						st.pop();
					} else {
						break;
					}
				}
				st.push(i);
			}
			vector<int> C, D;
			while (st.size()) {
				int x = st.top(); st.pop();
				C.push_back(-A[x]);
				D.push_back(B[x]);
			}
			A = C, B = D;
			N = A.size();
		}
		vector<line> C;
		ll ans{};
		for (int i = 0, j = 0; i < N; ++i) {
			ll k = B[i] - A[i];
			line L{2 * k, k * k + ans, -INF};
			while (C.size()) {
				L.c = get_x(L, C.back());
				if (L.c < C.back().c - EPS) {
					C.pop_back();
				} else {
					break;
				}
			}
			C.push_back(L);
			k = A[i] + B[i];
			while (j + 1 < C.size() && C[j + 1].c - EPS < k) {
				++j;
			}
			ans = C[j].a * k + C[j].b + k * k;
		}
		cout << ans / 4 << "." << setfill('0') << setw(2) << ans % 4 * 25 << "\n";
	}
	return 0;
}
