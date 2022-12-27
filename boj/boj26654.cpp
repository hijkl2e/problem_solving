#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const double EPS = 1e-12;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, A{}, B{};
		cin >> N >> A >> B;
		double a = sqrt(2 * A / (N * sin(2 * PI / N)));
		double b = sqrt(B / PI);
		if (a < b + EPS) {
			cout << N << "\n";
			continue;
		}
		int K = N * asin(b / a) / PI + 1 + EPS;
		cout << K << "\n";
	}
	return 0;
}
