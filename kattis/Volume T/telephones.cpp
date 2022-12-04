#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<int> S(N);
		vector<int> D(N);
		for (int i = 0; i < N; ++i) {
			cin >> S[i] >> D[i] >> S[i] >> D[i];
		}
		while (M--) {
			int s{}, d{};
			cin >> s >> d;
			int ans{};
			for (int i = 0; i < N; ++i) {
				if (s < S[i] + D[i] && S[i] < s + d) {
					++ans;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
