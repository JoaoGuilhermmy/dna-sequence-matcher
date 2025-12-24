#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>
#include <map>

// Declaração da classe DNA.
// Esta classe é responsável por encapsular uma sequência de DNA e fornecer
// métodos para carregá-la de um arquivo e gerar seu perfil de STRs.
class DNA
{
private:
    // Membro de dados que armazena a sequência de DNA completa como uma string.
    std::string sequence;

public:
    // Carrega a sequência de DNA a partir de um arquivo de texto.
    bool load_sequence_from_file(const std::string &filename);

    // Analisa a sequência de DNA para encontrar a maior sequência consecutiva de cada STR
    // fornecido na lista, gerando um perfil numérico.
    std::vector<int> generate_profile(const std::vector<std::string> &str_list);

    // Método de acesso para obter a sequência de DNA armazenada.
    const std::string &get_sequence() const;
};

#endif // DNA_H