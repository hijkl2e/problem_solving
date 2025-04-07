#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << (N % 2 ? "Either" : N / 2 % 2 ? "Odd" : "Even") << "\n";
	return 0;
}
