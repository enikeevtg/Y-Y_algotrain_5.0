/**
 * g++ g_1.cc
 * gcc -lstdc++ g_1.cc
 * Первая попытка решить задачу - неудача на тесте #09
 **/

#include <iostream>

int main() {
  int soldiers, barrack_health, enemies_per_step;
  std::cin >> soldiers >> barrack_health >> enemies_per_step;

  int rounds = 1;
  barrack_health -= soldiers;
  int enemies = barrack_health > 0 ? enemies_per_step : 0;
  if (soldiers > enemies_per_step) {
    while (barrack_health > 0) {
      ++rounds;
      barrack_health -= (soldiers - enemies);
    }
  } else {
    while (barrack_health + enemies > 0 && soldiers > 0) {
      ++rounds;
      if (barrack_health > 0) {
        barrack_health -= 1;
        enemies -= soldiers - 1;
      } else {
        enemies -= soldiers;
      }
      soldiers -= enemies;
      if (soldiers <= 0) {
        rounds = -1;
      }
      if (barrack_health) {
        enemies += enemies_per_step;
      }
    }
  }

  std::cout << rounds;

  return 0;
}
