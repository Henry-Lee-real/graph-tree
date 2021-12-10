#include <bits/stdc++.h>
using namespace std;
//�ж�һ��ͼ�ĳ��ܶ�
//M~N^2�ж�Ϊ����ͼ
//M~N�ж�Ϊϡ��ͼ
//���ڿ�֪��ϡ��ͼ���������ڽӱ�����
const int N = 1e6 + 10, M = N * 2;//���峣��
int n;
int h[N], e[M], ne[M], idx, ans = N;//�����ڽӱ�
bool st[N];//����߹�

void add(int a, int b) {//�ڽӱ�Ĭ�ϲ����ȫ���ӱ�ͷ����
 e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int  dfs(int u) {
 st[u] = true;//���һ���߹���
 int sum = 1, res = 0;//sum�洢 ��uΪ������ �Ľڵ���, ����u
 for (int i = h[u]; i != -1; i = ne[i]) {//��������ķ���
  int j = e[i];//��Ϊÿ���ڵ�ı�Ŷ��ǲ�һ���ģ����� �ñ��Ϊ�±� ������Ƿ񱻷��ʹ�
  if (!st[j]) {//���Ƿ���ʹ�
   int s = dfs(j); // u�ڵ�ĵ��������ڵ��� ��ͼ�е�sizeֵ
   res = max(res, s);// ��¼�����ͨ��ͼ�Ľڵ���
   sum += s;//��jΪ������ �Ľڵ���
  }
 }
 res = max(res, n - sum);// ѡ��u�ڵ�Ϊ���ģ����� ��ͨ��ͼ�ڵ���
 ans = min(ans, res); //�������ļ��������У���С�������ͨ��ͼ�� �ڵ���
 return sum;
}

int main() {
 cin.tie(0);//���ٶ���
 cin >> n;
 memset(h, -1, sizeof h);//��ʼ����ͷȫ��-1
 for (int i = 0; i < n; i++) {
  int a, b;
  cin >> a >> b;
  add(a, b), add(b, a);//����ͼ����������a->b��b->a
 }
 dfs(1);//�����һ������ʼ��������ͼ
 cout << ans << endl;//�����
 return 0;
}
