#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int arr[50000];
void merge(int[], int, int, int);

void merge_sort(int *a, int p, int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

void merge(int a[], int p, int q, int r){
	int n1 = q - p + 2;
	int n2 = r - q + 1;
	int la[n1], ra[n2], i, j, k;
	for(i=0;i<n1 - 1;i++)
	    la[i] = a[p + i];
	for(j=0;j<n2 - 1;j++)
	    ra[j] = a[j + q + 1];
	la[n1 - 1] = ra[n2 - 1] = INT_MAX;
	i = j = 0;
	for(k=p;k<r+1;k++){
		if(la[i]<=ra[j]){
		    a[k] = la[i];
		    i++;
		}
		else{ 
		    a[k] = ra[j];
		    j++;
		}
	}
}

int main(){
	int data,i=0;
//	for(i=0;i<9;i++){
//		cin>>arr[i];
//	}
	while(cin>>data)
	    arr[i++] = data;
	merge_sort(arr,0,i-1);
	for(int j=0;j<i;j++)
	    cout<<arr[j]<<" ";
	cout<<endl;
	
	return 0;
}
