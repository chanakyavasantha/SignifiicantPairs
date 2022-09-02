#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
int ans = 0;
void Search(int* b,int start,int end,float k,int j) {
    int middle = (start + end) / 2;
    if (start <= end) {
        if (b[middle] <= k && m[b[middle]] < j) {
            //cout<<b[middle]<<endl;
            ans+= middle+1;
            return;
        }
        else{
            Search(b,start,middle-1,k,j);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    for(int i = 0;i<n;i++){
        m.insert(make_pair(a[i],i));
    }
    for(int j = 0;j<n;j++){
        float k = a[j]/2;
        //cout<<"pairs: "<<endl;
        //cout<<a[j]<<endl;
        Search(b,0,j,k,j);
    }
    cout<<ans<<endl;

}