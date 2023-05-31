#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(20);
	for (int i = 0; i < 20; ++i) {
		A[i] = i + 1;
	}
	for (int i = 0; i < 10; ++i) {
		int s{}, e{};
		cin >> s >> e;
		reverse(A.begin() + s - 1, A.begin() + e);
	}
	for (int i = 0; i < 20; ++i) {
		cout << A[i] << (i == 19 ? "\n" : " ");
	}
	return 0;
}
