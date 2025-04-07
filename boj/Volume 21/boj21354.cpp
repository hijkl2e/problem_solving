#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, P{};
	cin >> A >> P;
	A *= 7;
	P *= 13;
	string ans = A > P ? "Axel" : A < P ? "Petra" : "lika";
	cout << ans << "\n";
	return 0;
}
