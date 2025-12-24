#include "UserInterface.h"
#include <iostream>
#include <string>

// Imprime a mensagem de boas-vindas e informações sobre o programa.
void UserInterface::display_welcome_message()
{
    std::cout << "================================================================================\n";
    std::cout << "\t \tWelcome to the C++ DNA Profiler, v1.0" << std::endl;
    std::cout << "\t \tCopyright (C) 2024, Danilo Curvelo" << std::endl;
    std::cout << "================================================================================\n";
    std::cout << "This programa loads a DNA database and an unknown DNA sequence and tries" << std::endl;
    std::cout << "to find a match between the input DNA sequence and the DNA database." << std::endl;
}

// Imprime as instruções de uso correto do programa via linha de comando.
void UserInterface::display_usage()
{
    std::cout << "Uso: dnaprofiler -d <database_file> -s <dna_sequence_file>" << std::endl;
}

// Exibe o status de carregamento de um arquivo (banco de dados ou sequência).
// Formata a saída para indicar sucesso ou falha, usando códigos de escape ANSI para cores.
void UserInterface::display_loading_status(const std::string &filename, bool success)
{
    if (filename.find(".csv") != std::string::npos)
    {
        std::cout << "[+] Loading DNA database file \033[31m[" << filename << "]\033[0m ... ";
    }
    else
    {
        std::cout << "[+] Loading unknown DNA sequence file \033[31m[" << filename << "]\033[0m ... ";
    }

    if (success)
    {
        std::cout << "[\033[32mOK\033[0m]" << std::endl;
    }
    else
    {
        std::cout << "[FAILED]" << std::endl;
    }
}

// Imprime uma mensagem indicando que a busca no banco de dados está em andamento.
void UserInterface::display_searching()
{
    std::cout << "[+] Searching the database for a match... Please wait." << std::endl;
    std::cout << "[================================================================================] 100 %" << std::endl;
}

// Exibe a mensagem padrão para quando nenhuma correspondência é encontrada.
void UserInterface::display_no_match()
{
    std::cout << ">>> Sorry, no match found in our database." << std::endl;
}

// Formata e exibe os detalhes de uma correspondência encontrada, incluindo o nome,
// o perfil de STRs e a sequência de DNA.
void UserInterface::display_match(const std::string &name, const std::string &sequence, const std::map<std::string, int> &profile)
{
    std::cout << "Match ID (99.9%): " << name << std::endl
              << std::endl;

    for (const auto &pair : profile)
    {
        std::cout << "\t" << pair.first << " [x" << std::to_string(pair.second) << "]";
    }
    std::cout << std::endl;

    for (const auto &pair : profile)
    {
        std::cout << "\t";
        for (size_t i = 0; i < (pair.first.length() * pair.second); ++i)
        {
            std::cout << "v";
        }
    }
    std::cout << std::endl
              << std::endl;

    std::cout << sequence << std::endl;
}