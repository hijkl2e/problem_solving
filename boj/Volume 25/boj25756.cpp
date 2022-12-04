#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	double V{};
	cout << fixed << setprecision(10);
	while (N--) {
		double x{};
		cin >> x;
		V = (1 - (1 - V / 100) * (1 - x / 100)) * 100;
		cout << V << "\n";
	}
	return 0;
}
