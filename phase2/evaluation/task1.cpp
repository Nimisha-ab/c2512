#include <iostream>
#include <vector>
#include <limits>
# include<string>

class Prescription {
private:
    std::string p_id;
    double dosage;

public: 
    Prescription(std::string p_id, double dosage) : p_id(p_id), dosage(dosage) {
        
    }
    int getResult()
    {
        return dosage;
    }
};

int findsum( std:: vector <Prescription> &prescriptions)
{
    double sum=0;
    for(auto &e:prescriptions)
    {
        sum += e.getResult();
        
    }
    return sum;
}
int findminfirsthalf( std:: vector <Prescription> &prescriptions)
{
    int min=prescriptions[0].getResult();
    int half=(prescriptions.size()/2);
    for(int i=1;i<half;i++)
    {
        if(prescriptions[i].getResult()<min)
        {
            min=prescriptions[i].getResult();
            
        }
    }
    return min;
}
int findmaxsecondhalf( std:: vector <Prescription> &prescriptions)
{
    int max=prescriptions[0].getResult();
    int half=(prescriptions.size()-1/2);
    for(int i=1;i<half;i++)
    {
        if(prescriptions[i].getResult()>max)
        {
            max=prescriptions[i].getResult();
            
        }
    }
    return max;
}      
    

int main() {
    
    std::vector<Prescription> prescriptions= {
        Prescription("1", 10.5),
        Prescription("2", 20.0),
        Prescription("3", 15.5),
        Prescription("4", 5.0),
        Prescription("5", 6.0)

    };
    double sum = findsum(prescriptions);
    double min = findminfirsthalf(prescriptions);
    double max = findmaxsecondhalf(prescriptions);
    

    
    std::cout << "Total Dosage: " << sum << std::endl;
    std::cout << "Minimum Dosage: " << min << std::endl;
    std::cout << "Maximum Dosage: " << max << std::endl;

    return 0;
}    
                                                             //create vector of 5 objects   
                                                                                                            //findsum() of prescription  
                                                                                                      //findmin() of firsthalf ,secondhalf findmax
  
