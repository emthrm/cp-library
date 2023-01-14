# バイナリ行列

有限体 $\mathbb{F}_2$ 上の行列である。


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`BinaryMatrix<N>(m, n = N, def = false)`|初期値 $\mathrm{def}$ の $M \times N$ 型バイナリ行列|
|`nrow()`|$M$|
|`ncol()`|$N$|
|`pow(exponent)`|$A^\mathrm{exponent}$|
|`operator()[i]`|$A$ の $i$ 行目|
|`operator=(x)`|代入|
|`operator+=(x)`<br>`operator+(x)`|加算|
|`operator+=(*)`<br>`operator+(*)`|乗算|

### [ガウス・ジョルダンの消去法](../gauss_jordan.md)

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`gauss_jordan(&a, 拡大係数行列か? = false)`|行列 $A$ のランク|$A$ は行階段形に変形される。|

### [連立一次方程式](../linear_equation.md)

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`linear_equation(a, b)`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$|解なしのときは空配列となる。|

### [逆行列](../inverse_matrix.md)

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`inverse(a)`|行列 $A$ の逆行列|存在しないときは空行列となる。|


## 参考文献

- http://drken1215.hatenablog.com/entry/2019/03/20/202800
- https://atcoder.jp/contests/utpc2014/submissions/428573


## Submissons

- [行列累乗](https://atcoder.jp/contests/utpc2014/submissions/9308568)
- [ガウス・ジョルダンの消去法](https://yukicoder.me/submissions/414183)
- [連立一次方程式](https://yukicoder.me/submissions/626481)
- [逆行列](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2624/review/4088806/emthrm/C++14)
