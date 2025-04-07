#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	char c{};
	cin >> N >> c >> M;
	int g = gcd(N, M);
	cout << N / g << ":" << M / g << "\n";
	return 0;
}
