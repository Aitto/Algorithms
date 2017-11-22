#include<stdio.h>
#include<iostream>

using namespace std;

long long int bigMod(long long int n,long long int p,long long int m){
    if(p==0) return 1;
    if(p%2){
        return ((n%m)*bigMod(n,p-1,m))%m;
    }else{
        long long int c=bigMod(n,p/2,m);
        return ((c%m)*(c%m))%m;
    }
}

int main(){

    long long int n,p,m;
    cin>>n>>p>>m;
    cout<<bigMod(n,p,m);

    return 0;
}

/**
a^(x*y)%k means (a^x)^y%k;
so int that case,
p=bigMod(a,x,k);
q=bigMod(p,y,k);

and q is the answer;
*/
