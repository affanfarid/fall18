

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include <cstdio>

using namespace std;


class Bus{
    
private:
    int lower;
    int upper;
    

public:
    
    int lower;
    int upper;
    
    Bus(int L, int U)
    {
        lower = L;
        upper = U;
        
    }
    
//    string getDept(){
//        return Dept;
//
//    }

};

class City{
    
private:
    

    
public:
    
    int num;
    
    int numBusesToCity;
    
    City(int Num){
        num = Num;
    }
    
    bool reachesCity(Bus b){
        
        if(b1.lower <= num && b1.upper >= num){
            return true;
        }
        else return false;
        
    }
    
    
    
    
};



int main(){
    
    int numInputs;
    //cin>>numInputs;
    getLine(cin,numInputs);
    
    for(int x = 0; x<numInputs; x++){
        
        vector<City> cities;
        vector<Bus> buses;
        
        int numBuses;
        
        
        getLine(cin,numBuses);
        //cin>> numBuses;
        
        for(int i =0; i< numBuses; i++){
            int lower;
            int upper;
            
            string line3;
            //getLine(cin,line3);
            
            cin>>lower>>upper;
            Bus b = new Bus (lower, upper);
            buses.push_back(b);
            
        }
        
        
        //cin>>endl;
        
        
        int numCities;
        
        cin>>numCities;
        
        for(int j = 0; j<numCities; j++){
            
            int cityNum;
            
            cin>>cityNum;
            
            City c1 = new City(cityNum);
            cities.push_back(c1);
        }
        
        for(auto k: buses){
            
            for(auto h: cities){
                if(h.reachesCity(k)){
                    h.numBusesToCity++;
                }
            }
            
        }
        
        for (auto y: cities){
            printf("Case %d: ",x+1,y.numBusesToCity);
        }
        
        
    }
    
    
    
    
    

    return 0;
}
