    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
     
    int main() {
     
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        ll N,M;
        
        // input N and M
        cin >> N >> M;
        
        //initialize an empty set
        set<ll> s;
        //initialize the ans as 0
        ll ans = 0;
        
        while(M--){
            
            ll X;
            //input the value to insert in a set
            cin >> X;
            
            //if the value is already present in the set
            if(s.find(X) != s.end())
            {
                //just output the previous ans and continue
                cout << ans << endl;
                continue;
            }
            
            //if set is empty
            if(s.size() == 0)
            {
                ans = ans + 1 + N;
            }
            else
            {
                //find the next greter value than X in a set
                auto it = s.upper_bound(X);
                
                //if there is no greater value than X in a set
                if(it == s.end())
                {
                    ans = ans + *(--it) + X;
                }
                
                //if there is greater value than X but no smaller value in a set
                else if(it == s.begin())
                {
                    ans = ans + *(it) + X;
                }
                
                // if both greater and smaller value than X is present in a set
                else
                {
                    ans = ans + 2*X;
                }
            }
            
            // output the ans
            cout << ans << endl;
            
            //insert the X in the set and continue
            s.insert(X);
        }
    }
