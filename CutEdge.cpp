#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <functional>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <stdlib.h>
#include <time.h>

#define INF 999999999
#define INFLL 999999999999999

#define s1(x) scanf("%d", &x)
#define s2(x,y) scanf("%d %d",&x,&y)
#define s3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define p1(x) printf("%d\n", x)
#define p2(x,y) printf("%d %d\n",x,y)
#define p3(x,y,z) printf("%d %d %d\n",x,y,z)
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> intii;
typedef pair<ii, ii> pii;
typedef tuple<int, int, int> iii;

/////////////////////////////////////////////////////



/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

vector<int> edge[100005];
vector<int> visited(100005, -1);
set<ii> cutedge;

int v,e,cnt;

int dfs(int curr, int prev){
    int rlt = visited[curr]=cnt++;
    
    for(int next : edge[curr]){
        if(next==prev) continue;
        if(visited[next]==-1) {
            int vis = dfs(next,curr);
            rlt=min(rlt, vis);
            if(vis > visited[curr]) cutedge.insert(ii(min(curr, next), max(curr,next)));
        }
        else rlt = min(rlt, visited[next]);
    }
    
    return rlt;
}


int main(){
    s2(v,e);
    while(e--){
        int a,b; s2(a,b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    for(int i=1;i<=v;i++)
        if(visited[i]==-1) dfs(i,0);
  
    printf("%lu\n", cutedge.size());
    for(ii a : cutedge) printf("%d %d\n", a.first, a.second);

    return 0;
}






























