import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class boj4312 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		final BigInteger THREE = BigInteger.valueOf(3);
		while (true) {
			BigInteger N = new BigInteger(br.readLine());
			if (N.equals(BigInteger.ZERO)) {
				break;
			}
			N = N.subtract(BigInteger.ONE);
			if (N.equals(BigInteger.ZERO)) {
				out.append("{ }\n");
				continue;
			}
			out.append("{ ");
			for (int i = 0; N.compareTo(BigInteger.ZERO) == 1; ++i) {
				if (N.mod(BigInteger.TWO).equals(BigInteger.ONE)) {
					out.append(THREE.pow(i)).append(", ");
				}
				N = N.divide(BigInteger.TWO);
			}
			out.replace(out.length() - 2, out.length(), " }\n");
		}
		System.out.print(out);
		br.close();
	}
}
