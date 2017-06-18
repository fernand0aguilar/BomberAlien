#include "stage.hpp"

void StageScene::game_logic(){
  GameObject* ground_stage1 = &get_game_object("ground");
  ground_stage1->main_positionY = 568;
  ground_stage1->main_positionX = 0;
  ground_stage1->main_width = 800;
  ground_stage1->main_height = 32;

}

StageScene::~StageScene(){}
