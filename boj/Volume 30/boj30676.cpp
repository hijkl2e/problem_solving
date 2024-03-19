#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{380, 425, 450, 495, 570, 590, 620};
	vector<string> B{"Violet", "Indigo", "Blue", "Green", "Yellow", "Orange", "Red"};
	int x{};
	cin >> x;
	int idx = upper_bound(A.begin(), A.end(), x) - A.begin() - 1;
	cout << B[idx] << "\n";
	return 0;
}
