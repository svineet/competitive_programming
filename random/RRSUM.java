import java.io.*;

class RRSUM {
    public static void main(String args[])
        throws IOException {
        BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
        String parts[] = in.readLine().split(" ");
        long n = Long.parseLong(parts[0]);
        long m = Long.parseLong(parts[1]);
        for (int cse=0; cse<m; cse++) {
            long q = Long.parseLong(in.readLine());
            if (q<(n+2) || q>(3*n)) {
                System.out.println("0");
                continue;
            }
            long diff = Math.abs(2*n+1-q);
            System.out.println(n-diff);
        }
    }
}
