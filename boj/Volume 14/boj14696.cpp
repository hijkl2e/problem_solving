#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<int> A(4);
		vector<int> B(4);
		for (int i = 0; i < 2; ++i) {
			auto &v = i ? B : A;
			int k{};
			cin >> k;
			while (k--) {
				int x{};
				cin >> x;
				++v[4 - x];
			}
		}
		cout << (A > B ? "A" : A < B ? "B" : "D") << "\n";
	}
	return 0;
}
