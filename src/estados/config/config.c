#include "config.h"
#include <stdio.h>
#include <admin.h>
#include <input.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <list.h>
#include <string.h>

void editarPaginaInicial()
{
    char line[100];
    size_t total;
    int c;

    while (true) {
        clear();

        printf("Mensagem inicial atual:\n\"%s\"\n\n", machineInfo.greetings);
        printf("Deseja editar? (s/n): ");

        do {
            c = getchar();
        } while (c == ' ' || c == '\t' || c == '\n');

        if (c == 'n' || c == 'N') {
            return;
        } else if (c == 's' || c == 'S') {
            printf("\nDigite nova mensagem (várias linhas).\n");
            printf("Para terminar, digite \":q\" em uma linha só.\n\n");

            machineInfo.greetings[0] = '\0';
            total = 0;

            while (true) {
                if (!fgets(line, sizeof(line), stdin)) {
                    break;
                }
                line[strcspn(line, "\n")] = '\0';
                if (strcmp(line, ":q") == 0) 
                {
                    break;
                }

                size_t len = strlen(line);
                if (total + len + (total > 0 ? 1 : 0) >= sizeof(machineInfo.greetings)) {
                    printf("\nLimite de 100 caracteres atingido. Leitura encerrada.\n");
                    fflush(stdin);
                    pause();
                    break;
                }

                if (total > 0) {
                    machineInfo.greetings[total++] = '\n';
                }

                memcpy(machineInfo.greetings + total, line, len);
                total += len;
                machineInfo.greetings[total] = '\0';
            }

            printf("\nNova mensagem inicial salva!\n\n");
            pause();
            atualizarArquivoAdmin();
            return;
        } else {
            printf("Opção inválida, por favor responda 's' ou 'n'.\n\n");
        }
    }
};

void mostrarOpções()
{
    clear();

    printf("------------------------------------------------\n");
    printf("> MENU CONFIGURAÇÃO MÁQUINA DE REFRIS\n");
    printf("------------------------------------------------\n");
    printf(" *  0: Sair do modo configuração.\n");
    printf("------------------------------------------------\n");
    printf(" *  1: Imprimir logs de vendas.\n");
    printf(" *  2: Salvar logs de vendas no arquivo de logs.\n");
    printf("------------------------------------------------\n");
    printf(" *  3: Editar mensagem do menu inicial.\n");
    printf("------------------------------------------------\n");
    printf(" *  4: Editar/Deletar um produto.\n");
    printf(" *  5: Criar um produto.\n");
    printf("------------------------------------------------\n");
    printf(" * -1: Desligar máquina.\n");
    printf("------------------------------------------------\n> ");
};

void mostrarLogs()
{
    clear();
    printf("> Logs de vendas:\n\n");
    imprimirLogs();
    pause();
}

void forcarSalvamento()
{
    salvarLogs(true);
    printf("> Logs salvos!\n");
    pause();
}

void criarNovoProduto()
{
    PRODUTO_HEADER novo;
    novo.naVitrine = false;

    clear();
    printf("Nome: ");
    fflush(stdin);
    if (fgets(novo.name, sizeof novo.name, stdin))
    {
        novo.name[strcspn(novo.name, "\n")] = '\0';
    }

    fflush(stdin);
    printf("Preço: ");
    scanf("%f", &novo.preço);

    fflush(stdin);
    printf("Estoque: ");
    scanf("%i", &novo.estoque);

    int temp;
    printf("Mostrar na vitrine (1: sim): ");

    fflush(stdin);
    scanf("%i", &temp);
    if (temp == 1)
        novo.naVitrine = true;

    printf("Confirmar criação (1: sim): ");

    fflush(stdin);
    scanf("%i", &temp);
    if (temp == 1)
    {
        criarProduto(novo.name, novo.preço, novo.estoque, novo.naVitrine);
        carregarProdutos();
    }
}

void editarProduto()
{
    clear();
    printf("Selecione o produto (-1 voltar):\n");
    listarProdutos(true);
    printf("> ");

    int entrada;
    do
    {
        entrada = captarEntrada(false);
        if(entrada == -1)
        {
            return;
        }
    } while (!produtoExiste(entrada));

    PRODUTO_HEADER *produto = getProductOnList(entrada);

    bool edita = true;

    do
    {
        clear();
        printf(" (a) %s:\n (b) Preço R$ %0.2f\n (c) Estoque: %01i\n (d) Na vitrine: %s\n (e) Deletado: %s\n",
               produto->name,
               produto->preço,
               produto->estoque,
               produto->naVitrine ? "Sim" : "Não",
               produto->deletado ? "Sim" : "Não");

        printf(" (s) Sair/Salvar\n> ");

        fflush(stdin);
        char oqueEditar = getc(stdin);

        switch (oqueEditar)
        {
        case 'a':
            printf("\nNome: > ");
            fflush(stdin);
            if (fgets(produto->name, sizeof produto->name, stdin))
            {
                produto->name[strcspn(produto->name, "\n")] = '\0';
            }
            break;
        case 'b':
            printf("\nPreço: > ");
            fflush(stdin);
            scanf("%f", &produto->preço);
            break;
        case 'c':
            printf("\nEstoque: > ");
            fflush(stdin);
            scanf("%i", &produto->estoque);
            break;
        case 'd':
            produto->naVitrine = !produto->naVitrine;
            break;
        case 'e':
            produto->deletado = !produto->deletado;
            break;
        case 's':
            edita = false;
            break;
        default:
            break;
        }
    } while (edita);

    atualizarProduto(entrada);
}

void input(RESULTADO_ESTADO *result)
{
    mostrarOpções();

    int entrada = captarEntrada(false);
    switch (entrada)
    {
    case 0:
        *result = PROXIMO;
        return;
        break;
    case 1:
        mostrarLogs();
        break;
    case 2:
        forcarSalvamento();
        break;
    case 3:
        editarPaginaInicial();
        break;
    case 4:
        editarProduto();
        break;
    case 5:
        criarNovoProduto();
        break;
    case -1:
        *result = SAIR;
        return;
        break;
    }

    input(result);
}

RESULTADO_ESTADO estadoConfig()
{
    RESULTADO_ESTADO res;

    input(&res);

    return res;
}