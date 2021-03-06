#include "GameCoreIncludes.hpp"
#include "player.hpp"

#include "scene.hpp"

#include "components/image.hpp"
#include "components/animation.hpp"
#include "components/animation_controller.hpp"
#include "components/music.hpp"

using namespace engine;

int main(int, char**){

  //Configurando nome e tamanho
  std::pair<int, int> window_size(800, 576);
  Game::instance.set_properties("BomberAliens", window_size);


  //===================================== MAIN MENU =================================================================
  Log::instance.jumpLine("Configurando hierarquia de jogo\n");
  MainMenu menu("Initial Menu");

  //Menu background Image
  GameObject menuBackground("menuBackground");
  ImageComponent menuImage(menuBackground, "menuImage", "assets/sprites/title_flat.jpg");
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
  menu.add_game_object(menuButtonStart);
  menu.add_game_object(menuBackground);


  // ===================================== STAGE 1 =================================================================
  StageScene stage1("Game Stage");

  /* 777 Player configurations */
  GameObject player("player", true, "player");

  AnimationControllerComponent player_anim_ctrl(player, "animationController");
  GameObject attack_box("attack_box", true, "attack_box", GameObject::State::disabled);

  Animation player_idle(player, "playerIdle", "assets/sprites/boneco_parado.png", 254/4, 52, 4);
  Animation player_running(player, "playerRunning", "assets/sprites/boneco_andando.png" , 566/9, 54, 9);
  Animation player_attack(player, "playerAttack", "assets/sprites/boneco_colocando_bomba.png" ,386/6, 50, 6);
  Animation player_frente(player, "playerFrente", "assets/sprites/boneco_de_frente.png", 377/6, 48, 6);
  Animation player_costas(player, "playerCostas", "assets/sprites/boneco_de_costas.png", 383/6, 50, 6);

  player_idle.setDelay(100);
  player_running.setDelay(100);
  player_attack.setDelay(400);
  player_frente.setDelay(100);
  player_costas.setDelay(100);

  Player player_logic(player, "player_logic", &player_anim_ctrl, attack_box);

  player_anim_ctrl.add_animation("player_idle", player_idle);
  player_anim_ctrl.add_animation("player_running", player_running);
  player_anim_ctrl.add_animation("player_attack", player_attack);
  player_anim_ctrl.add_animation("player_frente", player_frente);
  player_anim_ctrl.add_animation("player_costas", player_costas);

  //Adding componentes to player
  player.add_component(player_idle);
  player.add_component(player_running);
  player.add_component(player_attack);
  player.add_component(player_frente);
  player.add_component(player_costas);
  player.add_component(player_anim_ctrl);
  player.add_component(player_logic);

  player.main_positionY = 499;
  player.main_positionX = 23;
  //player.set_layer(GameObject::Layer::layer);
  /* 777 End of Player configurations */


  /* 555 MAP configurations */
  GameObject background_game_map("mapBackground");
  ImageComponent backgroundImage(background_game_map,"background_game_map", "assets/sprites/map_small.png");
  background_game_map.set_layer(GameObject::Layer::background);
  background_game_map.main_width = 800;
  background_game_map.main_height = 576;
  background_game_map.add_component(backgroundImage);

  GameObject ground_stage1("ground", true, "ground");
  /* 555 End of Map configurations */

  /* 333 Undestructable blocks configurations */
  Log::instance.jumpLine("Adding Plataforms To MAP");

  GameObject plataform0("plataform0", true, "bloco_indestrutivel");
  plataform0.main_positionX = 150;
  plataform0.main_positionY = 160;

  ImageComponent img_plataform(plataform0, "plataform0", "assets/sprites/ExplodableBlock.png");

  plataform0.add_component(img_plataform);
  stage1.add_game_object(plataform0);
  Log::instance.jumpLine("333 End of Undestructable blocks configurations ");
  /* 333 End of Undestructable blocks configurations */

  stage1.add_game_object(player);
  stage1.add_game_object(attack_box);
  stage1.add_game_object(ground_stage1);
  stage1.add_game_object(background_game_map);

  // ===================================== Adding scenes to game =================================================================
  Game::instance.add_scene(menu);
  Game::instance.add_scene(stage1);

  //Game Loop
  Game::instance.run();

  return 0;
}
