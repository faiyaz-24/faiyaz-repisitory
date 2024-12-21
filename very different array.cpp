#include<iostream>
#include<vector>
using namespace std;
void self_merge(vector<int> &vec,int l,int mid,int h){
  int n1=(mid-l)+1;
  int n2=(h-mid);
  vector<int> arr1;
  vector<int> arr2;
  for(int i=0;i<n1;i++){
    arr1.push_back(vec[l+i]);
  }
  for(int i=0;i<n2;i++){
    arr2.push_back(vec[mid+1+i]);
  }
  int p1=0,p2=0,p_ans=l;
  while(p1<n1 && p2<n2){
    if(arr1[p1]<arr2[p2]){
       vec[p_ans++]=arr1[p1++];
    }
    else{
        vec[p_ans++]=arr2[p2++];
    }
  }
   for(;p1<n1;p1++){
      vec[p_ans++]=arr1[p1];
   }
   for(;p2<n2;p2++){
      vec[p_ans++]=arr2[p2];
   }
}
void merge_sort(vector<int> &vec,int l,int h){
  if(l<h){
    int mid=(l+h)/2;
    merge_sort(vec,l,mid);
    merge_sort(vec,mid+1,h);
    self_merge(vec,l,mid,h);
  }
}
int main(){
 int t;
 cin >> t;
 for(int f=0;f<t;f++){
   int n,m;
   cin >> n >> m;
   vector<int> arr1;
   vector<int> arr2;
   for(int i=0;i<n;i++){
    int a;
    cin >> a;
    arr1.push_back(a);
   }
   for(int i=0;i<m;i++){
    int a;
    cin >> a;
    arr2.push_back(a);
   }
   merge_sort(arr1,0,n-1);
   merge_sort(arr2,0,m-1);
   /*int middle=n/2-1;
   int first_p=0,last_p_arr2=m-1,last_p_arr1=n-1;
   long long sum=0;
   for(int i=0;i<=middle;i++){
       sum=sum+abs(arr2[last_p_arr2-i]-arr1[first_p+i]);
       sum=sum+abs(arr1[last_p_arr1-i]-arr2[first_p+i]);
   }
   int extra_add=0,add;
   if(n%2!=0){
      int p_mid=n/2;
      int p1=n/2,p2=m-n/2-1;
      while(p1<=p2){
         add=abs(arr1[p_mid]-arr2[p1]);
        if(extra_add<add){extra_add=add;}
        p1++;
      }
   }
   sum=sum+extra_add;
   cout << sum << endl;*/
   int p1=0,p2=n-1,q1=0,q2=m-1;
   long long sum=0;
   while(p1<=p2){
     int d1=abs(arr1[p1]-arr2[q2]);
     int d2=abs(arr1[p2]-arr2[q1]);
    if(d1>=d2){
        sum=sum+d1;
        p1++;
        q2--;
    }
    else{
        sum=sum+d2;
        p2--;
        q1++;
    }
   }
   cout << sum << endl;

 }
return 0;
}
