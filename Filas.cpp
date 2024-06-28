#include <iostream>
#include <queue>

int main() {
    std::queue<int> senhasGeradas;
    std::queue<int> senhasAtendidas;
    int contadorSenhas = 0;
    int opcao;

    do {
        std::cout << "Selecione uma opção:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Gerar senha\n";
        std::cout << "2. Realizar atendimento\n";
        std::cout << "Quantidade de senhas aguardando atendimento: " << senhasGeradas.size() << "\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch(opcao) {
            case 0:
                if (!senhasGeradas.empty()) {
                    std::cout << "Não é possível sair. Ainda há senhas aguardando atendimento.\n";
                } else {
                    std::cout << "Encerrando o programa.\n";
                    std::cout << "Quantidade de senhas atendidas: " << senhasAtendidas.size() << "\n";
                }
                break;

            case 1:
                contadorSenhas++;
                senhasGeradas.push(contadorSenhas);
                std::cout << "Senha " << contadorSenhas << " gerada e enfileirada.\n";
                break;

            case 2:
                if (senhasGeradas.empty()) {
                    std::cout << "Nenhuma senha para atender.\n";
                } else {
                    int senhaAtendida = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senhaAtendida);
                    std::cout << "Atendendo senha: " << senhaAtendida << "\n";
                }
                break;

            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while(opcao != 0 || !senhasGeradas.empty());

    return 0;
}
