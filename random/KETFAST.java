import java.io.*;
import java.util.*;

class CompactClass {
    int cost;
    char assocChar;

    CompactClass(char cur, int cost) {
        this.cost = cost;
        assocChar = cur;
    }
}

class GayComparator implements Comparator<CompactClass> {
    @Override
    public int compare(CompactClass a,
                       CompactClass b) {
        if (a.cost==b.cost)
            return 0;
        else if(a.cost > b.cost)
            return 1;
        else
            return -1;
    }
}

class KETFAST {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        for (int cases=0; cases<t; cases++) {
            int numToIgnore = Integer.parseInt(in.readLine());

            String parts[] = in.readLine().split(" ");
            int costs[] = new int[parts.length];
            for (int i=0; i<costs.length; i++) {
                costs[i] = Integer.parseInt(parts[i]);
            }

            String toManip = in.readLine();
            CompactClass assocCosts[] = new CompactClass[toManip.length()];
            for (int i=0; i<toManip.length(); i++) {
                char cur = toManip.charAt(i);
                assocCosts[i] = new CompactClass(cur, costs[cur-97]);
            }

            Arrays.sort(assocCosts, new GayComparator());
            int realCost=0;
            for (int i=0; i<(assocCosts.length-numToIgnore); i++) {
                realCost += assocCosts[i].cost;
            }
            System.out.println(realCost);
        }
    }
}
