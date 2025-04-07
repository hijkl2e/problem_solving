#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int B{}, C{};
	cin >> B >> C;
	ll ans = N;
	for (int x : A) {
		if (x > B) {
			ans += (x - B - 1) / C + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
