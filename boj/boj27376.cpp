#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<iii> A(K);
	for (auto &[x, t, s] : A) {
		cin >> x >> t >> s;
	}
	sort(A.begin(), A.end());
	int prev{};
	ll T{};
	for (auto &[x, t, s] : A) {
		T += x - prev;
		if (T < s) {
			T = s;
		} else {
			ll r = (T - s) % (2 * t);
			if (r >= t) {
				T += 2 * t - r;
			}
		}
		prev = x;
	}
	T += N - prev;
	cout << T << "\n";
	return 0;
}
