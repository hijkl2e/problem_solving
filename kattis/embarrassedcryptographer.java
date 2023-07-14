import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class embarrassedcryptographer {
	public static boolean[] sieve() {
		boolean[] p = new boolean[1000001];
		Arrays.fill(p, true);
		p[0] = p[1] = false;
		for (int i = 2; i < p.length; ++i) {
			if (p[i]) {
				for (int j = 2 * i; j < p.length; j += i) {
					p[j] = false;
				}
			}
		}
		return p;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		boolean[] p = sieve();
		List<Integer> P = new ArrayList<>();
		for (int i = 2; i < p.length; ++i) {
			if (p[i]) {
				P.add(i);
			}
		}
		while (true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			BigInteger K = new BigInteger(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			if (L == 0) {
				break;
			}
			int ans = 0;
			for (int x : P) {
				if (x >= L) {
					break;
				}
				BigInteger r = K.remainder(BigInteger.valueOf(x));
				if (r.equals(BigInteger.ZERO)) {
					ans = x;
					break;
				}
			}
			if (ans > 0) {
				out.append("BAD " + ans + "\n");
			} else {
				out.append("GOOD\n");
			}
		}
		System.out.print(out);
		br.close();
	}
}
