soma(X, Y, Z):-Z is X+Y.


fatorial(0,1).
fatorial(X, Y):-
	X1 is X-1,
	fatorial(X1,Y1),
	Y is X *Y1.

somarec(0,0).
somarec(X, Y):-
	X1 is X mod 10,
	X2 is X // 10,
	somarec(X2, Y1),
	Y is X1 + Y1.