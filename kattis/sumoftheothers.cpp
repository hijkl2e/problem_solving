#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		int x{}, sum{};
		while (iss >> x) {
			sum += x;
		}
		cout << sum / 2 << "\n";
	}
	return 0;
}
