# Euler's phi function

$$
\large
\phi(n)=|\lbrace k:1\le k\le n\ \wedge\ \gcd(n,k)=1\rbrace|
$$

## Theorem 1. $\gcd(m,n)=1\implies\phi(mn)=\phi(m)\phi(n)$

## Proof

$$
\large
A_{ij}=(i-1)n+j\qquad\text{for }1\le i\le m\ \wedge\ 1\le j\le n
$$

### Step 1. $\gcd(m,x)=\gcd(n,x)=1\iff\gcd(mn,x)=1$

Hanc marginis exiguitas non caperet.

### Step 2. $\forall\ j,\ \lbrace A_{kj}:1\le k\le m\rbrace\equiv\lbrace0,\ 1,\ \ldots,\ m-1\rbrace\pmod{m}$

#### Assumption

$$
\large
A_{k_1j}\equiv A_{k_2j}\pmod{m}
$$

$$
\large
m\mid(A_{k_2j}-A_{k_1j})\qquad\text{for }k_1< k_2
$$

#### Contradiction

$$
\large
A_{k_2j}-A_{k_1j}=(k_2-k_1)n
$$

$$
\large
\because\ 0< k_2-k_1< m\ \wedge\ \gcd(m,n)=1
$$

$$
\large
m\not\mid(A_{k_2j}-A_{k_1j})
$$

#### Conclusion

$$
\large
\forall\ j,\ \lbrace A_{kj}:1\le k\le m\rbrace\equiv\lbrace0,\ 1,\ \ldots,\ m-1\rbrace\pmod{m}
$$

### Step 3. $\phi(mn)=\phi(m)\phi(n)$

$$
\large
\eqalign{
\phi(mn)&=|\lbrace k:1\le k\le mn\ \wedge\ \gcd(mn,k)=1\rbrace|\\
&=|\lbrace A_{ij}:\gcd(mn,A_{ij})=1\rbrace|\\
&=|\lbrace A_{ij}:\gcd(m,A_{ij})=\gcd(n,A_{ij})=1\rbrace|\\
&=|\lbrace A_{ij}:\gcd(m,A_{ij}\bmod m)=\gcd(n,j)=1\rbrace|\\
&=|\lbrace i:\gcd(m,i)=1\rbrace|\times|\lbrace j:\gcd(n,j)=1\rbrace|\\
&=\phi(m)\phi(n)\\
}
$$

### Conclusion

$$
\large
\gcd(m,n)=1\implies\phi(mn)=\phi(m)\phi(n)
$$

***

## Theorem 2. $\phi(n)=n\displaystyle\prod\limits_{p\mid n}\left(1-\dfrac{1}{p}\right)$

## Proof

### Step 1. $\phi(p)=p-1\implies\phi(p^k)=p^k\left(1-\dfrac{1}{p}\right)$

$$
\large
\phi(p^k)=p^k-p^{k-1}=p^k\left(1-\frac{1}{p}\right)
$$

### Step 2. $\phi(n)=n\displaystyle\prod\limits_{p\mid n}\left(1-\dfrac{1}{p}\right)$

$$
\large
\eqalign{
\phi(n)&=\phi(p_1^{k_1})\phi(p_2^{k_2})\cdots\phi(p_r^{k_r})\\
&=p_1^{k_1}\left(1-\frac{1}{p_1}\right)p_2^{k_2}\left(1-\frac{1}{p_2}\right)\cdots p_r^{k_r}\left(1-\frac{1}{p_r}\right)\\
&=n\prod_{p\mid n}\left(1-\frac{1}{p}\right)\\
}
$$

### Conclusion

$$
\large
\phi(n)=n\prod\limits_{p\mid n}\left(1-\dfrac{1}{p}\right)
$$

