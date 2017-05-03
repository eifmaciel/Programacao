fun a(n) = if n=1 then
                10
            else a(n–1) + 10;

fun petencia(x, y) = if y=0 then
                    1
                else x * potencia(x, y-1);

fun c(n) = if n=1 then
                1
            else c(n – 1) + potencia(n, 2);

fun d(n) = if n=1 then
                2
            else if(n=2) then
                2
            else 2 * d(n-1) + d(n-2);

fun b(n) = if n=1 then
                2
            else if (n=2) then
                2
            else b(n-1)/2 +b(n-2)*3;
