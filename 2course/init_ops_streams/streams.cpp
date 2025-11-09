#include <fstream>

int main() {
    std::ofstream file_out;
    file_out.open("output.txt", std::ios_base::app);
    file_out << "Hey!\n";
    file_out.close();
}