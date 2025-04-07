#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(100001);
	while (N--) {
		int y1{}, m1{}, y2{}, m2{};
		char c{};
		cin >> y1 >> c >> m1 >> y2 >> c >> m2;
		++A[(y1 - 2000) * 12 + m1 - 1];
		--A[(y2 - 2000) * 12 + m2];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int p = max_element(A.begin(), A.end()) - A.begin();
	cout << (p / 12 + 2000) << "-" << setfill('0') << setw(2) << (p % 12 + 1) << "\n";
	return 0;
}
