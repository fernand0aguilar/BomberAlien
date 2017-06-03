#include "GameCoreIncludes.hpp"

using namespace engine;

int main(int, char**){

  //Configurando nome e tamanho
  std::pair<int, int> window_size(800, 600);
  Game::instance.set_properties("BomberAliens",window_size);


  //===================================== MAIN MENU =================================================================
  MainMenu menu("Initial Menu");

  //Menu background Image
  GameObject menuBackground("background");
  ImageComponent menuImage(menuBackground, "menuImage", "assets/sprites/menu_background.png");
  menuBackground.add_component(menuImage);

  // Main menu music
  Music menu_music(menuBackground, "menu_musicBackground", "assets/music/gm.wav");

  //(Start Button)
  GameObject menuButtonStart("buttonStart");
  Animation image_button_start(menuButtonStart, "imageButtonStart", "assets/sprites/buttonStart.png", 448/2, 100, 2);
  image_button_start.setAnimation("normal", 0, 0);
  image_button_start.setAnimation("mouseON", 1, 1);
  menuButtonStart.add_component(image_button_start);

  //Adding GameObjects to menu StageScene
  menu.add_game_object(menuBackground);
  menu.add_game_object(menuButtonStart);


  // ===================================== STAGE 1 =================================================================
  StageScene stage("Game Stage");
  GameObject gameMap("map");
  ImageComponent backgroundImage(gameMap,"map", "assets/sprites/map.png");
  gameMap.add_component(backgroundImage);
  stage.add_game_object(gameMap);


  // Adding scenes to game
  Game::instance.add_scene(menu);
  // Game::instance.add_scene(stage);

  //Game Loop
  Game::instance.run();

  return 0;
}
