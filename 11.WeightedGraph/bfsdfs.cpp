//---------------------------------------------------------------------------
//
//  2020112377 컴퓨터공학전공 김민수
//  Laboratory 11                                          bfsdfs.cpp
// Implement a program that prints the results of searching 
// with BFSand searching with DFS for a given graph
//
//----------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N, M, V; //정점개수, 간선개수, 시작정점
int graph[1001][1001]; //인접 행렬 그래프
bool visited[1001] = { false, }; //정점 방문 여부


void clear() { //방문 여부 clear
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

void dfs(int v) {
    stack<int> stk;

    stk.push(v);

    while (!stk.empty())
    {
        int  top = stk.top();
        stk.pop();
        if (visited[top] == false)
            cout << top << " ";  //뽑은게 방문한게 아니면 출력
        visited[top] = true;
        for (int i = N; i > 0; i--) { //정점번호가 작은 것 부터 먼저 방문
            if (graph[top][i] == 1 && visited[i] == false) //현재 정점과 연결되어있고 방문하지 않았으면
                stk.push(i);
        }
    }
}

/*
void dfs(int v){
//재귀
   visited[v] = true;
   cout << v << " ";

   for (int i = 1; i <= N; i++) {
       if (graph[v][i] == 1 && visited[i] == false) { //현재 정점과 연결되어있고 방문하지 않았으면
           dfs(i);
       }
   }
   */

void bfs(int v) {
    queue<int> que;
    que.push(v);
    visited[v] = true;
    cout << v << " ";

    while (!que.empty()) {
        v = que.front();
        que.pop();

        for (int w = 1; w <= N; w++) {
            if (graph[v][w] == 1 && visited[w] == false) { //현재 정점과 연결되어있고 방문하지 않았으면
                que.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    clear();
    cout << "BFS: ";
    bfs(V);
    cout << "\n";

    clear();
    cout << "DFS: ";
    dfs(V);
    cout << '\n';

    return 0;
}