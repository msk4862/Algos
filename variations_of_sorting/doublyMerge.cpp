#include<iostream>
#include<cstdlib>

using namespace std;

 template<class T>
 class node{

	public:
	T data;
	node<T> *next;
	node<T> *previous;

  };


 template<class T>
 class DLList{

	public:
	 node<T> *head,*tail;

	public:

	 DLList(){  head = tail = 0; };

 void insert(T data){

		 node<T> *temp = new node<T>;

		 temp->data = data;

	     if(head == 0){

	     head = tail = temp;
	     temp->next = temp->previous = 0;

	     }


	     else{

	       tail->next = temp;
	       temp->previous = tail;
	       tail = temp;
	       tail->next = 0;


	     }

	}


 void display(){

   node<T> *temp = head;

   if(temp!=0){

    while(temp->next !=0){

     cout<<temp->data<<"  ";
     temp = temp->next;


    }

     cout<<temp->data<<"  ";

   }




  }

node<T>* merge(DLList list1,DLList list2){


 node<T> *temp1=new node<T>,*temp2 = new node<T>;

   temp1 = list1.head; temp2 = list2.head;


if(temp1 == 0)
return temp2;

else if(temp2 == 0)
return temp1;

else{

   while(temp1!=0 && temp2!=0){
   if(temp1->data < temp2->data){
     temp2= temp2->next;

   }

   else{

       node<T> *temp = temp2;
      temp->next = temp1->next;
      temp1->next = temp;
      temp->previous = temp1;
      temp->next->previous = temp2;


      temp2= temp2->next;
   }
   }

   if(temp1!=0){
     return list1.head;

   }

   while(temp2!=0){
      if(list1.tail->data < temp2->data){
        node<T> *temp = temp2;
        list1.tail->next = temp;
        temp->previous = list1.tail;
        list1.tail = list1.tail->next;
        tail->next = 0;

        temp2 = temp2->next;
        temp2->previous = 0;

   }

   else{

      node<T> *temp = temp2;
      temp->previous = list1.tail->previous;
      temp->previous->next = temp;
      temp->next = list1.tail;

         temp2 = temp2->next;
         temp2->previous = 0;
   }

   }

}
  return list1.head;

}

void mergeSort(node<T> *head){


}



};


int main(){

DLList<int> list1,list2,list3;

int choice ;

int count=0;

do{


cout<<"\n\n =========== option ========== ";
cout<<"\n(1) insert number";
cout<<"\n(2) show list";
cout<<"\n(3) sort list using merge sort  ";
cout<<"\n(4) exit\n";
cout<<"\nenter choice :: ";

cin>>choice;

switch(choice){

case 1 :   cout<<"\n\n===== input =====\n\n";
           cout<<"enter number :: ";
           int num;
           cin>>num;
           if(count%2==0)
           list1.insert(num);
           else
           list2.insert(num);
           break;


case 2 :   cout<<"\n\n===== output =====\n\n";
           cout<<"array :: ";
           list1.display();

           cout<<endl;

           cout<<"array :: ";
           list2.display();


            cout<<endl;
           break;

case 3 :   list3.head = list1.mergeSort(list1,list2);

           break;


case 4 :  cout<<"\n\n===== exit =====\n\n";
          cout<<"exiting .....\n";
          exit(0);




}

}while(true);










return 0;

}
