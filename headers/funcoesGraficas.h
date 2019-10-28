/** Lucas S. Beiler (https://github.com/lucassbeiler) e Gustavo Martins (https://github.com/00-000)
 *  Trabalho #1 de Algoritmos e Programação II | 2⁰ semestre de Ciência da Computação | Universidade do Vale do Itajaí
 *  Réplica de Guitar Hero feita em SDL e C++
 **/
#ifndef FUNCOESGRAFICAS_H
#define FUNCOESGRAFICAS_H
#define SDL_MAIN_HANDLED
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include <sstream>
#undef main

void desenhaNota(SDL_Texture *textura, int idCor, int idadeNota, int alturaTela, int larguraTela, SDL_Renderer* renderizador, SDL_Rect recorteNota, SDL_Rect botao, int *pontuacao);
void desenhaRastro(SDL_Texture *textura, int idCor, int idadeNota, int atraso, int alturaTela, int larguraTela, SDL_Renderer* renderizador, SDL_Rect botao, int *pontuacao);
void desenhaNotas(struct musica *m, int tempoAtual, SDL_Rect todasAsNotas[], SDL_Texture *rastros[], SDL_Texture* notas, int alturaTela, int larguraTela, SDL_Renderer* renderizador);
SDL_Texture *carregaTextura(SDL_Renderer *renderizador, const char *imagem);
SDL_Texture *carregaTextura(SDL_Renderer *renderizador, const char *texto, const char *fonte, SDL_Color cor, int tamanhoFonte);

#endif // FUNCOESGRAFICAS_H
