#include<stdio.h>
#include<stdlib.h>
int main() {
int ip[4];
int i;
for (i = 0; i< 4; i++) {
printf("Enter the octet-%d: ", i);
scanf("%d", &ip[i]);
}
int p, s;
printf("Entertheprefix length:");
scanf("%d", & p);
int n;
printf("Enter the number of different blocks: ");
scanf("%d", & n);
int blocks[n][2];
for (i = 0; i< n; i++) {
printf("Enterthenumberof customers:");//
scanf("%d", & blocks[i][0]);//
printf("Enterthe addresses for each customer: ");//
scanf("%d", & blocks[i][1]);//
}
s = 32 - p;
int x, ip2[4];
x = pow(2, s);
printf("The suffix length is: %d\n", s);
printf("The total number of addresses are: %d\n", x);
int a, j, k;
for (i = 0; i< n; i++) {
int a = log2(blocks[i][1]);
a = 32 - a;
printf("\n\n");
printf("The range of addresses in block: %d\n", i + 1);
for (j = 0; j < blocks[i][0]; j++) {
for (k = 0; k < 4; k++) {
ip2[k] = ip[k];
}
printf("%d.%d.%d.%d/%d - ", ip[0], ip[1], ip[2], ip[3], a);
for (k = 3; k >= 0; k--) {
if (ip2[k] >= 255) {
ip2[k] = 0;
ip2[k - 1] = ip2[k - 1] + 1;
}
}
ip2[3] = ip2[3] + blocks[i][1] - 1;
printf("%d.%d.%d.%d/%d", ip2[0], ip2[1], ip2[2], ip2[3], a);
printf("\n");
for (k = 0; k < 4; k++) {
ip[k] = ip2[k];
}
ip[3] = ip[3] + 1;
for (k = 3; k > 0; k--) {
if (ip[k] >= 255) {
//printf("%d Address =>",ip[k-1]); 
ip[k]=0;
ip[k - 1] = ip[k - 1] + 1;
}
}
}
}
int b = 0;
for (i = 0; i< n; i++) {
b = b + (blocks[i][0] * blocks[i][1]);
}
x = x - b;
printf("\n");
printf("The remaining addresses are:%d", x);
}
