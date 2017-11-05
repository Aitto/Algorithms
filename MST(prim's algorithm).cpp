#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<cstring>

#define lli long long int
#define pf printf
#define sf scanf
#define pi 3.141592653589793116
#define INF 99999
#define maxInt 99999999
#define maxNEG -99999999.0
#define debug cout<<"Hello here!"<<endl;
#define readFile freopen("in.txt","r",stdin);

using namespace std;

class Element{
public:
    int data;
    int key;

    Element(int a=0,int b=INF){
        data=a;
        key=b;
    }

};

class MinHeap{
    Element *arr;
    int length;
    int nVertices;
    int *mapping; //Keeping track of data for O(1) access;

public:

    MinHeap(int n){
        nVertices=n;
        length=0;
        arr=new Element[nVertices];
        mapping =new int[10000];
    }

    void Update(int d,int k){
        int index=mapping[d];
        if(index==0) return;

        if(arr[index].key >k ){
            arr[index].key=k;
            buHeapify(index);
        }else{
            arr[index].key=k;
            Heapify(index);
        }
    }

    void add(int d,int k){
        if(length > nVertices) return;
        length++;
        arr[length].data=d;
        arr[length].key=k;

        buHeapify(length);
    }

    //top to bottom
    void Heapify(int n){
        int parent=n;
        int left;
        int right;
        int smallest;

        while(1){

            left=parent*2;
            right=left +1;
            if(left> length) return; //We are done. We are at the bottom
            if(right>length) smallest=left;
            else if( arr[left].key < arr[right].key ) smallest=left;
            else smallest=right;


            if( arr[parent].key <= arr[smallest].key ) break; //we are done heapifying
            Element temp;


            temp=arr[parent];
            arr[parent]=arr[smallest];
            arr[smallest]=temp;

            mapping[ arr[smallest].data ]=smallest;
            mapping[ arr[parent].data ]=parent;

            parent=smallest;

        }

    }

    //From bottom to top
    void buHeapify(int n){
        int child=n;
        int parent=child/2;

        while(parent){

            if( arr[parent].key < arr[child].key ) return; //We are done

            Element temp;
            temp=arr[parent];
            arr[parent]=arr[child];
            arr[child]=temp;

            mapping[ arr[parent].data ]=parent;
            mapping[ arr[child].data ]=child;

            child=parent;
            parent=child/2;
        }

    }

    void printHeap(){
        cout<< "printing********"<<endl;
        for(int i=1;i<=length;i++) pf("%d %d\n",arr[i].data,arr[i].key);
        cout<< "Complete*********"<<endl;
    }

    int getMin(){
        if(length==0) return -1;
        return arr[1].data;
    }

    int removeMin(){
        if(length==0) return -1;
        Element temp;
        temp=arr[1];
        arr[1]=arr[length];
        length--;
        Heapify(1);
        return temp.data;
    }

    bool isEmpty(){
        if(length==0) return true;
        return false;
    }

};

int main(){

    cout<< "Initialized for vertex 1\nVertex limit 10,000"<<endl;
    readFile

    int **arr,*p,*v,s,*d,n;
    cin>>n;
    MinHeap mh(100);
    arr=new int*[n +1];
    p=new int[n +1];
    v=new int[n +1];
    d=new int[n +1];

    for(int i=0;i<=n;i++) {
        arr[i]=new int[n+1];
        p[i]=-1;
        v[i]=0;
        d[i]=INF;
    }

    for(int i=1;i<=n;i++){
        //mh.add(i,INF);
        for(int j=1;j<=n;j++)
            cin>>arr[i][j];
    }

    cout<< "Source? :"<<endl;
    cin>>s;
    p[s]=0;
    d[s]=0;

    mh.add(s,0);

    while(!mh.isEmpty()){
        s=mh.removeMin();

        if(v[s]==1) continue;

        for(int i=1;i<=n;i++) {
            if( arr[i][s]!=0 and ( arr[i][s] < d[i] ) and v[i]==0 ){
                p[i]=s;
                mh.add(i,arr[i][s]);
                d[i]=d[s] + arr[i][s];
            }
        }

        v[s]=1;
    }

    for(int i=1;i<=n;i++) pf("%d %d\n",i,p[i]);


    return 0;
}

/**
1 9 9
1 7 4

*/
