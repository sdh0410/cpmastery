#include <iostream>
#include <vector>
using namespace std;
int n;
int value[100][100];
//idx: 내가 지금 결정해야 하는 사람의 인덱스
//left: 스타트팀에 들어간 사람들
//right: 링크팀에 들어간 사람들

//1.정답 idx==n 이 상태에서 판별한다!
//두 팀의 인원이 같은지 확인
//team(idx,left+'idx',right+'idx')

int team(int idx,vector<int> &left,vector<int> &right){
    if(idx==n){ //사람들을 다 넣었나?
        if(left.size()!=n/2) return -1;//------\|/
        if(right.size()!=n/2) return -1; //------------>양팀의 선수의 수가 불균형이면 나가라
        int left_y=0;
        int right_y=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                if(i==j) continue;
                left_y+=value[left[i]][left[j]];
                right_y+=value[right[i]][right[j]];
            }
        }//양팀의 총 실력 구하기
        int diff=left_y-right_y;//양팀의 실력 차
        if(diff<0) diff*=-1;//절댓값
        return diff;//차이를 반환
    }
    int ans=-1;
    left.push_back(idx);//왼쪽팀에 현제선수 집어넣기
    int lv=team(idx+1,left,right);//재귀
    if(ans==-1||(lv!=-1&&ans>lv))
        ans=lv;
    left.pop_back();//현재선수 왼쪽에서 빼기
    right.push_back(idx);//다지 오른쪽에 집어넣게
    int rv=team(idx+1,left,right);//재귀
    if(ans==-1||(rv!=-1&&ans>rv))
        ans=rv;
    right.pop_back();//빼기
    return ans;
}
//8명기준 1 2 3 4 5 6 7 8
//왼왼왼왼 1234
//왼왼왼오 1235
//왼왼오왼 1254
//왼왼오오 1256
//왼오왼왼 1534
//왼오오왼 1564
//왼오오오 1567
//오왼왼왼 5234
//오오왼왼 5634
//오오오왼 5674
//오오오오 5678 

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
