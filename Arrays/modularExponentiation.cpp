//Day3
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int nn = n;
    long xx = x;
    long ans = 1;
    if(nn<0) nn = -1*nn;
    while(nn){
        if(nn%2){
            ans = ((ans%m)*(xx%m))%m;
            nn=nn-1;
        }else{
            xx=((xx%m)*(xx%m))%m;
            nn=nn/2;
        }
    }
    if (n < 0) ans = 1 / ans;
    return (int)ans%m;
}