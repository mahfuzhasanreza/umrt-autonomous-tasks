#include<bits/stdc++.h>
using namespace std;

double totalDis=0;
double minDis=0;
double tempMinDis=0;
double minLon1=0, minLat1=0, minLon2=0, minLat2=0;

void minDisCal(double lon1, double lat1, double lon2, double lat2, double distance){
    if(!tempMinDis){
        tempMinDis=1;
        minDis=distance;
        minLon1=lon1;
        minLat1=lat1;
        minLon2=lon2;
        minLat2=lat2;
        return;
    }

    if(minDis>distance){
        minDis=distance;
        minLon1=lon1;
        minLat1=lat1;
        minLon2=lon2;
        minLat2=lat2;
    }
}

double disCal(double lon1, double lat1, double lon2, double lat2) {
    double distance=acos(sin(lat1*(M_PI/180.0))*sin(lat2*(M_PI/180.0))+cos(lat1*(M_PI/180.0))*cos(lat2*(M_PI/180.0))*cos(lon2*(M_PI/180.0)-lon1*(M_PI/180.0)))*6371;
    distance*=1000;
    totalDis+=distance;

    minDisCal(lon1, lat1, lon2, lat2, distance);

    return distance;
}

int main(){
    int n;
    cin>>n;

    double lon2, lat2;
    if(n>0) cin>>lon2>>lat2;
    for(int i=0; i<n-1; i++){
        double lon1=lon2, lat1=lat2;
        cin>>lon2>>lat2;
        cout<<fixed<<setprecision(8)<<"Point "<<i+1<<": ("<<lon1<<", "<<lat1<<")"<<endl;
        cout<<fixed<<setprecision(8)<<"Point "<<i+2<<": ("<<lon2<<", "<<lat2<<")"<<endl;
    
        double distance = disCal(lon1, lat1, lon2, lat2);
        
        cout<<"Distance between point "<<i+1<<" and "<<i+2<<": "<<distance<<" meter"<<endl;
    }

    cout<<endl<<"Total distance among all points: "<<totalDis<<" meter"<<endl;
    cout<<"Minimum ditsance among all points: "<<minDis<<" meter"<<endl;
    cout<<endl<<"Minimum distance point 1 (longitude, latitude): ("<<minLon1<<", "<<minLat1<<")"<<endl;
    cout<<"Minimum distance point 2 (longitude, latitude): ("<<minLon2<<", "<<minLat2<<")"<<endl;

    return 0;
}