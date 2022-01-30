//---------------------------------------------------------------------------
//
//  2020112377 ��ǻ�Ͱ������� ��μ�
//  Laboratory 11                                          bfsdfs2.cpp
//  Implement a program that determines whether 
//  a given graph is a bipartite graph or not
//
//----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V; //��������, ��������, ��������
vector<int> graph[2001];
int visited[2001]; //�湮 X->0 RED->1 BLUE->2

void bfs(int v) {
    queue<int> que;
    int color = 1; // ó�� ������ RED==1

    visited[v] = color;
    que.push(v);
    while (!que.empty()) {
        v = que.front();
        que.pop();

        if (visited[v] == 1) { //RED�̸� BLUE�� �ٲ�
            color = 2;
        }
        else if (visited[v] == 2) { //BLUE�̸� RED�� �ٲ�
            color = 1;
        }

        int gsize = graph[v].size();
        for (int i = 0; i < gsize; i++) {
            int next = graph[v][i]; //������ ����
            if (!visited[next]) {
                visited[next] = color; //������ ���� ���� RED->BLUE or BLUE->RED�� ĥ����
                que.push(next);
            }
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= N; i++) {
        int gsize = graph[i].size();
        for (int j = 0; j < gsize; j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) { //������ ������ ������ ������ ������ false
                return false;
            }
        }
    }
    return true;
}


int main() {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) { //�������� �ٲ㰡�� ��� ������ ���� ����
        if (!visited[i]) { // �ش� ������ ���� �湮���� �ʾҴٸ�,
            bfs(i);
        }
    }

    if (isBipartiteGraph() == true) {
        cout << "Is this bipartit graph? Yes";
    }
    else {
        cout << "Is this bipartite graph? No";
    }
}
