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

using namespace std;

char menu(SDL_Renderer *renderizador){
    char escolha = '1'; // escolha setada como 1 para que, por enquanto, o menu seja ignorado.
    SDL_Point mouse;
    SDL_Texture *jogar = carregaTextura(renderizador, "Jogar", "res/fonte.ttf", {255, 255, 255}, 30);
    SDL_Texture *creditos = carregaTextura(renderizador, "Equipe", "res/fonte.ttf", {255, 255, 255}, 20);
    SDL_Texture *sair = carregaTextura(renderizador, "Sair", "res/fonte.ttf", {255, 255, 255}, 20);

    SDL_Rect jogarPos = {obtemResolucaoTela().w/4, obtemResolucaoTela().h/4, obtemResolucaoTela().w/8, obtemResolucaoTela().h/8};
    SDL_Rect creditosPos = {obtemResolucaoTela().w/2, obtemResolucaoTela().h/2-100, obtemResolucaoTela().w/8, obtemResolucaoTela().h/8};
    SDL_Rect sairPos = {obtemResolucaoTela().w/4, obtemResolucaoTela().h/4+300, obtemResolucaoTela().w/8, obtemResolucaoTela().h/8};
    while(escolha == '0'){
        cout << "Mouse X:" << obtemPosicaoMouse(mouse).x << endl << obtemPosicaoMouse(mouse).y << endl;

        SDL_RenderCopy(renderizador, jogar, NULL, &jogarPos);
        SDL_RenderCopy(renderizador, creditos, NULL, &creditosPos);
        SDL_RenderCopy(renderizador, sair, NULL, &sairPos);
        SDL_RenderPresent(renderizador);
        SDL_RenderClear(renderizador);
    }

    return escolha;
}

int main(void){
    musica m;

    //SDL_Point mouse;

   // cout << obterPosicaoMouse(mouse);
    leChart(m);
    char *pontuacaoChar;
    bool fim = false, pause = false;
    int velocidades[4] = {4, 4, 4, 4}, pontuacaoInt = 100;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 || TTF_Init() < 0){
        cout << SDL_GetError() << endl;
    }

    const int alturaTela = 720, larguraTela = 1280;

    // inicializa janela e renderizador.
    SDL_Window* janela = SDL_CreateWindow("GuitarHub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, larguraTela, alturaTela, 0);
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

    //SDL_RenderSetLogicalSize(renderizador, larguraTela, alturaTela);
    if(menu(renderizador) == '1'){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); // inicializa o subsistema de áudio.

    Mix_Music *musica = Mix_LoadMUS("res/DragonForce-OnceInALifetime.mp3"); // carrega a música.
    SDL_Texture *notas = carregaTextura(renderizador, "res/notas.bmp");
    SDL_Texture *botoes = carregaTextura(renderizador, "res/pontos.bmp"); // aplica a superfície de pontos.bmp à textura.
    SDL_Texture *caminho = carregaTextura(renderizador, "res/caminho.bmp");
    SDL_Texture *rastroVerde = carregaTextura(renderizador, "res/greenTrail.bmp");

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

    //SDL_Rect recorteFogo = {767, 44, 179, 255};

    SDL_Rect caminhoRetangulo = {0, 0, larguraTela, alturaTela};

    SDL_Rect pontuacaoTexto = {600, 0, 100, 50};
    SDL_Rect pontuacaoNum = {700, 0, 40, 50};
    SDL_Texture *pontuacaoTextura = carregaTextura(renderizador, "Score", "res/fonte.ttf", {255, 255, 255}, 20);

    int inicioNota = 0, idadeNota = 0;

    SDL_Rect recortesNotas[] = {recorteNotaVerde, recorteNotaVermelha, recorteNotaAmarela, recorteNotaAzul, recorteNotaLaranjada};
    
    //Mix_PlayMusic(musica, 0); // inicia a música.
    int indice = 0;
    while(!fim){
        if(m.tempoNota[indice] <= SDL_GetTicks()){
                inicioNota = SDL_GetTicks();
                indice++;
        }
        
	// função abaixo desenha as notas caindo, mas com um bug: elas só caem até metade da tela.


       // desenhaRastro(rastroVerde, m.idCor[indice], m.duracaoNota[indice], SDL_GetTicks() - inicioNota, 0, renderizador, alturaTela, larguraTela, notaVerde);

        SDL_RenderCopy(renderizador, caminho, NULL, &caminhoRetangulo);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoVerde, &botaoVerde);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoVermelho, &botaoVermelho);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoAmarelo, &botaoAmarelo);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoAzul, &botaoAzul);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoLaranjado, &botaoLaranjado);

        desenhaNota(notas, m.idCor[indice], SDL_GetTicks() - inicioNota, alturaTela, larguraTela, renderizador, recortesNotas[m.idCor[indice]]);

        SDL_RenderPresent(renderizador);
        SDL_RenderClear(renderizador);

        //SDL_Delay(1000/120);
    }
    encerraPrograma(renderizador, janela, musica); // executa o encerramento quando o loop é quebrado.
}
}

