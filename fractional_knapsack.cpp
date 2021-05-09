/*
    Fractional knapsack;
*/

#include<iostream>
#include<algorithm>
using namespace std;

class item{
    public:
        int weight , value;
};

class Solution{
    public:
        double fknapsack(item it[] , int n , int k);
};

bool comp(const item &a , const item &b){
    double a1 , b1;
    
    a1 = double(a.value)/a.weight;
    
    b1 = double(b.value)/b.weight;
    
    return a1 >= b1;
}

int main(){

    int n;
    cout<<"Enter no of items: ";
    cin>>n;

    item it[n];
    cout<<"Enter weight and value: ";

    for(int i = 0 ; i < n ; ++i){
        cin>>it[i].weight>>it[i].value;
    }

    int k;
    cout<<"Enter knapsack weight: ";
    cin>>k;

    Solution sl;

    double ans = sl.fknapsack(it , n , k);

    cout<<"Max value is "<<ans;



    return 0;
}

double Solution::fknapsack(item arr[] , int n , int k){

     sort(arr ,arr+n , comp);
        
        int i = 0;
        double ans = 0;
        while( i < n && k > 0){
            
            if( arr[i].weight <= k){
                
                ans += arr[i].value;
                
                k -= arr[i].weight;
                
            }
            else{
                
                ans += (double(k)*arr[i].value)/arr[i].weight;
                
                k = 0 ;
                
            }
            
            ++i;
            
        }
        
        return ans;
        

}