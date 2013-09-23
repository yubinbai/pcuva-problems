    #include<vector>
    #include<cstdio>
    using namespace std;

    int len;
    vector<int> ans, now;

    bool update()
    {
        if (len > now.size())
            return true;
        for (int i = 0; i < len; i++)
            if (ans[i] > now[i])
                return true;
            else if (ans[i] < now[i])
                return false;
        return false;
    }

    void dfs(int depth, int x, int last)
    {
        if (x == 1)
        {
            if (update())
            {
                ans = now;
                len = depth - 1;
            }
            return;
        }
        if (depth > len)
            return;
        for (int i = last; i <= 9; i++)
            if (x % i == 0)
            {
                now.push_back(i);
                dfs(depth + 1, x / i, i);
                now.pop_back();
            }
    }

    int main()
    {
        int T;
        scanf("%d", &T);
        while (T--)
        {
            int n;
            scanf("%d", &n);

            if (n == 0 || n == 1)
            {
                printf("%d\n", n);
                continue;
            }
            len = 0x7f7f7f7f;
            now.clear();
            dfs(1, n, 2);

            if (len == 0x7f7f7f7f)
                printf("%d\n", -1);
            else
            {
                for (int i = 0; i < ans.size(); i++)
                    printf("%d", ans[i]);
                printf("\n");
            }
        }

        return 0;
    }
