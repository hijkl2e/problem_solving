#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A{}, B{}, C{}, D{};
	cin >> A >> B >> C >> D;
	int t = (A * 3600 + B * 60 + C + D) % 86400;
	cout << t / 3600 << " " << t % 3600 / 60 << " " << t % 60 << "\n";
	return 0;
}
