#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N /= 5;
	int t{};
	while (11 * t % 720 != N) {
		++t;
	}
	cout << setfill('0') << setw(2) << t / 60 << ":" << setw(2) << t % 60 << "\n";
	return 0;
}
