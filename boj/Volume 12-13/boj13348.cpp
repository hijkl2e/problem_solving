#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<string> A(N + 1);
	set<string> pic;
	int ans{};
	while (K--) {
		int c1{}, c2{};
		string p1{}, p2{};
		cin >> c1 >> c2 >> p1 >> p2;
		A[c1] = p1;
		A[c2] = p2;
		if (p1 == p2) {
			--ans;
		}
		pic.insert(p1);
		pic.insert(p2);
	}
	int cnt{};
	for (int i = 1; i <= N; ++i) {
		if (A[i] == "") {
			++cnt;
		}
	}
	if (pic.size() == N / 2 || (pic.size() == N / 2 - 1 && cnt == 2)) {
		ans += N / 2;
	} else {
		for (int i = 1; i <= N; ++i) {
			if (A[i] == "") {
				continue;
			}
			for (int j = i + 1; j <= N; ++j) {
				if (A[i] == A[j]) {
					++ans;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
