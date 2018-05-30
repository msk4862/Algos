#include<iostream>
#include<cstdlib>
using namespace std;


int noOfComparison=0;
int noOfSwap=0;

  void swap(int *arr,int i,int j){

    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
    noOfSwap++;

  }


  void selectionSort(int *arr,int size){

     for(int i=0;i<size-1;i++){
       int minIndex = i;

      for(int j=i+1;j<size;j++){

        if(arr[j]<arr[minIndex]){
          swap(arr,j,minIndex);
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


        selectionSort(arr,size);

         cout<<"\n the given array after applying insertion sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}


