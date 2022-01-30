//---------------------------------------------------------------------------
//
//  2020112377 컴퓨터공학전공 김민수
//  Laboratory 11                                          bfsdfs2.cpp
//  Implement a program that determines whether 
//  a given graph is a bipartite graph or not
//
//----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V; //정점개수, 간선개수, 시작정점
vector<int> graph[2001];
int visited[2001]; //방문 X->0 RED->1 BLUE->2

void bfs(int v) {
    queue<int> que;
    int color = 1; // 처음 시작은 RED==1

    visited[v] = color;
    que.push(v);
    while (!que.empty()) {
        v = que.front();
        que.pop();

        if (visited[v] == 1) { //RED이면 BLUE로 바꿈
            color = 2;
        }
        else if (visited[v] == 2) { //BLUE이면 RED로 바꿈
            color = 1;
        }

        int gsize = graph[v].size();
        for (int i = 0; i < gsize; i++) {
            int next = graph[v][i]; //인접한 정점
            if (!visited[next]) {
                visited[next] = color; //인접한 정점 색깔 RED->BLUE or BLUE->RED로 칠해줌
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
            if (visited[i] == visited[next]) { //인접한 정점의 색깔이 같은게 있으면 false
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

    for (int i = 1; i <= N; i++) { //시작점을 바꿔가며 모든 정점에 대해 수행
        if (!visited[i]) { // 해당 정점을 아직 방문하지 않았다면,
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
