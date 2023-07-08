#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
#define ll long long;
#define mod 1000000007

class DisjointSet{
    vector<int> rank , parent , size;

    public:
      DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i = 0 ; i <= n ; i++) parent[i] = i;
      }

      int findUpar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUpar(parent[node]);
      }

      void unionByRank(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;//belonging to same component
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

      }

      void unionBySize(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }      
      }     

};

int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
     
    DisjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUpar(3) == ds.findUpar(7)){
        cout<<"same";
    }
    else cout<<"Not same";
    cout<<endl;
    ds.unionBySize(3,7);
    if(ds.findUpar(3) == ds.findUpar(7)){
        cout<<"same";
    }
    else cout<<"Not same";    


    return 0;
}