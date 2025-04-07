#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t1{}, e1{}, f1{}, t2{}, e2{}, f2{};
	cin >> t1 >> e1 >> f1 >> t2 >> e2 >> f2;
	int x = 3 * t1 + 20 * e1 + 120 * f1;
	int y = 3 * t2 + 20 * e2 + 120 * f2;
	string ans = x > y ? "Max" : x < y ? "Mel" : "Draw";
	cout << ans << "\n";
	return 0;
}
