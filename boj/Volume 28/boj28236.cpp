#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	int minv = 1e9, mini{};
	for (int i = 1; i <= K; ++i) {
		int f{}, d{};
		cin >> f >> d;
		if (minv > f + M - d) {
			minv = f + M - d;
			mini = i;
		}
	}
	cout << mini << "\n";
	return 0;
}
