#include<stdio.h>
#include<iostream>
#include<stack>

#define inf 99999999
#define NULL_VALUE -999999
#define debug cout<< "Here I'm!"<<endl;
#define readFile freopen("in.txt","r",stdin);


//Implementation for directed graph

using namespace std;

stack <int>path;

/**void dfs(int **graph,int n,int *dist,int *parent,int *visit,int source){

    if(visit[source]==1) return;

    for(int i=1;i<=n;i++){
        if(graph[source][i]!=inf and parent[i]==-1){
            parent[i]=source;
            dist[i]=dist[source] +1;
            dfs(graph,n,dist,parent,visit,i);
        }
    }

    visit[source]=1;

}*/

void dfs(int **graph,int n,int *dist,int *parent,int *visit,int source){

    if(visit[source]==1) return;

    for(int i=1;i<=n;i++){
        if(graph[source][i]!=inf && (dist[source] +1 <dist[i]) ){
            //visit[i]=2;
            parent[i]=source;
            dist[i]=dist[source] +1;
            dfs(graph,n,dist,parent,visit,i);
        }
    }

    visit[source]=1;

}

/*void dfs(int source,int *visit,int dest,int n,int **graph){
    path.push(source);
    visit[source]=1;

    if(source==dest){
            stack<int> tmp=path;
        while(!tmp.empty()){
            cout<<tmp.top()<< " ";
            tmp.pop();
       }
        return;
    }
    for(int i=1;i<=n;i++){
        if(graph[source][i]!=inf and visit[i]==0 ){
            dfs(i,visit,dest,n,graph);
        }
    }

    visit[source]=0;
    path.pop();
}*/

int main(){

    readFile

    int n,m,u,v,source,d;
    cin>>n>>m;

    int **graph,*parent,*visit,*dist;

    graph=new int*[n +1];
    parent=new int[n +1];
    visit=new int[n +1];
    dist=new int[n +1];

    for(int i=0;i<=n;i++){
        parent[i]=-1;
        visit[i]=0;
        dist[i]=inf;
        graph[i]=new int[n +1];
        for(int j=0;j<=n;j++) graph[i][j]=inf;
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<graph[i][j]<< " ";
        cout<<endl;
    }*/



    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u][v]=1;
        //graph[v][u]=1;
    }

    cin>>source>>d;
    parent[source]=0;
    dist[source]=0;

    //dfs(source,visit,d,n,graph);
    dfs(graph,n,dist,parent,visit,source);

    cout<< "Graph: ";

    for(int i=1;i<=n;i++) cout<<i<< " "<<parent[i]<< " "<<dist[i]<< endl;


    return 0;
}
