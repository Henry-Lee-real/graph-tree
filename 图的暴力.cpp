#include <bits/stdc++.h>
using namespace std;
//判断一下图的稠密度
//M~N^2判断为稠密图
//M~N判断为稀疏图
//现在可知是稀疏图，我们用邻接表来存
const int N = 1e6 + 10, M = N * 2;//定义常数
int n;
int h[N], e[M], ne[M], idx, ans = N;//开设邻接表
bool st[N];//标记走过

void add(int a, int b) {//邻接表默认插入边全部从表头插入
 e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int  dfs(int u) {
 st[u] = true;//标记一下走过了
 int sum = 1, res = 0;//sum存储 以u为根的树 的节点数, 包括u
 for (int i = h[u]; i != -1; i = ne[i]) {//链表遍历的方法
  int j = e[i];//因为每个节点的编号都是不一样的，所以 用编号为下标 来标记是否被访问过
  if (!st[j]) {//看是否访问过
   int s = dfs(j); // u节点的单棵子树节点数 如图中的size值
   res = max(res, s);// 记录最大联通子图的节点数
   sum += s;//以j为根的树 的节点数
  }
 }
 res = max(res, n - sum);// 选择u节点为重心，最大的 连通子图节点数
 ans = min(ans, res); //遍历过的假设重心中，最小的最大联通子图的 节点数
 return sum;
}

int main() {
 cin.tie(0);//加速读入
 cin >> n;
 memset(h, -1, sizeof h);//初始化表头全设-1
 for (int i = 0; i < n; i++) {
  int a, b;
  cin >> a >> b;
  add(a, b), add(b, a);//无向图，加两条边a->b和b->a
 }
 dfs(1);//从随便一个数开始爆搜整个图
 cout << ans << endl;//输出答案
 return 0;
}
