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
// podržano u C++17 standardu
```
template <class... T>
auto suma(const T&... argumenti){
    return (argumenti + ...);
}
```
//ispis beskonacno args
```
template<class T1>
void mojPrint(T1 prvi) {
	cout << prvi;
}

template<class T1,class... Tostali>
void mojPrint(T1 prvi, Tostali... ostali) {
	mojPrint(ostali...);
	cout << prvi;
}

