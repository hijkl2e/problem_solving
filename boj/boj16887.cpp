#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<ll, ll> dp{
		{1, 0}, {4, 1}, {16, 2}, {82, 0}, {6724, 3}, {50626, 1}, {2562991876LL, 2}
	};
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans ^= (--dp.upper_bound(A[i]))->second;
	}
	cout << (ans ? "koosaga" : "cubelover") << "\n";
	return 0;
}
