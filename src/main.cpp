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
#include <windows.h>
#undef main

#include "headers/funcoesLogicas.h"
#include "headers/funcoesGraficas.h"



using namespace std;
  char escolha = '0'; // escolha setada como 1 para que, por enquanto, o menu seja ignorado.
char menu(SDL_Renderer *renderizador){


    SDL_Point mouse;
    SDL_Texture *jogar = carregaTextura(renderizador,"res/Play.bmp");
    SDL_Texture *creditos = carregaTextura(renderizador,"res/TEAM.bmp");
    SDL_Texture *sair = carregaTextura(renderizador,"res/EXIT.bmp");

    SDL_Rect jogarPos = {(1280/2)-1280/16, 100, 1280/8, 720/8};
    SDL_Rect creditosPos = {(1280/2)-1280/16, 500, 1280/8, 720/8};
    SDL_Rect sairPos = {(1280/2)-1280/16, 300, 1280/8, 720/8};

    while(escolha == '0'){

        cout<<obtemPosicaoMouse(mouse).x<< "||"<<obtemPosicaoMouse(mouse).y<<endl;
        //ERRO: quando o botão Play é apertado(escolha é setada como 1), o programa não segue pra a música, ele fecha
             SDL_Event event;
                while(SDL_PollEvent(&event)){
                   switch (event.type) {
                   case SDL_MOUSEBUTTONDOWN:
                       //Play Button
                            if(obtemPosicaoMouse(mouse).x>=(1280/2)-1280/16 && obtemPosicaoMouse(mouse).x<=(1280/2)+(1280/16) && obtemPosicaoMouse(mouse).y>110 && obtemPosicaoMouse(mouse).y<179){
                            escolha ='1';

                            }
                        //Exit Button
                            if(obtemPosicaoMouse(mouse).x>=(1280/2)-1280/16 && obtemPosicaoMouse(mouse).x<=(1280/2)+(1280/16) && obtemPosicaoMouse(mouse).y>309 && obtemPosicaoMouse(mouse).y<380){
                                SDL_Quit();
                                exit(0);
                            }
                        //Team Button
                            if(obtemPosicaoMouse(mouse).x>=(1280/2)-1280/16 && obtemPosicaoMouse(mouse).x<=(1280/2)+(1280/16) && obtemPosicaoMouse(mouse).y>508 && obtemPosicaoMouse(mouse).y<580){
                                escolha = '2';
                            }
                       break;
                   default:
                       break;
                   }
               }


        //cout << "Mouse X:" << obtemPosicaoMouse(mouse).x << endl << obtemPosicaoMouse(mouse).y << endl;

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
    leChart(m);
    bool fim = false;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 || TTF_Init() < 0){
        cout << SDL_GetError() << endl;
    }

    const int alturaTela = 720, larguraTela = 1280;

    // inicializa janela e renderizador.
    SDL_Window* janela = SDL_CreateWindow("GuitarHub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, larguraTela, alturaTela, 0);
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

      //4 é a condição para o programa parar de executar
     while(menu(renderizador)!='4'){

    //SDL_RenderSetLogicalSize(renderizador, larguraTela, alturaTela);
    if(menu(renderizador) == '1'){

    //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); // inicializa o subsistema de áudio.

    Mix_Music *musica = Mix_LoadMUS("res/DragonForce-OnceInALifetime.mp3"); // carrega a música.
    SDL_Texture *notas = carregaTextura(renderizador, "res/notas.bmp");
    SDL_Texture *botoes = carregaTextura(renderizador, "res/pontos.bmp"); // aplica a superfície de pontos.bmp à textura.
    SDL_Texture *caminho = carregaTextura(renderizador, "res/caminho.bmp");
    SDL_Texture *pause = carregaTextura(renderizador, "res/PAUSE.bmp");
    SDL_Texture *sair = carregaTextura(renderizador, "res/EXIT.bmp");

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

    SDL_Rect caminhoRetangulo = {0, 0, larguraTela, alturaTela};

    SDL_Rect pauseRetangulo = {10, 10, 120, 100};

    SDL_Rect sairRetangulo = {10, 110, 120, 100};

    int inicioNota = 0, notaPassada = 0;

    SDL_Rect recortesNotas[] = {recorteNotaVerde, recorteNotaVermelha, recorteNotaAmarela, recorteNotaAzul, recorteNotaLaranjada};

    Mix_PlayMusic(musica, 0); // inicia a música.
    while(!fim && escolha!='0'){
        bool paused = false;

        SDL_Point mouse;
        //Loop inserido para não ocorrer erro ao executar algum evento na tela (CLick, movimento do mouse)
        SDL_Event event;
           while(SDL_PollEvent(&event)){
              switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:
              //Pause Button
              if(obtemPosicaoMouse(mouse).x>=10 && obtemPosicaoMouse(mouse).x<=130 && obtemPosicaoMouse(mouse).y>10 && obtemPosicaoMouse(mouse).y<100){
                paused = true;
                  while(paused == true){
                    while(SDL_PollEvent(&event)){
                       switch (event.type) {
                       //Quando o jogo sai do pause, a contagem do tempo não para, portanto as notas se teleportam
                         case SDL_MOUSEBUTTONDOWN:
                           paused = false;
                           break;
                       default:
                           break;
                       }
                    }
                 }
              }
              //Exit button
              if(obtemPosicaoMouse(mouse).x>=10 && obtemPosicaoMouse(mouse).x<=130 && obtemPosicaoMouse(mouse).y>110 && obtemPosicaoMouse(mouse).y<200){
              escolha='0';

              }
                  break;
              default:
                  break;
              }
          }

        cout << m.notaAtual << endl;

        SDL_RenderCopy(renderizador, caminho, NULL, &caminhoRetangulo);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoVerde, &botaoVerde);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoVermelho, &botaoVermelho);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoAmarelo, &botaoAmarelo);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoAzul, &botaoAzul);
        SDL_RenderCopy(renderizador, botoes, &recorteBotaoLaranjado, &botaoLaranjado);
        SDL_RenderCopy(renderizador, pause, NULL, &pauseRetangulo);
         SDL_RenderCopy(renderizador, sair, NULL, &sairRetangulo);


        desenhaNota(notas, m.idCor[m.notaAtual], SDL_GetTicks() - inicioNota, alturaTela, larguraTela, renderizador, recortesNotas[m.idCor[m.notaAtual]], &m);
        if(m.notaAtual > notaPassada){
            inicioNota = SDL_GetTicks();
            desenhaNota(notas, m.idCor[m.notaAtual], SDL_GetTicks() - inicioNota, alturaTela, larguraTela, renderizador, recortesNotas[m.idCor[m.notaAtual]], &m);
            notaPassada = m.notaAtual;
        }


        SDL_RenderPresent(renderizador);
        SDL_RenderClear(renderizador);

        //SDL_Delay(1000);
    }
    //executa apenas se não for para voltar pro menu
    if(escolha!='0'){
    encerraPrograma(renderizador, janela, musica); // executa o encerramento quando o loop é quebrado.
    }
}

       if(menu(renderizador)=='2'){
            SDL_Texture *cred = carregaTextura(renderizador,"res/Creditos.bmp");
            SDL_Rect credPos = {(1280/2)-1280/4, 100, 1280/2, 720/2};
                while(escolha=='2'){
                    SDL_Event event;
                       while(SDL_PollEvent(&event)){
                          switch (event.type) {
                          case SDL_MOUSEBUTTONDOWN:
                              escolha = '0';
                              break;
                          default:
                              break;
                          }
                      }

               SDL_RenderCopy(renderizador, cred, NULL, &credPos);
               SDL_RenderPresent(renderizador);
               SDL_RenderClear(renderizador);
                }

        }
     }
}

