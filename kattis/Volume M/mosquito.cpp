#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, P{}, L{};
	while (cin >> M >> P >> L) {
		int E{}, R{}, S{}, N{};
		cin >> E >> R >> S >> N;
		int C = M;
		while (N--) {
			C = P / S;
			P = L / R;
			L = M * E;
			M = C;
		}
		cout << C << "\n";
	}
	return 0;
}
