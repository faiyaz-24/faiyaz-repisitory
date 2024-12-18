#include<iostream>
#include<vector>
using namespace std;
int main(){
 int t;
 cin >> t;
 for(int f=0;f<t;f++){
    int m,day_sum=0;
    cin >> m;
    vector<int> day;
    vector<int> participent;
    for(int g=0;g<m;g++){
      int c;
      cin >> c;
      day_sum=day_sum+c;
      day.push_back(c);
      for(int h=0;h<day[g];h++){
        int d;
        cin >> d;
        participent.push_back(d);
      }
    }
    vector<int> winner;
    int participent_size=participent.size();
    winner.push_back(participent[day_sum-1]);
     day_sum--;
     int p1,p2,p2_end,p2_const;
     for(int i=m-1;i>0;i--){
        day_sum=day_sum-day[i];
        p2=day_sum;
        p2_const=p2;
        p2_end=p2-day[i-1];
        for(;p2>p2_end;p2--){
            p1=p2_const+1;
            int bulb=1;
           for(;p1<participent_size;p1++){
                if(participent[p1]==participent[p2]){
                    bulb=0;
                    break;
                }
           }
           if(bulb){
             winner.push_back(participent[p2]);
             break;
           }

        }
     }
     int winner_size=winner.size();
     if(winner_size<m){cout << "-1";}
     else{
        for(int i=winner_size-1;i>=0;i--){
            cout << winner[i] << " ";
        }

      }
     cout << endl;
 }

return 0;
}
