#include <stdio.h>
#include <stdlib.h>

/* Aspectos procedimentales
Resolver los siguientes enunciados. Para esto se debera entregar el diagrama de flujos y el codigo fuente correspondiente a cada uno. 
Nota: Debe utilizar al menos una funcion 
1) Una ferreteria recibe a diario pedidos de sus 200 clientes, esta ferreteria comercializa 1000 tipos distintos de lamparas y posee 10 
    empleados encargados de la recepcion y entrega de los pedidos.  Se sabe que tienen los siguientes lotes de datos

Lote 1
    Numero de lampara
    Precio
    Stock actual
Lote 2
    Nro de empleado 
    Comision sobre las ventas
Cada vez que recibe un pedido tiene los siguientes datos, que finalizan con nro de pedido=0
    Numero de pedido
    Numero de lampara
    Cantidad pedida
    Empleado que atendio el pedido
Resolver:
Solo se pueden vender aquellas lamparas que tienen stock suficiente para cumplimentar el pedido. Cada vez que se efectue un pedido 
correctamente se debe actualizar el stock.
Se desea saber:
a) Que cantidad de pedidos atendio cada empleado para cada tipo de lampara
b) lampara mas solicitada
c) Para cada lampara, que empleado vendio mas cantidad
d) stock final actualizado de cada numero de lampara
e) Imprima ordenado el punto 4
f) Escribir con comentarios en el codigo donde se invocan, donde se definen y donde se declaran las funciones utilizadas.
 */

// Lote 1
int lote1[3][1000],lote2[2][10],matriz[1000][4],staff[10][1000],lamps[2][1000],xlamps[10][1000],venta=1,stock=2000;
int quit=0,ordernumber=1,lampsnumber=0,order=0,employee=0,lamparas=0,EmployeeWhile=0,LamparasWhile=0,q=0,w=0,t=0,n=0,i=0,m=0,j=0,mi=0,aux0=0,aux1=0,aux2=0,aux3=0;


// Invoco funcion de empleados
int Employee();

// Invoco funcion de lamparas
int Lamparas();

int main(int argc, char *argv[]) {

    // Inicio de la matriz de lote1
	for(m=0;m<1000;m++){
        lote1[0][m]=m;
    }
    for(i=1;i<=2;i++){
        for(m=0;m<1000;m++){
			lote1[i][m]=0;
	    }
    }

    for(i=0;i<=1;i++){
	// Invoco matriz de lote2
        for(m=0;m<10;m++){
			lote2[i][m]=0;
	    }
    }
    // Invoco matriz de ventas
	for(mi=1;mi<1000;mi++){
        for(m=0;m<4;m++){
			matriz[mi][m]=0;
	    }
    }
    // Invoco matriz de Empleados
	for(mi=0;mi<10;mi++){
        for(m=0;m<1000;m++){
			staff[mi][m]=0;
	    }
    }
    // Invoco matriz de Lamparas
    
    for(m=0;m<1000;m++){
        lamps[0][m]=m;
    }
    for(mi=0;mi<1000;mi++){
        lamps[1][mi]=0;
    }
    // Invoco matriz Cantidad de Lamparas
	for(mi=0;mi<10;mi++){
        for(m=0;m<1000;m++){
			xlamps[mi][m]=0;
	    }
    }
    // Invoco Numero de stock
    for(j=0;j<1000;j++){
		lote1[2][j]=stock;
	   
    }
    // Comienza programa de opciones
    for(venta=1;venta<=20000 && quit==0;venta++)
    {
    	printf("Ingrese numero de pedido (max 1000)\nPresione 0 para finalizar el programa: ");
        scanf("%d",&ordernumber);
        switch (ordernumber)
        {
    	case 1 ... 20000:
            employee=Employee();
            lamparas=Lamparas();
                        
            
                       
            printf("Cantidad de lamparas: ");
            scanf("%d",&order);
                      
            if (lote1[2][lampsnumber]>=order)
            {
                printf("STOCK DISPONIBLE.\n");
                matriz[lampsnumber][3]+=order;
                matriz[lampsnumber][2]=lampsnumber;
                matriz[lampsnumber][1]=employee;
                lote1[2][lampsnumber]-=order; // Resta del stock del tipo de lamparas vendidas.
                lote1[0][lampsnumber]=lampsnumber; // Asigna numero de lampara al lote1.
                staff[employee][lampsnumber]++; // Adiciona 1 al contador de cantidad de transacciones por lampara
                lamps[1][lampsnumber]+=order; // Adiciona 1 al contador de lampara mas solicitada
                xlamps[employee][lampsnumber]+=order; // Adiciona la cantidad de lamparas pedidas por vendedor [x][]/ tipo de lampara [][x]
            }
            else{
                printf("SIN STOCK.\n");
            }

            break;
        
        case 0:
            printf("--------------------REPORT--------------------\n");
            
            quit=1;
            break;

        default:
            printf("ERROR!\n");
            break;
        }
    }

    // Ordena para el punto b) de mayor a menor, usando Lamparas[x][] x como id de lampara y  Lamparas[][x] como cantidad de lamparas.
    n = 1000;
    for(i=0;i<n-1;i++){
        for(t=0;t<n-1;t++){
            
            if (lamps[1][t+1]>lamps[1][t]){
                aux1=lamps[1][t+1];
                aux2=lamps[0][t+1];
                lamps[1][t+1]=lamps[1][t];
                lamps[0][t+1]=lamps[0][t];
                lamps[1][t]=aux1;
                lamps[0][t]=aux2;
            }
    
            
        }
    }

    // Ordena para el punto c) de mayor a menor, usando Lamparas[x][] x como id de lampara y  Lamparas[][x] como cantidad de lamparas.
    
    n = 1000;
    for(i=0;i<n-1;i++){
        for(t=0;t<n-1;t++){
            if (matriz[t+1][3]>matriz[t][3]){
                aux3=matriz[t+1][3];
                aux2=matriz[t+1][2];
                aux1=matriz[t+1][1];
                aux0=matriz[t+1][0];
                matriz[t+1][3]=matriz[t][3];
                matriz[t+1][2]=matriz[t][2];
                matriz[t+1][1]=matriz[t][1];
                matriz[t+1][0]=matriz[t][0];
                matriz[t][3]=aux3;
                matriz[t][2]=aux2;
                matriz[t][1]=aux1;
                matriz[t][0]=aux0;
            }
    
            
        }
    }   
    // Ordena el stock para el punto e) de mayor a menor, usando lote1[2][t]
    n = 1000;
    for(i=0;i<n-1;i++){
        for(t=0;t<n-1;t++){
            if (lote1[2][t+1]>lote1[2][t]){
                aux2=lote1[2][t+1];
                aux1=lote1[1][t+1];
                aux0=lote1[0][t+1];
                lote1[2][t+1]=lote1[2][t];
                lote1[1][t+1]=lote1[1][t];
                lote1[0][t+1]=lote1[0][t];
                lote1[2][t]=aux2;
                lote1[1][t]=aux1;
                lote1[0][t]=aux0;
            }
    
            
        }
    }
    
    // Lampara mas vendida, punto A
    for (q=0;q<10;q++){
        for (w=0;w<1000;w++){
            if (staff[q][w]!=0){
                printf("El empleado %d vendio %d pedido/s del modelo de lampara %d.\n",q,staff[q][w],w);
            }
        }
    }

    // Lampara mas vendida, punto B
    printf("Modelo de lampara mas vendido %d, se vendieron %d unidades.\n",lamps[0][0],lamps[1][0]);
    
    // Para cada lampara, que empleado vendio mas cantidad
    for (q=0;q<1000;q++){
        if (matriz[q][3]!=0){
            printf("Cantidad de lamparas vendidas %d, ventas realizadas por el empleado %d, modelo de lampara %d.\n",matriz[q][3],matriz[q][1],matriz[q][2]);
        } 
    }
    // Stock final de cada tipo de lampara
    for (w=0;w<1000;w++){
    	if (lote1[0][w] && lote1[2][w]<stock){
		printf("Modelo de lampara %d / Stock disponible: %d \n",lote1[0][w],lote1[2][w]);
		}
        
    }
return 0;
}

int Employee(){
    EmployeeWhile=0; // pongo EmpleadoWhile en 0 para arrancar el loop
    while (EmployeeWhile==0)
    {
        printf("Venta efectuada por el empleado: ");
        scanf("%d",&employee);

        if (employee>=0 && employee<10)
        {
            
            EmployeeWhile=1;
            return employee;
        }
        else
        {
            printf("Ingrese un numero de empleado valido (min 0 / max 9)\n");
        }
    }
}

int Lamparas(){
    LamparasWhile=0; // pongo EmpleadoWhile en 0 para arrancar el loop
    while (LamparasWhile==0)
    {
        printf("Modelo de lampara: ");
        scanf("%d",&lampsnumber);

        if (lampsnumber>=0 && lampsnumber<1000)
        {
            
            LamparasWhile=1;
            return lampsnumber;
        }
        else
        {
            printf("Ingrese un numero de lampara valido (min 0 / max 999)\n");
        }
    }
}

