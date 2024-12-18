#include<stdio.h>
void merge(int arr[],int l,int mid,int h){
  int s_l=mid-l+1;
  int s_h=h-mid;
  int l_arr[s_l],h_arr[s_h];
  for(int i=0;i<s_l;i++){
    l_arr[i]=arr[l+i];
  }
  for(int i=0;i<s_h;i++){
    h_arr[i]=arr[mid+1+i];
  }
  int p1=0,p2=0,p_ans=l;
  while(p1<s_l && p2<s_h){
    if(l_arr[p1]<h_arr[p2]){
        arr[p_ans++]=l_arr[p1++];
    }
    else{
        arr[p_ans++]=h_arr[p2++];
    }
  }
  for(;p1<s_l;p1++){
    arr[p_ans++]=l_arr[p1];
  }
  for(;p2<s_h;p2++){
    arr[p_ans++]=h_arr[p2];
  }

}

void merge_sort(int arr[],int l,int h){
  int mid;
  if(l<h){
    mid=(l+h)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,h);
    merge(arr,l,mid,h);
  }
}
int main(){
 int n;
 scanf("%d",&n);
 int arr[n];
 for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
 }
 merge_sort(arr,0,n-1);
 int day=0;
 int j=n;
 for(int i=n-1;j>0;j--){
    if(j<=arr[i]){
      day++;
      i--;
    }
 }
 printf("%d\n",day);

return 0;
}

