    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
     
    set<ll> level[200005];
    bool vis[200005];
    ll max_depth;
    vector<int> tree[200005];
    ll A[200005];
     
    void dfs(int x, ll depth)
    {
        //mark the vertes as visited
        vis[x] = true;
        
        //insert the present vertex in the present depth
        level[depth].insert(A[x]);
        
        //find the maximum depth
        if(depth > max_depth)
            max_depth = depth;
            
        //traverse on every edge connected to x
        for(int i = 0; i < tree[x].size(); i++)
        {
            //if the vexter is not already visited
            if(vis[ tree[x][i] ] == false)
            {
                //recursively call the dfs and increment the depth by 1
                dfs( tree[x][i] , depth+1 );
            }
        }
    }
    int main() {
     
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        ll N, Q;
        
        //input no of vertices and no of queries
        cin >> N >> Q;
        
        //input the value of every vertex
        for(int i = 1; i <= N; i++)
            cin >> A[i];
            
        //input the edges in the tree
        for(int i = 0; i < N-1; i++)
        {
            int x,y;
            
            cin >> x >> y;
            
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        
        max_depth = 0;
        memset(vis,false,sizeof(vis));
        
        //dfs to find the level of every vertex
        dfs(1,0);
        
        //use mod as max_depth + 1
        ll mod = max_depth + 1;
        while(Q--)
        {
            ll L,X;
            
            //input L and X according to the question
            cin >> L >> X;
            
            //find the actual level
            L = L%mod;
            
            //find the next greter or equal value than X in the level L
            auto it = level[L].lower_bound(X);
            
            //if there is no greater or equal value than X in level L
            if(it == level[L].end())
                cout << "-1\n";
            //if there is some value greater than or equal than X in level L
            else
                cout << *it << "\n";
        }
    }
     
    // complexity: O(Q * log(no_of_vextex_in_level_L))

