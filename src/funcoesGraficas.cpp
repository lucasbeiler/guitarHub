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

void desenhaNota(SDL_Texture *textura, int idCor, int idadeNota, int alturaTela, int larguraTela, SDL_Renderer* renderizador, SDL_Rect recorteNota, struct musica *m){
    double nIdadeNota = pow(idadeNota,1.9);
    SDL_Rect rect;
    rect.h = alturaTela * 0.01 + 0.0001 * nIdadeNota;
    rect.w = larguraTela * 0.01 + 0.00015 * nIdadeNota;
    rect.x = larguraTela * 0.50 - rect.w/2 + 25*(idCor-2) + (idCor-2)*0.00017*nIdadeNota;
    rect.y = alturaTela * 0.32 + nIdadeNota*0.0008;
    SDL_RenderCopy(renderizador, textura, &recorteNota, &rect);

    if(rect.y >= 660){
        m->notaAtual++;
    }
}
