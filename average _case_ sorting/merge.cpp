#include<iostream>
#include<cstdlib>
using namespace std;


int noOfComparison=0;
int noOfSwap=0;



  void merge(int arr[],int l,int m,int r) {

  int i,j,k;

  int num1 = m-l+1;
  int num2 = r-m;


  int L[num1],R[num2];

  for(i=0;i<num1;i++)
   L[i] = arr[l+i];

   for(j=0;j<num2;j++)
    R[j] = arr[m+1+j];

    i=j=0;
    k=l;

    while(i<num1 && j<num2){

    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
      noOfComparison++;

    }

    else{

      arr[k] = R[j];
      j++;

     noOfComparison++;
    }

    k++;

    }


    while(i<num1){

        arr[k] = L[i];
        i++;
        k++;
    }


    while(j<num2){

       arr[k] = R[j];
        j++;
        k++;

    }



  }

  void mergeSort(int arr[],int l,int r){

   if(l<r){

      //cout<<"hello";
      int m = l+(r-l)/2;
      //cout<<"hello";
      mergeSort(arr,l,m);
      mergeSort(arr,m+1,r);

      merge(arr,l,m,r);


  }


  }



int main(){



        int size;
	cout<<"\nenter the size of array \n";
	cin>>size;

        int arr[size];


        int temp = size;


        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }

        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        mergeSort(arr,0,size-1);

         cout<<"\n the given array after applying merge sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}


