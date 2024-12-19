#include<iostream>
#include<vector>
using namespace std;
int main(){
 int t;
 cin >> t;

 for(int f=0;f<t;f++){
   int n;
   cin >> n;
   vector<int> count_char;
   count_char.push_back(0);
   count_char.push_back(0);
   vector<char> bracket_series;
   cin.ignore(INT_MAX,'\n');
   for(int i=0;i<n;i++){
     char a;
     cin >> a;
     bracket_series.push_back(a);
     if(a!='_'){count_char[a-'(']++;}  //0 is ( and 1 is )
   }
   bracket_series[0]='(';
   count_char[0]=n/2-count_char[0]-1;
   count_char[1]=n/2-count_char[1];
   for(int j=n-2;count_char[0]>0 || count_char[1]>0;j-=2){
     if(bracket_series[j-1]==')'){
        bracket_series[j]='(';
        count_char[0]--;
     }
     else{
        bracket_series[j]=')';
        count_char[1]--;
     }
   }
   long long open=0,distance_bracket=0;
   for(int i=0;i<n;i++){
     if(bracket_series[i]=='('){
        open++;
     }
     else{
        open--;
     }
     distance_bracket=distance_bracket+open;
   }
   cout << distance_bracket << endl;

 }



return 0;
}
