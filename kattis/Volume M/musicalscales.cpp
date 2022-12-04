#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> note{
		"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"
	};
	map<string, int> n2i;
	for (int i = 0; i < note.size(); ++i) {
		n2i[note[i]] = i;
	}
	int N{};
	cin >> N;
	deque<bool> A(12);
	while (N--) {
		string s;
		cin >> s;
		A[n2i[s]] = true;
	}
	vector<int> ans;
	for (int i = 0; i < 12; ++i) {
		bool yes = true;
		for (int x : {1, 3, 6, 8, 10}) {
			if (A[(i + x) % 12]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) {
		cout << "none\n";
	} else {
		for (int i = 0; i < ans.size(); ++i) {
			cout << note[ans[i]] << (i == ans.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
