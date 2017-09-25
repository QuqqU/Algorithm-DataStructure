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
typedef tuple<int, int, int> iii;

/////////////////////////////////////////////////////

const int maxn = 5;



/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

int n,m,cnt, start, sn, s[500005];
vector<int> visited(500005, -1);
vector<int> finished(500005, false);
stack<int> st;
vector<int> edge[500005];
vector<vector<int>> scc;
int cash[500005];
bool rest[500005];

int sstart;
int scash[500005];
vector<int> sedge[500005];
int sindegree[500005];
bool srest[500005];
int dist[500005];

int dfs(int curr){
    int rlt = visited[curr]=cnt++;
    st.push(curr);
    
    for(int next : edge[curr]){
        if(visited[next]==-1) rlt=min(rlt, dfs(next));
        else if(!finished[next]) rlt=min(rlt,visited[next]);
    }
    
    if(visited[curr]==rlt){
        vector<int> currscc;
        
        while(1){
            int a=st.top();
            st.pop();
            currscc.push_back(a);
            s[a]=sn;
            finished[a]=true;
            if(a==curr) break;
        }
        sn++;
        scc.push_back(currscc);
    }
    
    return rlt;
}
void ipf(){
    s2(n,m);
    f0(i,m) {
        int a,b; s2(a,b);
        edge[a].push_back(b);
    }
    f1(i,n) s1(cash[i]);
    int p; s2(start,p);
    f0(i,p){
        int a; s1(a);
        rest[a]=true;
    }
}
void getscc() {
    f1(i,n)
        if(visited[i]==-1) dfs(i);
}
void set_I_to_SI(){
    f1(i,n){
        int si=s[i];
        scash[si]+=cash[i];
        
        if(rest[i]) srest[si]=true;
        if(i==start) sstart=si;
        
        for(int j : edge[i]){
            int sj = s[j];
            if(si==sj) continue;
            
            sedge[si].push_back(sj);
            sindegree[sj]++;
        }
    }
}
void scc_dijkstra(){
    priority_queue<ii> pq;
    dist[sstart]=scash[sstart];
    pq.push(ii(dist[sstart], sstart));
    
    while(!pq.empty()){
        int curr = pq.top().second;
        int currdist = pq.top().first;
        pq.pop();
        if(dist[curr]>currdist) continue;
        for(int next : sedge[curr]){
            int nextdist = dist[curr] + scash[next];
            if(dist[next] < nextdist){
                dist[next] = nextdist;
                pq.push(ii(dist[next], next));
            }
        }
    }
}
void opf(){
    int ans=0;
    f0(i,sn)
        if(srest[i]) ans=max(ans, dist[i]);
    p1(ans);
}


int main(int argc, const char * argv[]) {
    ipf();
    getscc();
    set_I_to_SI();
    scc_dijkstra();
    opf();
    return 0;
}











