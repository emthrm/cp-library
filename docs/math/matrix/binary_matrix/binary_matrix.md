# バイナリ行列

有限体 $\mathbb{F}_2$ 上の行列である．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BinaryMatrix(m, n = COL, def = false)`|初期値 $\mathrm{def}$ の $M \times N$ 型バイナリ行列|`COL` はコンパイル時定数である．|
|`m`|行の数||
|`n`|列の数||
|`pow(n)`|$A^n$||
|`operator()[idx]`|$A$ の $\mathrm{idx}$ 行目|
|`=`, `+=`, `*=`, `+`, `*`|||

- [ガウス・ジョルダンの消去法](../gauss_jordan.md)

||説明|備考|
|:--:|:--:|:--:|
|`gauss_jordan(mat, 拡大係数行列か? = false)`|行列 $\mathrm{mat}$ のランク|$\mathrm{mat}$ は行階段形に変形される．|

- [連立一次方程式](../linear_equation.md)

||説明|備考|
|:--:|:--:|:--:|
|`linear_equation(a, b)`|$x \text{ s.t. } A \boldsymbol{x} = \boldsymbol{b}$|解なしの場合は空配列となる．|

- [逆行列](../inverse_matrix.md)

||説明|備考|
|:--:|:--:|:--:|
|`inverse(mat)`|行列 $\mathrm{mat}$ の逆行列|存在しない場合は空行列となる．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800
- https://atcoder.jp/contests/utpc2014/submissions/428573


## Verified

- [行列累乗](https://atcoder.jp/contests/utpc2014/submissions/9308568)
- [ガウス・ジョルダンの消去法](https://yukicoder.me/submissions/414183)
- [連立一次方程式](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1308/review/4088796/emthrm/C++14)
- [逆行列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2624/review/4088806/emthrm/C++14)
