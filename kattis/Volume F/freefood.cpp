#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> chk(366);
	int N{};
	cin >> N;
	while (N--) {
		int s{}, t{};
		cin >> s >> t;
		for (int i = s; i <= t; ++i) {
			chk[i] = true;
		}
	}
	cout << accumulate(chk.begin(), chk.end(), 0) << "\n";
	return 0;
}
