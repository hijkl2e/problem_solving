#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << (N % 2 ? 0 : N % 4 ? 1 : 2) << "\n";
	return 0;
}
