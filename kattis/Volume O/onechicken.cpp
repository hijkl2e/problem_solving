#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N < M) {
		cout << "Dr. Chaz will have " << M - N << " piece";
		cout << (M - N == 1 ? "" : "s") << " of chicken left over!\n";
	} else {
		cout << "Dr. Chaz needs " << N - M << " more piece";
		cout << (N - M == 1 ? "" : "s") << " of chicken!\n";
	}
	return 0;
}
