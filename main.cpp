#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

class Track{
private:
    std::string title = "Unknown";
    std::tm* created;
    std::time_t duration;

    //int duration = 0;


    //std::time_t durationTime = static_cast<time_t>(duration);

public:
    int  durationTime =0;
    void setTrack(std::string titleTrack,std::tm* createdTrack, int durationTrack ){
        title = titleTrack;
        created = createdTrack;
        durationTime = durationTrack;
        duration = static_cast<time_t>(durationTime);
    }

    void getTrack(){
       // std::time_t durationTime = static_cast<time_t>(duration);
        std::cout << "Name track: " << title << std::endl;
        std::cout << "Created track: " << std::put_time(created, "%m/%Y") << std::endl;
        std::cout << "Duration track: " << std::put_time(std::localtime(&duration), "%M min : %S sec")
                  << std::endl;
    }
};

int main() {
    Track sound;
    std::string testNameTrack = "Test276";
    std::tm createdTrack{0, 30, 17, 12, 8, 129};
    int durationInt = 456;
    sound.setTrack(testNameTrack, &createdTrack, durationInt );
    sound.getTrack();


}
