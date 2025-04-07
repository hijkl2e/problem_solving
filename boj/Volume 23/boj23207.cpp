#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string note, ton;
	for (int tc = 1; cin >> note >> ton; ++tc) {
		cout << "Case " << tc << ": ";
		if (note.size() == 1) {
			cout << "UNIQUE\n";
			continue;
		}
		if (note[1] == '#') {
			note[0] = 'A' + (note[0] - 'A' + 1) % 7;
			note[1] = 'b';
		} else {
			note[0] = 'A' + (note[0] - 'A' + 6) % 7;
			note[1] = '#';
		}
		cout << note << " " << ton << "\n";
	}
	return 0;
}
