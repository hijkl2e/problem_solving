#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int X{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		X += x;
	}
	cout << "Junhee is " << (N - X > X ? "not " : "") << "cute!\n";
	return 0;
}
