#include<iostream>
#include<list>
#include<stack>
using namespace std;


class Graph  {

public:
	int V;
	list<int>* adj;

	bool cycle;

	Graph(int v) {
		V=v;
		cycle = false;
		adj = new list<int>[v];
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void print() {
			list<int>::iterator i;

			for (int j = 0; j < V; ++j)
			{
					cout<<j<<"=> ";
				for ( i = adj[j].begin(); i != adj[j].end(); ++i)
				{
						cout<<*i<<", ";
					
				}
				cout<<endl;
			}
			
	}

	bool isCycle() {
		bool* visited = new bool[V];

		for (int i = 0; i < V; ++i)
		{
			visited[i] = false;
		}


		stack<int> s;
		s.push(0);
		visited[0] = true;


			list<int>::iterator i;		

		while(!s.empty()) {
			int cur = s.top();
			s.pop();


			for ( i = adj[cur].begin(); i != adj[cur].end(); ++i)
			{
				if (!visited[*i])
				{
					visited[*i] = true;
					s.push(*i);
				}
				else {
					return true;
	
				}
			}
		}

		return cycle;
	}


};


int main() {
cout<<"\nenter the number of vertices in your graph\n";
int V;
cin>>V;

Graph graph(V);

cout<<"\nenter vertices between which you want edge\n";
int x,y;
int i=1;
while(1){
	cout<<"==========="<<i++<<"==========="<<endl;
	cin>>x>>y;
	if(x!=-1 && y!=-1)
		graph.addEdge(x,y);
	else
		break;
	
	
}

graph.print();


if (graph.isCycle())
{
	cout<<"Cycle";
}
else {
		cout<<"No Cycle";
}

//cout<<"\nenter the source vertex\n";
//int source;
//cin>>source;

//graph.dfs(source);

return 0;

}
