#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{}, e{}, x{};
	cin >> a >> b >> c >> d >> e >> x;
	char grade = x >= a ? 'A' : x >= b ? 'B' : x >= c ? 'C' : x >= d ? 'D' : x >= e ? 'E' : 'F';
	cout << grade << "\n";
	return 0;
}
