#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int d{};
		for (int i = 0; i < N - 1; ++i) {
			d = max(d, A[i + 1] - A[i]);
		}
		cout << "Class " << tc << "\n";
		cout << "Max " << A[N - 1] << ", Min " << A[0] << ", Largest gap " << d << "\n";
	}
	return 0;
}
