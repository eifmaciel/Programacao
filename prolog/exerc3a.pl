divrecursivo(X, Y, R):-
	X < Y,
	R is X.

divrecursivo(X, Y, R):-
	X1 is X-Y,
	divrecursivo(X1, Y, R).