#include <bits/stdc++.h>
using namespace std;

//idx 현재 부등호를 비교할 자리
//arr 모든 경우의 수를 넣음 (10팩토리알)
// 만약 idx가 최대크기+1면, 부등호 비교 -> 부등호가 다 참이면 result 배열에 추가
//모든 재귀가  끝나고 최댓값 최솟값 구하기
int n=0;
vector<string> ans;
int checker[10];
int a[10];
bool good(char x,char y,char op){
    if(op=='<')
        if(x>y) return false;
    if(op=='>')
        if(x<y) return false;
    
    return true;
}

void recu(int idx,string num){
    if(idx==n+1){
        ans.push_back(num);
        return;
    }
    for(int i=0;i<=9;i++){
        if(checker[i]) continue;
        if(idx==0||good(num[idx-1],i+'0',a[idx-1])){
            checker[i]=1;//풀기전에 재귀를 하기 때문에 아예 끝나고 돌아올때까지 책커가 풀리지 않는다.
            recu(idx+1,num+to_string(i));
            checker[i]=0;
        }
    }

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string num;
    recu(0,num);
    int mi=0,ni=0;
    for(int i=0;i<ans.size();i++){
        if(stoi(ans[i])>stoi(ans[mi]))
            mi=i;
        if(stoi(ans[i])<stoi(ans[ni]))
            ni=i;
    }
    cout<<ans[mi]<<endl<<ans[ni];
}