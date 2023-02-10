#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	cout << (N % 5 == 0 || N % 5 == 2 ? "CY" : "SK") << "\n";
	return 0;
}
