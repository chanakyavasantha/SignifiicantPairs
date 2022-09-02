#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
int ans = 0;
void Search(int* b,int start,int end,int k,int j) {
    int middle = (start + end)/ 2;
    if (start <= end) {
        if (b[middle] <= k && m[b[middle]] < j) {
            while(true) {
                if (b[middle + 1] <= k) {
                    middle += 1;
                }
                else{
                    break;
                }
            }
            //for (int i = 0; i <= middle; i++)
                //cout << b[i] << " ";
            ans += middle + 1;
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
    for(int j = 1;j<n;j++){
        int k = a[j]/2;
        //cout<<a[j];
        //cout<<"->";
        Search(b,0,j,k,j);
        //cout<<endl;
    }
    cout<<ans<<endl;
}