contar([],0).

contar([_|R], N):-
	contar(R, N1),
	N is 1 + N1.


soma([],0).
soma([C|R], N):-
	soma(R, N1),
	N is C + N1.

procura([X|_],X).
procura([_|R],X):-
	procura(R, X).

inserir(X,L,[X|L]).

concatena([],L,L).
concatena([C|T],L,L1):-
	concatena(T,L,L2),
	L1 = [C|L2].


remove(X,[],[]).
remove(X,[X|R]).
remove(X,[C|R],)