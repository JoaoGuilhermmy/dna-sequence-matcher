#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <map>

// Declaração da classe Database.
// Gerencia o carregamento, armazenamento e busca em um banco de dados de perfis de DNA.
class Database
{
private:
    // Vetor para armazenar os nomes dos STRs (cabeçalho do CSV).
    std::vector<std::string> str_names;
    // Mapa para associar o nome de uma pessoa (chave) ao seu perfil de DNA (valor).
    // std::map é eficiente para buscas baseadas em chaves.
    std::map<std::string, std::vector<int>> profiles;

public:
    // Carrega o banco de dados a partir de um arquivo no formato CSV.
    bool load_from_csv(const std::string &filename);

    // Busca no banco de dados por um perfil de DNA que corresponda ao fornecido.
    std::string find_match(const std::vector<int> &dna_profile);

    // Método de acesso para obter a lista de nomes dos STRs.
    const std::vector<std::string> &get_str_names() const;
};

#endif