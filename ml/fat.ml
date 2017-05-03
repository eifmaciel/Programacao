fun fatorial (n) = if n=0 then
					1
				else n * fatorial(n-1);

fun mdc (x, y) = if (x=y) then
					x
				else if (x>y) then
					mdc(x-y, y)
				else mdc(x, y-x);

fun mult(x, y) = if y=0 then
					1
				else
					x * mult(x, y-1);

fun fat 0=1
	| fat n=n *fat(n-1);

fun constante 1=1.0
	| constante n = 1.0/real(fat(n-1)) + constante(n-1);

fun soma(lista) = if lista = [] then
					0
				else
					hd(lista) + soma(tl(lista));

fun tam(lista) = if lista = [] then
						0
				else
					1 + tam(tl(lista));
