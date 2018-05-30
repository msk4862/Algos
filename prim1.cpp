 
#include<iostream>
#include<list>
#include<queue>
using namespace std;
 
class Graph  {

public:
    int V;
    list< pair<int, int> >* adj;

    bool cycle;

    Graph(int v) {
        V=v;
        cycle = false;
        adj = new list <pair<int, int> >[v];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));

    }

    void print() {
            list< pair<int, int> >::iterator i;

            for (int j = 0; j < V; ++j)
            {
                    
                for ( i = adj[j].begin(); i != adj[j].end(); ++i)
                {
                       cout<<j<<"=> "<<(*i).first<<" "<<(*i).second<<endl;
                    
                }
                cout<<endl;
            }
            
    }

   void prim(int source) {
        bool* visited = new bool[V];

        int minKey;

        int min  = 9999999;

        queue<int> s;

        for (int i = 0; i < V; ++i)
        {
            visited[i] = false;
            s.push(i);
        }


        visited[source] = true;


            list<pair<int, int> >::iterator i;      

        while(!s.empty()) {
            int cur = s.front();
            s.pop();


            for ( i = adj[cur].begin(); i != adj[cur].end(); ++i)
            {
                if (visited[(*i).first] == false && min > (*i).second)
                {


                    // cout<<(*i).first<<" ";
                    minKey = (*i).first;
                    min = (*i).second;

                }
            }
            if (minKey != -1)
            {
               visited[minKey] = true;

                cout<<cur<<"=>"<<(minKey)<<" "<<min<<endl;
            }
               

            min = 999999;
            minKey = -1;
        }

    }


};

int main()
{
cout<<"\nenter the number of vertices in your graph\n";
int V;
cin>>V;

Graph graph(V);

cout<<"\nenter vertices between which you want edge and weight\n";
int x,y, w;
int i=1;
while(1){
    cout<<"\n==========="<<i++<<"==========="<<endl;
    cin>>x>>y;
    cout<<"weight: ";
    cin>>w;
    if(x!=-1 && y!=-1)
        graph.addEdge(x,y, w);
    else
        break;
    
    
}
	
	graph.print();

    graph.prim(0);		
	
		return 0;
}

