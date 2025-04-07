#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, string> tab{
		{5, "A+"}, {15, "A0"}, {30, "B+"}, {35, "B0"}, {45, "C+"}, {48, "C0"}, {50, "F"}
	};
	vector<int> A(50);
	for (int i = 0; i < 50; ++i) {
		cin >> A[i];
	}
	int x{};
	cin >> x;
	int p = find(A.begin(), A.end(), x) - A.begin();
	cout << tab.lower_bound(p + 1)->second << "\n";
	return 0;
}
