#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		deque<bool> vst(N + 1);
		int ans{};
		for (int i = 1; i <= N; ++i) {
			if (vst[i]) {
				continue;
			}
			int j = i;
			while (!vst[j]) {
				vst[j] = true;
				j = A[j];
			}
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
