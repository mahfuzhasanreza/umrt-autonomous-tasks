#include<bits/stdc++.h>
using namespace std;

double totalDis=0;
double minDis=0;
double tempMinDis=0;
double minLat1=0, minLon1=0, minLat2=0, minLon2=0;

void minDisCal(double lat1, double lon1, double lat2, double lon2, double distance){
    if(!tempMinDis){
        tempMinDis=1;
        minDis=distance;
        minLat1=lat1;
        minLon1=lon1;
        minLat2=lat2;
        minLon2=lon2;
        return;
    }

    if(minDis>distance){
        minDis=distance;
        minLat1=lat1;
        minLon1=lon1;
        minLat2=lat2;
        minLon2=lon2;
    }
}

double disCal(double lat1, double lon1, double lat2, double lon2) {
    double distance=acos(sin(lat1*(M_PI/180.0))*sin(lat2*(M_PI/180.0))+cos(lat1*(M_PI/180.0))*cos(lat2*(M_PI/180.0))*cos(lon2*(M_PI/180.0)-lon1*(M_PI/180.0)))*6371;
    distance*=1000;
    totalDis+=distance;

    minDisCal(lat1, lon1, lat2, lon2, distance);

    return distance;
}

int main(){
    int n;
    cin>>n;

    double lat2, lon2;
    if(n>0) cin>>lat2>>lon2;
    for(int i=0; i<n-1; i++){
        double lat1=lat2, lon1=lon2;
        cin>>lat2>>lon2;
        cout<<fixed<<setprecision(8)<<"Point "<<i+1<<": ("<<lat1<<", "<<lon1<<")"<<endl;
        cout<<fixed<<setprecision(8)<<"Point "<<i+2<<": ("<<lat2<<", "<<lon2<<")"<<endl;
    
        double distance = disCal(lat1, lon1, lat2, lon2);
        
        cout<<"Distance between point "<<i+1<<" and "<<i+2<<": "<<distance<<" meter"<<endl;
    }

    cout<<endl<<"Total distance among all points: "<<totalDis<<" meter"<<endl;
    cout<<"Minimum ditsance among all points: "<<minDis<<" meter"<<endl;
    cout<<endl<<"Minimum distance point 1 (latitude, longitude): ("<<minLat1<<", "<<minLon1<<")"<<endl;
    cout<<"Minimum distance point 2 (latitude, longitude): ("<<minLat2<<", "<<minLon2<<")"<<endl;

    return 0;
}