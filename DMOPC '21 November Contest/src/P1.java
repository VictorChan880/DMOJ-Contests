import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

import java.util.StringTokenizer;

public class P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)1e6+5, mod = 998244353;
    static long k, a[] = new long[MM], cnt = 0;

    static void search (int idx, long odd, long even, long total) {
        if (cnt == (int)1e8) {
            System.out.println(-1);
            System.exit(0);
        }
        if (total > k) {
            cnt++;
            return;
        }
        else if (total == k) {
            System.out.println(idx);
            for (int i = 0; i < idx; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
            System.exit(0);
        }
        a[idx] = 1;
        search(idx+1, even+1,odd,total+odd);
        a[idx] = 0;
        search(idx+1, odd,even+1,total+even+1);
    }
    public static void main(String[] args) throws IOException {
        k = readLong();
        search(0,0,0,0);
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
/*
4 4
3
1 2
4 2 1
6 1 4 2
 */