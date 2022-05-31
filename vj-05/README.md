// predložak funkcije koja prima više od dva argumenta
```
template <class T1, class T2, class... TOstali>
auto suma(T1 a, T2 b, TOstali... ostali) {
    return a + suma(b, ostali...);
}
```
// "izlazni" predložak koji prima točno dva argumenta
```
template <class T1, class T2>
auto suma(T1 a, T2 b) {
   return a + b;
}
```

