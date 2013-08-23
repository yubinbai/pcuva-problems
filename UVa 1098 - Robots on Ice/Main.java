import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    int r1, c1, s1;
    int r2, c2, s2;
    int r3, c3, s3;
    int R, C;
    boolean[][] grid;
    long count;
    int calls;
    int[] dx = { -1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public boolean valid(int x, int y, int X, int Y) {
        return x >= 0 && x < X && y >= 0 && y < Y;
    }

    public int manhattan(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public boolean isDisconnected() {
        Queue<Point> q = new LinkedList<Point>();
        boolean[][] vis = new boolean[R][C];
        boolean found = false;
        for (int i = 0; i < grid.length && !found; i++)
            for (int j = 0; j < grid[i].length && !found; j++) if (!grid[i][j]) {
                    q.add(new Point(i, j));
                    vis[i][j] = true;
                    found = true;
                }

        while (!q.isEmpty()) {
            Point c = q.poll();
            for (int i = 0; i < dx.length; i++) {
                int x = c.x + dx[i], y = c.y + dy[i];
                if (!valid(x, y, R, C) || vis[x][y] || grid[x][y]) continue;
                q.add(new Point(x, y));
                vis[x][y] = true;
            }
        }
        for (int i = 0; i < vis.length; i++)
            for (int j = 0; j < vis[i].length; j++)
                if (!vis[i][j] && !grid[i][j]) return true;
        return false;
    }

    public void solve(int x, int y, int step) {
        if (x == 0 && y == 1) {
            if (step == R * C) count++;
            return;
        }

        // if reached checkpoints before time
        if (x == r1 && y == c1 && step != s1) return;
        if (x == r2 && y == c2 && step != s2) return;
        if (x == r3 && y == c3 && step != s3) return;
        // if didn't reach checkpoints on time
        if (step == s1 && (x != r1 || y != c1)) return;
        if (step == s2 && (x != r2 || y != c2)) return;
        if (step == s3 && (x != r3 || y != c3)) return;

        if (step < s1 && manhattan(x, y, r1, c1) > (s1 - step)) return;
        if (step < s2 && manhattan(x, y, r2, c2) > (s2 - step)) return;
        if (step < s3 && manhattan(x, y, r3, c3) > (s3 - step)) return;

        // if not connected
        if (isDisconnected()) return;

        // check neighborhood condition
        int urgent = 0, index = -1;
        for (int k = 0; k < dx.length; k++) {
            int r = x + dx[k], c = y + dy[k];
            if (!valid(r, c, R, C) || grid[r][c] || (r == 0 && c == 1)) continue;
            int neighbors = 0;
            for (int i = 0; i < dx.length; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (!valid(nr, nc, R, C) || grid[nr][nc]) continue;
                neighbors++;
            }
            if (neighbors == 0) return;
            if (neighbors == 1) {
                urgent++;
                index = k;
            }
        }

        // applying action on neighborhood case
        if (urgent > 1) return;
        else if (urgent == 1) {
            grid[x + dx[index]][y + dy[index]] = true;
            solve(x + dx[index], y + dy[index], step + 1);
            grid[x + dx[index]][y + dy[index]] = false;
            return;
        }

        // ordinary case
        for (int k = 0; k < dx.length; k++) {
            int r = x + dx[k], c = y + dy[k];
            if (!valid(r, c, R, C) || grid[r][c]) continue;
            grid[r][c] = true;
            solve(r, c, step + 1);
            grid[r][c] = false;
        }
    }

    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            int TC = 1;
            while (true) {
                String[] toks = in.readLine().trim().split("[ ]+");
                R = Integer.parseInt(toks[0]);
                C = Integer.parseInt(toks[1]);
                if (R == 0 && C == 0) break;
                toks = in.readLine().trim().split("[ ]+");
                r1 = Integer.parseInt(toks[0]);
                c1 = Integer.parseInt(toks[1]);
                r2 = Integer.parseInt(toks[2]);
                c2 = Integer.parseInt(toks[3]);
                r3 = Integer.parseInt(toks[4]);
                c3 = Integer.parseInt(toks[5]);

                count = 0L;
                grid = new boolean[R][C];
                s1 = R * C / 4;
                s2 = R * C / 2;
                s3 = 3 * R * C / 4;
                grid[0][0] = true;
                calls = 0;
                solve(0, 0, 1);
                System.out.println("Case " + (TC++) + ": " + count);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
