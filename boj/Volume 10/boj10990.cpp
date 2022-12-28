#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << string(N - 1, ' ') << "*\n";
	for (int i = 2; i <= N; ++i) {
		cout << string(N - i, ' ');
		for (int j = 0; j < i; ++j) {
			cout << "*" << (j == i - 1 ? "\n" : " ");
		}
	}
	return 0;
}
