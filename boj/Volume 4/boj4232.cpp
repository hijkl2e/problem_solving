#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		map<ll, int> freq;
		while (N--) {
			vector<int> A(5);
			for (int i = 0; i < 5; ++i) {
				cin >> A[i];
			}
			sort(A.begin(), A.end());
			ll x{};
			for (int i = 0; i < 5; ++i) {
				x = x * 400 + (A[i] - 100);
			}
			++freq[x];
		}
		int maxv{}, cnt{};
		for (auto &p : freq) {
			if (maxv < p.second) {
				maxv = p.second;
				cnt = 1;
			} else if (maxv == p.second) {
				++cnt;
			}
		}
		cout << maxv * cnt << "\n";
	}
	return 0;
}
