homem('pedro III').
homem('pedro I').
homem('pedro II').
homem('joao VI').
homem('miguel').

mulher('maria I').
mulher('carlota joaquin').
mulher('leopoldina').
mulher('maria da gloria').

pai('pedro III', 'joao VI').
pai('joao VI', 'pedro I').
pai('joao VI', 'miguel').
pai('pedro I', 'maria da gloria').
pai('pedro I', 'pedro II').

mae('maria I', 'joao VI').
mae('carlota joaquin', 'miguel').
mae('leopoldina', 'maria da gloria').
mae('leopoldina', 'pedro II').

filho(X, Y):-
	homem(X),
	pai(Y, X).

filho(X, Y):-
	homem(X),
	mae(Y, X).

filha(X, Y):-
	mulher(X),
	pai(Y, X).

filha(X, Y):-
	mulher(X),
	mae(Y, X).







