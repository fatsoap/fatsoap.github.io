/* python big integer */
s = input()
a = int(s.split())
b = int(s.split())



/* prime */
//160ms , 2*10e7 time complexity
int N = 10000000; //10e7 prime
static bool notPrime[10000000] = { 1, 1 };	
int SQRT = sqrt(N);
for (int i = 2; i <= SQRT; i++)
	if (!notPrime[i])
		for (int j = i << 1; j < N; j += i)
			notPrime[j] = true;
			
/* Number theory*/
Goldbach’s Conjecture : 大於等於四的整數可以由兩個質數相加而成