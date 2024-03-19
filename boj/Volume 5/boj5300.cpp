#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cout << i << " ";
		if (i % 6 == 0 || i == N) {
			cout << "Go!" << (i == N ? "\n" : " ");
		}
	}
	return 0;
}
