//Simple C program to encrypt and decrypt a string

#include <stdio.h>

int main()
{

   int i, x,key;
   char str[100];

   printf("\nPlease enter your sentence:\t");
   gets(str);

   printf("Enter key for encryption: ");
   scanf("%d",&key);
    do
    {
   printf("\nPlease choose following options:\n");
   printf("1 = Encrypt the sentence.\n");
   printf("2 = Decrypt the sentence.\n");
   scanf("%d", &x);

   //using switch case statements
   switch(x)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + key; //the key for encryption added to ASCII value

      printf("\nEncrypted string: %s\n", str);
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - key; //the key for encryption subtracted to ASCII value

      printf("\nDecrypted string: %s\n", str);
      break;

   default:
      printf("\nError\n");
   }
    }while(x!=0);
   return 0;
}
