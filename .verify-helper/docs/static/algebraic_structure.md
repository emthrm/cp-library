# 代数的構造 (algebraic structure)


### アーベル群 (abelian group)

二項演算 $+$ が定義されている集合 $G$ に対して $a, b, c \in G$ とおくと

- 結合法則 $a + (b + c) = (a + b) + c$，
- 単位元（零元）の存在 $\exists 0,\ a + 0 = 0 + a = a$，
- 逆元（反数）の存在 $\forall a,\ \exists {-a},\ a + (-a) = (-a) + a = 0$，
- 交換法則 $a + b = b + a$

を満たす $(G, +)$，すなわち群演算が可換な群である．


### 帯 (band)

二項演算 $\cdot$ が定義されている集合 $S$ に対して $a, b, c \in G$ とおくと

- 結合律 $(a \cdot b) \cdot c = a \cdot (b \cdot c)$，
- 冪等律 $a \cdot a = a$

を満たす $(S, \cdot)$，すなわち冪等律を満たす半群である．


### 可換環 (commutative ring)

- 可換律 $\forall a, b \in R,\ a \cdot b = b \cdot a$

を満たす環 $R$，すなわち乗法が可換な環である．


### 交わり半束 (meet-semilattice)

二項演算 $\land$ が定義されている集合 $S$ に対して $a, b, c \in S$ とおくと

- associativity $(a \land b) \land c = a \land (b \land c)$，
- commutativity $a \land b = b \land a$，
- idempotency $a \land a = a$

を満たす $(S, \land)$ である．


### 単位的半群 (monoid)

二項演算 $\cdot$ が定義されている集合 $S$ に対して

- 結合律 $\forall a, b, c \in S,\ (a \cdot b) \cdot c = a \cdot (b \cdot c)$，
- 単位元の存在 $\forall a \in S,\ \exists e \in S,\ a \cdot e = e \cdot a = a$

を満たす $(S, \cdot, e)$ である．

e.g. $(\mathbb{Z}, +, 0), (\mathbb{R}, \ast, 1)$


### 半環 (semi-ring / rig)

以下を満たすような加法 $+$ と乗法 $\cdot$ が定義された集合 $R$ である．

- $(R, +, 0)$ は可換モノイドである．
- $(R, \cdot, 1)$ はモノイドである．
- 分配法則 $\forall a, b, c \in R,\ a \cdot (b + c) = (a \cdot b) + (a \cdot c),\ (a + b) \cdot c = (a \cdot c) + (b \cdot c)$
- 零元の存在 $\exists 0,\ a \cdot 0 = 0 \cdot a = 0$

e.g. $(\mathbb{N}, \oplus, \land, 0, \text{0xFFFF...})$


### 半群 (semigroup)

二項演算 $\cdot$ が定義されている集合 $S$ に対して

- 結合律 $\forall a, b, c \in S,\ (a \cdot b) \cdot c = a \cdot (b \cdot c)$

を満たす $(S, \cdot)$ である．


## 参考文献

アーベル群
- https://ja.wikipedia.org/wiki/%E3%82%A2%E3%83%BC%E3%83%99%E3%83%AB%E7%BE%A4

帯
- https://en.wikipedia.org/wiki/Band_(algebra)

可換環
- https://ja.wikipedia.org/wiki/%E5%8F%AF%E6%8F%9B%E7%92%B0

交わり半束
- http://koba-e964.hatenablog.com/entry/2016/12/14/214132
- https://en.wikipedia.org/wiki/Semilattice

単位的半群
- http://koba-e964.hatenablog.com/entry/2016/12/14/214132
- https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89
- ~~http://beet-aizu.hatenablog.com/entry/2017/09/10/132258~~

半環
- https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%92%B0
- https://www.slideshare.net/chokudai/abc009

半群
- https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%BE%A4

群
- https://hackmd.io/@koboshi/H1li1wPlF


## TODO

- 半群の区間クエリ
  - https://qiita.com/convexineq/items/4b6920af3e3d37a96540#%E5%8C%BA%E9%96%93%E3%81%AB%E8%BE%BA%E3%82%92%E5%BC%B5%E3%82%8B%E3%83%86%E3%82%AF
