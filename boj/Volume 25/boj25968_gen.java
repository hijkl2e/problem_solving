import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class boj25968_gen {
	static List<BigDecimal> A, B;
	
	static BigDecimal f(BigDecimal x) {
		BigDecimal ret = BigDecimal.ZERO;
		x = x.multiply(x);
		for (int i = 0; i < A.size(); ++i) {
			ret = ret.multiply(x).add(A.get(i));
		}
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		A = new ArrayList<>();
		for (int i = 0; i <= N; ++i) {
			A.add(sc.nextBigDecimal());
		}
		B = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			B.add(A.get(i).multiply(new BigDecimal(2 * (N - i))));
		}
		BigDecimal x = new BigDecimal("32");
		int K = sc.nextInt();
		BigDecimal len = x.divide(new BigDecimal(K));
		BigDecimal ans = BigDecimal.ZERO;
		for (int i = 1; i < K; i += 2) {
			ans = ans.add(len.multiply(f(len.multiply(new BigDecimal(i)))));
		}
		ans = ans.abs().multiply(new BigDecimal("4"));
		System.out.println(ans);
		sc.close();
	}
}
