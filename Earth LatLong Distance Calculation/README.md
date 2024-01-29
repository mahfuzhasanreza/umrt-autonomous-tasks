## Earth LatLong Distance Calculation

#### Code
```cpp
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
```

#### Sample Input 1
```
8
38.41907780
-110.7827790
38.41931294
-110.7833323
38.41963887
-110.7837727
38.41992346
-110.7839157
38.41927765
-110.7846484
38.41866347
-110.7835360
38.41887030
-110.7840279
38.41911949
-110.7836188
```

#### Sample Output 1
```
Point 1: (38.41907780, -110.78277900)
Point 2: (38.41931294, -110.78333230)
Distance between point 1 and 2: 54.83785279 meter
Point 2: (38.41931294, -110.78333230)
Point 3: (38.41963887, -110.78377270)
Distance between point 2 and 3: 52.77804919 meter
Point 3: (38.41963887, -110.78377270)
Point 4: (38.41992346, -110.78391570)
Distance between point 3 and 4: 34.00883969 meter
Point 4: (38.41992346, -110.78391570)
Point 5: (38.41927765, -110.78464840)
Distance between point 4 and 5: 96.07986854 meter
Point 5: (38.41927765, -110.78464840)
Point 6: (38.41866347, -110.78353600)
Distance between point 5 and 6: 118.55795812 meter
Point 6: (38.41866347, -110.78353600)
Point 7: (38.41887030, -110.78402790)
Distance between point 6 and 7: 48.63569690 meter
Point 7: (38.41887030, -110.78402790)
Point 8: (38.41911949, -110.78361880)
Distance between point 7 and 8: 45.14450429 meter

Total distance among all points: 450.04276951 meter
Minimum ditsance among all points: 34.00883969 meter

Minimum distance point 1 (latitude, longitude): (38.41963887, -110.78377270)
Minimum distance point 2 (latitude, longitude): (38.41992346, -110.78391570)
```

#### Sample Input 2
```
7
38.41931294
-110.7833323
38.41963887
-110.7836188
38.41992346
-110.7837727
38.41927765
-110.7839157
38.41887030
-110.7840279
38.41911949
-110.7846484
38.41866347
-110.7835360
```

#### Sample Output 2
```
Point 1: (38.41931294, -110.78333230)
Point 2: (38.41963887, -110.78361880)
Distance between point 1 and 2: 44.00514762 meter
Point 2: (38.41963887, -110.78361880)
Point 3: (38.41992346, -110.78377270)
Distance between point 2 and 3: 34.36815134 meter
Point 3: (38.41992346, -110.78377270)
Point 4: (38.41927765, -110.78391570)
Distance between point 3 and 4: 72.88335608 meter
Point 4: (38.41927765, -110.78391570)
Point 5: (38.41887030, -110.78402790)
Distance between point 4 and 5: 46.33795686 meter
Point 5: (38.41887030, -110.78402790)
Point 6: (38.41911949, -110.78464840)
Distance between point 5 and 6: 60.74553569 meter
Point 6: (38.41911949, -110.78464840)
Point 7: (38.41866347, -110.78353600)
Distance between point 6 and 7: 109.37638192 meter

Total distance among all points: 367.71652952 meter
Minimum ditsance among all points: 34.36815134 meter

Minimum distance point 1 (latitude, longitude): (38.41963887, -110.78361880)
Minimum distance point 2 (latitude, longitude): (38.41992346, -110.78377270)
```

#### Sample Test 2 Scenario

![sample_test_2_scenario](https://github.com/mahfuzhasanreza/UMRT-Autonomous-Tasks/assets/115473925/8ea91b89-0fbe-42b3-a17b-0eaf3f2e5fe4)