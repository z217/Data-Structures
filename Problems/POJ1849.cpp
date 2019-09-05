/*
POJ-1849
http://poj.org/problem?id=1849
*/

#include <iostream>
#include <vector>

std::vector<int> edge[100001];                 //边
std::vector<int> distance[100001];             //距离
int sum, maxLength, newStart;                  //距离之和,最长路径,最长路径末端叶子

void dfs(int s, int father, int length) {
  if (length > maxLength) {                    //选出最长路径
    maxLength = length;
    newStart = s;                              //确定叶子
  }
  for (int i = 0; i < edge[s].size(); ++i) {
    int j = edge[s][i];
    if (j == father) continue;                 //非父节点
    int k = distance[s][i];
    dfs(j, s, length + k);
  }
}

int main() {
  int N, S, a, b, c;
  std::cin >> N >> S;
  for (int i = 1; i < N; ++i) {
    std::cin >> a >> b >> c;
    edge[a].push_back(b);
    edge[b].push_back(a);
    distance[a].push_back(c);
    distance[b].push_back(c);
    sum += c * 2;
  }
  dfs(S, 0, 0);                                 //找到最长路径末端的叶子
  dfs(newStart, 0, 0);                          //从叶子处dfs求出最长距离
  std::cout << sum - maxLength;                 //行驶距离 = 树所有边长度 * 2 - 树中最长路径距离(树的深度/直径)
  return 0;
}