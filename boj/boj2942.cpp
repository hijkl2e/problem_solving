#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int g = gcd(N, M);
	vector<int> A;
	for (int i = 1; i * i <= g; ++i) {
		if (g % i == 0) {
			A.push_back(i);
			if (i * i < g) {
				A.push_back(g / i);
			}
		}
	}
	sort(A.begin(), A.end());
	for (int x : A) {
		cout << x << " " << N / x << " " << M / x << "\n";
	}
	return 0;
}
