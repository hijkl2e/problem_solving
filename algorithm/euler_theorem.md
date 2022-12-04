# Euler's theorem

## Summary

$$
\large
\gcd(a,n)=1\implies a^{\phi(n)}\equiv1\pmod{n}
$$

## Proof

$$
\large
\eqalign{
S&=\lbrace k:1\le k\le n\ \wedge\ \gcd(n,k)=1\rbrace\\
&=\lbrace c_1,\ c_2,\ \ldots,\ c_{\phi(n)}\rbrace\\
}
$$

$$
\large
aS=\lbrace ac_1,\ ac_2,\ \ldots,\ ac_{\phi(n)}\rbrace
$$

### Step 1. $\forall\ i,\ (ac_i\bmod n)\in S$

#### Assumption

$$
\large
(ac_i\bmod n)\notin S
$$

$$
\large
\gcd(n,ac_i\bmod n)>1
$$

#### Contradiction

$$
\large
\because\ \gcd(a,n)=\gcd(c_i,n)=1
$$

$$
\large
\gcd(ac_i,n)=\gcd(n,ac_i\bmod n)=1
$$

#### Conclusion

$$
\large
\forall\ i,\ (ac_i\bmod n)\in S
$$

### Step 2. $S\equiv aS\pmod{n}$

#### Assumption

$$
\large
ac_i\equiv ac_j\pmod{n}
$$

$$
\large
n\mid(ac_j-ac_i)\qquad\text{for }i< j
$$

#### Contradiction

$$
\large
ac_j-ac_i=a(c_j-c_i)
$$

$$
\large
\because\ \gcd(a,n)=1\ \wedge\ 0< c_j-c_i< n
$$

$$
\large
n\not\mid(ac_j-ac_i)
$$

#### Conclusion

$$
\large
S\equiv aS\pmod{n}
$$

### Step 3. $a^{\phi(n)}\equiv1\pmod{n}$

$$
\large
\because\ S\equiv aS\pmod{n}
$$

$$
\large
\prod_{k=1}^{\phi(n)}c_k\equiv\prod_{k=1}^{\phi(n)}ac_k=a^{\phi(n)}\prod_{k=1}^{\phi(n)}c_k\pmod{n}
$$

$$
\large
\therefore\ a^{\phi(n)}\equiv1\pmod{n}
$$

### Conclusion

$$
\large
\gcd(a,n)=1\implies a^{\phi(n)}\equiv1\pmod{n}
$$

***

## Corollary

$$
\large
a^{\phi(n)}\equiv a^{2\phi(n)}\pmod{n}
$$

## Proof

### Case 1. $\gcd(a,n)=1$

$$
\large
a^{\phi(n)}\equiv1\equiv a^{2\phi(n)}\pmod{n}
$$

### Case 2. $n=p^k\ \wedge\ \phi(p)=p-1$

$$
\large
\eqalign{
a^{\phi(n)}&=a^{\prime\ \phi(n)}p^{k^\prime\ \phi(n)}\\
&\equiv p^{k^\prime\ \phi(p^k)}\pmod{n}\\
&=p^{k^\prime p^{k-1}(p-1)}
}
$$

$$
\large
\because\ k^\prime>0\ \wedge\ p^{k-1}\ge k
$$

$$
\large
n\mid p^{k^\prime p^{k-1}(p-1)}
$$

$$
\large
\therefore\ a^{\phi(n)}\equiv0\equiv a^{2\phi(n)}\pmod{n}
$$

### Case 3. $n=p_1^{k_1}p_2^{k_2}\cdots p_r^{k_r}$

$$
\large
\because\ \phi(p_i^{k_i})\mid\phi(n)
$$

$$
\large
a^{\phi(p_i^{k_i})}\equiv a^{\phi(n)}\equiv a^{2\phi(n)}\pmod{p_i^{k_i}}
$$

By [Chinese remainder theorem](https://en.wikipedia.org/wiki/Chinese_remainder_theorem),

$$
\large
\therefore\ a^{\phi(n)}\equiv a^{2\phi(n)}\pmod{n}
$$

### Conclusion

$$
\large
a^{\phi(n)}\equiv a^{2\phi(n)}\pmod{n}
$$

