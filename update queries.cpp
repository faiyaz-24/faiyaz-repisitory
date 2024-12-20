#include<iostream>
#include<vector>
using namespace std;
void self_merge(vector<int> &vec,int l,int mid,int h){
  int n1=(mid-l)+1;
  int n2=h-mid;
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
void merge_sort_int(vector<int> &vec,int l,int h){
 if(l<h){
    int mid=(l+h)/2;
    merge_sort_int(vec,l,mid);
    merge_sort_int(vec,mid+1,h);
    self_merge(vec,l,mid,h);
 }
}
void self_merge_char(vector<char> &vec,int l,int mid,int h){
  int n1=(mid-l)+1;
  int n2=h-mid;
  vector<char> arr1;
  vector<char> arr2;
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
void merge_sort_char(vector<char> &vec,int l,int h){
 if(l<h){
    int mid=(l+h)/2;
    merge_sort_char(vec,l,mid);
    merge_sort_char(vec,mid+1,h);
    self_merge_char(vec,l,mid,h);
 }
}
int main(){
 int t;
 cin >> t;
 for(int f=0;f<t;f++){
    int n,m;
    cin >> n >> m;
    cin.ignore(INT_MAX,'\n');
    vector<char> s1;
    vector<char> s2;
    vector<int> l;
    for(int i=0;i<n;i++){
        char a;
        cin >> a;
        s1.push_back(a);
    }
    cin.ignore(INT_MAX,'\n');
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        l.push_back(a);
    }
    cin.ignore(INT_MAX,'\n');
    for(int i=0;i<m;i++){
        char a;
        cin >> a;
        s2.push_back(a);
    }
    merge_sort_int(l,0,m-1);
    merge_sort_char(s2,0,m-1);
    int repetence=0,save=0,j=0;
    for(int i=0;i<m;i++){
      if(save!=l[i]){
        s1[l[i]-1]=s2[j];
        j++;
      }
      save=l[i];
    }
    for(int i=0;i<n;i++){
        cout << s1[i];
    }
    cout << endl;

 }



return 0;
}
