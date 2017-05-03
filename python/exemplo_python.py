# estruturas

filme = {
	nome,
	ano,
	diretor,
	autores
}

autor = {
	nome,
	filmes
}

lista_filmes = {
	filme
}

lista_autores = {
	autor
}

lista_filme_autor = {
	autor
}

lista_autor_filme = {
	filme
}

# inicio

lista_filme = []
lista_autores = []

while (not final_linha):
	filme = {}
	for item in linha:
		if item.index() == 0 
			filme['nome'] = item
		elif item.index() == 1:
			filme['ano'] = item
		elif item.index() == 2:
			filme['diretor'] == item
		else:
			if item not in lista_autores:
				lista_autor_filme = []
				lista_autor_filme.append(filme)
				autor = {
					'nome': item,
					'filme': lista_autor_filme
				}
				lista_autores.append(autor)
			else:
				lista_autores[item][lista_autores].append(filme)

			lista_filme_autor.append(autor)
		filme['autores'] = lista_filme_autor
		lista_filmes.append(filme)