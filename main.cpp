#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>

class Track {
private:
    std::string title = "Unknown";
    std::time_t t = std::time(nullptr);
    std::tm* created = std::localtime(&t);
    int duration = 0;

public:
    void setTrack(std::string titleTrack, int durationTrack) {
        title = titleTrack;
        duration = durationTrack;
    }

    void getTrack() {
        std::time_t durationTime = static_cast<time_t>(duration);
        std::cout << "Name track: " << title << std::endl;
        std::cout << "Created track: " << std::put_time(created, "%m/%Y") << std::endl;
        std::cout << "Duration track: " << std::put_time(std::localtime(&durationTime), "%M min : %S sec")
                  << std::endl;
    }
};

class Player {
private:
    std::vector<Track> playList;

public:

};

int main() {

}