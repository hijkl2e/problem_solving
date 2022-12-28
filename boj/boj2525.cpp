#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	int t = (A * 60 + B + C) % 1440;
	cout << t / 60 << " " << t % 60 << "\n";
	return 0;
}
