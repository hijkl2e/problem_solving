#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A.begin(), A.end());
	for (int i = 1; i < N && i < 4; ++i) {
		if (A[N - i].first - A[N - i - 1].first > M) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = N - 3; i >= 0; --i) {
		cout << A[i].second << " ";
	}
	for (int i = N - (N == 1 ? 1 : 2); i < N; ++i) {
		cout << A[i].second << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
