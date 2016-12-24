import java.util.*;
import java.math.BigInteger;

public class ProblemC {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        BigInteger i = BigInteger.ONE;
        BigInteger cur = new BigInteger("2");
        while (n>0) {
            BigInteger mult = i.multiply(i.add(BigInteger.ONE));
            BigInteger ans = mult.multiply(mult).subtract(cur).divide(i);
            System.out.println(ans);
            cur = mult;
            i = i.add(BigInteger.ONE);
            n--;
        }
    }
}
