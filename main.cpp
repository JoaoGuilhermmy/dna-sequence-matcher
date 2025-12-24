#include <iostream>
#include <string>
#include <vector>
#include "UserInterface.h"
#include "Database.h"
#include "DNA.h"

int main(int argc, char *argv[])
{
    // 1. Validação e parsing dos argumentos de linha de comando.
    if (argc != 5)
    {
        UserInterface::display_usage();
        return 1;
    }

    std::string db_filename;
    std::string dna_filename;

    // Loop para processar os argumentos em qualquer ordem (-d e -s).
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "-d" && i + 1 < argc)
        {
            db_filename = argv[++i]; // Atribui o próximo argumento como nome do arquivo.
        }
        else if (arg == "-s" && i + 1 < argc)
        {
            dna_filename = argv[++i];
        }
    }

    // Verifica se ambos os nomes de arquivo foram fornecidos.
    if (db_filename.empty() || dna_filename.empty())
    {
        UserInterface::display_usage();
        return 1;
    }

    // 2. Orquestração do fluxo do programa.
    UserInterface::display_welcome_message();

    // Carrega o banco de dados.
    Database db;
    bool db_loaded = db.load_from_csv(db_filename);
    UserInterface::display_loading_status(db_filename, db_loaded);
    if (!db_loaded)
    {
        return 1; // Encerra se o carregamento falhar.
    }

    // Carrega a sequência de DNA.
    DNA dna;
    bool dna_loaded = dna.load_sequence_from_file(dna_filename);
    UserInterface::display_loading_status(dna_filename, dna_loaded);
    if (!dna_loaded)
    {
        return 1; // Encerra se o carregamento falhar.
    }

    UserInterface::display_searching();

    // 3. Execução da lógica principal: gerar perfil e buscar correspondência.
    // Obtém os nomes dos STRs do banco de dados para saber o que procurar.
    std::vector<int> generated_profile = dna.generate_profile(db.get_str_names());
    // Usa o perfil gerado para encontrar uma correspondência no banco de dados.
    std::string match_name = db.find_match(generated_profile);

    // 4. Exibição dos resultados.
    if (!match_name.empty())
    {
        // Se uma correspondência for encontrada, prepara os dados e exibe o resultado detalhado.
        std::map<std::string, int> profile_map;
        const auto &str_names = db.get_str_names();
        for (size_t i = 0; i < str_names.size(); ++i)
        {
            profile_map[str_names[i]] = generated_profile[i];
        }
        UserInterface::display_match(match_name, dna.get_sequence(), profile_map);
    }
    else
    {
        // Caso contrário, exibe a mensagem de não correspondência.
        UserInterface::display_no_match();
    }

    return 0;
}