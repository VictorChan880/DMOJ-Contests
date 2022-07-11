import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e5+5, mod = 998244353;

    public static void main(String[] args) throws IOException {
        int n = readInt(), m = readInt();
        char a[][] = new char[n][m];
        for (int i = 0; i < n; i++) {
            String str = next();
            for (int j = 0; j < m; j++) {
                a[i][j] = str.charAt(j);
            }
        }
        int pre = n * m, cnt = n*m;
        while (true) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int mirror_i = n - i - 1;
                    int mirror_j = m - j - 1;
                    if (a[i][j] != '.') {
                        if (a[mirror_i][j] != '.' && a[i][j] != a[mirror_i][j]) {
                            System.out.print(-1);
                            return;
                        }
                        if (a[i][mirror_j] != '.' && a[i][j] != a[i][mirror_j]) {
                            System.out.print(-1);
                            return;
                        }
                        if (a[mirror_i][j] == '.') {
                            a[mirror_i][j] = a[i][j];
                            cnt--;
                        }
                        if (a[i][mirror_j] == '.') {
                            a[i][mirror_j] = a[i][j];
                            cnt--;
                        }
                    }
                }
            }
            if (cnt == pre) break;
            pre = cnt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(a[i][j] == '.' ? 'a' : a[i][j]);
            }
            if (i != n-1) System.out.println();
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
/*
3 3
...
...
..b
 */