#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int a, int b) {
	vector<int> ret;
	for (int i = a; i <= b; ++i) {
		bool yes = true;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				yes = false;
				break;
			}
		}
		if (yes) {
			ret.push_back(i);
		}
	}
	return ret;
}

int solve(vector<int> &v1, vector<int> &v2) {
	int ret{}, p1{}, p2{};
	while (p1 < v1.size() && p2 < v2.size()) {
		if (v1[p1] < v2[p2]) {
			++p1;
		} else if (v1[p1] > v2[p2]) {
			++p2;
		} else {
			++ret, ++p1, ++p2;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	vector<int> A = solve(a, b);
	vector<int> B = solve(c, d);
	int c3 = solve(A, B);
	int c1 = A.size() - c3 + c3 % 2;
	int c2 = B.size() - c3;
	cout << (c1 > c2 ? "yt" : "yj") << "\n";
	return 0;
}
