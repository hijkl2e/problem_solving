#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;

using is = pair<int, string>;

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

template <size_t _Nb>
is lcs(const string &S, const string &T, bool str) {
	static vector<bitset<_Nb>> A(26);
	for (int i = 0; i < 26; ++i) {
		A[i].reset();
	}
	for (int i = 0; i < T.size(); ++i) {
		A[T[i] - 'a'][i] = true;
	}
	static vector<bitset<_Nb>> B(3136 - _Nb);
	bitset<_Nb> x;
	for (int i = 0; i < S.size(); ++i) {
		x = A[S[i] - 'a'] | B[i];
		B[i + 1] = x & ((x - (B[i] << 1).set(0)) ^ x);
	}
	is ret = {B[S.size()].count(), ""};
	if (str) {
		string L;
		int p1 = S.size(), p2 = T.size();
		while (p1 && p2) {
			if (S[p1 - 1] == T[p2 - 1]) {
				L += S[p1 - 1];
				--p1, --p2;
			} else if (B[p1][p2 - 1]) {
				--p1;
			} else {
				--p2;
			}
		}
		reverse(L.begin(), L.end());
		ret.second = L;
	}
	return ret;
}

is _solve(const string &S, const string &T, bool str) {
	if (T.size() <= 128) return lcs<128>(S, T, str);
	if (T.size() <= 192) return lcs<192>(S, T, str);
	if (T.size() <= 256) return lcs<256>(S, T, str);
	if (T.size() <= 320) return lcs<320>(S, T, str);
	if (T.size() <= 384) return lcs<384>(S, T, str);
	if (T.size() <= 448) return lcs<448>(S, T, str);
	if (T.size() <= 512) return lcs<512>(S, T, str);
	if (T.size() <= 576) return lcs<576>(S, T, str);
	if (T.size() <= 640) return lcs<640>(S, T, str);
	if (T.size() <= 704) return lcs<704>(S, T, str);
	if (T.size() <= 768) return lcs<768>(S, T, str);
	if (T.size() <= 832) return lcs<832>(S, T, str);
	if (T.size() <= 896) return lcs<896>(S, T, str);
	if (T.size() <= 960) return lcs<960>(S, T, str);
	if (T.size() <= 1024) return lcs<1024>(S, T, str);
	if (T.size() <= 1088) return lcs<1088>(S, T, str);
	if (T.size() <= 1152) return lcs<1152>(S, T, str);
	if (T.size() <= 1216) return lcs<1216>(S, T, str);
	if (T.size() <= 1280) return lcs<1280>(S, T, str);
	if (T.size() <= 1344) return lcs<1344>(S, T, str);
	if (T.size() <= 1408) return lcs<1408>(S, T, str);
	if (T.size() <= 1472) return lcs<1472>(S, T, str);
	return lcs<1536>(S, T, str);
}

is solve(const string &S, const string &T, bool str = false) {
	return S.size() < T.size() ? _solve(T, S, str) : _solve(S, T, str);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	for (int tc = 1; tc <= T; ++tc) {
		string S;
		getline(cin, S);
		int maxi = 1, maxv{};
		for (int i = 1; i < S.size(); ++i) {
			is res = solve(S.substr(0, i), S.substr(i));
			if (maxv < res.first) {
				maxv = res.first;
				maxi = i;
			}
		}
		is ans = solve(S.substr(0, maxi), S.substr(maxi), true);
		cout << "Case #" << tc << ": " << 2 * ans.first << "\n";
		if (ans.first) {
			cout << ans.second << ans.second << "\n";
		}
	}
	return 0;
}
