#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << (N % 7 == 1 || N % 7 == 3 ? "CY" : "SK") << "\n";
	return 0;
}
