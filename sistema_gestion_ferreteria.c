#include <stdio.h>
#include <stdlib.h>
#define nrolamp 10
#define numeroempl 10
struct lampara {
 int numerolamp, stock, vendedormax, maxcantvendida;

 float precio;
};
void buscarlampara(struct lampara lamparas[], int n, int buscar, int *posicion) {
 int i;
 *posicion = -1;
 for (i = 0; i < n; i++) {
 if (lamparas[i].numerolamp == buscar) {
 *posicion = i;
 break;
 }
 }
}
int main() {
 struct lampara lamparas[nrolamp];
 int posicion;
 int i;
 int nropedido, nrolampapedido, nroempleado, cantpedido;
 printf("Ingrese datos de %d lamparas: ", nrolamp);
 for (i = 0; i < nrolamp; i++) {
 printf("Lampara %d:\n", i + 1);
 printf("Numero (3 digitos): ");
 scanf("%d", &lamparas[i].numerolamp);
 printf("Precio: ");
 scanf("%f", &lamparas[i].precio);
 printf("Stock: ");
 scanf("%d", &lamparas[i].stock);
 lamparas[i].vendedormax = -1;
 lamparas[i].maxcantvendida = 0;
 }
 printf("\nIngrese pedidos (pedido 0 para finalizar):\n");
 while (1) {
 printf("Numero de pedido: ");
 scanf("%d", &nropedido);
 if (nropedido == 0)
 break;
 printf("Numero de lampara: ");
 scanf("%d", &nrolampapedido);
 printf("Numero de empleado (1-%d): ", numeroempl);
 scanf("%d", &nroempleado);
 printf("Cantidad pedida: ");
 scanf("%d", &cantpedido);
 buscarlampara(lamparas, nrolamp, nrolampapedido, &posicion);
 if (posicion == -1) {
 printf("Lampaara no encontrada.\n");
 continue;
 }
 if (lamparas[posicion].stock < cantpedido) {
 printf("Sin stock. ");
 continue;
 }
 lamparas[posicion].stock -= cantpedido;
 if (cantpedido > lamparas[posicion].maxcantvendida) {
 lamparas[posicion].maxcantvendida = cantpedido;
 lamparas[posicion].vendedormax = nroempleado;
 }
 }
 printf("\nLampara. Empleado que mas vendio. Stock \n");
 for (i = 0; i < nrolamp; i++) {
 printf(" %03d | %2d | %d\n",
 lamparas[i].numerolamp,
 lamparas[i].vendedormax,
 lamparas[i].stock);
 }
 return 0;
}
