#include <stdio.h>
#define MAX 1000

// deklarácia funkcíí
void nacitanie_sifra(int array[], int *pocet_znakov);
void vypis_sifra(int array[], int pocet_znakov);
void uprava_sifra(int array[], int upravene_array[], int pocet_znakov, int *pocet_z_upravenych);
void vypis_upravena_sifra(int upravene_array[], int pocet_z_upravenych);
void cesarova_sifra(int upravene_array[], int pocet_z_upravenych, int n);
void vypis_slov(int array[], int pocet_znakov, int k);
void histogram(int upravene_array[], double pocet_z_upravenych);

void nacitanie_sifra(int array[], int *pocet_znakov)
{
  int k, c;
  FILE *fnacitanie;
  
  if((fnacitanie = fopen("sifra.txt", "r")) == NULL)
  {
    printf("Spravu sa nepodarilo nacitat.\n");
    return;
  }
  else
  {
  fnacitanie = fopen("sifra.txt", "r");
    while((c = fgetc(fnacitanie)) != EOF)
    {
    array[k] = c;
    k++;
    if(c>=MAX)
      break;
    }
    *pocet_znakov = k;
    fclose(fnacitanie);
  }
  
}

void vypis_sifra(int array[], int pocet_znakov)
{
	int k;
	if(pocet_znakov == 0)
	  {
	  	printf("Sprava nie je nacitana.\n");
	  } 
	else
	{
  	for (k = 0; k < pocet_znakov; k++)
    {
    	printf("%c", array[k]);
    }
    putchar('\n');
    }
}

void uprava_sifra(int array[], int upravene_array[], int pocet_znakov, int *pocet_z_upravenych)
{
  int k, j = 0;
	  if(pocet_znakov == 0)
	  {
	  	printf("Sprava nie je nacitana.\n");
      return;
	  } 
	  else
	  {
	    for(k = 0; k < pocet_znakov; k++)
		{
	      if(array[k] >= 'a' && array[k] <= 'z')
		  {
	        upravene_array[j] = (array[k]) - 'a' + 'A';
	        j++;
	      }
	      else if(array[k] >= 'A' && array[k] <= 'Z')
		  {
	        upravene_array[j] = array[k];
	        j++;
	      }
	    }
	    *pocet_z_upravenych = j;
	  }
}

void vypis_upravena_sifra(int upravene_array[], int pocet_z_upravenych)
{
  int k;
  if(pocet_z_upravenych == 0)
	{
	  printf("Nie je k dispozicii upravena sprava.\n");
    return;
	} 
  else
  {
	  for(k=0; k < pocet_z_upravenych; k++)
	  {
	  	printf("%c", upravene_array[k]);
	  }
	  putchar('\n');
  }
}

void cesarova_sifra(int upravene_array[], int pocet_z_upravenych, int n){
  int k;
  n = -n;

  if(pocet_z_upravenych == 0)
	  {
	  	printf("Nie je k dispozicii upravena sprava.\n");
      return;
	  } 
    
  else
  {
  for(k=0; k < pocet_z_upravenych; k++)
  {
    if(upravene_array[k] - n < 'A')
      printf("%c", 'Z' - ('A'- upravene_array[k] + n));
    else
      printf("%c", upravene_array[k] + n);
  }
  putchar('\n');
  }
}

void vypis_slov(int array[], int pocet_znakov, int k)
{
	int i, j, m;

	if(pocet_znakov == 0)
	{
		printf("Sprava nie je nacitana");
		return;
    }

	if(k >= 1 && k <= 100)
	{
		for(i = 0; i <= pocet_znakov; i++)
    	{
			if (i == pocet_znakov)
      		{
				if (j == k)
        		{
					for (m = i - k; m < i; m++)
          			{
						printf("%c", array[m]);
          			}
				}
				else 
				j=0;
			}

			if (array[i] != ' ' && array[i] != '\n')
      		{
			  j++;	
			}
				
			if (array[i] == ' ')
			{
				if (j == k)
        		{
					for (m = i - k; m < i; m++)
          			{
						printf("%c", array[m]);
          			}
					j=0;
					putchar('\n');
          		}
				    else
				    j=0;
			 }
 
			 if (array[i] == '\n')
       		 {
        		if (j == k)
        		{
          			for (m = i-k; m < i ; m++)
          			{
            			printf("%c", array[m]);
          			}
            		j=0;
            		putchar('\n');
        		}
        		else
        		{
          			j=0;
        		}	
			}
		}
	}
}

void histogram(int upravene_array[], double pocet_z_upravenych)
{
  int i, j;
  int array[26];
  
  if(pocet_z_upravenych == 0)
  {
		printf("Nie je k dispozicii upravena sprava");
		return;
  }
  for(i=0; i <= 25; i++)
  {
    array[i]=0;
  }
  for(i = 0; i < pocet_z_upravenych; i++){
    array[upravene_array[i] - 'A']++;
  }
  for(i = 0; i < 10 ; i++)
  {
      for(j = 0; j <= 25; j++)
      {
          if((array[j]) / pocet_z_upravenych * 10 > 9 - i )
          {
              putchar('*');
          }
          else
          {
            putchar(' ');
          }
      }
      putchar('\n');
  } 
      for(i = 0; i < 26; i++)
      {
        printf("%c", 'A' + i);
      }    
}

int main()
{
  int array[MAX], upravene_array[MAX];
  int pocet_znakov, pocet_z_upravenych, k, n;
  char c;
  while((c = getchar()) != 'k'){ 
    switch(c){
      case 'n': nacitanie_sifra(array, &pocet_znakov); 
	   break;
      case 'v': vypis_sifra(array, pocet_znakov);
	   break;
      case 'u': uprava_sifra(array, upravene_array, pocet_znakov, &pocet_z_upravenych);
	   break;
      case 's': vypis_upravena_sifra(upravene_array, pocet_z_upravenych);
	   break;
      case 'd': 
	  	  scanf("%d",&k);
		    vypis_slov(array, pocet_znakov, k);
	   break;
      case 'h': histogram(upravene_array, pocet_z_upravenych);
	   break;
      case 'c': 
        scanf("%d",&n);
        cesarova_sifra(upravene_array, pocet_z_upravenych, n);
	   break;
    }
  }
  return 0;
}
