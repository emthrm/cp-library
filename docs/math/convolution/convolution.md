- 添え字 and での畳み込み

  $$C_k = \sum_{k = i \land j} A_i B_j \text{．}$$

- 添え字 or での畳み込み

  $$C_k = \sum_{k = i \lor j} A_i B_j \text{．}$$

- 添え字 xor での畳み込み

  $$C_k = \sum_{k = i \oplus j} A_i B_j \text{．}$$

- 添え字 gcd での畳み込み

  $$C_k = \sum_{k = \gcd(i, j)} A_i B_j \text{．}$$

添え字 xor での畳み込みには「高速ウォルシュ・アダマール変換 (fast Walsh-Hadamard transform)」を用いる．


## 時間計算量

$O(N\log{N})$


## 使用法

- 添え字 and での畳み込み

||説明|
|:--:|:--:|
|`and_convolution(a, b, 単位元 = 0)`|$A, B$ に対する添え字 and での畳み込み|

- 添え字 or での畳み込み

||説明|
|:--:|:--:|
|`or_convolution(a, b, 単位元 = 0)`|$A, B$ に対する添え字 or での畳み込み|

- 添え字 xor での畳み込み

||説明|
|:--:|:--:|
|`xor_convolution(a, b, 単位元 = 0)`|$A, B$ に対する添え字 xor での畳み込み|

- 添え字 gcd での畳み込み

||説明|
|:--:|:--:|
|`gcd_convolution(a, b)`|$A, B$ に対する添え字 gcd での畳み込み|


## 参考

- https://codeforces.com/blog/entry/48417
- https://aprilganmo.hatenablog.com/entry/2020/07/24/190816
- http://kazuma8128.hatenablog.com/entry/2018/05/31/144519
- https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform
- 添え字 gcd での畳み込み
  - https://noshi91.hatenablog.com/entry/2019/09/23/002445


## ToDo

- https://noshi91.hatenablog.com/entry/2020/10/27/175112
- 添え字 gcd での畳み込みを $O(N\log{\log{N}})$ に高速化する．
  - http://noshi91.hatenablog.com/entry/2018/12/27/121649
  - https://github.com/drken1215/algorithm/blob/master/MathAlgebra/fast_gcd_convolution.cpp


## Verified

- [添え字 and での畳み込み](https://judge.yosupo.jp/submission/32176)
- 添え字 or での畳み込み
- [添え字 xor での畳み込み](https://judge.yosupo.jp/submission/32459)
- [添え字 gcd での畳み込み](https://atcoder.jp/contests/agc038/submissions/9311349)
