#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main(){

cout<<"\nenter the number";
int num;
cin>>num;

/*
cout<<"\n enter the name for file\n";
char *name;
cin>>name;
*/

ofstream f;
f.open("rand1000");


//cout<<"ok?";
int random;
for(int i=0;i<num;i++){
random = rand()%1000;
 f<<random<<" ";

}
//cout<<"ok?";
f.close();
cout<<"\n done \n";
return 0;
}
