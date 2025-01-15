#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <string>

using namespace std;

class Prescription {
private:
    string Prescription_id;
    double Dosage;
public:
    Prescription(string p_id, double p_dosage) : Prescription_id(p_id), Dosage(p_dosage) {}

    
    double getDosage() 
    { 
        return Dosage; 
    }
};



void client(int read_fd, int write_fd) {
    vector<Prescription> prescriptions = {
        Prescription("01", 4.1), 
        Prescription("02", 5.2), 
        Prescription("03", 6.0), 
        Prescription("04", 7.2), 
        Prescription("05", 1.2)
    };

    int size = prescriptions.size();
    int dosage[100];

    for (int i = 0; i < size; i++){
        dosage[i] = prescriptions[i].getDosage();
    }

    cout << "Client sending dosages: ";
    for (int i = 0; i < size; ++i){
        cout << dosage[i] << " ";
    }
    cout << endl;

    write(read_fd, &size, sizeof(size));
    write(read_fd, dosage, sizeof(double)* size);

    int sum;
    read(write_fd, &sum, sizeof(sum));
    cout << "Client received sum from server: " << sum << endl;

    close(read_fd);
    close(write_fd);
}


void server(int read_fd, int write_fd) {
    int buffer[100];
    int size;
    int sum = 0;

    read(read_fd, &size, sizeof(size));
    read(read_fd, buffer, sizeof(int)* size);

    cout << "Server received dosages: ";
    for (int i = 0; i < size; i++) {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    write(write_fd, &sum, sizeof(sum));

    close(read_fd);
    close(write_fd);
}

int main() {
    int pipe_clienttoserver[2], pipe_servertoclient[2];

    if (pipe(pipe_clienttoserver) == -1 || pipe(pipe_servertoclient) == -1) {
        perror("Pipe creation failed");
        return 1;
    }
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {  // Child process (Client)
        close(pipe_servertoclient[1]); //
        close(pipe_clienttoserver[0]); //read end 
        client(pipe_clienttoserver[1], pipe_servertoclient[0]);
        exit(0);
    } else {  // Server
        close(pipe_clienttoserver[1]);
        close(pipe_servertoclient[0]);
        server(pipe_clienttoserver[0], pipe_servertoclient[1]);
        //wait(nullptr); 
    }
}
    return 0;
}
