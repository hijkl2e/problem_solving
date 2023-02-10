#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N = (N - 2016) % 13;
	bool yes = N % 2 == 0 && N != 12;
	cout << (yes ? "yes" : "no") << "\n";
	return 0;
}
