#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> C(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> C[i];
	}
	C[0] = -1e9;
	C[N + 1] = 2e9;
	sort(C.begin(), C.end());
	int A{}, B{};
	cin >> A >> B;
	A += 1 - A % 2;
	B -= 1 - B % 2;
	int d{};
	int ans = -1;
	for (int i = 1; i < N; ++i) {
		int nd = (C[i + 1] - C[i]) / 2;
		nd -= 1 - nd % 2;
		if (d < nd) {
			int x = C[i] + nd;
			if (A <= x && x <= B) {
				d = nd;
				ans = x;
			}
			x = C[i + 1] - nd;
			if (A <= x && x <= B) {
				d = nd;
				ans = x;
			}
		}
	}
	for (int x : {A, B}) {
		auto it = lower_bound(C.begin(), C.end(), x);
		int nd = *it - x;
		nd = min(nd, x - *--it);
		if (d < nd) {
			d = nd;
			ans = x;
		}
	}
	cout << ans << "\n";
	return 0;
}
