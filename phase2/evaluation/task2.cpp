#include <iostream>
#include <vector>
#include <thread>
# include<string>

using namespace std;
 int dosage_sum, min_dosage, max_dosage;

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

void findsum( std:: vector <Prescription> &prescriptions)
{
    double sum=0;
    for(auto &e:prescriptions)
    {
        sum += e.getResult();
        
    }
    dosage_sum= sum;
}
void findminfirsthalf( std:: vector <Prescription> &prescriptions)
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
    min_dosage= min;
}
void findmaxsecondhalf( std:: vector <Prescription> &prescriptions)
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
    max_dosage= max;
}      
    

int main() {
    
    std::vector<Prescription> prescriptions= {
        Prescription("1", 10.5),
        Prescription("2", 20.0),
        Prescription("3", 15.5),
        Prescription("4", 5.0),
        Prescription("5", 6.0)

    };
     thread threadsum(findsum, ref(prescriptions));
     thread threadfindminfirsthalf(findminfirsthalf, ref(prescriptions));
     thread threadfindmaxsecondhalf(findmaxsecondhalf, ref(prescriptions));

     threadsum.join();
     threadfindminfirsthalf.join();
     threadfindmaxsecondhalf.join();

    

    
    std::cout << "Total Dosage: " << dosage_sum<< std::endl;
    std::cout << "Minimum Dosage: " << min_dosage << std::endl;
    std::cout << "Maximum Dosage: " << max_dosage << std::endl;

    return 0;
}    
                                                             //create vector of 5 objects   
                                                                                                            //findsum() of prescription  
                                                                                                      //findmin() of firsthalf ,secondhalf findmax
  
