#include<stdio.h>
#include<string.h>

main()
{
  char opcode[10],operand[10],label[10],code[10][10],ch,op[10],ml_equ[2];
  int locctr,start,len,i=0,j=0,f;
  
  FILE *fp1,*fp2,*fp3,*fp4;
  fp1=fopen("INPUT.DAT","r");//mnemonic code
  fp2=fopen("SYMTAB.DAT","wb+");//SYMTAB
  fp3=fopen("INERMEDIATE.DAT","wb+");//intermediate file
  fp4=fopen("OPTAB.DAT","r");//OPTAB

  fscanf(fp1,"%s%s%s",label,opcode,operand);//read the first input line

  if(strcmp(opcode,"START")==0)
  {
    start = atoi(operand);//save starting_address <- #[OPERAND]
    locctr = start;//LOCCTR <- starting_address
    fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);//write line to intermediate file
    fscanf(fp1,"%s%s%s",label,opcode,operand);//read next input line
  }
  else
    locctr=0;//LOCCTR <- 0

  while(strcmp(opcode,"END")!=0)
  {
    fprintf(fp3,"%d",locctr);
    if(strcmp(label,"**")!=0)//label exists
    { 
      //search SYMTAB for LABEL
      //if found error = 1
      //else
        fprintf(fp2,"%s\t%d\n",label,locctr);//insert{LABEL, LOCCTR} into SYMTAB
    }
    //search optab for opcode
    f = 0;
    fseek(fp4,0,SEEK_SET);
    while(!feof(fp4))
    {
      fscanf(fp4,"%s%s",op,ml_equ);
      if(strcmp(opcode,op)==0)//opcode found
      {  
          locctr+=3;
          f=1;
          break;
      }
    }
    //check if opcode is an assembler directive
    if(f==0)
    {
      if(strcmp(opcode,"WORD")==0)
          locctr+=3;
      else if(strcmp(opcode,"RESW")==0)
          locctr+=(3*(atoi(operand)));
      else if(strcmp(opcode,"RESB")==0)
          locctr+=(atoi(operand));
      else if(strcmp(opcode,"BYTE")==0)
          locctr+=strlen(operand)-3; //since C'' or X'' has to be removed from the string length
      //else
      // set error
    }

    fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);//write line to intermediate file
    fscanf(fp1,"%s%s%s",label,opcode,operand);//read next input line

  }

  fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);//write last line to intermediate file

//displaying the output in console

  printf("\n\nThe mnemonic code:\n\n");
  fseek(fp1,0,SEEK_SET);
  while((ch=fgetc(fp1))!=EOF)
    printf("%c",ch);

  printf("\n\nThe contents of intermediate file :\n\n\t");
  fseek(fp3,0,SEEK_SET);
  while((ch = fgetc(fp3))!=EOF)
    printf("%c",ch);

  len=locctr-start;//pgm_len = LOCCTR - starting_address
  printf("\nThe length of the program is %d.\n\n",len);

  printf("\n\nThe contents of SYMTAB:\n\n");
  fseek(fp2,0,SEEK_SET);
  while((ch = fgetc(fp2))!=EOF)
    printf("%c",ch);

  fcloseall();
}
