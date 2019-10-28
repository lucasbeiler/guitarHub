/** Lucas S. Beiler (https://github.com/lucassbeiler) e Gustavo Martins (https://github.com/00-000)
 *  Trabalho #1 de Algoritmos e Programação II | 2⁰ semestre de Ciência da Computação | Universidade do Vale do Itajaí
 *  Réplica de Guitar Hero feita em SDL e C++
 **/
#define SDL_MAIN_HANDLED
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h> // SDL principal
#include <SDL2/SDL_ttf.h> // para fontes
#include <time.h>
#include <sstream>
#include <SDL2/SDL_mixer.h> // para áudio
#undef main

#include "headers/funcoesLogicas.h"
#include "headers/funcoesGraficas.h"
#include "headers/controles.h"

using namespace std;

int main(void){
    musica m;
    struct controle c;
    leChart(m);

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 || TTF_Init() < 0){
        cout << SDL_GetError() << endl;
    }

    const int alturaTela = 720, larguraTela = 1280;

    // inicializa janela e renderizador.
    SDL_Window* janela = SDL_CreateWindow("GuitarHub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, larguraTela, alturaTela, 0);
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

    //SDL_RenderSetLogicalSize(renderizador, larguraTela, alturaTela);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); // inicializa o subsistema de áudio.

    Mix_Chunk *guitarra = Mix_LoadWAV("res/ElectricEye-guit.ogg");
    Mix_Chunk *vocal = Mix_LoadWAV("res/ElectricEye-voc.ogg");
    SDL_Texture *notas = carregaTextura(renderizador, "res/notas.bmp");
    SDL_Texture *botoes = carregaTextura(renderizador, "res/pontos.bmp"); // aplica a superfície de pontos.bmp à textura.
    SDL_Texture *caminho = carregaTextura(renderizador, "res/caminho.bmp");

    SDL_Texture *rastroVerde = carregaTextura(renderizador, "res/rastroVerde.bmp");
    SDL_Texture *rastroVermelho = carregaTextura(renderizador, "res/rastroVermelho.bmp");
    SDL_Texture *rastroAmarelo = carregaTextura(renderizador, "res/rastroAmarelo.bmp");
    SDL_Texture *rastroAzul = carregaTextura(renderizador, "res/rastroAzul.bmp");
    SDL_Texture *rastroLaranjado = carregaTextura(renderizador, "res/rastroLaranjado.bmp");


    // retângulos referentes aos recortes dos sprites.
    SDL_Rect recorteNotaVerde = {0, 0, 119, 70};
    SDL_Rect recorteNotaVermelha = {120, 0, 119, 70};
    SDL_Rect recorteNotaAmarela = {240, 0, 119, 70};
    SDL_Rect recorteNotaAzul = {360, 0, 119, 70};
    SDL_Rect recorteNotaLaranjada = {480, 0, 119, 70};

    SDL_Rect recorteBotaoVerde = {3, 0, 129, 128};
    SDL_Rect recorteBotaoVermelho = {146, 0, 129, 128};
    SDL_Rect recorteBotaoAmarelo = {303, 0, 129, 128};
    SDL_Rect recorteBotaoAzul = {456, 0, 129, 128};
    SDL_Rect recorteBotaoLaranjado = {598, 0, 129, 128};

    SDL_Rect botaoVerde = {415, 600, 60, 50};
    SDL_Rect botaoVermelho = {515, 600, 60, 50};
    SDL_Rect botaoAmarelo = {615, 600, 60, 50};
    SDL_Rect botaoAzul = {715, 600, 60, 50};
    SDL_Rect botaoLaranjado = {815, 600, 60, 50};

    SDL_Rect caminhoRetangulo = {0, 0, larguraTela, alturaTela};

    SDL_Rect recortesNotas[] = {recorteNotaVerde, recorteNotaVermelha, recorteNotaAmarela, recorteNotaAzul, recorteNotaLaranjada};
    SDL_Texture *rastros[] = {rastroVerde, rastroVermelho, rastroAmarelo, rastroAzul, rastroLaranjado};

    Mix_PlayChannel(-1, guitarra, 0 );
    Mix_PlayChannel(-1, vocal, 0 );

    long long tempoInicioJogo = tempoMilisseg();
    int tempoAtualDeJogo = 0;
    int tempoAnteriorDeJogo = 0;
    int qtdLinhas = qtdLinhasChart("res/ElectricEye.chart");


    while(m.notaAtual < qtdLinhas){
        tempoAnteriorDeJogo = tempoAtualDeJogo;
        tempoAtualDeJogo = tempoMilisseg() - tempoInicioJogo;
        SDL_RenderCopy(renderizador, caminho, NULL, &caminhoRetangulo);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoVerde, &botaoVerde);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoVermelho, &botaoVermelho);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoAmarelo, &botaoAmarelo);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoAzul, &botaoAzul);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoLaranjado, &botaoLaranjado);

        desenhaNotas(&m, tempoAtualDeJogo, recortesNotas, rastros, notas, alturaTela, larguraTela, renderizador);
        SDL_RenderPresent(renderizador);
        SDL_RenderClear(renderizador);
    }
    }
