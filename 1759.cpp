#include <cstdio>
#include <iostream>
using namespace std;
int l,c;
char ch[15];
void dislock(char str[],int size=0){
    if(size>1&&str[size-2]>=str[size-1])
        return;
    if(size==l){
        int cnt=0;
        for(int i=0;i<l;i++)
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
                cnt++;
        
        if(cnt==0)
            return;
        for(int i=0;i<4;i++)
            printf("%c",str[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<c;i++){
        str[size]=ch[i];
        dislock(str,size+1);
    }

}

int main(){
    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>ch[i];
    }
    int cn=0;
    do{
        cn=0;
        for(int i=0;i<c-1;i++){
            if(ch[i]>ch[i+1]){
                char cup=ch[i];
                ch[i]=ch[i+1];
                ch[i+1]=cup;
            }
        }
    }while(cn!=0);
    
    char c[15];
    dislock(c);

}