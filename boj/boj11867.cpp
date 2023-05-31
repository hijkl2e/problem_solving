#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cout << (N % 2 && M % 2 ? "B" : "A") << "\n";
	return 0;
}
