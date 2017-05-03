binario(0).

binario(N):-
	R is N mod 2,
	N1 is N // 2,
	binario(N1),
	write(R).

	