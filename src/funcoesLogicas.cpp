/** Lucas S. Beiler (https://github.com/lucassbeiler) e Gustavo Martins (https://github.com/00-000)
 *  Trabalho #1 de Algoritmos e Programação II | 2⁰ semestre de Ciência da Computação | Universidade do Vale do Itajaí
 *  Réplica de Guitar Hero feita em SDL e C++
 **/
#include "headers/funcoesLogicas.h"

using namespace std;

int qtdLinhasChart(string chartArquivo){
    ifstream chart(chartArquivo);
    string linha = "";
    int nLinhas = 0;
    for (nLinhas = 0; getline(chart, linha); ++nLinhas);
    return nLinhas;
}

SDL_DisplayMode obtemResolucaoTela(){
    SDL_DisplayMode SDM;
    if(SDL_GetDesktopDisplayMode(0, &SDM) == 0){
        return SDM;
    }else{
        cout << "ERRO";
        return SDM;
    }
}

SDL_Point obtemPosicaoMouse(SDL_Point mouse){
    SDL_GetMouseState(&mouse.x, &mouse.y);

    return {mouse.x, mouse.y};
}

void leChart(musica m){
    ifstream chart("res/DragonForce-OnceInALifetime.chart");
    string linha = "", temp;
    int nLinha = 0;

    while(getline(chart, linha)){
        m.tempoNota[nLinha] = converteStringParaUnsignedInt(strtok(const_cast<char*>(linha.c_str()), " \t="));
        m.tipoNota[nLinha] = strtok(nullptr, " \t=");
        m.idCor[nLinha] = converteStringParaUnsignedInt(strtok(nullptr, " \t="));
        m.duracaoNota[nLinha] = converteStringParaUnsignedInt(strtok(nullptr, " \t="));

        nLinha++;
    }
}

void encerraPrograma(SDL_Renderer* renderizador, SDL_Window* janela, Mix_Music* musica){
    Mix_FreeMusic(musica);
    SDL_DestroyWindow(janela);
    SDL_DestroyRenderer(renderizador); // desaloca o renderizador e todas as suas texturas
    Mix_CloseAudio();
    SDL_Quit();
}

long long tempoMilisseg() {
    struct timeval tiv;
    gettimeofday(&tiv, NULL); // get current time
    long long ms = tiv.tv_sec*1000LL + tiv.tv_usec/1000; // calculate milliseconds
    return ms;
}

unsigned int converteStringParaUnsignedInt(string str){
    unsigned int inteiro = 0;
    istringstream ss(str);
    ss >> inteiro;

    return inteiro;
}
