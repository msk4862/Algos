#include<iostream>
#include<cstdlib>

using namespace std;


int noOfComparison=0;
int noOfSwap = 0;

  void swap(int *arr,int i,int j){

    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;

    noOfSwap++;

  }


  void insertionSort(int *arr,int size){

     for(int i=1;i<size;i++){
      for(int j=i;j>0;j--){

        if(arr[j]<arr[j-1]){
          swap(arr,j,j-1);
          noOfComparison++;

        }

      }

     }

    }



int main(){



        int size;
	cout<<"\nenter the size of\n";
	cin>>size;



     int temp = size;

        int arr[size];
        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }


        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        insertionSort(arr,size);

         cout<<"\n\n the given array after applying insertion sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }

        cout<<"\n total number of swap : "<<noOfSwap<<endl;
        cout<<"\n total number of comparisons : "<<noOfComparison<<endl;
	return 0;

}


