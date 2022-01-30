//--------------------------------------------------------------------
// 2020112377 컴퓨터공학전공 김민수
//  Laboratory 11                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include "wtgraph.h"

//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber)
	:maxSize(maxNumber), size(0)
{
	vertexList = new Vertex[maxSize];
	adjMatrix = new int[maxSize* maxSize];
	pathMatrix = new int[maxSize * maxSize];

	for (int i = 0; i < maxSize * maxSize; i++) {
		adjMatrix[i] = infiniteEdgeWt;
		pathMatrix[i] = infiniteEdgeWt; //초기화
	}
}

WtGraph::~WtGraph()
{
	delete[] vertexList;
	delete[] adjMatrix;
	delete[] pathMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
	string str = v;
	for (int i = 0; i < size; i++) {
		if (str == vertexList[i].label)
			return i;
	}
	return -1; //못찾으면 -1리턴
}

int WtGraph::getEdge(int row, int col)
{
	return adjMatrix[maxSize* row + col];
}

void WtGraph::setEdge(int row, int col, int wt)
{
	adjMatrix[maxSize * row + col] = wt;
}

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex)
{
	if (isFull()) { //Graph is not full
		cout << "Graph is Full" << endl;
	}
	else {
		int index = getIndex(newVertex.label);
		if (index == -1) { 
			vertexList[size++] = newVertex;
		}
		else {//If the vertex already exists in the graph, then updates it.
			vertexList[index] = newVertex;
		}
	}
}

void WtGraph::insertEdge(char* v1, char* v2, int wt)
{
	int row = getIndex(v1);
	int column = getIndex(v2); 
	if (row == -1 || column == -1) { //Graph includes vertices v1and v2.
		cout << "Either v1 and v2 does Not exist" << endl;
	}
	else {
		setEdge(row, column, wt);
		setEdge(column, row, wt);
	}
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
	if (getIndex(v) == -1)
		return false;
	else { //If this vertex is found, then copies the vertex’s data to vData and returns true.
		vData = vertexList[getIndex(v)];
		return true;
	}
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt)
{
	int row = getIndex(v1);
	int column = getIndex(v2);

	if (row == -1 || column == -1) {  //Graph includes vertices v1and v2.
		return false;
	}
	else if (getEdge(row, column) != infiniteEdgeWt) { //If this edge exists, then returns true with wt returning the weight of the edge.
		wt = adjMatrix[maxSize * row + column];
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v)
{
	int index = getIndex(v);
	if (index == -1) {
		cout << "Vertex does Not exist" << endl;
	}
	else 
	{
			for (int i = index; i < size-1; i++) {
				vertexList[i] = vertexList[i + 1];
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = index; j < size - 1; j++)
					setEdge(i, j, getEdge(i, j + 1));
			}

			for (int i = 0; i < size; i++)
			{
				for (int j = index; j < size - 1; j++)
					setEdge(j, i, getEdge(j + 1, i));
			}
			size--;
	}
}

void WtGraph::removeEdge(char* v1, char* v2)
{
	int row = getIndex(v1);
	int column = getIndex(v2); 

	if (row == -1 || column == -1) { //Graph includes vertices v1and v2.
		cout << "Either v1 and v2 does Not exist" << endl;
	}
	else {
		setEdge(row, column, infiniteEdgeWt);
		setEdge(column, row, infiniteEdgeWt);
	}
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
	size = 0;
	for (int i = 0; i < maxSize * maxSize; i++) {
		adjMatrix[i] = infiniteEdgeWt;
		pathMatrix[i] = infiniteEdgeWt;
	}
}

bool WtGraph::isEmpty() const
{
	return size == 0;
}

bool WtGraph::isFull() const
{
	return size == maxSize;
}

//--------------------------------------------------------------------
void WtGraph::showStructure()

// Outputs a graph's vertex list, adjacency matrix, and path matrix.
// This operation is intended for testing/debugging purposes only.

{
	int wt,         // Edge weight
		row, col;   // Loop counters

	if (size == 0)
		cout << "Empty graph" << endl;
	else
	{
		cout << endl << "Vertex list : " << endl;
		for (row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].label << endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getEdge(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}

		cout << endl << "Path matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getPath(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

//--------------------------------------------------------------------


 int WtGraph::getPath(int row, int col)
 {
	 return pathMatrix[row * maxSize + col];
 }

void WtGraph::setPath(int row, int col, int wt)
{
	pathMatrix[row * maxSize + col] = wt;
}


void WtGraph::computePaths() 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) 
				pathMatrix[i * maxSize + j] = 0; // create a path with cost 0 from each vertex back to itself
			else 
				pathMatrix[i * maxSize + j] = adjMatrix[i * maxSize + j]; //Initialize the path matrix so that it is the same as the edge matrix(all edges are paths).
		}
	}

	for (int m = 0; m < size; m++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				int path1 = getPath(j, m);
				int path2 = getPath(m, k);
				int totalpath = getPath(j, k);
				if (path1 != infiniteEdgeWt && path2 != infiniteEdgeWt && path1 + path2 <totalpath) {
					/*If there exists a path from vertex j to vertex m and
						there exists a path from vertex m to vertex k and
						the sum of entries(j, m) and (m, k) is less than entry (j, k) in the path matrix,*/
					setPath(j, k, path1 + path2); 
					setPath(k, j, path1 + path2); //then replace entry (j,k) with the sum of entries (j,m) and (m, k).
				}
			}
		}
	}
}