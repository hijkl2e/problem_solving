#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, ii> B;
	for (int i = 0; i < 31; ++i) {
		for (int j = 0; j < 31; ++j) {
			B[(1 << i) - (1 << j)] = {i, j};
		}
	}
	vector<int> C(31);
	vector<int> D(31);
	vector<int> E(31);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		ll sum = accumulate(A.begin(), A.end(), 0LL);
		if (sum % N) {
			cout << "No\n";
			continue;
		}
		int avg = sum / N;
		bool yes = true;
		fill(C.begin(), C.end(), 0);
		fill(D.begin(), D.end(), 0);
		fill(E.begin(), E.end(), 0);
		for (int i = 0; i < N; ++i) {
			int x = avg - A[i];
			auto it = B.find(x);
			if (it == B.end()) {
				yes = false;
				break;
			}
			auto &[u, v] = *it;
			++C[v.first], --C[v.second];
			if (x == 0) {
				continue;
			}
			int y = abs(x);
			if ((y & -y) == y) {
				if (x > 0) {
					++D[v.first];
				} else {
					++E[v.second];
				}
			}
		}
		for (int i = 30; i > 0; --i) {
			while (C[i] > 0 && D[i] > 0) {
				--C[i], --D[i];
				C[i - 1] += 2;
			}
			while (C[i] < 0 && E[i] > 0) {
				++C[i], --E[i];
				C[i - 1] -= 2;
			}
		}
		yes &= count(C.begin(), C.end(), 0) == 31;
		cout << (yes ? "Yes" : "No") << "\n";
	}
	return 0;
}
