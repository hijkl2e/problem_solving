#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{}, H{}, W{};
	cin >> N >> B >> H >> W;
	int ans = INF;
	while (H--) {
		int p{};
		cin >> p;
		int bed{};
		for (int i = 0; i < W; ++i) {
			int x{};
			cin >> x;
			bed = max(bed, x);
		}
		if (bed >= N) {
			ans = min(ans, p * N);
		}
	}
	if (ans <= B) {
		cout << ans << "\n";
	} else {
		cout << "stay home\n";
	}
	return 0;
}
