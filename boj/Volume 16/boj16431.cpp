#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int br{}, bc{}, dr{}, dc{}, jr{}, jc{};
	cin >> br >> bc >> dr >> dc >> jr >> jc;
	int d1 = max(abs(br - jr), abs(bc - jc));
	int d2 = abs(dr - jr) + abs(dc - jc);
	cout << (d1 < d2 ? "bessie" : d1 > d2 ? "daisy" : "tie") << "\n";
	return 0;
}
