/** Longest common subsequence problem is a dynamic problem. With this algo we solve the longest common sub-sequence of two given arrays.
    Examples:
    LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
    LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

    In this problem, the longest common subsequence for two char arrays a & b (length are m and n) will be:
    if a(m)=b(n) then 1+ lcs(a,b,m-1,n-1)
    else if a(m) and b(n) doesn't match then max of lcs(a,b,m-1,n) or lcs(a,b,m,n-1)

    means:
    Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of
    LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).
    If last characters of both sequences match (or X[m-1] == Y[n-1]) then
    L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])
    If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
    L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2])

    We solve this using another technique:(example 1)
        A E D F H R
      0 0 0 0 0 0 0
    A 0 1 1 1 1 1 1
    B 0 1 1 1 1 1 1
    C 0 1 1 1 1 1 1
    D 0 1 1 2 2 2 2
    G 0 1 1 2 2 2 2
    H 0 1 1 2 2 3(3)<- answer

    The this here is, we write 1st string in left side and 2nd string on upside. Now we take a matrix of size n+1 * m+1
    and make 1st whole row and 1st whole column equal to zero. Then match one char by another char. If two char chars matches then
    we put number in the diagonal +1. Else, if doesn't match we put max of one box updide, and one box left side, means max(A[i][j-1],A[i-1][j])
    And the answer will be A[m][n]

    web:http://www.geeksforgeeks.org/longest-common-subsequence/
*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

int max(int a,int b){
    return a>b ? a:b;
}

int lcs(char *str1,char *str2,int m,int n){
    if(m==0|| n==0) return 0;
    if(str1[m-1]==str2[n-1]) return 1+ lcs(str1,str2,m-1,n-1);
    else return max(lcs(str1,str2,m-1,n),lcs(str1,str2,m,n-1));
}

int lcsdp(char *str1,char *str2,int s1,int s2){
    int arr[s1+1][s2+1];
    for(int i=0;i<=s1;i++)
        for(int j=0;j<=s2;j++)
        arr[i][j]=0;

    for(int i=1;i<=s1;i++)
        for(int j=1;j<=s2;j++){
            if(str1[i-1]==str2[j-1]) arr[i][j]=arr[i-1][j-1] +1;
            else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }

    return arr[s1][s2];
}

int main(){

    char st1[100],st2[100];

    cin>>st1>>st2;

    cout<<lcsdp(st1,st2,strlen(st1),strlen(st2));


    return 0;
}
