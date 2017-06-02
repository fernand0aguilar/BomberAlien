#include "GameCoreIncludes.hpp"

using namespace engine;

int main(int, char**){

  //Configurando nome e tamanho
  std::pair<int, int> window_size(800, 600);
  Game::instance.set_properties("BomberAliens",window_size);


  //================= MAIN MENU =====================
  MainMenu menu("Initial Menu");
  GameObject menuBackground("background");
  ImageComponent menuImage(menuBackground, "menuImage", "assets/sprites/menu_background.png");
  menuBackground.add_component(menuImage);
  menu.add_game_object(menuBackground);


  //================ STAGE 1 =========================
  StageScene stage("Game Stage");
  GameObject background("background");
  ImageComponent backgroundImage(background,"imageBackground", "assets/sprites/background.png");
  background.add_component(backgroundImage);
  stage.add_game_object(background);


  // Adding scene to game
  Game::instance.add_scene(menu);
  Game::instance.add_scene(stage);

  //Game Loop
  Game::instance.run();

  return 0;
}
