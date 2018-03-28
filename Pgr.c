


# include <stdio.h>
# include <string.h>
# include <stdlib.h>
void main()
{
char add[6],length[10],input[10],binary[12],bitmask[12],relocbit;
int start,inp,len,i,address,opcode,addr,actualadd;
FILE *fp1,*fp2;
printf("Enter the actual starting address : ");
scanf("%d",&start);
fp1=fopen("relinput.dat","r");
fp2=fopen("reloutput.dat","w");
fscanf(fp1,"%s",input);
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(fp1,"%s",add);
fscanf(fp1,"%s",length);
fscanf(fp1,"%s",input);
}
if(strcmp(input,"T")==0)
{
fscanf(fp1,"%d",&address);
fscanf(fp1,"%s",bitmask);
address+=start;
len=strlen(bitmask);
for(i=0;i<len;i++)
{
fscanf(fp1,"%d",&opcode);
fscanf(fp1,"%d",&addr);
relocbit=bitmask[i];
if(relocbit=='0')
actualadd=addr;
else
actualadd=addr+start;
fprintf(fp2,"%d\t%d%d\n",address,opcode,actualadd);
address+=3;
}
fscanf(fp1,"%s",input);
}
}
fclose(fp1);
fclose(fp2);
printf("FINISHED");
}
INPUT : RELINPUT.DAT
H 1000 200
T 1000 11001 14 1033 48 1039 90 1776 92 1765 57 1765T 2011 11110 23 1838 43 1979 89 
1060 66 1849 99 1477
E 1000
