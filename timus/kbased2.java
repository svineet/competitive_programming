import java.util.Scanner;
import java.math.BigInteger;

public class kbased2 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong(); long k = in.nextLong(); long m = in.nextLong();
        BigInteger M = new BigInteger(Long.toString(m));
        BigInteger dp[][] = new BigInteger[3][k+1l];
        dp[1][0] = BigInteger.ZERO;
        for (int i=1; i<k; i++)
            dp[1][i] = BigInteger.ONE;

        int source = 1, dest = 2;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<k; j++) {
                dp[dest][j] = BigInteger.ZERO;
                for (int w=0; w<k; w++) {
                    if (j==0 && w==0) continue;
                    dp[dest][j] = dp[dest][j].add(dp[source][w]);
                    dp[dest][j] = dp[dest][j].mod(M);
                }
            }
            source = source^dest;
            dest = dest^source;
            source = source^dest;
            System.out.println(source+" "+dest);
        }
 
        BigInteger tot = BigInteger.ZERO;
        for (int i=0; i<k; i++) {
            tot = tot.add(dp[source][i]).mod(M);
        }
        System.out.println(tot);
    }
}
