#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ii> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = {A[i], i};
	}
	sort(B.begin(), B.end());
	for (int i = N - 1; i > 0; --i) {
		if (B[i].second == i) {
			continue;
		}
		auto it = lower_bound(B.begin(), B.end(), make_pair(A[i], -1));
		it->second = B[i].second;
		swap(A[B[i].second], A[i]);
		if (--K == 0) {
			break;
		}
	}
	if (K) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < N; ++i) {
			cout << A[i] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
