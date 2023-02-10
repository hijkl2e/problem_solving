#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	cout << (N % 7 == 0 || N % 7 == 2 ? "CY" : "SK") << "\n";
	return 0;
}
