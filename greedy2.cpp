#include<iostream>
#include<list>

using namespace std;


class Jobs{

 
list<int> jobs;

public:
void insert(int dead) {
	jobs.push_back(dead);
}

void sortJobs() {
	jobs.sort();
}

void calc() {
	
		list<int>::iterator i;

		int lastFin = 0, j = 1;

	    for ( i = jobs.begin(); i != jobs.end(); ++i) {
	    	cout<<"Job: "<<j++<<"   From :"<<lastFin<<"-"<<lastFin+(*i)<<endl;
	    	lastFin+=(*i);
	    }

			
}


};

int main(){

	Jobs l;
	
	l.insert(5);

	l.insert(6);
	l.insert(3);
	l.insert(1);
	

	l.sortJobs();

	
	//l.sort();
	l.calc();

	
	return 0;


}