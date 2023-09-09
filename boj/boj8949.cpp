#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	if (a.size() > b.size()) {
		swap(a, b);
	}
	while (a.size() < b.size()) {
		a = "0" + a;
	}
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] + b[i] - 2 * '0';
	}
	cout << "\n";
	return 0;
}
