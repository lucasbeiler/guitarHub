/** Lucas S. Beiler (https://github.com/lucassbeiler) e Gustavo Martins (https://github.com/00-000)
 *  Trabalho #1 de Algoritmos e Programação II | 2⁰ semestre de Ciência da Computação | Universidade do Vale do Itajaí
 *  Réplica de Guitar Hero feita em SDL e C++
 **/
#include "headers/funcoesGraficas.h"
#include "headers/funcoesLogicas.h"

SDL_Texture *carregaTextura(SDL_Renderer *renderizador, const char *imagem){
    SDL_Surface *surface = SDL_LoadBMP(imagem);
    SDL_Texture *textura = SDL_CreateTextureFromSurface(renderizador, surface);
    SDL_FreeSurface(surface);

    return textura;
}

SDL_Texture *carregaTextura(SDL_Renderer *renderizador, const char *texto, const char *fonte, SDL_Color cor, int tamanhoFonte){
    TTF_Font* ttf = TTF_OpenFont(fonte, tamanhoFonte);
    SDL_Surface *surface = TTF_RenderText_Solid(ttf, texto, cor);
    SDL_Texture *textura = SDL_CreateTextureFromSurface(renderizador, surface);
    SDL_FreeSurface(surface);

    return textura;
}

void desenhaNota(musica m, int indice, int idCor, int duracaoNota){

}
