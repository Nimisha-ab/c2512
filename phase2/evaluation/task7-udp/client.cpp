#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

class Prescription {
private:
    string Prescription_id;
    double Dosage;
public:
    Prescription(string p_id, double p_dosage) : Prescription_id(p_id), Dosage(p_dosage) {}

    double getDosage() { 
        return Dosage; 
    }
};

void client(const char* server_ip) {
    int sock_fd;
    struct sockaddr_in server_addr;
    vector<Prescription> prescriptions = {
        Prescription("01", 4.1), 
        Prescription("02", 5.2), 
        Prescription("03", 6.0), 
        Prescription("04", 7.2), 
        Prescription("05", 1.2)
    };

    int size = prescriptions.size();
    int dosage[100];

    for (int i = 0; i < size; i++) {
        dosage[i] = prescriptions[i].getDosage();
    }

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Client socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);  // Connect to server on port 8080

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(1);
    }

    // Send size and dosages to server
    sendto(sock_fd, &size, sizeof(size), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    sendto(sock_fd, dosage, sizeof(double) * size, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Receive the sum from the server
    int sum;
    recvfrom(sock_fd, &sum, sizeof(sum), 0, nullptr, nullptr);

    cout << "Client received sum from server: " << sum << endl;

    // Close the socket
    close(sock_fd);
}

int main() {
    const char* server_ip = "127.0.0.1";  // Localhost IP
    client(server_ip);
    return 0;
}
