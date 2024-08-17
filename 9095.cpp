#include <iostream>
#include <cstdio>

int n,cnt=0;
void all(int a=0){
    if(a>n)
        return;
    else if(a==n){
        cnt++;
        return;
    }
    for(int i=1;i<=3;i++)
        all(a+i);
    
}

int main(){
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&n);
        cnt=0;
        all();
        printf("%d\n",cnt);
    }
}
