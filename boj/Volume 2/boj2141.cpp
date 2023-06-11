#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	for (int i = 1; i < N; ++i) {
		A[i].second += A[i - 1].second;
	}
	int p{};
	while (A[p].second < (A[N - 1].second + 1) / 2) {
		++p;
	}
	cout << A[p].first << "\n";
	return 0;
}
