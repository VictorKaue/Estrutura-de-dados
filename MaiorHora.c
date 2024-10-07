#include <stdio.h>
#include <stdlib.h>


typedef struct horas{
    int hora;
    int minuto;
    int segundo;
}Horas;

void imprimirHorarios(Horas *horario){
    int i;
    for (i = 0; i < 5; i++){
        printf("\nhorario %d\n", i+1);
        printf("Horas: %d\n", horario[i].hora); 
        printf("Minutos: %d\n", horario[i].minuto);
        printf("Segundos: %d\n", horario[i].segundo);
    }
}

Horas maiorHorario(Horas *horario){
    int i;
    int maior = 0;
    for (i = 0; i < 5; i++){
        if(horario[i].hora > horario[maior].hora){
            maior = i;
        } else if(horario[i].hora == horario[maior].hora && horario[i].minuto > horario[maior].minuto){
            maior = i;
        } else if(horario[i].hora == horario[maior].hora && horario[i].minuto == horario[maior].minuto && horario[i].segundo > horario[maior].segundo){
            maior = i;    
        }
    }
    return horario[maior];
}

Horas menorHorario(Horas *horario){
    int i;
    int menor = 0;

    for (i = 0; i < 5; i++){
        if(horario[i].hora < horario[menor].hora){
            menor = i;
        } else if(horario[i].hora == horario[menor].hora && horario[i].minuto < horario[menor].minuto){
            menor = i;
        } else if(horario[i].hora == horario[menor].hora && horario[i].minuto == horario[menor].minuto && horario[i].segundo < horario[menor].segundo){
            menor = i;    
        }
    }
    return horario[menor];
}

void incializarAleatoriamente(Horas *horario){
    int i;
    for (i = 0; i < 5; i++){
        horario[i].hora = rand() %25;
        horario[i].minuto = rand() %61;
        horario[i].segundo = rand() %61;
    }
}

void inicializarManualmente(Horas *horario){
    int i = 0;
    while (i < 5){
        printf("Digite as horas: ");
        scanf("%d", &horario[i].hora);
        printf("Digite os minutos: ");
        scanf("%d", &horario[i].minuto);
        printf("Digite os segundos: ");
        scanf("%d", &horario[i].segundo);
        if (horario[i].hora < 0 && horario[i].hora > 24){
            printf("Hora inválida!\n");
        }else if(horario[i].minuto < 0 && horario[i].minuto > 60){
            printf("Minuto inválido!\n");
        } else if(horario[i].segundo < 0 && horario[i].segundo > 60){
            printf("Segundo inválido!\n");
        } else{
            i++;
        }
        
        
    }

}

int main(){
    Horas horario[5];
    Horas MaiorHorario;
    Horas MenorHorario;
    int op;
    printf("Digite [1] para inicializar manualmente e [2] para inicializar aleatoriamente: ");
    scanf("%d", &op);
    if(op == 1){
        inicializarManualmente(horario);
    } else{
        incializarAleatoriamente(horario);
    }
    imprimirHorarios(horario);
    MaiorHorario = maiorHorario(horario);
    MenorHorario = menorHorario(horario);

    printf("Maior horario: %d:%d:%d\n", MaiorHorario.hora, MaiorHorario.minuto, MaiorHorario.segundo);
    printf("Maior horario: %d:%d:%d\n", MenorHorario.hora, MenorHorario.minuto, MenorHorario.segundo);
    

    return 0;
}