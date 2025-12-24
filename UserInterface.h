#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>
#include <map>

// Declaração da classe UserInterface.
// Esta é uma classe utilitária, contendo apenas métodos estáticos. Seu único
// propósito é gerenciar toda a saída de dados para o console, separando
// a lógica de apresentação da lógica de negócio da aplicação.
class UserInterface
{
public:
    // Protótipos para os métodos estáticos de exibição.
    // Cada método é responsável por imprimir uma parte específica da interface do usuário.
    static void display_welcome_message();
    static void display_usage();
    static void display_loading_status(const std::string &filename, bool success);
    static void display_searching();
    static void display_no_match();
    static void display_match(const std::string &name, const std::string &sequence, const std::map<std::string, int> &profile);
};

#endif