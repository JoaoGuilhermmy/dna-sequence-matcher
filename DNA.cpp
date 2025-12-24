#include "DNA.h"
#include <fstream>
#include <iostream>

// Implementação do método de carregamento da sequência.
bool DNA::load_sequence_from_file(const std::string &filename)
{
    // Utiliza ifstream para abrir o arquivo.
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // Retorna 'false' se o arquivo não puder ser aberto.
        return false;
    }
    // Lê a linha inteira do arquivo e a armazena no membro 'sequence'.
    std::getline(file, sequence);
    file.close();
    return true;
}

// Implementação do algoritmo de geração de perfil de DNA.
std::vector<int> DNA::generate_profile(const std::vector<std::string> &str_list)
{
    std::vector<int> profile; // Vetor que armazenará as contagens de cada STR.

    // Itera sobre cada STR (ex: "AGAT", "AATG") que precisa ser contado.
    for (const std::string &str : str_list)
    {
        int max_repeats = 0; // Armazena a maior sequência de repetições para o STR atual.

        // O loop externo varre a sequência de DNA inteira, caractere por caractere.
        // Isso é necessário para garantir que a maior sequência seja encontrada,
        // não importando em que posição ela comece.
        for (size_t i = 0; i < sequence.length(); ++i)
        {
            int current_repeats = 0; // Contador para a sequência de repetições a partir da posição 'i'.
            size_t pos = i;

            // Este loop 'while' conta quantas vezes o STR se repete consecutivamente.
            while (pos + str.length() <= sequence.length() && sequence.substr(pos, str.length()) == str)
            {
                current_repeats++;
                pos += str.length(); // Avança a posição pela largura do STR.
            }

            // Se a sequência contada a partir desta posição 'i' for a maior já encontrada,
            // atualiza o valor máximo.
            if (current_repeats > max_repeats)
            {
                max_repeats = current_repeats;
            }
        }
        // Adiciona a contagem máxima para o STR atual ao perfil.
        profile.push_back(max_repeats);
    }
    return profile;
}

// Implementação do método de acesso à sequência.
const std::string &DNA::get_sequence() const
{
    return sequence;
}