#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1, -1);
	for (int i = 1, p = N + 1; i <= N; ++i) {
		if (A[i] != -1) {
			continue;
		}
		while (!is_prime(p)) {
			++p;
		}
		cout << "? " << i << " " << p++ << endl;
		int y{};
		cin >> y;
		if (y == i) {
			A[i] = i;
			continue;
		}
		vector<int> B{y};
		while (true) {
			cout << "? " << i << " " << p++ << endl;
			cin >> y;
			if (B[0] == y) {
				break;
			}
			B.push_back(y);
		}
		for (int j = 0; j < B.size(); ++j) {
			A[B[j]] = B[(j + 1) % B.size()];
		}
	}
	cout << "!";
	for (int i = 1; i <= N; ++i) {
		cout << " " << A[i];
	}
	cout << endl;
	return 0;
}
