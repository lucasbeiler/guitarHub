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

void desenhaNota(SDL_Texture *textura, int idCor, int idadeNota, int alturaTela, int larguraTela, SDL_Renderer* renderizador, SDL_Rect recorteNota){
    double nIdadeNota = pow(idadeNota,1.9);
    SDL_Rect rect;
    rect.h = alturaTela * 0.01 + 0.0001 * nIdadeNota;
    rect.w = larguraTela * 0.01 + 0.00015 * nIdadeNota;
    rect.x = larguraTela * 0.50 - rect.w/2 + 25*(idCor-2) + (idCor-2)*0.00017*nIdadeNota;
    rect.y = alturaTela * 0.32 + nIdadeNota*0.0008;
    SDL_RenderCopy(renderizador, textura, &recorteNota, &rect);
}

void desenhaRastro(SDL_Texture *textura, int idCor, int idadeNota, int atraso, int alturaTela, int larguraTela, SDL_Renderer* renderizador){
    double nIdadeNota = pow(idadeNota - atraso,1.7);
    SDL_Rect rect;
    rect.h = 100;
    rect.w = 44;
    rect.x = larguraTela * 0.50 - rect.w/2 + 30 * (idCor - 2) + (idCor - 2)*0.001 * nIdadeNota;
    rect.y = alturaTela * 0.32 + nIdadeNota*0.0050;
    SDL_RenderCopy(renderizador, textura, NULL, &rect);
}

void desenhaNotas(struct musica *m, int tempoAtual, SDL_Rect todasAsNotas[], SDL_Texture* rastros[],  SDL_Texture* notas, int alturaTela, int larguraTela, SDL_Renderer* renderizador){
  int notaAtual = 0;
  int idadeNota = 0;
  int idCor = 0;
  int duracaoNota = 0;
  int tempoNotaAnterior = -2000;
  int tempoNota = 0;
  int idCorAnterior = 0;
  int duracaoNotaReps = 0;
  int compensaLag = 800;

  int qtdLinhas = qtdLinhasChart("res/ElectricEye.chart");

  while(notaAtual < qtdLinhas){
    duracaoNotaReps = 0;
    idadeNota = tempoAtual - m->tempoNota[notaAtual];
    idCor = m->idCor[notaAtual];
    duracaoNota = m->duracaoNota[notaAtual];
    if(notaAtual > 0){
      idCorAnterior = m->idCor[notaAtual-1];
      tempoNotaAnterior = m->tempoNota[notaAtual-1];
      tempoNota = m->tempoNota[notaAtual];
    }

    if(idadeNota >= -compensaLag && idadeNota-duracaoNota < 1300+compensaLag){
        while(duracaoNota-duracaoNotaReps > 0){
           desenhaRastro(rastros[idCor], idCor, idadeNota-350+compensaLag, duracaoNotaReps, alturaTela, larguraTela, renderizador);
          duracaoNotaReps += 50;
        }if((tempoNota - tempoNotaAnterior) > 0 && (tempoNota-tempoNotaAnterior) < 121 && (idCor != idCorAnterior)){
          if(notaAtual >= m->notaAtual){
              desenhaNota(notas, idCor, idadeNota+compensaLag, alturaTela, larguraTela, renderizador, todasAsNotas[idCor]);
          }
        }else{
          if(notaAtual >= m->notaAtual && tempoAtual > 1000){
              desenhaNota(notas, idCor, idadeNota+compensaLag, alturaTela, larguraTela, renderizador, todasAsNotas[idCor]);
          }
        }
    }
    notaAtual++;
}
}

