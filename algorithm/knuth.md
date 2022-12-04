# Knuth's Optimization

## Summary

$$
\large
\text{dp}(i,j)=\min_{i< k< j}\lbrace\text{dp}(i,k)+\text{dp}(k,j)\rbrace+\text{cost}(i,j)
$$

$$
\large
\text{opt}(i,j)=\mathop{\arg\min}_{i< j< k}\lbrace\text{dp}(i,k)+\text{dp}(k,j)\rbrace
$$

$$
\large
\forall\ a< b< c< d,\ \text{cost}(a,c)+\text{cost}(b,d)\le\text{cost}(a,d)+\text{cost}(b,c)
\implies\text{opt}(i,j-1)\le\text{opt}(i,j)\le\text{opt}(i+1,j)
$$

## Proof

Hanc marginis exiguitas non caperet.
