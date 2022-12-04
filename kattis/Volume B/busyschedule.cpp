#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			int h{}, m{};
			char c{};
			cin >> h >> c >> m;
			h %= 12;
			string s;
			cin >> s;
			if (s == "p.m.") {
				h += 12;
			}
			A[i] = 60 * h + m;
		}
		sort(A.begin(), A.end());
		if (tc) {
			cout << "\n";
		}
		for (int time : A) {
			int h = time / 60;
			int m = time % 60;
			cout << (h % 12 == 0 ? 12 : h % 12) << ":" << setfill('0') << setw(2) << m << " ";
			cout << (h < 12 ? "a.m." : "p.m.") << "\n";
		}
	}
	return 0;
}
