Neka je zadana sljedeća funkcija main. Napišite klasu Razlomak koja u sebi ima sve potrebne podatkovne članove i metode kako bi glavni program (funkcija main) mogla raditi kao što je to u kodu i predviđeno.
```
int main(){
	Razlomak r1(2,3), r2, r3;
	r2 = 2;  // 2/1
	r3 = r1 + r2;
	cout << r3++ << endl;	// 8/3
	cout << r3 * r1 << endl;	// 18/12
	return 0;
}
