#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

class Track{
private:
    std::string title = "Unknown";
    std::time_t t = std::time(nullptr);
    std::tm* created = std::localtime(&t);
    int duration = 0;
   // std::time_t durationTime = static_cast<time_t>(duration);

public:
    void setTrack(std::string titleTrack,/*std::tm* createdTrack,*/ int durationTrack ){
        title = titleTrack;
       // created = createdTrack;
        duration = durationTrack;

    }

    void getTrack(){
        std::time_t durationTime = static_cast<time_t>(duration);
        std::cout << "Name track: " << title << std::endl;
       // std::cout << "Created track: " << created << std::endl;
        std::cout << "Duration track: " << std::put_time(std::localtime(&durationTime), "%M min : %S sec")
                   << std::endl;
    }
};

int main() {
 Track sound;
 std::string testNameTrack = "Test276";
 int durationInt = 30;

 sound.setTrack(testNameTrack, durationInt );
 sound.getTrack();
}
