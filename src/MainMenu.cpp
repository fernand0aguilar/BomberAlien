#include "MainMenu.hpp"

void MainMenu::game_logic(){
  buttons_controller();
}

MainMenu::~MainMenu(){}

void MainMenu::buttons_controller(){
  GameObject* buttonStart = &get_game_object("buttonStart");

  buttonStart->main_positionX = 300;
  buttonStart->main_positionY = 200;

  Animation* buttonStartAnimation = (dynamic_cast<Animation *>(buttonStart->get_component("imageButtonStart")));

  if(Game::instance.mouse->is_over(buttonStart)){
        if (Game::instance.mouse->is_right_button()) {
            Game::instance.change_scene("Game Stage");
        }
        buttonStartAnimation->useAnimation("normal");
    }
    else{
        buttonStartAnimation->useAnimation("mouseON");
    }
}
