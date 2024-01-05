#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>

enum class PlayerStatus{
    PLAY,
    PAUSE,
    STOP
};
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
    const std::string& getTitle() const {return title;}

};

class Player{
private:
    std::vector<Track> playList;

public:

    bool status = false;
    PlayerStatus state = PlayerStatus::STOP;

    void addPlayList(Track &track){
        playList.push_back(track);
    }

    void displayPlayList()  {
      for ( auto &track:playList){
           track.getTrack();
      }
    }

    void playMusic(const std::string& title) {
            for (size_t i = 0; i < playList.size(); i++) {
                if (playList[i].getTitle() == title) {
                        if (state == PlayerStatus::STOP) {
                            status = true;
                        }
                    if (status && state != PlayerStatus::PLAY){
                        state = PlayerStatus::PLAY;
                        std::cout << "Playing selected track:" << std::endl;
                        playList[i].getTrack();
                        std::cout << "Please pause or stop current track" << std::endl;
                    } else{
                        std::cout << "Track not found in the playlist!" << std::endl;
                    }
                    return;
                }
            }
    }
    void pauseMusic(){
        if (state == PlayerStatus::PLAY){
            state == PlayerStatus::PAUSE;
            std::cout << "Pause music. " << std::endl;
        } else {
            std::cout << "Track not selected for playback. " << std::endl;
        }
    }

    void nextMusic(){
        if (playList.empty()){
            std::cout << "Track list empty! " << std::endl;
            return;
        }
        state == PlayerStatus::PLAY;
        status = true;
        std::cout << "Playing randomly selected track:" << std::endl;
        playList[(std::rand()% playList.size())].getTrack();
        std::cout << "Please pause or stop current track" << std::endl;
    }

    void stopMusic(){
        if (status && (state == PlayerStatus::PLAY || state == PlayerStatus::PAUSE)){
            state == PlayerStatus::STOP;
            status = false;
            std::cout << "Stop music. " << std::endl;
        } else {
            std::cout << "Track not selected for playback. " << std::endl;
        }

    }
    };

int main() {
    std::string command, trackName;
    Track sound1, sound2, sound3;
    Player music;

    sound1.setTrack("Test Sound 1.mp3", {0, 0, 0, 0, 4, 123}, 31 );
    sound2.setTrack("Test Sound 2.mp3", {0, 0, 0, 0, 3, 122}, 32 );
    sound3.setTrack("Test Sound 3.mp3", {0, 0, 0, 0, 2, 121}, 33 );
    music.addPlayList(sound1);
    music.addPlayList(sound2);
    music.addPlayList(sound3);

    std::cout << "Music player (command: read - view playlist, play, pause, next, stop and exit" << std::endl;
    while (command != "exit"){
        std::cout << "Input command player: ";
        std::cin >> command;
        if (command == "read"){
            music.displayPlayList();
        } else if (command == "play"){
                std::cout << "Input track name to play: ";
                std::cin.ignore();
                std::getline(std::cin, trackName);
                music.playMusic(trackName);
        } else if (command == "pause"){
                music.pauseMusic();
        } else if (command == "next"){
                music.nextMusic();
        } else if (command == "stop"){
                music.stopMusic();
        }
    }

}
