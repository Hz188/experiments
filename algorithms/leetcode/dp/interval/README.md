
## 区间DP

与线性DP的区别

- 线性DP：一般是在前缀或者后缀上转移
- 区间DP：从小区间转移到大区间

选或不选

- 从两侧向内部**缩小**问题规模
- 516. 最长回文子序列

枚举选哪个

- **分割**成多个规模更小的子问题
- 1039. 多边形三角剖分的最低得分

### 516 最长回文子序列

s = eacbba

- 思路1：「转换」求s和s翻转后的LCS
- 思路2：「选或不选」从两侧向内缩小问题规模
  - <img src="../../../assets/imgs/algorithms/leetcode/dp/image-3.png" width="50%"/>

这里展开的是思路2

- dfs(i,j) 表示s[i]到s[j]的最长回文子序列的长度

转移方程有

- dfs(i,j) =
  - dfs(i+1, j-1) s[i] == s[j]
  - max(dfs(i+1, j), dfs(i, j-1))  s[i] != s[j]

递归边界

- dfs(i, i) = 1
- dfs(i+1, i) = 0

递归入口

- dfs(0, n-1)

翻译成递推, f[i][j]

- 0 i > j
- 1 i == j
- f[i+1][j-1] + 2 s[i] == s[j]
- max(f[i+1][j], f[i][j-1])) s[i] != s[j]

循环顺序

- f[i]从f[i+1]转移过来，所以i要**倒序**枚举
- f[i][j]从f[i][j-1]转移过来，所以j要**正序**枚举

答案：f[0][n-1]


### 1039 多边形三角形剖分的最低得分

无论怎么去剖分，相邻两个顶点连线的边（比如1-5），**一定**在一个三角形中，枚举这个三角形，有四种选择

<img src="../../../assets/imgs/algorithms/leetcode/dp/image-4.png" width="25%"/>

数组values简记为v

- 定义「从i到j」表示沿着边从顶点i到顶点j，再加上直接从j到i的这条边所组成的多边形<img src="../../../assets/imgs/algorithms/leetcode/dp/image-5.png" width="20%"/>
- 子问题：计算从i到j的最低得分
- 选择：枚举k
- 下一个子问题：计算从i到k的最低得分，计算从k到j的最低得分

所以有递归函数定义和转移

- dfs(i, j) 是「从i到j」这个多边形的最低得分
- dfs(i, j) = min(dfs(i,k)+dfs(k,j)+v[i]\*v[j]\*v[k]), k in [i+1,j-1]
- 递归边界：dfs(i,i+1) = 0
- 递归入口：dfs(0,n-1)

翻译成递推

- f[i][j] =  min(f[i][k] + f[k][j] + v[i]\*v[j]\*v[k]), k in [i+1, j)
- 循环顺序
  - i < k, f[i] 从 f[k] 转移过来，所以i要倒序枚举
  - j > k, f[i][j] 从f[i][k] 转移过来，所以j要正序枚举
- 初始状态 f[i][j+1] = 0
- 最终答案 f[0][n-1]
