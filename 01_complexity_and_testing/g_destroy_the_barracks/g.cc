/**
 * g++ g.cc
 * gcc -lstdc++ g.cc
 **/

#include <iostream>

int calc_rounds(int barrack_hp_stop, int units, int barrack_hp,
                int enemies_per_step) {
  int rounds = 0;
  int enemies = 0;

  // Бьём всех вражеских солдат и казарму, пока её здоровье больше ограничения
  while (barrack_hp >= barrack_hp_stop) {
    if (units <= enemies) {
      return -1;
    }

    barrack_hp -= units - enemies;
    enemies = 0;
    if (barrack_hp > 0) {
      enemies += enemies_per_step;
    }
    ++rounds;
  }

  // Бьём только казарму
  while (barrack_hp > 0) {
    if (units <= 0) {
      return -1;
    }

    if (barrack_hp - units > 0) {
      barrack_hp -= units;
      enemies += enemies_per_step;
    } else {
      enemies -= units - barrack_hp;
      barrack_hp = 0;
    }
    units -= enemies;
    ++rounds;
  }

  // Добиваем вражеских юнитов
  while (enemies > 0) {
    if (units <= 0) {
      return -1;
    }

    enemies -= units;
    if (enemies > 0) {
      units -= enemies;
    }
    ++rounds;
  }

  return rounds;
}

int main() {
  int units, barrack_hp, enemies_per_step;
  std::cin >> units >> barrack_hp >> enemies_per_step;

  int result_rounds = -1;
  for (int i = 0; i < barrack_hp + 1; ++i) {
    if (result_rounds == -1) {
      result_rounds = calc_rounds(i, units, barrack_hp, enemies_per_step);
      continue;
    }
    int tmp_rounds = calc_rounds(i, units, barrack_hp, enemies_per_step);
    if (tmp_rounds != -1 && tmp_rounds < result_rounds) {
      result_rounds = tmp_rounds;
    }
  }

  std::cout << result_rounds;

  return 0;
}
