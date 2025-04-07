#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	string S(N / 2, 'A');
	while (S.size() < N) {
		int k = min(N / 2, K);
		S.insert(S.begin() + k, 'B');
		K -= k;
	}
	if (K) {
		cout << "-1\n";
	} else {
		cout << S << "\n";
	}
	return 0;
}
