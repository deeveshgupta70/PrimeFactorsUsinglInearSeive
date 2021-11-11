#include<bits/stdc++.h>

using namespace std;

vector<int> solve(int);

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        
        vector<int> res = solve(n);
        for( auto i : res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}

vector<int> solve( int n){
    
    vector<int> res(n+1,0);
    for( int i = 0; i < res.size(); i++) res[i] = i;
    
    for( int i = 2 ; i*i <= n; i++){
        
        if( res[i] == i){
            
            for( int j = i*i ; j < res.size() ; j += i) {
                
                if( res[j] == j) res[j] = i;
            }
        }
    }
    
    vector<int> ans;
    int temp = n;
    while( temp != 1){
        
        if( temp == res[n]) ans.push_back(temp);
        
        else ans.push_back(res[temp]);
        
        temp = temp/res[temp];
    }
    
    return ans;
    
}
