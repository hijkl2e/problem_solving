#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, p1{}, r{}, p2{};
	cin >> a >> p1 >> r >> p2;
	cout << (a * p2 < PI * r * r * p1 ? "Whole" : "Slice of") << " pizza\n";
	return 0;
}
