#include <scene.hpp>
#include "components/animation.hpp"

using namespace engine;

class MainMenu : public Scene{
  public:
    MainMenu(std::string name):
      Scene(name){}

    ~MainMenu();

    void game_logic();
    void buttons_controller();
};
