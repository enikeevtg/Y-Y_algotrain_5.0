## G. Разрушить казарму

| | |
|------------|------------|
| Ограничение времени | 1 секунда |
| Ограничение памяти |	256Mb |
| Ввод |	стандартный ввод или input.txt |
| Вывод |	стандартный вывод или output.txt |

Вы играете в интересную стратегию. У вашего соперника остались всего одна казарма — здание, в котором постоянно появляются новые солдаты. Перед атакой у вас есть x солдат. За один раунд каждый солдат может убить одного из солдат противника или нанести 1 очко урона казарме (вычесть единицу здоровья у казармы). Изначально у вашего оппонента нет солдат. Тем не менее, его казарма имеет y единиц здоровья и производит p солдат за раунд.

Ход одного раунда:

1. Каждый солдат из вашей армии либо убивает одного из солдат вашего противника, либо наносит 1 очко урона казарме. Каждый солдат может выбрать своё действие. Когда казарма теряет все свои единицы здоровья, она разрушается.

2. Ваш противник атакует. Он убьет k ваших солдат, где k — количество оставшихся у противника солдат.

3. Если казармы еще не разрушены, ваш противник производит p новых солдат.

Ваша задача — разрушить казарму и убить всех солдат противника. Если это возможно, посчитайте минимальное количество раундов, которое вам нужно для этого. В противном случае выведите -1.

### Формат ввода
На вход подаётся три целых числа x, y, p (1 ≤ x, y, p ≤ 5000) — количество ваших солдат на старте игры, количество очков здоровья казармы и количество производимых за раунд казармой солдат, соответственно. Каждое число расположено в новой строке.

### Формат вывода
Если возможно убить всех вражеских солдат и разрушить казарму, выведите минимальное количество раундов, необходимых для этого. В противном случае выведите -1.

### Пример 1
| Ввод | Вывод |
| ---- | ----- |
| 10 | 4 |
| 11 |
| 15 |
4

### Пример 2
| Ввод | Вывод |
| ---- | ----- |
| 1 | -1 |
| 2 |
| 1 |
-1

### Пример 3
| Ввод | Вывод |
| ---- | ----- |
| 1 | 1 |
| 1 |
| 1 |

### Пример 4
| Ввод | Вывод |
| ---- | ----- |
| 25 | 13 |
| 200 |
| 10 |

### Примечания
В первом примере в первом раунде сначала все ваши солдату атакуют казарму, после этого не происходит ничего, потому что у врага нет солдат, затем у врага появляется 15 солдат. Во втором раунде один ваш солдат добивает казарму, остальные 9 солдат убивают 9 солдат врага. Оставшиеся 6 солдат врага убивают 6 ваших солдат, но армия врага не пополняется, поскольку казарма разрушена. В третьем раунде сначала вы убиваете четверых солдат врага, затем враг двоих ваших солдат. В последнем, четвертом, раунде вы добиваете двух оставшихся солдат врага.