/*
POJ-1849
http://poj.org/problem?id=1849
*/

#include <iostream>
#include <vector>

std::vector<int> edge[100001];                 //��
std::vector<int> distance[100001];             //����
int sum, maxLength, newStart;                  //����֮��,�·��,�·��ĩ��Ҷ��

void dfs(int s, int father, int length) {
  if (length > maxLength) {                    //ѡ���·��
    maxLength = length;
    newStart = s;                              //ȷ��Ҷ��
  }
  for (int i = 0; i < edge[s].size(); ++i) {
    int j = edge[s][i];
    if (j == father) continue;                 //�Ǹ��ڵ�
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
  dfs(S, 0, 0);                                 //�ҵ��·��ĩ�˵�Ҷ��
  dfs(newStart, 0, 0);                          //��Ҷ�Ӵ�dfs��������
  std::cout << sum - maxLength;                 //��ʻ���� = �����б߳��� * 2 - �����·������(�������/ֱ��)
  return 0;
}