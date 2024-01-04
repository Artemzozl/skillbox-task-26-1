#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>


class Track{
private:
    std::string title = "Unknown";
    std::tm created;
    std::time_t duration;



public:
    void setTrack(std::string titleTrack,std::tm createdTrack, int durationTrack ){
        title = titleTrack;
        created =  createdTrack;
        duration = static_cast<time_t>(durationTrack);
    }

    void getTrack() {
        std::cout << "Name track: " << title << std::endl;
        std::cout << "Created track: " << std::put_time(&created, "%m/%Y") << std::endl;
        std::cout << "Duration track: " << std::put_time(std::localtime(&duration), "%M min : %S sec")
                << std::endl;


    }

};

class Player{
private:
    std::vector<Track> playList;

public:
    void addPlayList(Track &track){
        playList.push_back(track);
    }

    void displayPlayList()  {
      for ( auto &track:playList){
           track.getTrack();
      }
    }
};

int main() {
    std::string command;
    Track sound1, sound2, sound3;
    Player music;
    sound1.setTrack("Test Sound 1.mp3", {0, 0, 0, 0, 4, 123}, 31 );
    sound2.setTrack("Test Sound 2.mp3", {0, 0, 0, 0, 3, 122}, 32 );
    sound3.setTrack("Test Sound 3.mp3", {0, 0, 0, 0, 2, 121}, 33 );
    music.addPlayList(sound1);
    music.addPlayList(sound2);
    music.addPlayList(sound3);

    std::cout << "Music player (command: read - view playlist, play, pause, stop and exit" << std::endl;
    while (command != "exit"){
        std::cout << "Input command player: ";
        std::cin >> command;
        if (command == "read"){
            music.displayPlayList();
        }
    }

}
