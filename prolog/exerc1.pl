nasceu(joao, pelotas).
nasceu(jean, paris).
fica(pelotas, rs).
fica(paris, franca).

gaucho(X):-
	nasceu(X, Y),
	fica(Y, rs).