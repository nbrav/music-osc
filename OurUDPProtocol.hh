#include <array>

class OurUDPProtocol {

public:
  
  static constexpr double TIMESTEP = 0.010;  // 10 ms
  static constexpr unsigned int KEYBOARDSIZE = 88;

  enum {SUSTAINCOMMAND = 0,
	PITCHBENDDOWNCOMMAND,
	MODULATECOMMAND,
	PITCHBENDUPCOMMAND,
	VOLUMECOMMAND,
	COMMANDKEYS};
  
  // Start package sent from the MUSIC side
  struct startPackage {
    int magicNumber;
    double stopTime;
  };

  // Data package sent to MUSIC
  struct toMusicPackage {
    double timestamp;
    std::array<double, KEYBOARDSIZE> keysPressed;
    std::array<double, COMMANDKEYS> commandKeys;
  };
  static constexpr int TOMUSICPORT = 9931;
  static constexpr int MAGICFROMMUSIC = 4712;
  static constexpr char const * MIDISERVER_IP = "130.237.221.78"; // wand.pdc.kth.se
  // static constexpr char const * MIDISERVER_IP = "127.0.0.1";

  // Data package received from MUSIC
  struct fromMusicPackage {
    double timestamp;
    std::array<double, KEYBOARDSIZE> keysPressed;
  };
  static constexpr int FROMMUSICPORT = 9930;
  static constexpr int MAGICTOMUSIC = 4711;
  
};
