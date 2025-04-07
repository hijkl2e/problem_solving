#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d{};
	string S;
	cin >> d >> S;
	ll X{}, Y{};
	for (int i = 0; i < d; ++i) {
		if (S[i] == '1' || S[i] == '4') {
			X += 1LL << (d - i - 1);
		}
		if (S[i] == '1' || S[i] == '2') {
			Y += 1LL << (d - i - 1);
		}
	}
	ll x{}, y{};
	cin >> x >> y;
	X += x, Y += y;
	if (X < 0 || X >= (1LL << d) || Y < 0 || Y >= (1LL << d)) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < d; ++i) {
		bool f1 = X & (1LL << (d - i - 1));
		bool f2 = Y & (1LL << (d - i - 1));
		S[i] = f1 ? f2 ? '1' : '4' : f2 ? '2' : '3';
	}
	cout << S << "\n";
	return 0;
}
