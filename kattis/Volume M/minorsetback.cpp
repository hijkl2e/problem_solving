#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

const double EPS = 1e-4;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> F(N);
	int chk{};
	for (int i = 0; i < N; ++i) {
		double x{};
		cin >> x;
		int idx = log2(x / 13.75) * 12 + EPS;
		idx %= 12;
		F[i] = idx;
		chk |= (1 << idx);
	}
	vector<si> A{
		{"G major", 0x6ad}, {"C major", 0x5ad}, {"Eb major", 0xd6a},
		{"F# minor", 0xab5}, {"G minor", 0x56b}
	};
	vector<string> B{
		"A", "Bb", "B", "C", "C#", "D", "Eb", "E", "F", "F#", "G"
	};
	vector<int> ans;
	for (int i = 0; i < A.size(); ++i) {
		if ((chk & A[i].second) == chk) {
			ans.push_back(i);
		}
	}
	if (ans.size() == 1) {
		cout << A[ans[0]].first << "\n";
		for (int x : F) {
			cout << (x == 11 ? ans[0] == 2 ? "Ab" : "G#" : B[x]) << "\n";
		}
	} else {
		cout << "cannot determine key\n";
	}
	return 0;
}
