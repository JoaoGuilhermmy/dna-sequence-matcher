#include "Database.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Implementação do carregamento do banco de dados a partir de um arquivo CSV.
bool Database::load_from_csv(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }

    std::string line;
    // 1. Processa a primeira linha (cabeçalho) para obter os nomes dos STRs.
    if (std::getline(file, line))
    {
        std::stringstream ss(line); // Usa stringstream para facilitar o parsing da linha.
        std::string header;
        std::getline(ss, header, ','); // Ignora a primeira coluna ("name").
        while (std::getline(ss, header, ','))
        {
            str_names.push_back(header); // Adiciona cada nome de STR ao vetor.
        }
    }

    // 2. Processa as linhas de dados restantes.
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name;
        std::getline(ss, name, ','); // Extrai o nome da pessoa.

        std::vector<int> counts;
        std::string count_str;
        // Itera sobre os valores de contagem de STRs na linha.
        while (std::getline(ss, count_str, ','))
        {
            try
            {
                // Converte a contagem de string para inteiro.
                counts.push_back(std::stoi(count_str));
            }
            catch (const std::invalid_argument &e)
            {
                // Se a conversão falhar, o formato do arquivo é inválido.
                return false;
            }
        }

        // Adiciona o perfil ao mapa se o número de contagens corresponder ao número de STRs.
        if (counts.size() == str_names.size())
        {
            profiles[name] = counts;
        }
    }

    file.close();
    return true;
}

// Implementação da busca por correspondência.
std::string Database::find_match(const std::vector<int> &dna_profile)
{
    // Itera sobre todos os pares (nome, perfil) no mapa de perfis.
    for (const auto &pair : profiles)
    {
        // O operador '==' para std::vector faz uma comparação elemento a elemento.
        // Se os perfis forem idênticos, uma correspondência foi encontrada.
        if (pair.second == dna_profile)
        {
            return pair.first; // Retorna o nome da pessoa correspondente.
        }
    }
    // Se o loop terminar sem encontrar correspondência, retorna uma string vazia.
    return "";
}

// Implementação do método de acesso aos nomes dos STRs.
const std::vector<std::string> &Database::get_str_names() const
{
    return str_names;
}