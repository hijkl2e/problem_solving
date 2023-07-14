#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum{};
	for (int i = 0; i < X - 1; ++i) {
		sum += A[i];
	}
	int maxv{}, cnt{};
	for (int i = X - 1; i < N; ++i) {
		sum += A[i];
		if (maxv < sum) {
			maxv = sum;
			cnt = 1;
		} else if (maxv == sum) {
			++cnt;
		}
		sum -= A[i - X + 1];
	}
	if (maxv) {
		cout << maxv << "\n" << cnt << "\n";
	} else {
		cout << "SAD\n";
	}
	return 0;
}
