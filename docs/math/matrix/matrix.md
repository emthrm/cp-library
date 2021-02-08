---
title: 行列 (matrix)
documentation_of: math/matrix/matrix.hpp
---


### 行列累乗

繰り返し二乗法を用いて行列の積を求めるアルゴリズムである．


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|加算|$O(MN)$|
|減算|$O(MN)$|
|乗算|$O(N^3)$|
|行列累乗|$O(N^3 \log{M})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Matrix<T>(m, n, val = 0)`|初期値 $\mathrm{val}$ の $M \times N$ 型行列||
|`height()`|行の数||
|`width()`|列の数||
|`pow(n)`|$A^n$|半環上で成立する．|
|`operator[](idx)`|$A$ の $\mathrm{idx}$ 行目||
|`operator=(x)`|代入||
|`operator+=(x)`<br>`operator+(x)`|加算||
|`operator-=(x)`<br>`operator-(x)`|減算||
|`operator*=(x)`<br>`operator*(x)`|乗算|半環上で成立する．|


## 参考

- https://ei1333.github.io/luzhiled/snippets/math/matrix.html


## ToDo

- https://github.com/eandbsoftware/libraryCPP/blob/master/!Matrix.cpp
- 疎行列 (sparse matrix)
  - https://ja.wikipedia.org/wiki/%E7%96%8E%E8%A1%8C%E5%88%97
  - https://github.com/ei1333/library/blob/master/math/sparse-matrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SparseMatrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SparseSquareMatrix.cpp
  - https://judge.yosupo.jp/problem/sparse_matrix_det
  - https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_e
- 正方行列 (square matrix)
  - https://ja.wikipedia.org/wiki/%E6%AD%A3%E6%96%B9%E8%A1%8C%E5%88%97
  - https://github.com/beet-aizu/library/blob/master/matrix/squarematrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SquareMatrix.cpp
- ウェーブレット行列 (wavelet matrix)
  - https://www.hamayanhamayan.com/entry/2017/06/13/103352
  - https://takeda25.hatenablog.jp/entry/20130303/1362301095
  - http://miti-7.hatenablog.com/entry/2018/04/28/152259
  - https://www.dropbox.com/sh/9lknvq4xay709cn/AAAX61z5W1m20MPkJ8V53l5ma/%23WaveletMatrix.cpp?dl=0
  - https://www.pandanoir.info/entry/2016/03/01/230031
  - https://github.com/MitI-7/Algorithm/wiki/%E3%82%A6%E3%82%A7%E3%83%BC%E3%83%96%E3%83%AC%E3%83%83%E3%83%88%E8%A1%8C%E5%88%97
  - https://anta1.hatenadiary.org/entry/20130114/1358113488
  - https://docs.google.com/presentation/d/1J7jl8BLHkbukicFzSP7zNYTcwF-DPevCUfVxD4VjzX0
  - https://algoogle.hadrori.jp/algorithm/wavelet.html
  - https://ei1333.github.io/algorithm/wavelet-matrix.html
  - https://ei1333.github.io/luzhiled/snippets/structure/wavelet-matrix.html
  - https://github.com/ei1333/library/tree/master/structure/wavelet
  - https://github.com/beet-aizu/library/blob/master/datastructure/waveletmatrix.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/wavelet_matrix.cc
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23WaveletMatrix.cpp
  - https://ferin-tech.hatenablog.com/entry/2019/11/09/yukicoder_No.924_%E7%B4%B2%E6%98%9F
  - https://wiki.kimiyuki.net/wavelet%20matrix
  - https://judge.yosupo.jp/problem/rectangle_sum
- ウェーブレット木
  - https://www.slideshare.net/pfi/ss-15916040
  - https://takeda25.hatenablog.jp/entry/20120804/1344066875
  - https://echizen-tm.hatenadiary.org/entry/20100822/1282489619
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23WaveletTree.cpp
  - https://jetbead.hatenablog.com/entry/20130202/1359735146
  - https://drive.google.com/file/d/1NQb6ZXrPZuWI0gNBhJUQAvONjGqFxgUX
- 固有値, 固有ベクトル
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%80%A4
  - http://www.prefield.com/algorithm/math/eigensystem.html
- ハフニアン (hafnian)
  - https://mathtrain.jp/pfaffian
  - https://en.wikipedia.org/wiki/Hafnian
  - https://github.com/yosupo06/library-checker-problems/issues/467
  - https://judge.yosupo.jp/problem/hafnian_of_matrix


## Verified

https://atcoder.jp/contests/arc050/submissions/9305863
