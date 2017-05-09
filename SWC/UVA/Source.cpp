#include <iostream>

using namespace std;

#define N 101
bool relationArray[N][N];
int numberOfTask, numberOfRelations;
bool shouldPrintSpace = false;
bool visited[N];

void DFS(int start){
	
	for (int i = 0; i <= numberOfTask; i++)
	{
		if (relationArray[start][i] && visited[start] == false)
		{
			visited[start] = true;
			DFS(i);

		}
	}
	if (shouldPrintSpace)
	{
		cout << ' ';
	}
	shouldPrintSpace = true;
	
	cout << start;
	
}

void clearAll(){
	bool shouldPrintSpace = false;
	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
		for (int j = 0; j < N; j++)
		{
			relationArray[i][j] = false;
		}
	}
}

void takeInput(){
	for (int i = 0; i < numberOfRelations; i++)
	{
		int before, after;
		cin >> before>> after;
		relationArray[before][after] = true;
	}
}

int main(){
	
	while (cin>> numberOfTask>>numberOfRelations)
	{
		if (numberOfTask == 0 && numberOfRelations == 0)
		{
			break;
		}
		clearAll();
		takeInput();
		for (int i = 1; i <= numberOfTask; i++)
		{
			DFS(i);
		}
		cout << endl;
	}
}