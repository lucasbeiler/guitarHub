**VEJA A ABA ISSUES DO PROJETO AQUI NO GITHUB PARA CONSULTAR TÓPICOS SOBRE O QUE FALTA IMPLEMENTAR NO JOGO E DISCUTIR SOBRE.**

## Instruções Gerais
* Crie um novo projeto no teu qtCreator.
* Baixe as libs **[SDL2](https://www.libsdl.org/release/SDL2-devel-2.0.10-mingw.tar.gz)**, **[SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-mingw.tar.gz)**, **[SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-mingw.tar.gz)** e as adicione ao teu projeto.
* Copie as pastas **src** e **headers** pra pasta do teu projeto.
* Copie a pasta **res** pra pasta do teu projeto e pra pasta onde o qtCreator gera os executáveis compilados.

## Adicionando as bibliotecas no qtCreator no Windows
* Vá com o botão direito do mouse no nome do teu projeto no lado esquerdo da tela do qtCreator.
* Clique na opção **Add Library**.
* Escolha **External Library** e prossiga.
* Desmarque todas as plataformas que não sejam Windows.
* Clique em **Browse...** na linha de **Library File** e selecione o arquivo .a da bibilioteca...
* ... o arquivo .a da biblioteca se encontra no local onde tu descompactou a biblioteca, lá numa pasta **lib/i686-w64-mingw32/libSDL2.a** ou **lib/x86_64-w64-mingw32/libSDL2.a** (libSDL2.a é, no caso, para selecionar a SDL2 padrão, os arquivos para as outras bibliotecas são **libSDL2_mixer.a** e **libSDL2_ttf.a**, mas adicione uma de cada vez).
* A opção **linkage** deve ser marcada como **Dynamic**.
* A opção **Add "d" suffix for debug version** deve ser **desmarcada**.
* Copie as DLLs necessárias para as pastas do executável e do código.
* Repita os passos para todas as bibliotecas necessárias.

**Os diretórios mencionados nos passos acima, lib/i686-w64-mingw32/ (para 32-bit) e lib/x86_64-w64-mingw32/ (para 64-bit), variam de acordo com a arquitetura do teu Windows**

## O JOGO (imagem antiga)
![jogo](https://i.imgur.com/TLTTVZM.gif)
