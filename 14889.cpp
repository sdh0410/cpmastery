#include <iostream>
#include <vector>
using namespace std;
int n;
int value[100][100];
//idx: 내가 지금 결정해야 하는 사람의 인덱스
//left: 스타트팀에 들어간 사람들
//right: 링크팀에 드어간 사람들

//1.정답 idx==n 이 상태에서 판별한다!
//두 팀의 인원이 같은지 확인
//team(idx,left+'idx',right+'idx')

int team(int idx,vector<int> &left,vector<int> &right){
    if(idx==n){
        if(left.size()!=n/2) return -1;
        if(right.size()!=n/2) return -1;
        int left_y=0;
        int right_y=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                if(i==j) continue;
                left_y+=value[left[i]][left[j]];
                right_y+=value[right[i]][right[j]];
            }
        }
        int diff=left_y-right_y;
        if(diff<0) diff*=-1;
        return diff;
    }
    int ans=-1;
    left.push_back(idx);
    int lv=team(idx+1,left,right);
    if(ans==-1||(lv!=-1&&ans>lv))
        ans=lv;
    left.pop_back();
    right.push_back(idx);
    int rv=team(idx+1,left,right);
    if(ans==-1||(rv!=-1&&ans>rv))
        ans=rv;
    right.pop_back();
    return ans;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>value[i][j];
    vector<int> l;
    vector<int> r;
    cout<<team(0,l,r);
}
