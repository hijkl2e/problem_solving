import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class boj5615 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int ans = 0;
		while (N-- > 0) {
			long x = Integer.parseInt(br.readLine());
			BigInteger y = BigInteger.valueOf(2 * x + 1);
			if (y.isProbablePrime(10)) {
				++ans;
			}
		}
		System.out.println(ans);
		br.close();
	}
}
