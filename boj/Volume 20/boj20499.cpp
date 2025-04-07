#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k{}, d{}, a{};
	char c{};
	cin >> k >> c >> d >> c >> a;
	cout << (k + a < d || d == 0 ? "hasu" : "gosu") << "\n";
	return 0;
}
