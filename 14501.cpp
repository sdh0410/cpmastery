#include <cstdio>
using namespace std;

int n=0;
int t[20];
int v[20];
int ans=0;
void recu(int day,int sum){
    if(day==n){
        if(ans<sum) ans=sum;
        return;
    }
    if(day>n) return;

    recu(day+t[day],sum+v[day]);
    recu(day+1,sum);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&t[i],&v[i]);
    recu(0,0);
    printf("%d",ans);
}