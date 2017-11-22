#include<stdio.h>
#include<iostream>

#define inf 99999999
#define NULL_VALUE -999999
#define debug cout<< "Here I'm!"<<endl;
#define readFile freopen("in.txt","r",stdin);

//BFS works on unweighted graph only. Finds shortest path.

using namespace std;

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}


void initialize(int *a,int n,int val){
    for(int i=0;i<n;i++) a[i]=val;
}

void bfs(int **arr,int n,int *p,int *d,int *visit,int source){
    Queue que;
    int cur;

    //initialize(p,n+1,-1);
    //initialize(d,n+1,inf);
    //initialize(visit,n+1,0);

    que.enqueue(source);
    while(!que.empty()){
        cur=que.dequeue();

        for(int i=1;i<=n;i++){
            if(visit[i]==1) continue;
            if(arr[cur][i]!=inf and p[i]==-1){
                que.enqueue(i);
                p[i]=cur;
                d[i]=d[cur] +1;
            }
        }

        visit[cur]=1;
    }

}

int main(){

    readFile
    int n,m,u,v,source;
    cin>>n>>m;

    int **graph,*p,*d,*visit;

    //1 Indexing
    graph=new int*[n+1];
    p=new int[n +1];
    d=new int[n +1];
    visit=new int[n +1];
    for(int i=0;i<=n;i++) graph[i]=new int[n +1];

    //Initializing graph
    for(int i=0;i<=n;i++){
        p[i]=-1;
        d[i]=inf;
        visit[i]=0;
        for(int j=0;j<=n;j++) graph[i][j]=inf;
    }

    //Taking input
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        graph[u][v]=1;
        //graph[v][u]=1;
    }

    cin>>source;
    d[source]=0;
    p[source]=0;

    bfs(graph,n,p,d,visit,source);

    cout<< "Graph: ";

    for(int i=1;i<=n;i++) cout<<i<< " "<<p[i]<< " "<<d[i]<< endl;

    return 0;
}
