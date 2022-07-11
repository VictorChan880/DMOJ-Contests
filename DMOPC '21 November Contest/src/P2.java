import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)1e6+5, mod = 998244353;
    public static void main(String[] args) throws IOException {
        long k = readLong();
        long a = 0,  b = (long)1e6;

        if (k == (Math.pow((int)1e6+1, 2) - (int)(1e6+1))/2) {
            System.out.println(1000000);

            for (int i = 0; i < 1e6; i++) {
                System.out.print(0);
                if (i != 1e6-1) System.out.print(" ");
            }
            System.out.println();
            return;
        }
        while (a <= (int)1e6 && b >= 0) {
            if ((a+1) *  (a)/2 + b * (b-1)/2 == k && a + b <= (int)1e6+1) break;
            else if ((a+1) *  (a)/2 + b * (b-1)/2 < k) a++;
            else b--;
        }
        if (a== (long)1e6+1 || b < 0) {
            System.out.println(-1);
            return ;
        }
        int n = 0, ans[] = new int[(int)1e6+5];
        for (int i = 0; i < a; i++) {
            ans[i] = 0;
            n++;
        }
        ans[n] = 1;
        n++;
        for (int i = 0; i < b-1; i++) {
            ans[n] = 0;
            n++;
        }
        System.out.println(n);
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i]);
            if (i != n-1) System.out.print(" ");
        }
        System.out.println();
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