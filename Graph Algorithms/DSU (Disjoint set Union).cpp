/*
Author @Aitto_sang
CSE@Buet
*/
#include<stdio.h>
#include<iostream>
//#include<ctime>
//#include<cmath>
//#//include<cstdlib>
#include<algorithm>
//#include<map>
//#include<stack>
//#include<cstring>
//#include<bits/stdc++.h>

#define lli long long int
#define pf printf
#define sf scanf
#define pi 3.141592653589793116
#define inf 1e9
#define linf 1e18
#define NULL_VALUE -999999
#define maxNEG -inf
#define debug cout<<"Hello here!"<<endl;
#define readFile freopen("in.txt","r",stdin);
#define syncronize ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define red 1
#define black 2
#define doubleBlack 3
#define nullNode -176539

using namespace std;

struct nodes{
    int data;
    int parent;
    int rank;
};

class Tree{
private:
    nodes *node;
    int elements;

public:

    Tree(int n=8){
        elements=8;
        node=new nodes[elements];
    }

    void makePair(int x=-1){
        if(x==-1){
            for(int i=0;i<elements;i++){
                node[i].data=i;
                node[i].parent=i;
                node[i].rank=0;
            }
        }else{
            node[x].data=x;
            node[x].parent=x;
            node[x].rank=0;
        }
    }

    int findParent(int x){
        if(node[x].parent==x) return x;
        return node[x].parent=findParent(node[x].parent);
    }

    void makeUnion(int a,int b){
        int x=findParent(a);
        int y=findParent(b);

        if(node[x].rank==node[y].rank){
            node[x].parent=y;
        }else{
            if(node[x].rank<node[y].rank){
                node[x].parent=y;
                if(node[y].rank!=0){
                    node[x].rank++;
                }
            }else{
                node[y].parent=x;
                if(node[x].rank!=0){
                    node[y].rank++;
                }
            }
        }
    }

};

int main(){
    int n,x;

    cin>>n;
    Tree tree(n);
    while(1){
        cout<< "1. make Pair 2.make union, 3.find Set 4.Exit"<<endl;
        cin>>x;

        if(x==1){
            tree.makePair();
        }else if(x==2){
            cin>>x>>n;
            tree.makeUnion(x,n);
        }else if(x==3){
            cin>>x;
            cout<<tree.findParent(x)<<endl;
        }else break;
    }

    return 0;
}
