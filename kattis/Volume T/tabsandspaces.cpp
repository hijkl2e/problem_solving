#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int F{};
	cin >> F;
	vector<int> A;
	while (F--) {
		int L{};
		cin >> L;
		while (L--) {
			int x{};
			cin >> x;
			A.push_back(x);
		}
	}
	int maxi = 1, maxv{};
	for (int i = 2; i < 80; ++i) {
		int cnt{};
		for (int x : A) {
			cnt += x / i * (i - 1);
		}
		if (maxv < cnt) {
			maxi = i;
			maxv = cnt;
		}
	}
	cout << maxi << "\n" << maxv << "\n";
	return 0;
}
