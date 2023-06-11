#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, N{};
	cin >> a >> b >> N;
	while (N--) {
		a = a % b * 10;
	}
	cout << a / b << "\n";
	return 0;
}
