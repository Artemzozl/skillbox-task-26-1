#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

class Track{
private:
    std::string title = "Unknown";
    std::tm created;
    std::time_t duration;



public:
    int  durationTime;
    void setTrack(std::string titleTrack,std::tm createdTrack, int durationTrack ){
        title = titleTrack;
        created =  createdTrack;
        durationTime = durationTrack;
        duration = static_cast<time_t>(durationTime);
    }

    void getTrack(){
        std::cout << "Name track: " << title << std::endl;
        std::cout << "Created track: " << std::put_time(&created, "%m/%Y") << std::endl;
        std::cout << "Duration track: " << std::put_time(std::localtime(&duration), "%M min : %S sec")
                  << std::endl;
    }
};

int main() {
    Track sound;
    sound.setTrack("Test Sound", {0, 30, 17, 12, 4, 129}, 60 );
    sound.getTrack();


}
