#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	if (N == 0) {
		cout << "NO\n";
		return 0;
	}
	ll fact = 1;
	for (int i = 1; i < 20; ++i) {
		fact *= i;
	}
	for (int i = 19; i > 0; --i) {
		if (N >= fact) {
			N -= fact;
		}
		fact /= i;
	}
	cout << (N < 2 ? "YES" : "NO") << "\n";
	return 0;
}
