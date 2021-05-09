/*
    Activity selection problem;
*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
        int max_activity(pair < int , int > pr[] , int n);

        
};

bool comp(const pair < int , int > &a , const pair < int , int > &b){
    return a.second <= b.second;
}

int main(){

    int n;
    cout<<"Enter number of activities: ";
    cin>>n;

    pair < int , int > pr[n];
    cout<<"Enter activities starting and ending time: ";
    
    for(int i = 0 ; i < n ; ++i){
        cin>>pr[i].first>>pr[i].second;
    }

    Solution sl;

    cout<<"Max activity that can be done are "<<sl.max_activity(pr , n);

    return 0;
}


// First sort in increasing order of end time

int Solution::max_activity( pair < int , int > pr[] , int n){

    if(n == 0){
        return 0;
    }

    sort( pr , pr + n , comp );

    // initialize first element as solution
    int mx = 1, endt = pr[0].second;

    for(int i = 1 ; i < n ; ++i){

        // check whether current element overlaps the previous element , if not then add it to solution else not
        if(pr[i].first >= endt){
            ++mx;
            endt = pr[i].second;
        }

    }
    
    return mx;

}

