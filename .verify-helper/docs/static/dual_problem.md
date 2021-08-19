# 双対問題 (dual problem)

主問題 (primary problem) の補問題である．


### 強双対定理 (strong duality theorem)

主問題に最適解が存在するならば, その最適解に等しい双対問題の最適解も存在する．


## 例

### 線形計画問題 (linear programming problem)

|$\max$|$\min$|
|:--:|:--:|
|制約条件|決定変数|
|$\geq$|$\boldsymbol{x} \leq \boldsymbol{0}$|
|$=$|なし|
|$\leq$|$\boldsymbol{x} \geq \boldsymbol{0}$|
|決定変数|制約条件|
|$\boldsymbol{x} \geq \boldsymbol{0}$|$\geq$|
|なし|$=$|
|$\boldsymbol{x} \leq \boldsymbol{0}$|$\leq$|

主問題

$$\max \boldsymbol{c}^{\mathrm{T}} \boldsymbol{x} \text{ s.t. } \begin{cases} A \boldsymbol{x} \leq \boldsymbol{b} \\ \boldsymbol{x} \geq \boldsymbol{0} \text{．} \end{cases}$$

双対問題

$$\min \boldsymbol{b}^{\mathrm{T}} \boldsymbol{y} \text{ s.t. } \begin{cases} A^{\mathrm{T}} \boldsymbol{y} \geq \boldsymbol{c} \\ \boldsymbol{y} \geq \boldsymbol{0} \text{．} \end{cases}$$

### 牛ゲー

自己ループのない有向グラフ $(V, E)$, 始点 $s$, 終点 $t$, 辺 $e \in E$ のコスト $c_e$ とおく．

主問題 (最短経路問題)

$$\min \sum_{e \in E} c_e x_e \text{ s.t. } \begin{cases} \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = \begin{cases} -1 & (v = s) \\ 1 & (v = t) \\ 0 & (\text{otherwise}) \end{cases} \\ x_e \geq 0 & (e \in E) \text{．} \end{cases}$$

双対問題

$$\max{(p_t - p_s)} \text{ s.t. } p_v - p_u \leq c_e \ (e = (u, v) \in E) \text{．}$$

### [最大フロー最小カット定理](../graph/flow/maximum_flow/maximum_flow.md)

有向グラフ $(V, E)$, 始点 $s$, 終点 $t$, 辺 $e \in E$ の容量 $c_e$ とおく．

主問題 (最大流問題)

$E^{\prime} = E \cup \lbrace (t, s) \rbrace$ とし辺 $e \in E^{\prime}$ の流量を $x_e$ とおくと

$$\max x_{(t, s)} \text{ s.t. } \begin{cases} \sum_{e \in \delta^-(v) \subset E^{\prime}} x_e - \sum_{e \in \delta^+(v) \subset E^{\prime}} x_e = 0 & (v \in V) \\ x_e \leq c_e & (e \in E) \\ x_e \geq 0 & (e \in E^{\prime}) \text{．} \end{cases}$$

双対問題 (最小カット問題)

$$\max \sum_{e \in E} c_e y_e \text{ s.t. } \begin{cases} y_e + z_u - z_v \geq 0 & (e = (u, v) \in E) \\ z_t - z_s \geq 1 \\ y_e \geq 0 & (e \in E) \text{．} \end{cases}$$

e.g. http://hos.ac/slides/20150319_flow.pdf p.84 の有向グラフ

主問題

$$\max \begin{pmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 1 \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4 \\ x_5 \\ x_{(t, s)} \end{pmatrix} \text{ s.t. } \begin{pmatrix} 1 & & & & & \\ & 1 & & & & \\ & & 1 & & & \\ & & & 1 & & \\ & & & & 1 & \\ 1 & 1 & 0 & 0 & 0 & -1 \\ -1 & -1 & 0 & 0 & 0 & 1 \\ -1 & 0 & 1 & 0 & 1 & 0 \\ 1 & 0 & -1 & 0 & -1 & 0 \\ 0 & -1 & 0 & 1 & -1 & 0 \\ 0 & 1 & 0 & -1 & 1 & 0 \\ 0 & 0 & -1 & -1 & 0 & 1 \\ 0 & 0 & 1 & 1 & 0 & -1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4 \\ x_5 \\ x_{(t, s)} \end{pmatrix} \leq \begin{pmatrix} c_1 \\ c_2 \\ c_3 \\ c_4 \\ c_5 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 0 \end{pmatrix} \text{．}$$

双対問題

$$\min \begin{pmatrix} c_1 \\ c_2 \\ c_3 \\ c_4 \\ c_5 \\ 0 \\ 0 \\ 0 \\ 0 \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} y_1 \\ y_2 \\ y_3 \\ y_4 \\ y_5 \\ z_1 \\ z_2 \\ z_3 \\ z_4 \end{pmatrix} \text{ s.t. } \begin{pmatrix} 1 & & & & & 1 & -1 & 0 & 0 \\ & 1 & & & & 1 & 0 & -1 & 0 \\ & & 1 & & & 0 & 1 & 0 & -1 \\ & & & 1 & & 0 & 0 & 1 & -1 \\ & & & & 1 & 0 & 1 & -1 & 0 \\ & & & & & -1 & 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} y_1 \\ y_2 \\ y_3 \\ y_4 \\ y_5 \\ z_1 \\ z_2 \\ z_3 \\ z_4 \end{pmatrix} \geq \begin{pmatrix} 0 \\ 0 \\ 0 \\ 0 \\ 0 \\ 1 \end{pmatrix} \text{．}$$

### 最小費用流問題

有向グラフ $(V, E)$, 頂点 $v \in V$ の流出量を $f_v$, 辺 $e \in E$ の流量 $x_e \ (0 \leq l_e \leq x_e \leq u_e)$, コスト $c_e$ とおく．

主問題 (最小流量制約付き最小費用流)

$$\min \sum_{e \in E} c_e x_e \text{ s.t. } \begin{cases} \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = -f_v & (v \in V) \\ 0 \leq l_e \leq x_e \leq u_e & (e \in E) \text{．} \end{cases}$$

双対問題

$$\max{\left(-\sum_{v \in V} f_v p_v + \sum_{e \in E} l_e a_e - u_e b_e \right)} \text{ s.t. } \begin{cases} p_v - p_u + a_e - b_e \leq c_e & (e = (u, v) \in E) \\ a_e, b_e \geq 0 & (e \in E) \text{．} \end{cases}$$

e.g. http://hos.ac/slides/20150319_flow.pdf p.84 の有向グラフ

主問題

$$\min \begin{pmatrix} c_1 \\ c_2 \\ c_3 \\ c_4 \\ c_5 \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4 \\ x_5 \end{pmatrix} \text{ s.t. } \begin{cases} \begin{pmatrix} -1 & -1 & 0 & 0 & 0 \\ 1 & 1 & 0 & 0 & 0 \\ 1 & 0 & -1 & -1 & 0 \\ -1 & 0 & 1 & 1 & 0 \\ 0 & 1 & 1 & 0 & -1 \\ 0 & -1 & -1 & 0 & 1 \\ 0 & 0 & 0 & 1 & 1 \\ 0 & 0 & 0 & -1 & -1 \\ 1 & & & & \\ & 1 & & & \\ & & 1 & & \\ & & & 1 & \\ & & & & 1 \\ -1 & & & & \\ & -1 & & & \\ & & -1 & & \\ & & & -1 & \\ & & & & -1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \\ x_3 \\ x_4 \\ x_5 \end{pmatrix} \geq \begin{pmatrix} -f_1 \\ f_1 \\ -f_2 \\ f_2 \\ -f_3 \\ f_3 \\ -f_4 \\ f_4 \\ l_1 \\ l_2 \\ l_3 \\ l_4 \\ l_5 \\ -u_1 \\ -u_2 \\ -u_3 \\ -u_4 \\ -u_5 \end{pmatrix} \\ \boldsymbol{x} \geq \boldsymbol{0} \text{．} \end{cases}$$

双対問題

$$\max \begin{pmatrix} -f_1 \\ -f_2 \\ -f_3 \\ -f_4 \\ l_1 \\ l_2 \\ l_3 \\ l_4 \\ l_5 \\ -u_1 \\ -u_2 \\ -u_3 \\ -u_4 \\ -u_5 \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} p_1 \\ p_2 \\ p_3 \\ p_4 \\ a_1 \\ a_2 \\ a_3 \\ a_4 \\ a_5 \\ b_1 \\ b_2 \\ b_3 \\ b_4 \\ b_5 \end{pmatrix} \text{ s.t. } \begin{cases} \begin{pmatrix} -1 & 1 & 0 & 0 & 1 & & & & & -1 & & & & \\ -1 & 0 & 1 & 0 & & 1 & & & & & -1 & & & \\ 0 & -1 & 1 & 0 & & & 1 & & & & & -1 & & \\ 0 & -1 & 0 & 1 & & & & 1 & & & & & -1 & \\ 0 & 0 & -1 & 1 & & & & & 1 & & & & & -1 \end{pmatrix} \begin{pmatrix} p_1 \\ p_2 \\ p_3 \\ p_4 \\ a_1 \\ a_2 \\ a_3 \\ a_4 \\ a_5 \\ b_1 \\ b_2 \\ b_3 \\ b_4 \\ b_5 \end{pmatrix} \leq \begin{pmatrix} c_1 \\ c_2 \\ c_3 \\ c_4 \\ c_5 \end{pmatrix} \\ \boldsymbol{a}, \boldsymbol{b} \geq \boldsymbol{0} \text{．} \end{cases}$$

e.g. [How to Create a Good Game](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14)

DAG $(V, E)$, 最長経路の長さ $D$, 辺 $e \in E$ に加えるコスト $a_e$ とおく．

$$\max \sum_{e \in E} a_e \text{ s.t. } \begin{cases} p_x - p_y + a_e \leq -s_e & (e = (x, y) \in E) \\ p_{n - 1} - p_0 \leq D \\ \boldsymbol{a} \geq \boldsymbol{0} \text{．} \end{cases}$$

Sample Input 1 の場合，

$\boldsymbol{b} = \boldsymbol{0}$ としなければならない．

$$\max \begin{pmatrix} 0 \\ 0 \\ 0 \\ 1 \\ 1 \\ 1 \\ 0 \\ \infty \\ \infty \\ \infty \\ \infty \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} p_0 \\ p_1 \\ p_2 \\ a_{(0, 1)} \\ a_{(1, 2)} \\ a_{(0, 2)} \\ a_{(0, 2)}^{\prime} \\ b_{(0, 1)} \\ b_{(1, 2)} \\ b_{(0, 2)} \\ b_{(0, 2)}^{\prime} \end{pmatrix} \text{ s.t. } \begin{cases} p_x - p_y + a_e - b_e \leq -s_e & (e = (x, y) \in E) \\ p_2 - p_0 + a_{(0, 2)}^{\prime} - b_{(0, 2)}^{\prime} \leq 8 \\ \boldsymbol{a}, \boldsymbol{b} \geq \boldsymbol{0} \text{．} \end{cases}$$

e.g. [123パズル](https://atcoder.jp/contests/kupc2019/submissions/10486057)

単純グラフ $(V, E)$ とおく.

$$\min \sum_{e \in E} C_e \text{ s.t. } \begin{cases} A_v - A_u + C_e \geq 1 - l_e & (e = (u, v) \in E) \\ \boldsymbol{0} \leq \boldsymbol{A} \leq \boldsymbol{2},\ \boldsymbol{C} \geq \boldsymbol{0} \text{．} \end{cases}$$

超頂点 $S$ を用意すると

$$\max \sum_{e \in E} -C_e + \sum_{v \in V} -\infty \cdot (C_v + C_v^{\prime}) \text{ s.t. } \begin{cases} A_u - A_v - C_e \leq l_e - 1 & (e = (u, v) \in E) \\ A_v - A_s - C_v \leq 2,\ A_s - A_v - C_v^{\prime} \leq 0 & (v \in V) \\ \boldsymbol{C} \geq \boldsymbol{0} \text{．} \end{cases}$$

e.g. [Longest Shortest Path](https://atcoder.jp/contests/jag2015autumn/submissions/10498510)

有向グラフ $(V, E)$ とおく．

主問題

$$\max{(p_t - p_s)} \text{ s.t. } \begin{cases} p_u - p_v \leq d_e + x_e & (e = (v, u) \in E) \\ \sum_{e \in E} c_e x_e \leq P \\ \boldsymbol{x} \geq \boldsymbol{0} \text{．} \end{cases}$$

Sample Input 1 の場合，

$$\max \begin{pmatrix} -1 \\ 0 \\ 1 \\ 0 \\ 0 \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} p_1 \\ p_2 \\ p_3 \\ x_{(1, 2)} \\ x_{(2, 3)} \end{pmatrix} \text{ s.t. } \begin{cases} \begin{pmatrix} -1 & 1 & 0 & -1 & 0 \\ 0 & -1 & 1 & 0 & -1 \\ 0 & 0 & 0 & c_{(1, 2)} = 1 & c_{(2, 3)} = 2 \end{pmatrix} \begin{pmatrix} p_1 \\ p_2 \\ p_3 \\ x_{(1, 2)} \\ x_{(2, 3)} \end{pmatrix} \leq \begin{pmatrix} d_{(1, 2)} = 2 \\ d_{(2, 3)} = 1 \\ P = 3 \end{pmatrix} \\ \boldsymbol{x} \geq \boldsymbol{0} \text{．} \end{cases}$$

双対問題

$$\min{(Py + \sum_{e \in E} d_e f_e)} \text{ s.t. } \begin{cases} \sum_{e \in \delta^+(v)} f_e - \sum_{e \in \delta^-(v)} f_e \leq 0 & (v \in V \setminus \lbrace s, t \rbrace) \\ \sum_{e \in \delta^+(s)} f_e - \sum_{e \in \delta^-(s)} f_e \leq 1 \\ \sum_{e \in \delta^+(t)} f_e - \sum_{e \in \delta^-(t)} f_e \leq -1 \\ 0 \leq f_e \leq c_e y & (e \in E) \\ y \geq 0 \text{．} \end{cases}$$

制約式の上三つより $\boldsymbol{f}$ は始点 $s$, 終点 $t$, 流量 $1$ のフローとなる．

Sample Input 1 の場合，

$$\min \begin{pmatrix} d_{(1, 2)} = 2 \\ d_{(2, 3)} = 1 \\ P = 3 \end{pmatrix}^{\mathrm{T}} \begin{pmatrix} f_{(1, 2)} \\ f_{(2, 3)} \\ y \end{pmatrix} \text{ s.t. } \begin{cases} \begin{pmatrix} -1 & 0 & 0 \\ 1 & -1 & 0 \\ 0 & 1 & 0 \\ -1 & 0 & c_{(1, 2)} = 1 \\ 0 & -1 & c_{(2, 3)} = 2 \end{pmatrix} \begin{pmatrix} f_{(1, 2)} \\ f_{(2, 3)} \\ y \end{pmatrix} \geq \begin{pmatrix} -1 \\ 0 \\ 1 \\ 0 \\ 0 \end{pmatrix} \\ \boldsymbol{f} \geq \boldsymbol{0} \\ y \geq 0 \text{．} \end{cases}$$

### 最大マッチング問題と最小点カバー問題


## 参考

- http://tokoharuland.hateblo.jp/entry/2016/12/06/223614
- https://www.slideshare.net/wata_orz/ss-91375739
- http://beet-aizu.hatenablog.com/entry/2019/10/20/150649
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.223-224，マイナビ出版（2012）．
- https://paper.dropbox.com/doc/YqGiA3I6bDbMWWWsUc1an
- 最大フロー最小カット定理
  - http://hos.ac/slides/20150319_flow.pdf
- 123パズル
  - http://beet-aizu.hatenablog.com/entry/2019/10/13/235736
- Longest Shortest Path
  - https://jag-icpc.org/?plugin=attach&refer=2015%2FPractice%2F%E6%A8%A1%E6%93%AC%E5%9C%B0%E5%8C%BA%E4%BA%88%E9%81%B8%2F%E8%AC%9B%E8%A9%95&openfile=J.pdf
  - http://tokoharuland.hateblo.jp/entry/2015/11/22/221920


## ToDo

- http://topcoder.g.hatena.ne.jp/Mi_Sawa/20140311
- http://topcoder.g.hatena.ne.jp/Mi_Sawa/20140319
- http://topcoder.g.hatena.ne.jp/Mi_Sawa/20140320
- 単体法 (simplex method): 線形計画問題を解くアルゴリズムの一種である．
  - https://www.hamayanhamayan.com/entry/2017/05/31/131424
  - https://github.com/spaghetti-source/algorithm/blob/master/math/SimplexMethodLP.cc
  - http://www.prefield.com/algorithm/math/two_stage_simplex.html
  - https://www.mk-mode.com/blog/2014/02/21/cpp-linear-programming-by-simplex/#
  - https://yukicoder.me/submissions/53246
