masculino(jose).
masculino(joao).
masculino(jorge).
feminino(maria).
feminino(ana).
feminino(iris).
feminino(julia).

progenitor(maria, jose).
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, maria).
progenitor(jose, iris).
progenitor(iris, jorge).

pai(X,Y):- masculino(X), progenitor(X,Y).
mae(X, Y):- feminino(X), progenitor(X, Y).
avo(X,Y):- pai(X,Z), pai(Z,Y).
avo(X,Y):- pai(X,Z), mae(Z,Y).
avoh(X,Y):- mae(X,Z), pai(Z,Y).
avoh(X,Y):- mae(X,Z), mae(Z,Y).



