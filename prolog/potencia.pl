potencia(_, 0, 1).
potencia(X, Y, R):-
	Y1 is Y-1,
	potencia(X, Y1, R1),
	R is X * R1.
