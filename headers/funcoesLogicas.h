/** Lucas S. Beiler (https://github.com/lucassbeiler) e Gustavo Martins (https://github.com/00-000)
 *  Trabalho #1 de Algoritmos e Programação II | 2⁰ semestre de Ciência da Computação | Universidade do Vale do Itajaí
 *  Réplica de Guitar Hero feita em SDL e C++
 **/
#ifndef FUNCOESLOGICAS_H
#define FUNCOESLOGICAS_H
#define SDL_MAIN_HANDLED
#include <fstream>
#include <iostream>
#include <SDL2/SDL.h> // SDL principal
#include <sstream>
#include <sys/time.h>
#include <SDL2/SDL_mixer.h> // para áudio
#undef main

int qtdLinhasChart(std::string chartArquivo);
void leChart(struct musica m);
void encerraPrograma(SDL_Renderer* renderizador, SDL_Window* janela, Mix_Music* musica);
SDL_DisplayMode obtemResolucaoTela();
SDL_Point obtemPosicaoMouse(SDL_Point mouse);
long long tempoMilisseg();
unsigned int converteStringParaUnsignedInt(std::string str);

struct musica{
    unsigned int *tempoNota = new unsigned int[qtdLinhasChart("res/DragonForce-OnceInALifetime.chart")];
    std::string *tipoNota = new std::string[qtdLinhasChart("res/DragonForce-OnceInALifetime.chart")];
    int *idCor = new int[qtdLinhasChart("res/DragonForce-OnceInALifetime.chart")];
    unsigned int *duracaoNota = new unsigned int[qtdLinhasChart("res/DragonForce-OnceInALifetime.chart")];
};
#endif // FUNCOESLOGICAS_H
