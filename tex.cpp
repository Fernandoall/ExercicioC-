#include <iostream>
#include <queue>
#include <list>
#include <algorithm> // Para std::find_if
#include <functional> // Para std::function

struct Guiche {
    int id;
    std::queue<int> senhasAtendidas;
};

int main() {
    std::queue<int> senhasGeradas;
    std::list<Guiche> guiches;
    int contadorSenhas = 0;
    int opcao;

    do {
        std::cout << "Selecione uma opção:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Gerar senha\n";
        std::cout << "2. Abrir guichê\n";
        std::cout << "3. Realizar atendimento\n";
        std::cout << "4. Listar senhas atendidas\n";
        std::cout << "Quantidade de senhas aguardando atendimento: " << senhasGeradas.size() << "\n";
        std::cout << "Quantidade de guichês abertos: " << guiches.size() << "\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch(opcao) {
            case 0:
                if (!senhasGeradas.empty()) {
                    std::cout << "Não é possível sair. Ainda há senhas aguardando atendimento.\n";
                } else {
                    std::cout << "Encerrando o programa.\n";
                    int totalAtendidas = 0;
                    for (const auto& guiche : guiches) {
                        totalAtendidas += guiche.senhasAtendidas.size();
                    }
                    std::cout << "Quantidade de senhas atendidas: " << totalAtendidas << "\n";
                }
                break;

            case 1:
                contadorSenhas++;
                senhasGeradas.push(contadorSenhas);
                std::cout << "Senha " << contadorSenhas << " gerada e enfileirada.\n";
                break;

            case 2:
                {
                    int idGuiche;
                    std::cout << "Digite o ID do guichê: ";
                    std::cin >> idGuiche;

                    auto it = std::find_if(guiches.begin(), guiches.end(), [idGuiche](const Guiche& guiche) {
                        return guiche.id == idGuiche;
                    });

                    if (it == guiches.end()) {
                        Guiche novoGuiche = { idGuiche };
                        guiches.push_back(novoGuiche);
                        std::cout << "Guichê " << idGuiche << " aberto.\n";
                    } else {
                        std::cout << "Guichê " << idGuiche << " já está aberto.\n";
                    }
                }
                break;

            case 3:
                if (senhasGeradas.empty()) {
                    std::cout << "Nenhuma senha para atender.\n";
                } else {
                    int idGuiche;
                    std::cout << "Digite o ID do guichê: ";
                    std::cin >> idGuiche;

                    auto it = std::find_if(guiches.begin(), guiches.end(), [idGuiche](const Guiche& guiche) {
                        return guiche.id == idGuiche;
                    });

                    if (it != guiches.end()) {
                        int senhaAtendida = senhasGeradas.front();
                        senhasGeradas.pop();
                        it->senhasAtendidas.push(senhaAtendida);
                        std::cout << "Atendendo senha: " << senhaAtendida << " no guichê " << idGuiche << "\n";
                    } else {
                        std::cout << "Guichê " << idGuiche << " não encontrado.\n";
                    }
                }
                break;

            case 4:
                {
                    int idGuiche;
                    std::cout << "Digite o ID do guichê: ";
                    std::cin >> idGuiche;

                    auto it = std::find_if(guiches.begin(), guiches.end(), [idGuiche](const Guiche& guiche) {
                        return guiche.id == idGuiche;
                    });

                    if (it != guiches.end()) {
                        std::cout << "Senhas atendidas pelo guichê " << idGuiche << ": ";
                        std::queue<int> tempQueue = it->senhasAtendidas;
                        while (!tempQueue.empty()) {
                            std::cout << tempQueue.front() << " ";
                            tempQueue.pop();
                        }
                        std::cout << "\n";
                    } else {
                        std::cout << "Guichê " << idGuiche << " não encontrado.\n";
                    }
                }
                break;

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while(opcao != 0 || !senhasGeradas.empty());

    return 0;
}
