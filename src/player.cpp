#include "player.hpp"

int life_points = 5;
float DAMAGE_DELAY = 1000;
unsigned int damage_time = 0;
bool attacked = false;


bool isRight = true;
int lastDirection;
int maxHeight = 200;
float moveForce = 4;
float prev_position_y;

float dy = 0;

bool Player::init(){
  return true;
}

Player::~Player(){}

void Player::update(){
  animCtrl->play_animation("player_idle");
  lastDirection = side;

  move_player();
  damage();

  processPos();
}

// // ============================================== MOVE LOGIC ===================================================
void Player::move_player(){

  define_key_pressed();

  if(_main_game_object->main_positionY > 600 || _main_game_object->main_positionY < 0){
    Log::instance.error("Player position Y is BuGGed");
  }

  if(walkR && (_main_game_object->main_positionX + _main_game_object->main_width) < 768){
    if(is_colliding() && lastDirection == RIGHT){
      walkR = false;
    }
    else{
      move_right();
    }
  }

  else if(walkL && (_main_game_object->main_positionX) >= 22){
    if(is_colliding() && lastDirection == LEFT){
      walkL = false;
    }
    else{
    move_left();
    }
  }

  else if(walkUp && (_main_game_object->main_positionY) >= 30 ){
    if(is_colliding() && lastDirection == UP){
      walkUp = false;
    }
    else
      move_up();
  }
  else if(walkDown && (_main_game_object->main_positionY) < 497){
    if(is_colliding() && lastDirection == DOWN){
      walkDown = false;
    }
    else{
      move_down();
    }
  }
}

void Player::move_right(){
  isRight = true;
  animCtrl->play_animation("player_running");
  side = RIGHT;
  animCtrl->flipping(side);
    _main_game_object->main_positionX += moveForce;
}

void Player::move_left(){
  isRight = false;
  animCtrl->play_animation("player_running");
  side = LEFT;
  animCtrl->flipping(side);
  _main_game_object->main_positionX -= moveForce;
}

void Player::move_down(){
  side = DOWN;
  animCtrl->play_animation("player_frente");
  _main_game_object->main_positionY += moveForce;
}

void Player::move_up(){
  side = UP;
  animCtrl->play_animation("player_costas");

  if(!is_colliding()){
    _main_game_object->main_positionY -= moveForce;
  }
}

void  Player::define_key_pressed(){
  // Detect move right
  if(Game::instance.keyboard->isKeyDown(SDLK_d)){
    walkR = true;
  }
  if(Game::instance.keyboard->isKeyUp(SDLK_d)){
    walkR = false;
  }
  // Detect move left
  if(Game::instance.keyboard->isKeyDown(SDLK_a)){
    walkL = true;
  }
  if(Game::instance.keyboard->isKeyUp(SDLK_a)){
    walkL = false;
  }
  // Detect move up
  if(Game::instance.keyboard->isKeyDown(SDLK_w)){
    walkUp = true;
  }
  if(Game::instance.keyboard->isKeyUp(SDLK_w)){
    walkUp = false;
  }
  // Detect move down
  if(Game::instance.keyboard->isKeyDown(SDLK_s)){
    walkDown = true;
  }
  if(Game::instance.keyboard->isKeyUp(SDLK_s)){
    walkDown = false;
  }
}


void Player::processPos(){
  prev_position_y = _main_game_object->main_positionY;
  _main_game_object->main_positionY += dy;   // current velocity components.
}


bool Player::is_colliding(){
  ground = Game::instance.collision_manager->checkCollision(_main_game_object, "bloco_indestrutivel");

  if(ground){
    return true;
  }
  return false;
}

void Player::damage(){
  if(!attack && Game::instance.collision_manager->checkCollision(_main_game_object,"monster")){
    animCtrl->play_animation("player_damage");
    if(Game::instance.timer->getTicks() > damage_time){
      life_points--;
      damage_time = Game::instance.timer->getTicks() + 1000;
    }
    if(life_points <= 0){
      _main_game_object->setState(GameObject::State::disabled);
      Game::instance.change_scene("Lose Scene");
    }
  }
}

void Player::is_dead(){
  if(life_points <= 0){
    printf("Player dead\n");
    Log::instance.info("Player dead");
  }
}
