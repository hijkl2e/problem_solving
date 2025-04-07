#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		string S;
		int a{}, b{}, c{};
		cin >> S >> a >> b >> c;
		int total = a + b + c;
		bool pass = total >= 55 && a >= 11 && b >= 8 && c >= 12;
		cout << S << " " << total << " " << (pass ? "PASS" : "FAIL") << "\n";
	}
	return 0;
}
