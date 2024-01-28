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


















// #include<bits/stdc++.h>
// using namespace std;

// const double earthRadius=6371.0;
// double totalDis=0;

// double disCal(double long1, double lat1, double long2, double lat2) {
//     long1*=(M_PI/180.0);
//     lat1*=(M_PI/180.0);
//     long2*=(M_PI/180.0);
//     lat2*=(M_PI/180.0);

//     //cout<<lat1<<"))))))))))))))))))))))))))))))))";

//     double distance=acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(long2-long1))*6371;
//     distance*=1000;

//     totalDis+=distance;
//     return distance;
// }

// int main(){
//     int n;
//     cin>>n;
//     double longitude[n], latitude[n];


//     for(int i=0; i<n; i++){
//         cin>>longitude[i];
//         cout<<fixed<<setprecision(8)<<longitude[i]<<endl;
//         cin>>latitude[i];
//         cout<<fixed<<setprecision(8)<<latitude[i]<<endl;
//     }

//     for(int i=0; i<n-1; ){
//         //cout<<longitude[i]<<"============="<<endl;
//         double nn=disCal(longitude[i], latitude[i++], longitude[i], latitude[i]);
//         //double nn=disCal(-110.78200000, 38.41900000, -110.78300000, 38.41900000);
//         cout<<nn<<"+++++++++++++"<<endl;
//         //cout<<longitude[i]<<"=="<<i+1<<"=="<<latitude[i]<<endl;
//     }

//     cout<<totalDis<<"==========="<<endl;

//     return 0;
// }










// #include<bits/stdc++.h>
// using namespace std;

// const double earthRadius = 6371.0;

// double toRadians(double degree){
//     return degree*(M_PI/180.0);
// }

// double disCal(double long1, double lat1, double long2, double lat2) {
//     lat1 = toRadians(lat1);
//     long1 = toRadians(lon1);
//     lat2 = toRadians(lat2);
//     lon2 = toRadians(lon2);

//     // Calculate differences in coordinates
//     double dlat = lat2 - lat1;
//     double dlon = lon2 - lon1;

//     // Haversine formula
//     double a = std::sin(dlat / 2.0) * std::sin(dlat / 2.0) +
//                std::cos(lat1) * std::cos(lat2) *
//                std::sin(dlon / 2.0) * std::sin(dlon / 2.0);

//     double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

//     // Distance in kilometers
//     double distance = EarthRadiusKm * c;

//     return distance;
// }

// double totalDis=0;

// double disCal(double long1, double lat1, double long2, double lat2){
//     //cout<<long1<<"--"<<lat1<<"--"<<long2<<"--"<<lat2<<"--";
//     double dist;
//     dist=sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(long1-long2);
//     dist=acos(dist);
//     dist=(6371*PI*dist)/180;
//     totalDis+=dist;
//     return dist;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<double> longitude, latitude;


//     for(int i=0; i<n; i++){
//         double x, y;
//         //cout<<"Enter Longitude: ";
//         cin>>x;
//         longitude.push_back(x);
//         cout<<fixed<<setprecision(8)<<longitude[i]<<endl;
//         //cout<<"Enter Latitude: ";
//         cin>>y;

//         latitude.push_back(y);
//         cout<<fixed<<setprecision(8)<<latitude[i]<<endl;
//     }

//     for(int i=0; i<n; i++){
//         double nn=disCal(longitude[i], latitude[i], longitude[++i], latitude[i]);
//         cout<<nn*1000<<"+++++++++++++"<<endl;
//         //cout<<longitude[i]<<"=="<<i+1<<"=="<<latitude[i]<<endl;
//     }

//     //cout<<totalDis*1000<<"==========="<<endl;

//     return 0;
// }