#include<iostream>

using namespace std;


class node{

    public:
	int start;
	int finish;
	node *next;
	node *pre;
	node(int x,int y){
		next = pre = NULL;
		start = x;
		finish = y;
		
	}
	
};

class DLList{

public:

node* head;
node* tail;


DLList() {
	head = NULL;
	tail = NULL;
}

void insert(node * temp){


if(head==NULL){
	
head = tail = temp;

}

else{
	

	node* t = head;

	while(t!=NULL && t->finish <= temp->finish) {

		t = t->next;
	}


if (t == NULL)
{


	tail->next = temp;
		temp->pre = tail;

		tail = temp;
		tail->next = NULL;
}

else if (t->finish > temp->finish) {


	if (t == head)
	{



		temp->next = head;
		head->pre = temp;

		head = temp;

		head->pre = NULL;
	}

	else if (t == tail)
	{


		tail->pre->next = temp;
		temp->pre = tail->pre;

		temp->next = tail;
		tail->next = NULL;
	}

	else
	{


		node* tempor = t->pre;
		tempor->next = temp;
		temp->pre = tempor;

		t->pre = temp;
		temp->next = t;


	}
	
	}
	
	
}
}

void DeleteComp(node * temp) {
	
	node* t= temp->next;
	cout<<t->finish; 	 	
	
	while(t!=NULL) {
		
		if(t->start < temp->finish) {
			
				/*if(t==head) {
							cout<<"1"<<t->finish;

					head = head->next;
					head->pre = NULL;
					
					delete t;
				}*/
				
				if(t == tail) {

					tail = tail->pre;
					tail->next = NULL;
					
					//delete t;
				}
				else {

					t->pre->next = t->next;
					t->next->pre = t->pre;
					
					//delete t;
				}

		}

				t = t->next;
		
	}
}


void print() {
	
	node * t = head;
	
		while(t != NULL) {
			cout<<"Start Time: "<<t->start<<"  "<<"Finish Time: "<<t->finish<<endl;
			t=t->next;
		}
			
}


};

int main(){

	DLList l;
	
	l.insert(new node(1, 2));
	l.insert(new node(5, 6));
	l.insert(new node(3, 7));
	l.insert(new node(3, 4));

	
	
	//l.print();


	node* t = l.head;


	while(t!=l.tail) {
		l.DeleteComp(t);
		t = t->next;
	}
	
	//l.sort();
	l.print();

	
	return 0;


}