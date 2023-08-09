#include <bits/stdc++.h>

using namespace std;

#define pi (3.14159)
#define sq(a) a*a
#define debug(x) cout<<#x<<' '<<x<<endl;


class DisjointSet {
    vector<int> rank , parent, size;
public:
    DisjointSet(int n){
        //n+1 for 1 based
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)  return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)  return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] +=  size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



int main()
{
    

    return 0;
}