%{
int ch=0, bl=0, ln=0, wr=0;
%}
%%
[\n] {ln++;wr++;}
[\t] {bl++;wr++;}
[" "] {bl++;wr++;}
[^\n\t] {ch++;}
%%
int main()
{
FILE *fp=fopen("hello.txt","r");
 char file[10];
//printf("\nEnter the filename: ");
yyin=fp;
yylex();
printf("\nTotal No. of Characters are=%d\nTotal No. of Blank Spaces=%d\nTotal No. of Lines=%d\nTotal No. of Words=%d\n", ch, bl, ln, wr); 
return 0;
}
