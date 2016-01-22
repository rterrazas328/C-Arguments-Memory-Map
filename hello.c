#include<stdio.h>
#include<stdint.h>

void displaySplitVal(int addrV, int* addrA){
int q;
unsigned int mask=255;
for (q=sizeof(int); q>0; q--){
  int pval = (addrV>>(q-1)*8)&mask;
  printf("%x|",pval);
  }
printf("	%x\n", addrA);
}

void displaySplitArgv(char **addrV, char ***addrA){
int q;
int addrIV = (intptr_t)addrV;
unsigned int mask=255;
for (q=sizeof(int); q>0; q--){
  int pval = (addrIV>>(q-1)*8)&mask;
  printf("%x|",pval);
  }
printf("	%x\n", addrA);
}

void displaySplitAddress(char * addrV, char** addrA){
int q;
int addrIV = (intptr_t)addrV;
unsigned int mask=255;
for (q=sizeof(int); q>0; q--){
  int pval = (addrIV>>(q-1)*8)&mask;
  printf("%x|",pval);
  }
printf("	%x\n", addrA);
}

int main(int argc, char *argv[]) {
printf("\n");

printf("argc |");
displaySplitVal(argc, &argc);
printf("argv |");
displaySplitArgv(argv, &argv);
//printf("argv is %x and &argv is %x\n", argv, &argv);

printf("\n");
int i;
for(i=0;i<argc;i++){
  printf("argv[%d] |",i);
  displaySplitAddress(argv[i], &argv[i]);
  }

printf("\n");

int u;
for (u=0; u<argc; u++){
printf("        ");
while (**argv!=0){
	printf("|%c",**argv );
	*argv+=1;

}
printf("	%x\n", *argv);
argv+=1;
}
return 0;
}
