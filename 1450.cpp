#include <iostream>
using namespace std;

int n,back;
int cnt=1;
void pack(int it[],int now){
    if(now>back)
        return;
    if(now==back){
        cnt++;
        return;
    }
    if(now<back){
        cnt++;
        for(int i=0;i<n;i++){
            if(it[i]!=0){
                int cup=it[i];
                it[i]=0;
                pack(it,now+=cup);
                it[i]=cup;
            }
        }
    }
}

int main(){
    
    cin>>n>>back;
    int it[30];
    for(int i=0;i<n;i++)
        cin>>it[i];
    pack(it,0);
    cout<<cnt;
}