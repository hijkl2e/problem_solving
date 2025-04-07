#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cout << "LoveisKoreaUniversity" << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
