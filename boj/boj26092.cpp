#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A{}, B{};
	cin >> A >> B;
	ll i = 2, j = 2;
	bool yes = true;
	while (A != B && yes) {
		yes = false;
		if (A > B) {
			for (; i * i <= A; ++i) {
				if (A % i == 0) {
					A /= i;
					yes = true;
					break;
				}
			}
		} else {
			for (; j * j <= B; ++j) {
				if (B % j == 0) {
					B /= j;
					yes = true;
					break;
				}
			}
		}
	}
	A = yes ? A : 1;
	cout << A << "\n";
	return 0;
}
