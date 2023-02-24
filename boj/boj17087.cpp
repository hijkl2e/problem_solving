#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int g{};
	for (int i = 0; i < N; ++i) {
		g = gcd(g, abs(S - A[i]));
	}
	cout << g << "\n";
	return 0;
}
