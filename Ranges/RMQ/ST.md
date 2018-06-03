# RMQ-ST(Sparse Table)

RMQ（Range Minimum/Maximum Query），即区间最值查询，是指这样一个问题：对于长度为n的数列A，回答若干次询问RMQ(i,j)，返回数列A中下标在区间[i,j]中的最小/大值。 

时间复杂度：$O(nlogn)$



## 预处理：

$f[i][j]$ 表示从 $i$ 这个数开始连续 $2^j$ 个数中的最大值

初始值：$f[i][0]=a[i]$

状态转移：$f[i][j]=max(f[i][j-1],f[i+2^{j-1}][j-1])$



## 查询

$RMQ(i, j)=max(F[i][k], F[ j-2^k+1][k])$

其中 $k=log_2(j-i+1)$



## 代码

```cpp
void ST(int n)
{
    for (int i=1;i<=n;i++) dp[i][0]=A[i];
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r)
{
    int k=0;
    while ((1<<(k+1))<=r-l+1) k++;
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
```

