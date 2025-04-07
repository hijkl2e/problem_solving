#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int W{}, N{};
	for (int tc = 1; cin >> W >> N, W; ++tc) {
		vector<string> S(N);
		vector<int> C(N);
		for (int i = 0; i < N; ++i) {
			cin >> S[i] >> C[i];
		}
		int cmax = *max_element(C.begin(), C.end());
		vector<int> P(N);
		for (int i = 0; i < N; ++i) {
			P[i] = 9 + 40.0 * (C[i] - 4) / (cmax - 4) - EPS;
		}
		int now_w{}, max_h{}, ans{};
		for (int i = 0; i < N; ++i) {
			int w = 1 + 9.0 / 16 * S[i].size() * P[i] - EPS;
			now_w += now_w ? 10 + w : w;
			if (now_w > W) {
				now_w = w;
				ans += max_h;
				max_h = P[i];
			}
			max_h = max(max_h, P[i]);
		}
		ans += max_h;
		cout << "CLOUD " << tc << ": " << ans << "\n";
	}
	return 0;
}
