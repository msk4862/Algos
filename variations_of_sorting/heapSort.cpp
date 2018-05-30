#include<iostream>
using namespace std;


 void swap(int A[],int i,int j){

    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;

 }

  void maxHeapify(int A[] , int size , int i){

      int l = 2*i+1;
      int r = 2*i+2;

      int largest = i;

      if(l< size && A[largest]<A[l])
      largest = l;

      else if(r<size && A[largest]<A[r])
      largest = r;

      if(largest!=i){
            swap(A,largest,i);
            maxHeapify(A,size,largest);

      }


  }


void BuildMaxHeap(int A[],int size){

for(int i=size/2-1;i>=0;--i)
maxHeapify(A,size,i);


}


    void HeapSort(int A[],int size){

     BuildMaxHeap(A,size);
     for(int i=size-1;i>=0;i--){
       swap(A,0,i);

       maxHeapify(A,i,0);
     }

    }


int main(){

     int size;
	cout<<"\nenter the size of\n";
	cin>>size;



     int temp = size;

        int arr[size];
        for(int i=0;i<size;i++){

          arr[i] = temp--;
            cout<<temp;


        }


        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        HeapSort(arr,size);

         cout<<"\n\n the given array after applying insertion sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }

        //cout<<"\n total number of swap : "<<noOfSwap<<endl;
        //cout<<"\n total number of comparisons : "<<noOfComparison<<endl;
	return 0;






}
