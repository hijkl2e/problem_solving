#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> A;

void solve(ll x) {
	A.push_back(x);
	for (int i = 0; i < x % 10; ++i) {
		solve(10 * x + i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.push_back(0);
	for (int i = 1; i < 10; ++i) {
		solve(i);
	}
	if (A.size() < N) {
		cout << "-1\n";
		return 0;
	}
	sort(A.begin(), A.end());
	cout << A[N - 1] << "\n";
	return 0;
}
