#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista Lista;
typedef struct Nodo Nodo;

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

struct Lista
{
	Nodo *inicio;
};

struct Estudiante
{
    char nombre[100];
    char carrera[100];
    char correo[200];
    int carnet, numero;
}est;

Lista *listaNueva(void)
{
	Lista *L;
	L = (Lista *) malloc(sizeof(Lista));
	L->inicio = NULL;
	return L;
}

void agregarEstudiante()
{
    int M,A;
    Lista *L;
    printf("Indique el nombre: ");
    gets(est.nombre);
    printf("\nIndique la carrera: ");
    gets(est.carrera);
    printf("Indique el correo: ");
    gets(est.correo);
    printf("Indique el carnet: ");
    scanf("%d",&est.carnet);
    printf("Indique el numero telefonico: ");
    scanf("%d",&est.numero);
    FILE *ptr;
    ptr = fopen("nuevo.txt", "a+");
    //A = &est.carnet;
    //insertarDato(L,A);
    M = verificarCarnet(L, est.carnet);
    if(M==-1){
        fwrite(&est, sizeof(est), 1, ptr);
        printf("DATOS GUARDADOS...");
    }else{
        int opcion;
            printf("Parece que este carnet ya esta registrado. ¿Desea intentarlo de nuevo?\n\n[1] Intentar de nuevo\n[2] Ir al menu principal\n\n");
            scanf("%d", opcion);
            if(opcion == 1){
                return agregarEstudiante();
            }else
            {
            return;
            }
    }

    fclose(ptr);
}

void insertarDato(Lista *L, int dato)
{
	Nodo *n, *aux;

	if(L->inicio == NULL)
	{
		L->inicio = (Nodo *) malloc(sizeof(Nodo));
		L->inicio->dato = dato;
		L->inicio->siguiente = NULL;
		return;
	}
	n = L->inicio;
	while(n!= NULL)
	{
		aux = n;
		n = n->siguiente;
	}
	aux->siguiente = (Nodo *) malloc(sizeof(Nodo));
	aux->siguiente->siguiente = NULL;
	aux->siguiente->dato = dato;
}

void verificarCarnet(Lista*L, int elemento)
{
    Nodo *current = L->inicio;
    int posicion = 0;
    while(current!=NULL){
        if(current->dato==elemento){
            return posicion;
        }
        current = current->siguiente;
        ++posicion;
    };
    return -1;
}

int main()
{
    agregarEstudiante();
	return 0;
}



