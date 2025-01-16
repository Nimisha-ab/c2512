#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

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

void server(int server_fd) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int buffer[100];
    int size;
    int sum = 0;

    // Receive the size of the dosages array
    recvfrom(server_fd, &size, sizeof(size), 0, (struct sockaddr*)&client_addr, &addr_len);

    // Receive the dosages from the client
    recvfrom(server_fd, buffer, sizeof(int) * size, 0, (struct sockaddr*)&client_addr, &addr_len);

    cout << "Server received dosages: ";
    for (int i = 0; i < size; i++) {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Send the sum back to the client
    sendto(server_fd, &sum, sizeof(sum), 0, (struct sockaddr*)&client_addr, addr_len);
}

int main() {
    int server_fd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Server socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);  // Server listens on port 8080
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Accept messages from any client

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Server bind failed");
        return 1;
    }

    cout << "Server is listening on port 8080..." << endl;

    // Handle client messages
    server(server_fd);

    // Close the server socket
    close(server_fd);

    return 0;
}
