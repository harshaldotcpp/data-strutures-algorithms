#include <iostream>
#include <stdlib.h>
using namespace std;

bool subsetSum(int arr[],int n,int sum){
	bool t[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(j == 0)
				t[i][j] = true;
			else if(i == 0)
				t[i][j] = false;
			else if(arr[i-1] <= j){
				t[i][j] = t[i-1][j - arr[i-1]] ||
				    t[i-1][j];
			}
			else t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}

bool equalSum(int arr[],int n){
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];
		
	if(sum % 2 != 0) return false;
	return subsetSum(arr,n,sum/2);
}




int main(int argc, char *argv[])
{
	int arr[] ={1,5,11,9};
	int n = sizeof(arr)/sizeof(int);
	cout<<equalSum(arr,n);
}