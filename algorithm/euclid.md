# 유클리드 알고리즘 관련 정리

## Theorem 1. $a,b\ne0\implies\gcd(a,b)=\min\lbrace ax+by:x,y\in\mathbb{Z}\ \wedge\ ax+by>0\rbrace$

## Proof

$$
\large
s=\min\lbrace ax+by\mid x,y\in\mathbb{Z}\ \wedge\ ax+by>0\rbrace
$$

### Step 1. $s\mid a$

$$
\large
q=\left\lfloor\frac{a}{s}\right\rfloor
$$

$$
\large
\eqalign{
a\bmod s&=a-qs\\
&=a-q(ax+by)\\
&=a(1-qx)+b(-qy)\\
}
$$

$$
\large
\because\ 0\le a\bmod s< s\ \wedge\ s=\min\lbrace ax+by\mid\ldots\rbrace
$$

$$
\large
a\bmod s=0
$$

$$
\large
\therefore\ s\mid a
$$

### Step 2. $s\mid b$

Hanc marginis exiguitas non caperet.

### Step 3. $\gcd(a,b)\ge s$

$$
\large
\because\ s\mid a\ \wedge\ s\mid b
$$

### Step 4. $\gcd(a,b)\mid s$

$$
\large
\because\ \gcd(a,b)\mid a\ \wedge\ \gcd(a,b)\mid b\ \wedge\ s=ax+by
$$

### Step 5. $\gcd(a,b)\le s$

$$
\large
\because\ \gcd(a,b)\mid s\ \wedge\ s>0
$$

### Step 6. $\gcd(a,b)=s$

$$
\large
\because\ \gcd(a,b)\ge s\ \wedge\ \gcd(a,b)\le s
$$

### Conclusion

$$
\large
a,b\ne0\implies\gcd(a,b)=\min\lbrace ax+by:x,y\in\mathbb{Z}\ \wedge\ ax+by>0\rbrace
$$

***

## Theorem 2. $a\ge0\ \wedge\ b>0\implies\gcd(a,b)=\gcd(b,a\bmod b)$

## Proof

### Step 1. $\gcd(a,b)\mid(a\bmod b)$

$$
\large
\because\ \gcd(a,b)\mid a\ \wedge\ \gcd(a,b)\mid b\ \wedge\ a\bmod b=a-\left\lfloor\frac{a}{b}\right\rfloor b
$$

### Step 2. $\gcd(a,b)\mid\gcd(b,a\bmod b)$

$$
\large
\because\ \gcd(a,b)\mid b\ \wedge\ \gcd(a,b)\mid(a\bmod b)
$$

### Step 3. $\gcd(b,a\bmod b)\mid a$

$$
\large
\because\ \gcd(b,a\bmod b)\mid b\ \wedge\ \gcd(b,a\bmod b)\mid(a\bmod b)
\ \wedge\ a=\left\lfloor\frac{a}{b}\right\rfloor b+(a\bmod b)
$$

### Step 4. $\gcd(b,a\bmod b)\mid\gcd(a,b)$

$$
\large
\because\ \gcd(b,a\bmod b)\mid a\ \wedge\ \gcd(b,a\bmod b)\mid b
$$

### Step 5. $\gcd(a,b)=\gcd(b,a\bmod b)$

$$
\large
\because\ \gcd(a,b)\mid\gcd(b,a\bmod b)\ \wedge\ \gcd(b,a\bmod b)\mid\gcd(a,b)
$$

### Conclusion

$$
\large
a\ge0\ \wedge\ b>0\implies\gcd(a,b)=\gcd(b,a\bmod b)
$$

***

## Theorem 3. $a>b\ge1\ \wedge\ \mathrm{EUCLID}(a,b)=k\implies b\ge F_{k+1}\quad(k\ge1)$

## Proof

### Base case

$$
\large
b\ge1=F_2
$$

$$
\large
\eqalign{
\mathrm{EUCLID}(a,b)=2&\implies b\ne1\\
&\implies b\ge2=F_3\\
}
$$

### Induction step

$$
\large
\eqalign{
a&=\left\lfloor\frac{a}{b}\right\rfloor b+(a\bmod b)\\
&\ge b+(a\bmod b)\\
}
$$

$$
\large
\because\ b\ge F_{k+1}\ \wedge\ (a\bmod b)\ge F_k
$$

$$
\large
\eqalign{
a&\ge b+(a\bmod b)\\
&\ge F_{k+1}+F_k=F_{k+2}\\
}
$$

### Conclusion

$$
\large
a>b\ge1\ \wedge\ \mathrm{EUCLID}(a,b)=k\implies b\ge F_{k+1}\quad(k\ge1)
$$

***

## Theorem 4. $a>b\ge1\ \wedge\ b< F_{k+1}\implies\mathrm{EUCLID}(a,b)< k\quad(k\ge2)$

## Proof

### Assumption

$$
\large
\mathrm{EUCLID}(a,b)\ge k
$$

### Contradiction

$$
\large
a>b\ge1\ \wedge\ \mathrm{EUCLID}(a,b)\ge k\implies b\ge F_{k+1}
$$

### Conclusion

$$
\large
a>b\ge1\ \wedge\ b< F_{k+1}\implies\mathrm{EUCLID}(a,b)< k\quad(k\ge2)
$$

***

## Theorem 5. $a>b\ge1\implies\mathrm{EUCLID}(a,b)\le\log_\phi{\dfrac{b}{\gcd(a,b)}}+1=O\left(\log_\phi{\dfrac{b}{\gcd(a,b)}}\right)$

## Proof

### Step 1. $\exists\ k\ge2,\ F_k\le b< F_{k+1}$

Hanc marginis exiguitas non caperet.

### Step 2. $\mathrm{EUCLID}(a,b)\le k-1$

$$
\large
\because\ b< F_{k+1}\implies\mathrm{EUCLID}(a,b)< k
$$

### Step 3. $k\le\log_\phi\left(b\sqrt{5}+\hat{\phi}^k\right)$

$$
\large
F_k\le b
$$

$$
\large
\frac{\phi^k-\hat{\phi}^k}{\sqrt{5}}\le b
$$

$$
\large
\phi^k\le b\sqrt{5}+\hat{\phi}^k
$$

$$
\large
\therefore\ k\le\log_\phi\left(b\sqrt{5}+\hat{\phi}^k\right)
$$

### Step 4. $\max\left(\log_\phi\left(b\sqrt{5}+\hat{\phi}^k\right)-\log_\phi{b}\right)=2$

$$
\large
\eqalign{
\max\left(\log_\phi\left(b\sqrt{5}+\hat{\phi}^k\right)-\log_\phi{b}\right)
&=\max\left(\log_\phi\left(\sqrt{5}+\frac{\hat{\phi}^k}{b}\right)\right)\\
&=\log_\phi\left(\sqrt{5}+\hat{\phi}^2\right)\\
&=\log_\phi\left(\sqrt{5}+\left(\frac{1-\sqrt{5}}{2}\right)^2\right)\\
&=\log_\phi\left(\frac{1+\sqrt{5}}{2}\right)^2\\
&=\log_\phi\phi^2=2\\
}
$$

### Step 5. $k\le\log_\phi{b}+2$

$$
\large
\because\ k\le\log_\phi\left(b\sqrt{5}+\hat{\phi}^k\right)
\ \wedge\ \max\left(\log_\phi\left(b\sqrt{5}+\hat{\phi}^k\right)-\log_\phi{b}\right)=2
$$

### Step 6. $\mathrm{EUCLID}(a,b)\le\log_\phi{b}+1$

$$
\large
\because\ \mathrm{EUCLID}(a,b)\le k-1\ \wedge\ k\le\log_\phi{b}+2
$$

### Step 7. $d\mid a\ \wedge\ d\mid b\implies a\bmod b=d\left(\dfrac{a}{d}\bmod\dfrac{b}{d}\right)$

$$
\large
a\bmod b=a-\left\lfloor\frac{a}{b}\right\rfloor b
$$

$$
\large
\frac{a}{d}\bmod\frac{b}{d}=\frac{a}{d}-\left\lfloor\frac{a}{b}\right\rfloor\frac{b}{d}
$$

$$
\large
d\left(\frac{a}{d}\bmod\frac{b}{d}\right)=a-\left\lfloor\frac{a}{b}\right\rfloor b=a\bmod b
$$

$$
\large
\therefore\ a\bmod b=d\left(\frac{a}{d}\bmod\frac{b}{d}\right)
$$

### Step 8. $\mathrm{EUCLID}(a,b)=\mathrm{EUCLID}\left(\dfrac{a}{\gcd(a,b)},\dfrac{b}{\gcd(a,b)}\right)$

$$
\large
\because\ a\bmod b=d\left(\frac{a}{d}\bmod\frac{b}{d}\right)
$$

### Step 9. $\mathrm{EUCLID}(a,b)\le\log_\phi{\dfrac{b}{\gcd(a,b)}}+1=O\left(\log_\phi{\dfrac{b}{\gcd(a,b)}}\right)$

$$
\large
\because\ \mathrm{EUCLID}(a,b)=\mathrm{EUCLID}\left(\frac{a}{\gcd(a,b)},\frac{b}{\gcd(a,b)}\right)
\le\log_\phi{\frac{b}{\gcd(a,b)}}+1=O\left(\log_\phi{\frac{b}{\gcd(a,b)}}\right)
$$

### Conclusion

$$
\large
a>b\ge1\implies\mathrm{EUCLID}(a,b)\le\log_\phi{\frac{b}{\gcd(a,b)}}+1=O\left(\log_\phi{\frac{b}{\gcd(a,b)}}\right)
$$

***

## Theorem 6. $\gcd(b,a\bmod b)=bx+(a\bmod b)y\implies\gcd(a,b)=ay+b\left(x-\left\lfloor\dfrac{a}{b}\right\rfloor y\right)$

## Proof

$$
\large
\gcd(a,b)=ax^\prime+by^\prime
$$

### Step 1. $ax^\prime+by^\prime=bx+(a\bmod b)y$

$$
\large
\because\ \gcd(a,b)=\gcd(b,a\bmod b)
$$

### Step 2. $x^\prime=y\ \wedge\ y^\prime=x-\left\lfloor\dfrac{a}{b}\right\rfloor y$

$$
\large
\eqalign{
ax^\prime+by^\prime&=bx+(a\bmod b)y\\
&=bx+\left(a-\left\lfloor\frac{a}{b}\right\rfloor b\right)y\\
&=ay+b\left(x-\left\lfloor\frac{a}{b}\right\rfloor y\right)\\
}
$$

$$
\large
\therefore\ x^\prime=y\ \wedge\ y^\prime=x-\left\lfloor\frac{a}{b}\right\rfloor y
$$

### Conclusion

$$
\large
\gcd(b,a\bmod b)=bx+(a\bmod b)y\implies\gcd(a,b)=ay+b\left(x-\left\lfloor\frac{a}{b}\right\rfloor y\right)
$$

***

## Theorem 7. $ax_1+by_1=ax_2+by_2\implies x_2=x_1+k\dfrac{b}{\gcd(a,b)}\ \wedge\ y_2=y_1-k\dfrac{a}{\gcd(a,b)}\quad(k\in\mathbb{Z})$

## Proof

### Step 1. $x_2=x_1+k\dfrac{b}{\gcd(a,b)}$

$$
\large
ax_1+by_1=ax_2+by_2
$$

$$
\large
a(x_1-x_2)=b(y_2-y_1)
$$

$$
\large
\frac{a}{\gcd(a,b)}(x_1-x_2)=\frac{b}{\gcd(a,b)}(y_2-y_1)
$$

$$
\large
\because\ \gcd\left(\frac{a}{\gcd(a,b)},\frac{b}{\gcd(a,b)}\right)=1
$$

$$
\large
(x_1-x_2)\mid\frac{b}{\gcd(a,b)}
$$

$$
\large
\therefore\ x_2=x_1+k\frac{b}{\gcd(a,b)}
$$

### Step 2. $y_2=y_1-k\dfrac{a}{\gcd(a,b)}$

$$
\large
\eqalign{
b(y_2-y_1)&=a(x_1-x_2)\\
&=-k\frac{ab}{\gcd(a,b)}\\
}
$$

$$
\large
y_2-y_1=-k\frac{a}{\gcd(a,b)}
$$

$$
\large
\therefore\ y_2=y_1-k\frac{a}{\gcd(a,b)}
$$

### Conclusion

$$
\large
ax_1+by_1=ax_2+by_2\implies x_2=x_1+k\frac{b}{\gcd(a,b)}\ \wedge\ y_2=y_1-k\frac{a}{\gcd(a,b)}\quad(k\in\mathbb{Z})
$$
