/**
 * g++ g_2.cc
 * gcc -lstdc++ g_2.cc
 * Начал решить задачу с помощью классов
 **/

#include <iostream>

class Barrack {
public:
  Barrack(int health, int soldiers_per_step)
      : health_(health), soldiers_per_step_(soldiers_per_step) {
    // std::cout << health_ << '\n' << soldiers_per_step;
  }

private:
  int health_{0};
  int soldiers_per_step_{0};
};

int main() {
  int soldiers, barrack_health, enemies_per_step;
  std::cin >> soldiers >> barrack_health >> enemies_per_step;

  Barrack barrack = Barrack(barrack_health, enemies_per_step);

  return 0;
}
