#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{};
	cin >> N >> B;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int idx = find(A.begin(), A.end(), B) - A.begin();
	vector<int> C(N);
	for (int i = idx - 1; i >= 0; --i) {
		C[i] = C[i + 1] + (A[i] < B ? 1 : -1);
	}
	for (int i = idx + 1; i < N; ++i) {
		C[i] = C[i - 1] + (A[i] > B ? 1 : -1);
	}
	map<int, int> freq;
	for (int i = 0; i <= idx; ++i) {
		++freq[C[i]];
	}
	ll ans{};
	for (int i = idx; i < N; ++i) {
		ans += freq[C[i]];
	}
	cout << ans << "\n";
	return 0;
}
