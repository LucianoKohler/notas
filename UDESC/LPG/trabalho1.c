#include <stdio.h>
#include <unistd.h>
#define conjuntos 8
#define tamanho_conjunto 10

/* NOTAS IMPORTANTES

 - Um conjunto não deve ter valores repetidos
 - Como é necessário conferir se o valor digitado não existe no conjunto, fiz a op. 2 diferente do enunciado
 - Perguntar ao professor se o conjunto escolhido deve ser ZERADO na segunda operação
 
*/

// Operação suporte para validar se o conjunto escolhido é válido
int validaOperacao(int cont, int arrEscolhido){
    if(arrEscolhido > conjuntos-1){
        printf("Este valor ultrapassa o valor máximo de conjuntos!\n");
        return 0;
    }
    if(arrEscolhido > cont-1){
        printf("Este array ainda não foi criado, crie-o!\n");
        return 0;
    }
    
    return 1;
}


// Operação suporte para insereConjunto() e buscaValor()
int buscaSequencial(int chave, int arr[]){
    for(int i = 0; i < tamanho_conjunto; i++){
        if(arr[i] == chave){
            return 1;
        }
    }
    
    return 0;
}

// Operação suporte para insereConjunto() e ExcluiConjunto()
void zeraConjunto(int arr[]){
    for(int i = 0; i < tamanho_conjunto; i++){
        arr[i] = 0;
    }
}

// OPERAÇÕES PRINCIPAIS

// OPERAÇÃO NÚMERO 1
int criaConjunto(int cont){
    if(cont > conjuntos){ // Maior que 8 pois cont sempre será o número de conjuntos + 1
        printf("Número máximo de conjuntos criados, exclua algum.\n");
    }else{
        printf("Um novo conjunto foi criado no espaço %d!\n", cont);
        cont++;
    }
    
    return cont;
}

// OPERAÇÃO NÚMERO 2
void insereConjunto(int cont, int arr[]){
    int valor;
    int i = 0;
    int pontoPartida = 0;
    // Encontrando onde continuar a inserção de valores
    for(int i = 0; i < tamanho_conjunto; i++){
        if(arr[i] != 0) pontoPartida++;
    }
    
    while(1){
        
        if(i + pontoPartida == tamanho_conjunto){
            printf("Valor máximo de números atingido no conjunto.\n");
            break;
        }
        
        printf("Insira o valor do %d° valor: ", i+pontoPartida+1);
        scanf("%d", &valor);
       
        // Tratando com erros
        if(valor == 0){
            printf("Nulo digitado\n");
            break;
            
        }else if(buscaSequencial(valor, arr)){
            printf("\nEste valor já está contido no conjunto.\n\n");
            
        }else{
            arr[i+pontoPartida] = valor;
            i++;
        }
    }
}

// OPERAÇÃO NÚMERO 3
int ExcluiConjunto(int cont, int arrEscolhido, int matriz[][tamanho_conjunto]){
    zeraConjunto(matriz[arrEscolhido]);
    for(int i = arrEscolhido; i < cont; i++){
        for(int j = 0; j < tamanho_conjunto; j++){
            matriz[i][j] = matriz[i+1][j];
        }
    }
    
    cont--;
    printf("Conjunto %d excluído com sucesso!\n", arrEscolhido);
    return cont;
}

// OPERAÇÃO NÚMERO 4
int uniaoConjunto(int cont, int arr1[], int arr2[], int matriz[][10]){
    if(cont == conjuntos-1){
        printf("Não há espaço para criar o conjunto união, exclua algum conjunto.\n");
    }else{
        
        int j = 0; // Tamanho do novo conjunto
        for(int i = 0; i < tamanho_conjunto; i++){ // Passando pelo primeiro conjunto
            
            if(arr1[i] == 0) break;
                
                matriz[cont][j] = arr1[i];
                j++;
            }
            
        for(int i = 0; i < tamanho_conjunto; i++){ // Passando pelo segundo conjunto
            if(arr2[i] == 0){
                break;
            }
            
            if(!buscaSequencial(arr2[i], matriz[cont])){ // Verificando se não for repetido
                matriz[cont][j] = arr2[i];
                j++;
            }
        }
        
        cont++;
        printf("Conjunto união criado, lembre-se que ele pode não ter cabido na capacidade do conjunto!\n");
    }
    return cont;
}

// OPERAÇÃO NÚMERO 5
int interConjunto(int cont, int arr1[], int arr2[], int matriz[][10]){
    if(cont == conjuntos-1){
        printf("Não há espaço para criar o conjunto intersecção, exclua algum conjunto.\n");
    }else{
        int k = 0; // Tamanho do novo conjunto
        
        for(int i = 0; i < tamanho_conjunto; i++){
            if(arr1[i] == 0) break;
            
            for(int j = 0; j < tamanho_conjunto; j++){
                if(arr2[j] == 0) break;
                if(k == tamanho_conjunto) break;
                
                if(arr1[i] == arr2[j]){
                    matriz[cont][k] = arr1[i];
                    k++;
                }
            }
        }
        cont++;
        printf("Conjunto intersecção criado, lembre-se que ele pode não ter cabido na capacidade do conjunto!\n");
    }
    return cont;
}

// OPERAÇÃO NÚMERO 6
void mostraConjunto(int arrEscolhido, int arr[]){
    printf("Conjunto %d: ", arrEscolhido);
    
    if(arr[0] == 0){
        printf("Conjunto vazio");
    }else{
        for(int i = 0; i < tamanho_conjunto; i++){
            if(arr[i] == 0) break;
            printf("%d, ", arr[i]);
        }
    }
    printf("\n");
}

// OPERAÇÃO NÚMERO 7
void mostraTodosConjuntos(int cont, int matriz[][tamanho_conjunto]){
    if(cont == 0){
        printf("Nenhum conjunto criado, crie algum!");
    }else{
        for(int i = 0; i < cont; i++){
            mostraConjunto(i, matriz[i]);
        }
    }
}

// OPERAÇÃO NÚMERO 8
void buscaValor(int chave, int cont, int matriz[][tamanho_conjunto]){
    if(cont == 0){
        printf("Nenhum conjunto criado, crie algum!");
    }else if(chave == 0){
        printf("0 é um valor inválido par busca!\n");
    }else{
        printf("\nConjuntos que contém o valor %d:\n\n", chave);
        for(int i = 0; i < cont; i++){
            if(buscaSequencial(chave, matriz[i])){
                printf("Conjunto %d\n", i);
            }
        }
    }
}

int main()
{
    
    int escolha = 0;
    int cont = 0;
    int matriz[conjuntos][tamanho_conjunto] = {0};
    int arrEscolhido; // Variável muito usada em operações que usam um conjunto específico
    int arrEscolhido2; // Variável usada em união e intersecçõa
    
    while(1){
    
        printf("Menu do gerenciador de Conjuntos:\n\n");

        printf("1. Criar novo conjunto vazio\n");
        printf("2. Inserir dados em um conjunto\n");
        printf("3. Remover um conjunto\n");
        printf("4. Fazer a união entre dois conjuntos\n");
        printf("5. Fazer a intersecção de dois conjuntos\n");
        printf("6. Mostrar um conjunto\n");
        printf("7. Mostrar todos os conjuntos\n");
        printf("8. Fazer busca por um valor\n");
        printf("9. Sair do programa\n");

        printf("\nSua escolha: ");
        scanf("%d", &escolha);
        
        printf("\033[H\033[J"); // Limpa a tela 

        
        switch(escolha){
            
            case 1:
                int cont = criaConjunto(cont);
                break;
                
                
                
            case 2:
                printf("Insira o índice do array para fazer a operacão (0 a 7): ");
                scanf("%d", &arrEscolhido);
                
                if(validaOperacao(cont, arrEscolhido)){
                    insereConjunto(cont, matriz[arrEscolhido]);
                    break;
                }else{
                    break;
                }
                
                
                
            case 3:
                printf("Insira o índice do array para fazer a operacão (0 a 7): ");
                scanf("%d", &arrEscolhido);
                if(validaOperacao(cont, arrEscolhido)){
                    cont = ExcluiConjunto(cont, arrEscolhido, matriz);
                    break;
                }else{
                    break;
                }
                
                
                
            case 4:
                printf("Insira o índice do PRIMEIRO conjunto para fazer a operacão (0 a 7): ");
                scanf("%d", &arrEscolhido);
                
                if(validaOperacao(cont, arrEscolhido)){
                    printf("Insira o índice do SEGUNDO conjunto para fazer a operacão (0 a 7): ");
                    scanf("%d", &arrEscolhido2);
                
                    if(arrEscolhido == arrEscolhido2){
                        printf("Os conjuntos não devem ser iguais.");
                        
                    }else if(validaOperacao(cont, arrEscolhido2)){
                        cont = uniaoConjunto(cont, matriz[arrEscolhido], matriz[arrEscolhido2], matriz);
                    }
                }
                break;
            
            
            
            case 5:
                printf("Insira o índice do PRIMEIRO conjunto para fazer a operacão (0 a 7): ");
                scanf("%d", &arrEscolhido);
                
                if(validaOperacao(cont, arrEscolhido)){
                    printf("Insira o índice do SEGUNDO conjunto para fazer a operacão (0 a 7): ");
                    scanf("%d", &arrEscolhido2);
                
                    if(arrEscolhido == arrEscolhido2){
                        printf("Os conjuntos não devem ser iguais.");
                        
                    }else if(validaOperacao(cont, arrEscolhido2)){
                        cont = interConjunto(cont, matriz[arrEscolhido], matriz[arrEscolhido2], matriz);
                    }
                }
                break;
                
                
                
            case 6:
                printf("Insira o índice do array para fazer a operacão (0 a 7): ");
                scanf("%d", &arrEscolhido);
                if(validaOperacao(cont, arrEscolhido)){
                    mostraConjunto(cont, matriz[arrEscolhido]);
                    break;
                }else{
                    break;
                }
                
                
                
            case 7:
                mostraTodosConjuntos(cont, matriz);
                break;
            
            
            
            case 8:
                int chave;
                printf("Insira o valor a ser procurado: ");
                scanf("%d", &chave);
                buscaValor(chave, cont, matriz);
                break;
                
                
                
            case 9:
                printf("Obrigado por usar nossos serviços!\n");
                return 0;
                break;
                
                
                
            default:
                printf("Valor inválido!\n");
                break;
        }
        
        printf("\nPressione ENTER para continuar...");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Limpa o buffer
        while (getchar() != '\n');
        
        printf("\033[H\033[J"); // Limpa a tela
    }
    
    return 0;
}
