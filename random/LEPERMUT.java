import java.io.*;

class LEPERMUT {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());

        for(int cases=0; cases<t; cases++) {
            int n = Integer.parseInt(in.readLine());
            int array[] = new int[n];
            String parts[] = in.readLine().split(" ");
            for (int i=0; i<parts.length; i++) {
                array[i] = Integer.parseInt(parts[i]);
            }

            int inversions = 0,
                localInversions = 0;
            boolean gay = false;
            for (int i=0; i<array.length; i++) {
                if (i!=array.length-1 && array[i]>array[i+1]) {
                    localInversions++;
                }

                for (int j=i+1; j<array.length; j++) {
                    if (array[i]>array[j]) {
                        inversions++;
                    }
                }
            }
            if (inversions==localInversions) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }
    }
}
