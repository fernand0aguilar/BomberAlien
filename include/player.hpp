#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"

using namespace engine;

class Player : public Component{

public:
  Player(GameObject &main_game_object, std::string id, AnimationControllerComponent *animC, GameObject &attack_box ):
  Component(main_game_object, id), animCtrl(animC), walkR(false), walkL(false), walkUp(false), walkDown(false),
  stand(false), attack(false), damageBool(false), side(false), m_attack_box(&attack_box){}

  ~Player();

  bool init();
  void update();

  void is_dead();
  void damage_player();
  void attack_player();
  void move_player();
  void jump_player();
  void damage();

  void processPos();
  void gravityF();
  bool has_ground();

  void move_right();
  void move_left();
  void move_up();
  void move_down();
  
  void define_key_pressed();


  //void monsterAI(GameObject *obj);

  GameObject *player;
  GameObject *plataform;
  GameObject *monster;

private:
  const bool RIGHT = true;
  const bool LEFT = false;
  const bool UP = true;
  const bool DOWN = false;

  AnimationControllerComponent *animCtrl;
  AnimationControllerComponent *monster_controler;
  unsigned int jumptime;

  bool walkR;
  bool walkL;
  bool walkUp;
  bool walkDown;

  bool jump;
  bool stand;
  bool attack;
  bool damageBool;
  bool side;
  GameObject *ground;
  GameObject* m_attack_box;
  float dy;
};

#endif
