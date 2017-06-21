#include <scene.hpp>
#include "components/animation.hpp"
#include "components/Sound.hpp"

using namespace engine;

class StageScene : public Scene{
  public:
    StageScene(std::string name):
      Scene(name){}

    ~StageScene();

    void game_logic();
    void setup_scene();
};
