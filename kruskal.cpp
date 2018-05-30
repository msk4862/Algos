#include<iostream>
#include<list>

using namespace std;

class edge {

public:

	int s, d, w;


	 void addEdge(int S, int D, int W) {
		s = S;
		d = D;
		w = W;
	}



		bool findset(edge a[]) {


				int len = sizeof(a)/sizeof(a[0]);

			for (int i = 0; i < len; ++i)
			{
				if (a[i].s == d || a[i].d == s || a[i].s == s || a[i].d == d)
				{
					return false;
				}
			}
			return true;
	}
};


	bool sortbyW(edge &A, edge &B) 
{
    return (A.w < B.w);
}

int main()
{
	
	
	int v;
	cout<<"Enter number vertices: ";
	cin>>v;

	edge MST[v];

	//edge edges[v];

	list<edge> e;

	/*edges = new edge[v];
	MST = new edge[v];*/

	edge ed;

	cout<<"\nenter vertices between which you want edge and weight\n";
int x,y, w;
int i=1;
while(1){
    cout<<"\n==========="<<i++<<"==========="<<endl;
    cin>>x>>y;
    cout<<"weight: ";
    cin>>w;
    if(x!=-1 && y!=-1) {
        //edges[i-2].addEdge(x,y, w);
        ed.addEdge(x, y, w);
        e.push_back(ed);
    }
    else
        break;
    
    
}

/*for (int i = 0; i < v-1; ++i)
{
	for (int j = i+1; j < v; ++j)
	{
		if (edges[j].w > edges[j+1].w)
		{
			edge e = edges[j];
			edges[j] = edges[j+1];
			edges[j+1] = e;
		}
	}


}*/

e.sort(sortbyW);

list<edge>:: iterator i;

for ( i = e.begin(); i != e.end(); ++i)
{
		cout<<(*i).s;//<<" => "<<e[i].d<<"   "<<e[i].w<<endl;

}

int k=1;

MST[0] = e.begin();

for ( i =e.begin(); i != e.end(); ++i)
{
	if ((*i).findset(MST))
	{
		MST[k++] = (*i);
	}
}
	

/*for (int i = 0; i < k; ++i)
{
	cout<<MST[i].s<<" => "<<MST[i].d<<endl;
}

	return 0;*/
}

