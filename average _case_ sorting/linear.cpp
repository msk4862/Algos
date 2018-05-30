#include<iostream>
using namespace std;

void linearSort(int *arr,int size){

   int min;int max;

   for(int i=0;i<size;i++){

    if(arr[i]<min)
    min = arr[i];

    if(arr[i]>max)
    max = arr[i];

   }

   int sizeTemp = max-min+1;

   int *tempArr = new int[sizeTemp];

   int x=0;int y=0;int z=0;                   //temprory

   for(int i =0;i<sizeTemp;i++){
   x = arr[i];
   tempArr[x] +=1;
   }


   for(int i =1;i<sizeTemp;i++)
   tempArr[i] = tempArr[i]+tempArr[i-1];


   int *finalArr = new int[size];


   for(int i=size-1;i>=0;i--){

    x = arr[i];
    y = tempArr[x];

    finalArr[y] = arr[i];

    tempArr[x]--;

   }

   for(int i=0;i<size;i++){
          arr[i] = finalArr[i];

        }

}


int main(){



        int size;
	cout<<"\nenter the size of array \n";
	cin>>size;

        int *arr = new int[size];


        int temp = size;


        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }

        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        linearSort(arr,size);

         cout<<"\n the given array after applying merge sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}
