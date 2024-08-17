#include <bits/stdc++.h>

using namespace std;

int k;
char op[10];
int check[10];
vector<int> pick;
vector<string> ans;

bool good(int x, int y, char z)
{
    if(z=='>'&&x<y)
        return false;
    if(z=='<'&&x>y)
        return false;
   return true;

}
void dfs(int cnt)
{
    if(cnt==k+1){
        string res="";
        for(int i=0;i<pick.size();i++){
            res=res+to_string(pick[i]);
        }
        ans.push_back(res);
        return;
    }
    for(int i=0;i<10;i++){
        if(check[i]==0){
            if(cnt==0||good(pick[cnt-1],i,op[cnt-1])){
                check[i]=1;
                pick.push_back(i);
                dfs(cnt+1);
                pick.pop_back();
                check[i]=0;
            }

        }
    }


}


int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>op[i];
    }
    dfs(0);

    cout<<ans[ans.size()-1]<<'\n'<<ans[0];

    return 0;
}
