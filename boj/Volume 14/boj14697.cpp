#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, N{};
	cin >> a >> b >> c >> N;
	bool yes{};
	for (int i = 0; a * i <= N; ++i) {
		for (int j = 0; a * i + b * j <= N; ++j) {
			if ((N - a * i - b * j) % c == 0) {
				yes = true;
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
