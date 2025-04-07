#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int x{};
		double y{};
		while (N--) {
			int C{};
			double G{};
			cin >> C >> G;
			x += C;
			y += C * G;
		}
		cout << fixed << setprecision(1);
		cout << x << " " << y / x << "\n";
	}
	return 0;
}
