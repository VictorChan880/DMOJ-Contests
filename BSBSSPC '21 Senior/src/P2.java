import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e5+5, mod = 998244353;

    public static void main(String[] args) throws IOException {
        int n = readInt(), k = readInt();long a[] = new long[n+1];
        long [] psa = new long[n+1];
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = readLong();
            psa[i] = psa[i-1] + a[i];
        }
        long [] min = new long[k+1];
        Arrays.fill(min,(long)1e10);
        min[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i % k == 0 || min[i%k] != 1e10) ans = Math.max(ans, psa[i] - min[i%k]);
            min[i%k] = Math.min(psa[i], min[i%k]);
        }
        System.out.println(ans);


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
