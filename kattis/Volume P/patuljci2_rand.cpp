#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, C{};
	cin >> N >> C;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(C + 1);
	for (int i = 1; i <= N; ++i) {
		B[A[i]].push_back(i);
	}
	mt19937 gen{random_device()()};
	int M{};
	cin >> M;
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		int ans{};
		for (int k = 0; k < 20; ++k) {
			int x = A[gen() % (b - a + 1) + a];
			int cnt = upper_bound(B[x].begin(), B[x].end(), b)
					- lower_bound(B[x].begin(), B[x].end(), a);
			if (cnt > (b - a + 1) / 2) {
				ans = x;
				break;
			}
		}
		if (ans) {
			cout << "yes " << ans << "\n";
		} else {
			cout << "no\n";
		}
	}
	return 0;
}
