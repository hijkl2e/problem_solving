import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair> {
	public Pair(String t, BigInteger b) {
		this.t = t;
		this.b = b;
	}
	public int compareTo(Pair p) {
		return p.b.compareTo(b);
	}
	String t;
	BigInteger b;
};

public class boj16323 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		BigInteger S = new BigInteger(st.nextToken());
		List<Pair> A = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			st = new StringTokenizer(br.readLine());
			String t = st.nextToken();
			BigInteger b = new BigInteger(st.nextToken());
			A.add(new Pair(t, b));
		}
		Collections.sort(A);
		List<String> B = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			if (S.compareTo(A.get(i).b) > -1) {
				S = S.subtract(A.get(i).b);
				B.add(A.get(i).t);
			}
		}
		if (S.equals(BigInteger.ZERO)) {
			out.append(B.size()).append("\n");
			for (String s : B) {
				out.append(s).append("\n");
			}
		} else {
			out.append("0\n");
		}
		System.out.print(out);
		br.close();
	}
}
