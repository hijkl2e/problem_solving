#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iii> A(N);
	for (auto &[a, b, c] : A) {
		cin >> b >> c >> a;
	}
	sort(A.rbegin(), A.rend());
	int p = 2;
	while (get<1>(A[0]) == get<1>(A[1]) && get<1>(A[1]) == get<1>(A[p])) {
		++p;
	}
	swap(A[p], A[2]);
	A.resize(3);
	for (auto &[a, b, c] : A) {
		cout << b << " " << c << "\n";
	}
	return 0;
}
