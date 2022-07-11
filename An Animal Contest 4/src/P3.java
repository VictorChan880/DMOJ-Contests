import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class P3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e5+5, mod = 998244353;
    static int grid[][] = new int [11][11];
    static int dy[] = {1,0,-1,0}, dx[] = {0,1,0,-1};
    static int n;
    static long gcd (long a, long b) {
        if (b == 0) return a;
        return gcd(b,a%b);
    }
    static long lcm (long a, long b) {
        return (a*b)/gcd(a,b);
    }
    public static void main(String[] args) throws IOException {
        int n = readInt(), m = readInt();
        long a[] = new long [n], psa[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = readInt();
            if (i != 0) psa[i] = lcm(psa[i-1], a[i]);
        }
        for (int i = 0; i < m; i++) {
            long t =readInt();
            int l = 0, r= n-1, ans = -1;
            while (l <= r) {
                int mid = (l+r)/2;

                if (t % psa[mid] != 0) {
                    ans = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            System.out.println(ans);
        }
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
