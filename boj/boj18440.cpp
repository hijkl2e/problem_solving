#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;

template <size_t _Nw>
void sub(_Base_bitset<_Nw> &A, _Base_bitset<_Nw> &B) {
	for (int i = 0, c = 0; i < _Nw; ++i) {
		c = _subborrow_u64(c, A._M_w[i], B._M_w[i],
				reinterpret_cast<unsigned long long *>(&A._M_w[i]));
	}
}

template <size_t _Nb>
bitset<_Nb> operator-(bitset<_Nb> &A, bitset<_Nb> &B) {
	bitset<_Nb> C = A;
	sub(C, B);
	return C;
}

vector<string> S(4);

template <size_t _Nb>
vector<int> lcs(int k, int x1, int x2, int y1, int y2) {
	static vector<bitset<_Nb>> A(26);
	for (int i = 0; i < 26; ++i) {
		A[i].reset();
	}
	for (int i = y1; i < y2; ++i) {
		A[S[k + 1][i] - 'A'][i - y1] = true;
	}
	bitset<_Nb> x, y;
	for (int i = x1; i < x2; ++i) {
		x = A[S[k][i] - 'A'] | y;
		y = x & ((x - (y << 1).set(0)) ^ x);
	}
	vector<int> ret(y2 - y1 + 1);
	for (int i = 1; i < ret.size(); ++i) {
		ret[i] = ret[i - 1] + y[i - 1];
	}
	return ret;
}

vector<int> solve(int k, int x1, int x2, int y1, int y2) {
	if (y2 - y1 <= 128) return lcs<128>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 256) return lcs<256>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 512) return lcs<512>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 1024) return lcs<1024>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 2048) return lcs<2048>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 4096) return lcs<4096>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 8192) return lcs<8192>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 16384) return lcs<16384>(k, x1, x2, y1, y2);
	if (y2 - y1 <= 32768) return lcs<32768>(k, x1, x2, y1, y2);
	return lcs<65536>(k, x1, x2, y1, y2);
}

string solve(int x1, int x2, int y1, int y2) {
	if (x1 == x2) {
		return "";
	} else if (x1 + 1 == x2) {
		for (int i = y1; i < y2; ++i) {
			if (S[0][x1] == S[1][i]) {
				return S[1].substr(i, 1);
			}
		}
		return "";
	}
	int x3 = (x1 + x2) / 2;
	vector<int> res1 = solve(0, x1, x3, y1, y2);
	vector<int> res2 = solve(2, S[0].size() - x2 + 1, S[0].size() - x3 + 1,
									S[1].size() - y2 + 1, S[1].size() - y1 + 1);
	reverse(res2.begin(), res2.end());
	int y3{};
	for (int i = 0; i < res1.size(); ++i) {
		if (res1[y3] + res2[y3] < res1[i] + res2[i]) {
			y3 = i;
		}
	}
	y3 += y1;
	return solve(x1, x3, y1, y3) + solve(x3, x2, y3, y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	getline(cin, S[0]);
	getline(cin, S[1]);
	S[0] = "#" + S[0];
	S[1] = "#" + S[1];
	S[2] = S[0], S[3] = S[1];
	reverse(S[2].begin() + 1, S[2].end());
	reverse(S[3].begin() + 1, S[3].end());
	string ans = solve(1, S[0].size(), 1, S[1].size());
	cout << ans.size() << "\n";
	cout << ans << "\n";
	return 0;
}
