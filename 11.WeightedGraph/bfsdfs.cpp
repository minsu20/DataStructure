//---------------------------------------------------------------------------
//
//  2020112377 ��ǻ�Ͱ������� ��μ�
//  Laboratory 11                                          bfsdfs.cpp
// Implement a program that prints the results of searching 
// with BFSand searching with DFS for a given graph
//
//----------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N, M, V; //��������, ��������, ��������
int graph[1001][1001]; //���� ��� �׷���
bool visited[1001] = { false, }; //���� �湮 ����


void clear() { //�湮 ���� clear
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
            cout << top << " ";  //������ �湮�Ѱ� �ƴϸ� ���
        visited[top] = true;
        for (int i = N; i > 0; i--) { //������ȣ�� ���� �� ���� ���� �湮
            if (graph[top][i] == 1 && visited[i] == false) //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
                stk.push(i);
        }
    }
}

/*
void dfs(int v){
//���
   visited[v] = true;
   cout << v << " ";

   for (int i = 1; i <= N; i++) {
       if (graph[v][i] == 1 && visited[i] == false) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
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
            if (graph[v][w] == 1 && visited[w] == false) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
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