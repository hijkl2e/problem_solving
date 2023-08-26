#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int a{}, b{}, T{}, t1{}, t2{};
	while (N--) {
		int x{}, m{}, s{};
		char c{};
		cin >> x >> m >> c >> s;
		int t = 60 * m + s;
		if (a > b) {
			t1 += t - T;
		} else if (a < b) {
			t2 += t - T;
		}
		if (x == 1) {
			++a;
		} else {
			++b;
		}
		T = t;
	}
	if (a > b) {
		t1 += 2880 - T;
	} else if (a < b) {
		t2 += 2880 - T;
	}
	cout << setfill('0');
	cout << setw(2) << t1 / 60 << ":" << setw(2) << t1 % 60 << "\n";
	cout << setw(2) << t2 / 60 << ":" << setw(2) << t2 % 60 << "\n";
	return 0;
}
