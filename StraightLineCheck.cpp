#include <bits/stdc++.h>

using namespace std;

double FindSlope(vector<int> a, vector<int> b){
    double slope= (b[1]-a[1]);
    slope /= (b[0]-a[0]);
    cout<<slope<<"**";
    return slope;
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n=coordinates.size();
    if(n==2){return true;}
    double slope = FindSlope(coordinates[1], coordinates[0]);
    cout<<slope<<"--"<<endl;
    for(int i=2; i<n; i++){
        double temp = FindSlope(coordinates[i], coordinates[0]);
        cout<<temp<<"\n";
        if(temp != slope){return false;}
    }
    return true;
}

int main(){
    //{{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}
    vector<vector<int> > v;
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    cout<<checkStraightLine(v);

}