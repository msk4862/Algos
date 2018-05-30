#include<iostream>
#include<list>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

class Graph{
private:
int V;
list<int>* adj;

public:
Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	
}

void addEdge(int u,int v){
	
	adj[u].push_back(v);
}


void top_sort(){
	
	bool *visited = new bool[V];
	int *inDegree = new int[V];
	
	
	for(int i=0;i<V;i++){
		visited[i] = false;
		inDegree[i] = 0;
	}
	
	
	for(int j =0;j<V;j++){
		list<int>::iterator x;
	for(x=adj[j].begin();x!=adj[j].end();x++){
	   inDegree[*x]++;
	}
	}
	/*for(int j =0;j<V;j++){
		cout<<" "<<inDegree[j]<<" ";
	}*/
	
	queue<int> q;
	for(int j =0;j<V;j++){
		if(inDegree[j] ==0)
			q.push(j);
		
	}
	
	int count=0;
	
	vector<int> sort;
	
	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		sort.push_back(u);
		
		list<int> :: iterator x;
		for(x=adj[u].begin();x!=adj[u].end();x++){
	   if(--inDegree[*x] == 0)
		   q.push(*x);
	   
		}
		
	   count++;
	}
	if(count!=V){
		cout<<"\nTHE GIVEN GRAPH CONTAINS CYCLE\n";
		return;
	}
	
	else{
		for(int j =0;j<sort.size();j++){
		 cout<< sort[j]<<" ";
	}
		
	}
	
	
}

};

int main(){
cout<<"\nenter the number of vertices in your graph\n";
int V;
cin>>V;

Graph graph(V);

cout<<"\nenter vertices between which you want edge\n";
int x,y;
int i=1;
while(1){
	cout<<"==========="<<i++<<"==========="<<endl;
	cin>>x;
	cin>>y;
	if(x!=-1 && y!=-1)
		graph.addEdge(x,y);
	else
		break;
	
	
}

cout<<"\nenter the source vertex\n";
int source;
cin>>source;

graph.top_sort(graph);

return 0;

}