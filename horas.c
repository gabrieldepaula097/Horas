#include <stdio.h>

int main(void){
    int horaEntrada, minutosEntrada;
    int horaIdaAlmoco, minutosIdaAlmoco;
    int horaVoltaAlmoco, minutosVoltaAlmoco;
    int horaDesconto, minutosDesconto;
    int horaSaida;
    int horasEstagio = 360;
    int antesAlmoco, horasFaltantes, minutos, horas;
    char op = 'Y', opAlmoco, opDesconto;

    while(op == 'Y'){
        printf("Entrada(HH MM): ");
        scanf(" %d %d", &horaEntrada, &minutosEntrada);
        printf("\n");

        while(1){
            printf("Almoço? (Y/N)");
            scanf("%s", &opAlmoco);

            if(opAlmoco == 'Y'){
                printf("Ida Almoço(HH MM): ");
                scanf("%d %d", &horaIdaAlmoco, &minutosIdaAlmoco);
                printf("Volta Almoço(HH MM): ");
                scanf("%d %d", &horaVoltaAlmoco, &minutosVoltaAlmoco);
                printf("\n");

                printf("Tem horas adiantadas? (Y/N)");
                scanf("%s", &opDesconto);
    
                if(opDesconto == 'Y'){
                    printf("Desconto de Horas adiantadas(HH MM): ");
                    scanf("%d %d", &horaDesconto, &minutosDesconto);
                    printf("\n");
                }else if(opDesconto == 'N'){
                    horaDesconto = 00;
                    minutosDesconto = 00;
                    printf("\n");
                }else{
                    printf("Desconto inválido, somente Y e N\n");
                }

                antesAlmoco = ((horaIdaAlmoco * 60) + minutosIdaAlmoco)- ((horaEntrada * 60) + minutosEntrada);
                //Horas trabalhadas até sair pro almoço
                horasFaltantes = horasEstagio - antesAlmoco - ((horaDesconto * 60)+minutosDesconto);
                minutos = horasFaltantes % 60;
                horas = (horasFaltantes - minutos)/60;
                printf("Horas Faltantes: %.2d:%.2d\n", horas, minutos);

                horaSaida = ((horaVoltaAlmoco * 60) + minutosVoltaAlmoco) + horasFaltantes;
                minutos = horaSaida % 60;
                horas = (horaSaida - minutos)/60;
                printf("Horário de saída: %.2d:%.2d\n", horas, minutos);
                printf("\n");
                break;
            }else if(opAlmoco == 'N'){
                printf("Tem horas adiantadas? (Y/N)");
                scanf("%s", &opDesconto);
    
                if(opDesconto == 'Y'){
                    printf("Desconto de Horas adiantadas(HH MM): ");
                    scanf("%d %d", &horaDesconto, &minutosDesconto);
                    printf("\n");
                }else if(opDesconto == 'N'){
                    horaDesconto = 00;
                    minutosDesconto = 00;
                    printf("\n");
                }else{
                    printf("Desconto inválido, somente Y e N\n");
                }

                horaSaida = (((horaEntrada * 60) + minutosEntrada) + horasEstagio) - ((horaDesconto * 60)+minutosDesconto);
                minutos = horaSaida % 60;
                horas = (horaSaida - minutos)/60;
                printf("Horário de saída: %.2d:%.2d\n", horas, minutos);
                break;
            }else{
                printf("Almoço inválido, somente Y e N\n");
            }
        }

        printf("\n");
        printf("\n");        
        printf("Calcular novamente?(Y/N)");
        scanf("%s", &op);
        printf("\n\n");   

        if(op != 'Y' && op != 'N'){
            printf("Opção inválida, somente Y e N\n");
            scanf("%s", &op);
            printf("\n\n");   
        }

    }    
        printf("As revoluções são a locomotiva da história (Karl Marx)\n");
}
