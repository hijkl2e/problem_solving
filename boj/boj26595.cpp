#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, A{}, Pa{}, B{}, Pb{};
	cin >> N >> A >> Pa >> B >> Pb;
	int x{}, y{};
	for (int i = 0; i * Pa <= N; ++i) {
		int j = (N - i * Pa) / Pb;
		if (A * x + B * y < A * i + B * j) {
			x = i, y = j;
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
