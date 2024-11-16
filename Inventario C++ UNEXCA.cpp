//LIBRERIAS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <direct.h>
#include <time.h>
#include <string.h>

//MODULOS

void Registro ();
void Consulta ();
void Modificar ();
void Desincorporar ();
void Listar ();
void Ayuda ();
void Creditos ();
void Salir ();

void gotoxy (int x, int y){
	HANDLE hcon = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition (hcon, dwPos);
}

struct {
	char NBP [8];
	char MAR [15];
	char USU [20];
	char DPTO [30];
	char FREG [9];
	char FMOD [9];
	char FDES [9];
} PC;

//ALIAS

FILE*PRINCIPAL;
FILE*AUXILIAR;
FILE*DESI;

//VARIABLES

int OP, OP1, OP2, OP3;
int RE=0;
char BBP[6];

time_t tiempo=time (0);
struct tm *tlocal = localtime (&tiempo);

int main (){
	do {
		
		system("color 17");
		system("mode con: lines=47 cols=115");
		                                                                                                 
    gotoxy (2,2); printf("||||======================================================================================================||||");
	gotoxy (2,3); printf("||||======================================================================================================||||");
	gotoxy (2,4); printf("||||                                                                                                      ||||");
	gotoxy (2,5); printf("||||                                                                                                      ||||");
	gotoxy (2,6); printf("||||                                                                                                      ||||");
	gotoxy (2,7); printf("||||                                                                                                      ||||");
	gotoxy (2,8); printf("||||                                                                                                      ||||");
	gotoxy (2,9); printf("||||                                                                                                      ||||");
	gotoxy (2,10); printf("||||                                                                                                      ||||");
	gotoxy (2,11); printf("||||                                                                                                      ||||");
	gotoxy (2,12); printf("||||                                                                                                      ||||");
	gotoxy (2,13); printf("||||                                                                                                      ||||");
	gotoxy (2,14); printf("||||                                                                                                      ||||");
	gotoxy (2,15); printf("||||                                                                                                      ||||");
	gotoxy (2,16); printf("||||                                                                                                      ||||");
	gotoxy (2,17); printf("||||                                                                                                      ||||");
	gotoxy (2,18); printf("||||                                                                                                      ||||");
	gotoxy (2,19); printf("||||                                                                                                      ||||");
	gotoxy (2,20); printf("||||                                                                                                      ||||");
	gotoxy (2,21); printf("||||                                                                                                      ||||");
	gotoxy (2,22); printf("||||                                                                                                      ||||");
	gotoxy (2,23); printf("||||                                                                                                      ||||");
	gotoxy (2,24); printf("||||                                                                                                      ||||");
	gotoxy (2,25); printf("||||                                                                                                      ||||");
	gotoxy (2,26); printf("||||                                                                                                      ||||");
	gotoxy (2,27); printf("||||                                                                                                      ||||");
	gotoxy (2,28); printf("||||                                                                                                      ||||");
	gotoxy (2,29); printf("||||                                                                                                      ||||");
	gotoxy (2,30); printf("||||                                                                                                      ||||");
	gotoxy (2,31); printf("||||                                                                                                      ||||");
	gotoxy (2,32); printf("||||                                                                                                      ||||");
	gotoxy (2,33); printf("||||                                                                                                      ||||");
	gotoxy (2,34); printf("||||                                                                                                      ||||");
	gotoxy (2,35); printf("||||                                                                                                      ||||");
	gotoxy (2,36); printf("||||                                                                                                      ||||");
	gotoxy (2,37); printf("||||                                                                                                      ||||");
	gotoxy (2,38); printf("||||                                                                                                      ||||");
	gotoxy (2,39); printf("||||                                                                                                      ||||");
	gotoxy (2,40); printf("||||                                                                                                      ||||");
	gotoxy (2,41); printf("||||                                                                                                      ||||");
	gotoxy (2,42); printf("||||======================================================================================================||||");
	gotoxy (2,43); printf("||||======================================================================================================||||");
	
	gotoxy (32,30); printf("UNIVERSIDAD NACIONAL EXPERIMENTAL DE LA GRAN CARACAS");
	gotoxy (55,32); printf("PRESENTA: ");
	
	gotoxy (8,5); printf("		                                                     .~^                ");                          
    gotoxy (8,6); printf("		                                                    11?#J               ");                   
    gotoxy (8,7); printf("		                                                    1BB#J               ");                   
    gotoxy (8,8); printf("	                                    SYJJJJY1   7YJJJYBBBPJJY^               ");               
    gotoxy (8,9); printf("	                                7555B#BBBB#G555G#BBBBBBBB#B#P5551    ^55555555Y      ");      
  	gotoxy (8,10); printf("               SPPPPPPPS      !PPPBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB##GPPPPGBBB##BBBBPPPPG?    ");  
  	gotoxy (8,11); printf("   YGGBJIIIYGGBGGGGBBBBBBBGGGGGGGBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPPB#BBBBBBBGPB#BBBBBBBBGGBS "); 
  	gotoxy (8,12); printf("   YBBBBBBBB#55BB###BBBBBBBBBBBBBB#GYG#BBBBB##BBBBPYYYGB#BY5BBBBBPY^ J5BBBBBB#7 S5GBB##BBBBB#1  ");
  	gotoxy (8,13); printf("   YBB###BBYS  GGJJJ5BB#BBBBB##BBPJS IJGB#BJJJYBB#7   5BY IBBBBBIS    7GB###BB7   PBJJJYBBB5J^  ");
  	gotoxy (8,14); printf("   YBP7775#I  1GP   I#Y7P#BB?77J#J     5B?I   SBB#7   PB.  IBBBBBI    7GG777Y#7   PG7  ^BB#7    ");
  	gotoxy (8,15); printf("   Y#Y   J#I  1GP   I#7  1PB1  V#Y     5BI    SBB#7   PBI  IBBBB#I    7BP   7#7   PB7  S#5S1    ");
  	gotoxy (8,16); printf("   Y#Y   1^I  1GP   I#7   5B1  .^1     5BI    SBB#7   5G.  I#5222Q    7G5   7#7   5G7  S#J      ");
  	gotoxy (8,17); printf("   YGJ    :   1P5   I:I   YP.      YGI    .17B!   11   IG?     11II   1B1   11    SG6      ");
   	gotoxy (8,18); printf("	           11                                                                               ");
    gotoxy (8,19); printf("                                                                                             ");
 	gotoxy (11,20); printf(" 211  171        11   ^71          S7777S        S71 ^7S           S!7!~.              ~.     ");
 	gotoxy (11,21); printf(" 1#Y  !#?        1B5! J#2          J#5           1PGJBJX         15G   Y1             J#Y     ");
  	gotoxy (11,22); printf(" 1#Y  7#7        1#5YPG#2          J#5            ^B#P.          1&J                 J# #Y    ");
   	gotoxy (11,23); printf("  P5YPY          1#7  ?G2          JB5Y52        SGY!PP1          SP5Y552           JBJ  GY.  ");
                                                                                    
	Sleep(1800);
	
		system("color 07");
		system("mode con: lines=30 cols=85");

	gotoxy (3,3); printf("---                                                                         ---");
	gotoxy (3,4); printf("---                                                                         ---");
	gotoxy (3,5); printf("---                                                                         ---");
	gotoxy (3,6); printf("---                                                                         ---");
	gotoxy (3,7); printf("---                                                                         ---");
	gotoxy (3,8); printf("---                                                                         ---");
	gotoxy (3,9); printf("---                                                                         ---");
	gotoxy (3,10); printf("---                                                                         ---");
	gotoxy (3,11); printf("---                                                                         ---");
	gotoxy (3,12); printf("---                                                                         ---");
	gotoxy (3,13); printf("---                                                                         ---");
	gotoxy (3,14); printf("---                                                                         ---");
	gotoxy (3,15); printf("---                                                                         ---");
	gotoxy (3,16); printf("---                    BIENVENIDO AL SISTEMA DE INVENTARIO                  ---");
	gotoxy (3,17); printf("---                                                                         ---");
	gotoxy (3,18); printf("---                                                                         ---");
	gotoxy (3,19); printf("---                                                                         ---");
	gotoxy (3,20); printf("---                                                                         ---");
	gotoxy (3,21); printf("---                                                                         ---");
	gotoxy (3,22); printf("---                                                                         ---");
	gotoxy (3,23); printf("---                                                                         ---");
	gotoxy (3,24); printf("---                                                                         ---");
	gotoxy (3,25); printf("---                                                                         ---");
	
	gotoxy (11,7); printf  ("888b     d888                   d8b 888                   888");
	gotoxy (11,8); printf  ("8888b   d8888                   Y8P 888                   888");
	gotoxy (11,9); printf  ("88888b.d88888                       888                   888");
	gotoxy (11,10); printf ("888Y88888P888  .d88b.  888  888 888 888 88888b.   .d88b.  888888");
	gotoxy (11,11); printf ("888 Y888P 888 d88  88b 888  888 888 888 888 .88b d8P  Y8b 888");
	gotoxy (11,12); printf ("888  Y8P  888 888  888 Y88  88P 888 888 888  888 88888888 888");
	gotoxy (11,13); printf ("888   *   888 Y88..88P  Y8bd8P  888 888 888  888 Y8b.     Y88b.");
	gotoxy (11,14); printf ("888       888  *Y88P*    Y88P   888 888 888  888 Y8888    Y888");

		Sleep(1980);	
				
		system ("color f0"); 
		system ("mode con: lines=35 cols=75");
		
		gotoxy (2,2);   printf("||||===============================================================||||");
		gotoxy (2,3);   printf("||||===============================================================||||");
		gotoxy (2,4);   printf("||||                                                               ||||");
		gotoxy (2,5);   printf("||||                       SECCI\340N PRINCIPAL                       ||||");
		gotoxy (2,6);   printf("||||===============================================================||||");
		gotoxy (2,7);   printf("||||===============================================================||||"); 
	   	gotoxy (2,8);   printf("||||                                                               ||||");
		gotoxy (2,9);   printf("||||                      1) Ingresar equipo                       ||||"); 
		gotoxy (2,10);  printf("||||                                                               ||||");
		gotoxy (2,11);  printf("||||                      2) Consultar equipo                      ||||");
		gotoxy (2,12);  printf("||||                                                               ||||");
		gotoxy (2,13);  printf("||||                      3) Modificar equipo                      ||||");
		gotoxy (2,14);  printf("||||                                                               ||||");
		gotoxy (2,15);  printf("||||                      4) Eliminar equipo                       ||||");
		gotoxy (2,16);  printf("||||                                                               ||||");
		gotoxy (2,17);  printf("||||                      5) Ver reporte                           ||||");
		gotoxy (2,18);  printf("||||                                                               ||||");
		gotoxy (2,19);  printf("||||                      6) Ayuda                                 ||||");
		gotoxy (2,20);  printf("||||                                                               ||||");
		gotoxy (2,21);  printf("||||                      7) Cr\202ditos                              ||||");
		gotoxy (2,22);  printf("||||                                                               ||||");
		gotoxy (2,23);  printf("||||                      8)  Salir                                ||||");
		gotoxy (2,24);  printf("||||                                                               ||||");
		gotoxy (2,25);  printf("||||===============================================================||||");
		gotoxy (2,26);  printf("||||                                                               ||||");
		gotoxy (2,27);  printf("||||         Indique el n\243mero de la operacion a realizar:         ||||");
		gotoxy (2,28);  printf("||||===============================================================||||");
		gotoxy (2,29);  printf("||||===============================================================||||");
		
		gotoxy (61,27); scanf("%d",&OP);
		
		switch (OP){
			case 1: system("cls");
				Registro ();
				break;
				
			case 2: system("cls");
				Consulta ();
				break;
				
			case 3: system("cls");
				Modificar ();
				break;
				
			case 4: system("cls");
				Desincorporar ();
				break;
				
			case 5: system("cls");
				Listar ();
				break;
			
			case 6: system("cls");
				Ayuda ();
				break;	
				
			case 7: system("cls");
				Creditos ();
				break;	
				
			case 8: system("cls");
				printf ("Saliendo...");
				break;
				
			default:
				printf("Opci\242n incorrecta\n");
				system("pause");
				break;
		}
	}while (OP!=7); 
}

void Registro (){
	
	do{
		system ("CLS");
		system ("color f0"); 
		system("mode con: lines=20 cols=78");
		
	gotoxy (2,3);printf("||====================================================================||");
	gotoxy (2,4);printf("||                    PLANILLA DE INGRESO DE EQUIPO                   ||");      
	gotoxy (2,5);printf("||____________________________________________________________________||");
	gotoxy (2,6);printf("||____________________________________________________________________||");
 	gotoxy (2,7);printf("||  Ingrese NBP:                    |  Ingrese marca:                 ||");
 	gotoxy (2,8);printf("||                                  |                                 ||"); 
 	gotoxy (2,9);printf("||                                  |                                 ||");
 	gotoxy (2,10);printf("||__________________________________|_________________________________||");
 	gotoxy (2,11);printf("||                                  |                                 ||");
 	gotoxy (2,12);printf("||  Ingrese usuario:                |  Ingrese departamento:          ||");
 	gotoxy (2,13);printf("||                                  |                                 ||");
 	gotoxy (2,14);printf("||                                  |                                 ||");              
 	gotoxy (2,15);printf("||__________________________________|_________________________________||");
	gotoxy (2,16);printf("||____________________________________________________________________||");
	
	    gotoxy (19,7); scanf("%s", PC.NBP);
	    gotoxy (56,7); scanf("%s", PC.MAR);
		gotoxy (25,12); scanf("%s", PC.USU);
		gotoxy (63,12); scanf("%s", PC.DPTO);
		
		strftime (PC.FREG, 9, "%d/%m/%y", tlocal);
		strcpy (PC.FMOD, "00/00/00");
		strcpy (PC.FDES, "00/00/00");
		
		mkdir ("INVENTARIOS");
		PRINCIPAL=fopen ("INVENTARIOS/PPAL.txt","a+");
		fprintf(PRINCIPAL,"%s %s %s %s %s\n", PC.NBP, PC.MAR, PC.USU, PC.DPTO,PC.FREG);
		
		system ("CLS");
		system ("color f0"); 
		system("mode con: lines=14 cols=60");
		
	fflush(stdin);

	gotoxy (3,2);  printf ("|====================================================|");
	gotoxy (3,3);  printf ("|                                                    |");
	gotoxy (3,4);  printf ("|            DATOS GUARDADOS EXITOSAMENTE!           |");
	gotoxy (3,5);  printf ("|                                                    |");
	gotoxy (3,6);  printf ("|             Desea registrar otro equipo?           |"); 
	gotoxy (3,7);  printf ("|                                                    |");
	gotoxy (3,8); printf  ("|                 Presione 1 para si                 |");
	gotoxy (3,9); printf  ("|____________________________________________________|");
	gotoxy	(3,10); printf ("|____________________________________________________|");
	gotoxy (3,11);	printf ("|____________________________________________________|");
		
		gotoxy (40,8); scanf("%d",&OP1);
		fflush(stdin);
		
		system ("cls");
	}while(OP1==1);
	fclose(PRINCIPAL);
	return;
}

void Consulta() {
	char BBP[6];
    int OP;
    int RE = 0; 
    
    system ("CLS");
    system ("color 70");
    system ("mode con: lines=14 cols=60");
    	
    	fflush(stdin);
    	
    	gotoxy (2,2); printf("||====================================================||");
     	gotoxy (2,3); printf("||           Consultar datos de un equipo             ||");
    	gotoxy (2,4); printf("||____________________________________________________||");
    	gotoxy (2,5); printf("||                                                    ||");
    	gotoxy (2,6); printf("||                                                    ||"); 
    	gotoxy (2,7); printf("||     Ingrese NBP:                                   ||");
    	gotoxy (2,8); printf("||                                                    ||");
    	gotoxy (2,9); printf("||____________________________________________________||");
    	gotoxy (2,10); printf("||____________________________________________________||");
    
      	gotoxy (22,7); scanf("%s", &BBP);
 
        FILE* PRINCIPAL = fopen("INVENTARIOS/PPAL.txt", "r");   
	
        int COMPA;
        
        do {
        	system ("CLS");
        	system ("mode con: lines=30 cols=93");
            fscanf(PRINCIPAL, "%s %s %s %s %s %s %s \n", PC.NBP, PC.MAR, PC.USU, PC.DPTO, PC.FREG, PC.FMOD, PC.FDES);
            COMPA = strcmp(BBP, PC.NBP);
            
            if (COMPA == 0) {
                RE = 1;
                
                gotoxy (2,3);printf("||====================================================================================||");
				gotoxy (2,4);printf("||                                    PLANILLA DE CONSULTA                            ||");      
				gotoxy (2,5);printf("||____________________________________________________________________________________||");
				gotoxy (2,6);printf("||____________________________________________________________________________________||");
 				gotoxy (2,7);printf("||                                          |                                         ||");
 				gotoxy (2,8);printf("||                 Usuario                  |                 Marca                   ||"); 
 				gotoxy (2,9);printf("||                                          |                                         ||");
			 	gotoxy (2,10);printf("||                                          |                                         ||");
 				gotoxy (2,11);printf("||__________________________________________|_________________________________________||");
			 	gotoxy (2,12);printf("||                                                                                    ||");
 				gotoxy (2,13);printf("||     Fecha de registro:                                                             ||");
			 	gotoxy (2,14);printf("||                                                                                    ||"); 
				gotoxy (2,15);printf("||     Fecha de modificaci\242n:                                                         ||"); 
				gotoxy (2,16);printf("||                                                                                    ||");  
				gotoxy (2,17);printf("||     Fecha de desincorporaci\242n:                                                     ||");
				gotoxy (2,18);printf("||____________________________________________________________________________________||");   
				gotoxy (2,19);printf("||____________________________________________________________________________________||");   
				gotoxy (2,20);printf("||                                                                                    ||");   
				gotoxy (2,21);printf("||   N\243mero de bien p\243blico:                                                          ||"); 
				gotoxy (2,22);printf("||                                                                                    ||");   
				gotoxy (2,23);printf("||   Departamento:                                                                    ||");   
				gotoxy (2,24);printf("||                                                                                    ||");   
 				gotoxy (2,25);printf("||____________________________________________________________________________________||");
				gotoxy (2,26);printf("||____________________________________________________________________________________||");
                
                   gotoxy (18,10); printf("%s", PC.USU);  
                   gotoxy (62,10); printf("%s", PC.MAR);
                   gotoxy (49,13); printf("%s", PC.FREG);
                   gotoxy (32,15); printf("%s", PC.FMOD);
                   gotoxy (38,17); printf("%s", PC.FDES);
                   gotoxy (34,21); printf("%s", PC.NBP);
                   gotoxy (25,23); printf("%s", PC.DPTO);
                
                getch();
                system ("CLS");
            }
            if (RE == 0 && feof(PRINCIPAL)) {
            	
            	system ("color 70");
    			system ("mode con: lines=14 cols=60");
            	
            	gotoxy (2,2);  printf ("||====================================================||");
     			gotoxy (2,3);  printf ("||           Consultar datos de un equipo             ||");
    			gotoxy (2,4);  printf ("||____________________________________________________||");
    			gotoxy (2,5);  printf ("||                                                    ||");
    			gotoxy (2,6);  printf ("||                                                    ||"); 
    			gotoxy (2,7);  printf ("||             Dato de equipo no encontrado           ||");
    			gotoxy (2,8); printf  ("||                                                    ||");
    			gotoxy (2,9); printf  ("||____________________________________________________||");
    			gotoxy (2,10); printf ("||____________________________________________________||");
            	
                getch();
            }
        } while (RE == 0 && !feof(PRINCIPAL));
        fclose(PRINCIPAL);
    
    return;
}

void Modificar() {
	
	system ("CLS");
	system ("color f0");
   
	PRINCIPAL=fopen("INVENTARIOS/PPAL.txt", "r");
	AUXILIAR=fopen("INVENTARIOS/AUXILIAR.txt","a+");
	int RE=0;
	system("mode con: lines=20 cols=60");

	fflush (stdin);
	
	gotoxy (3,4); printf(" ||=================================================||");
	gotoxy (3,5); printf(" ||          MODULO DE MODIFICAR DE EQUIPO          ||");
	gotoxy (3,6); printf(" ||=================================================||");
	gotoxy (3,7); printf(" ||    Ingrese n\243mero de bien p\243blico del equipo    ||");
	gotoxy (3,8); printf(" ||                                                 ||"); 
	gotoxy (3,9); printf(" ||                                                 ||");
	gotoxy (3,10); printf(" ||=================================================||");

	gotoxy (25,9); scanf("%s", BBP);
		
		do{
			
			fscanf(PRINCIPAL,"%s %s %s %s %s \n", PC.NBP, PC.MAR, PC.USU, PC.DPTO, PC.FREG);
			
			if (strcmp(PC.NBP,BBP) == 0){ 
				
				RE=1;
				
				do{	
					system ("CLS");
        			system ("mode con: lines=30 cols=93");
				
				    gotoxy (2,3);printf("||====================================================================================||");
			    	gotoxy (2,4);printf("||                              PLANILLA DE MODIFICACI\340N                              ||");      
			 		gotoxy (2,5);printf("||____________________________________________________________________________________||");
			    	gotoxy (2,6);printf("||____________________________________________________________________________________||");
 					gotoxy (2,7);printf("||                                                                                    ||");
 					gotoxy (2,8);printf("||                                  Datos modificables:                               ||"); 
 					gotoxy (2,9);printf("||                                                                                    ||");
			 		gotoxy (2,10);printf("||  1._ Marca:                                                                        ||");
 					gotoxy (2,11);printf("||                                                                                    ||");
			 		gotoxy (2,12);printf("||  2._ Usuario:                                                                      ||");
 					gotoxy (2,13);printf("||                                                                                    ||");
			 		gotoxy (2,14);printf("||  3._ Departamento:                                                                 ||"); 
					gotoxy (2,15);printf("||                                                                                    ||"); 
					gotoxy (2,16);printf("||  4_. Salir de la modificaci\242n                                                      ||");  
					gotoxy (2,17);printf("||                                                                                    ||");
					gotoxy (2,18);printf("||____________________________________________________________________________________||");   
					gotoxy (2,19);printf("||  Opci\340n:                                                                           ||");
					gotoxy (2,20);printf("||____________________________________________________________________________________||");   
					
						gotoxy (17,10); printf ("%s", PC.MAR);
						gotoxy (19,12); printf ("%s", PC.USU);
						gotoxy (24,14); printf ("%s", PC.DPTO);               
						gotoxy (14,19); scanf ("%d", &OP2);
					
					switch (OP2){
						
						case 1:
								system ("color 70");
								system("mode con: lines=15 cols=65");
								system ("cls");
								
								gotoxy (4,4); printf("|========================================================|");
								gotoxy (4,5); printf("|                    MODIFICAR MARCA                     |");
								gotoxy (4,6); printf("|========================================================|");
								gotoxy (4,7); printf("|                                                        |");
								gotoxy (4,8); printf("|        Ingrese marca :                                 |");
								gotoxy (4,9); printf("|                                                        |");
								gotoxy (4,10); printf("|========================================================|");
							
							    	gotoxy(29,8); scanf("%s", PC.MAR);
							break;
							
						case 2:
								system ("color 70");
								system("mode con: lines=15 cols=65");
								system ("cls");
								
								gotoxy (4,4); printf("|========================================================|");
								gotoxy (4,5); printf("|                    MODIFICAR USUARIO                   |");
								gotoxy (4,6); printf("|========================================================|");
								gotoxy (4,7); printf("|                                                        |");
								gotoxy (4,8); printf("|        Ingrese usuario:                                |");
								gotoxy (4,9); printf("|                                                        |");
								gotoxy (4,10); printf("|========================================================|");
								
									gotoxy (30,8); scanf("%s", PC.USU);
							
							break;
							
						case 3:
						    	system ("color 70");
								system("mode con: lines=15 cols=65");
								system ("cls");
								
								gotoxy (4,4); printf("|========================================================|");
								gotoxy (4,5); printf("|                 MODIFICAR DEPARTAMENTO                 |");
								gotoxy (4,6); printf("|========================================================|");
								gotoxy (4,7); printf("|                                                        |");
								gotoxy (4,8); printf("|      Ingrese departamento:                             |");
								gotoxy (4,9); printf("|                                                        |");
								gotoxy (4,10); printf("|========================================================|");
							
									gotoxy (33,8); scanf("%s", PC.DPTO);
											
							break;
							
						case 4:
							strftime(PC.FMOD,9,"%d/%m/%y",tlocal);
							system ("color 70");
							system ("mode con: lines=15 cols=55");
			
							gotoxy (4,4), printf ("|==============================================|");
							gotoxy (4,5), printf ("|            MODULO DE MODIFICACI\340N            |");
							gotoxy (4,6), printf ("|==============================================|");
							gotoxy (4,7), printf ("|                                              |");
							gotoxy (4,8), printf ("|               Datos modificados              |");
							gotoxy (4,9), printf ("|                                              |");
							gotoxy (4,10), printf ("|==============================================|");

							system ("pause");
							break;
							
						default:
							system ("color 70");
							system ("mode con: lines=15 cols=55");
			
							gotoxy (4,4), printf ("|==============================================|");
							gotoxy (4,5), printf ("|            MODULO DE MODIFICACI\340N            |");
							gotoxy (4,6), printf ("|==============================================|");
							gotoxy (4,7), printf ("|                                              |");
							gotoxy (4,8), printf ("|             Opci\242n no valida\n            |");
							gotoxy (4,9), printf ("|                                              |");
							gotoxy (4,10), printf ("|==============================================|");
							
							system("pause");
							break;
					}
				}while (OP!=5 && feof(PRINCIPAL));
			}
			fprintf(AUXILIAR, "%s %s %s %s \n", PC.NBP, PC.MAR, PC.USU, PC.DPTO);
			if (RE==0 && feof(PRINCIPAL)){
				
				system ("color 70");
				system ("mode con: lines=15 cols=55");
			
				gotoxy (4,4), printf ("|==============================================|");
				gotoxy (4,5), printf ("|            MODULO DE MODIFICACI\340N            |");
				gotoxy (4,6), printf ("|==============================================|");
				gotoxy (4,7), printf ("|                                              |");
				gotoxy (4,8), printf ("|        Dato de equipo no encontrado          |");
				gotoxy (4,9), printf ("|                                              |");
				gotoxy (4,10), printf ("|==============================================|");
		
				system ("pause");
			}
				
} while (!feof (PRINCIPAL));

fclose (PRINCIPAL);
fclose (AUXILIAR);
remove ("INVENTARIOS/PPAL.txt");
rename ("INVENTARIOS/AUXILIAR.txt", "INVENTARIOS/PPAL.txt");
return;
}

void Desincorporar (){
	system ("cls");
	system("color 47");
    system("mode con: lines=20 cols=60");

	fflush(stdin);

	gotoxy (4,4); printf ("|================================================|");
	gotoxy (4,5); printf ("|         MODULO DE ELIMINAR EQUIPO              |");
	gotoxy (4,6); printf ("|================================================|");
	gotoxy (4,7); printf ("|                                                |");
	gotoxy (4,8); printf ("|    Ingrese n\243mero de bien p\243blico del equipo   |"); 
	gotoxy (4,9); printf ("|                                                |");
	gotoxy (4,10); printf ("|                                                |");
	gotoxy (4,11); printf ("|================================================|");
	
		gotoxy (25,10); scanf("%s", BBP);
	
	PRINCIPAL=fopen("INVENTARIOS/PPAL.txt","r");
	AUXILIAR=fopen("INVENTARIOS/AUXILIAR.txt","a");
	
	DESI=fopen("INVENTARIOS/DESINCORPORADOS.txt","a");
	
	fflush(stdin);

	RE=0;

	int COMPA;
	do{
		fscanf(PRINCIPAL,"%s %s %s %s %s %s %s \n", PC.NBP, PC.MAR, PC.USU, PC.DPTO, PC.FREG, PC.FMOD, PC.FDES);
			COMPA=strcmp(BBP,PC.NBP);
			
			if (COMPA == 0){
				RE ==1 ;
				system ("mode con: lines=30 cols=93");
				
				gotoxy (2,3);printf ("||====================================================================================||");
				gotoxy (2,4);printf("||                            PLANILLA DE DESINCORPORAR                                 ||");      
				gotoxy (2,5);printf("||____________________________________________________________________________________||");
				gotoxy (2,6);printf("||____________________________________________________________________________________||");
 				gotoxy (2,7);printf("||                                          |                                         ||");
 				gotoxy (2,8);printf("||                 Usuario                  |                 Marca                   ||"); 
 				gotoxy (2,9);printf("||                                          |                                         ||");
			 	gotoxy (2,10);printf("||                                          |                                         ||");
 				gotoxy (2,11);printf("||__________________________________________|_________________________________________||");
			 	gotoxy (2,12);printf("||                                                                                    ||");
 				gotoxy (2,13);printf("||     Fecha de registro:                                                             ||");
			 	gotoxy (2,14);printf("||                                                                                    ||"); 
				gotoxy (2,15);printf("||     Fecha de modificaci\242n:                                                         ||"); 
				gotoxy (2,16);printf("||                                                                                    ||");  
				gotoxy (2,17);printf("||     Fecha de desincorporaci\242n:                                                     ||");
				gotoxy (2,18);printf("||____________________________________________________________________________________||");   
				gotoxy (2,19);printf("||____________________________________________________________________________________||");   
				gotoxy (2,20);printf("||                                                                                    ||");   
				gotoxy (2,21);printf("||   N\243mero de bien p\243blico:                                                          ||"); 
				gotoxy (2,22);printf("||                                                                                    ||");   
				gotoxy (2,23);printf("||   Departamento:                                                                    ||");   
				gotoxy (2,24);printf("||                                                                                    ||");   
 				gotoxy (2,25);printf("||____________________________________________________________________________________||");
				gotoxy (2,26);printf("||____________________________________________________________________________________||");
                
				
					gotoxy (18,10); printf("%s", PC.USU);  
               	    gotoxy (62,10); printf("%s", PC.MAR);
               	    gotoxy (49,13); printf("%s", PC.FREG);
               	    gotoxy (32,15); printf("%s", PC.FMOD);
               	    gotoxy (38,17); printf("%s", PC.FDES);
                    gotoxy (34,21); printf("%s", PC.NBP);
                    gotoxy (25,23); printf("%s", PC.DPTO);
                    
                     getch();
              	     system ("CLS");
				
				do{
					system("mode con: lines=19 cols=58");
						
					gotoxy (3,2); printf ("|====================================================|");
					gotoxy (3,3); printf ("|                                                    |");
					gotoxy (3,4); printf ("|     1_. Desea desincorporar este equipo?           |");
					gotoxy (3,5); printf ("|                                                    |");
					gotoxy (3,6); printf ("|     2_. Salir sin desincorporar                    |"); 
					gotoxy (3,7); printf ("|                                                    |");
					gotoxy (3,8); printf  ("|         Opci\242n:                                    |");
					gotoxy (3,9); printf  ("|                                                    |");
					gotoxy (3,10); printf ("|____________________________________________________|");
					gotoxy (3,11); printf ("|____________________________________________________|");
					
						gotoxy(21,8); scanf("%d",&OP3);
						getch();
              	   	    system ("CLS");
				
					switch (OP3){
						case 1:
							 system("mode con: lines=20 cols=60");
							
							gotoxy (4,4);  printf ("|================================================|");
							gotoxy (4,5);  printf ("|           MODULO DE ELIMINAR EQUIPO            |");
							gotoxy (4,6);  printf ("|================================================|");  
							gotoxy (4,7);  printf ("|                                                |");
							gotoxy (4,8);  printf ("|             Equipo desincorporado!             |"); 
							gotoxy (4,9);  printf ("|                                                |");
							gotoxy (4,10); printf ("|                                                |");
							gotoxy (4,11); printf ("|================================================|");
								
							strftime (PC.FDES,9,"%d,%m,%y",tlocal);
							fprintf(DESI,"%s \n", PC.NBP);
							system("pause");
							break;
							
						case 2:
							system("mode con: lines=20 cols=60");
							
							gotoxy (4,4);  printf ("|================================================|");
							gotoxy (4,5);  printf ("|           MODULO DE ELIMINAR EQUIPO            |");
							gotoxy (4,6);  printf ("|================================================|");  
							gotoxy (4,7);  printf ("|                                                |");
							gotoxy (4,8);  printf ("|              Registro no eliminado             |"); 
							gotoxy (4,9);  printf ("|                                                |");
							gotoxy (4,10); printf ("|                                                |");
							gotoxy (4,11); printf ("|================================================|");
										
							fprintf(AUXILIAR,"%s \n", PC.NBP);
							system("pause");
							break;
							
						default:
							system("mode con: lines=20 cols=60");
							
							gotoxy (4,4);  printf ("|================================================|");
							gotoxy (4,5);  printf ("|           MODULO DE ELIMINAR EQUIPO            |");
							gotoxy (4,6);  printf ("|================================================|");  
							gotoxy (4,7);  printf ("|                                                |");
							gotoxy (4,8);  printf ("|             Opci\242n inv\240lida              |"); 
							gotoxy (4,9);  printf ("|                                                |");
							gotoxy (4,10); printf ("|                                                |");
							gotoxy (4,11); printf ("|================================================|");
							
							system("pause");
							break;
					}	
			}while(OP3!=1 && OP3!=2);
			}else{
				fprintf(AUXILIAR, "%s %s %s %s \n", PC.NBP, PC.MAR, PC.USU, PC.DPTO);
			}
	}while (feof(PRINCIPAL));
	if (RE==0 &&feof(PRINCIPAL)){
		printf("Registro de equipo no encontrado");
		system ("pause");
	}
		fclose(PRINCIPAL);
		fclose(AUXILIAR);
		fclose(DESI);
		remove("INVENTARIOS/PPAL.txt");
		rename("INVENTARIOS/AUXILIAR.txt", "INVENTARIOS/PPAL.txt");
	return;
}

void Listar (){
		system ("cls");
		system("color 07");
		printf("Datos de un equipo:\n");
		
		PRINCIPAL=fopen("INVENTARIOS/PPAL.txt","r");
			
		do{
				
			if(fscanf(PRINCIPAL,"%s %s %s %s %s\n", PC.NBP, PC.MAR, PC.USU, PC.DPTO,PC.FREG) == 5){
				
				system("mode con: lines=20 cols=78");
		
				gotoxy (2,3);printf("||====================================================================||");
				gotoxy (2,4);printf("||                           PLANILLA DE LISTAR                        ||");      
				gotoxy (2,5);printf("||____________________________________________________________________||");
				gotoxy (2,6);printf("||____________________________________________________________________||");
			 	gotoxy (2,7);printf("||  Ingrese NBP:                    |  Ingrese marca:                 ||");
			 	gotoxy (2,8);printf("||                                  |                                 ||"); 
			 	gotoxy (2,9);printf("||                                  |                                 ||");
			 	gotoxy (2,10);printf("||__________________________________|_________________________________||");
			 	gotoxy (2,11);printf("||                                  |                                 ||");
			 	gotoxy (2,12);printf("||  Ingrese usuario:                |  Ingrese departamento:          ||");
 				gotoxy (2,13);printf("||                                  |                                 ||");
 				gotoxy (2,14);printf("||                                  |                                 ||");              
 				gotoxy (2,15);printf("||__________________________________|_________________________________||");
				gotoxy (2,16);printf("||____________________________________________________________________||");
	
	
				    gotoxy (19,7); printf("%s", PC.NBP);
				    gotoxy (56,7); printf("%s", PC.MAR);
					gotoxy (25,12); printf("%s", PC.USU);
					gotoxy (63,12); printf("%s", PC.DPTO);

					getch();	
	    			system ("CLS");
		
			}else{
				break;
			}
				
		}while(1);

		fclose(PRINCIPAL);
}

void Ayuda (){
 	system ("cls");
	system("color 07");
	system ("mode con: lines=50 cols=88");

	
		gotoxy (2,2);   printf("||||===========================================================================||||");
		gotoxy (2,3);   printf("||||===========================================================================||||");
		gotoxy (2,4);   printf("||||===========================================================================||||");
		gotoxy (2,5);   printf("||||===========================================================================||||");
		gotoxy (2,6);   printf("||||                                                                           ||||");
		gotoxy (2,7);   printf("||||          USTED HA INGRESADO AL MODULO DE AYUDA AL USUARIO                 ||||");
		gotoxy (2,8);   printf("||||                                                                           ||||");
		gotoxy (2,9);   printf("||||                                                                           ||||");
		gotoxy (2,10);  printf("||||                                                                           ||||");
		gotoxy (2,11);  printf("||||                                                                           ||||");
		gotoxy (2,12);  printf("||||                                                                           ||||");
		gotoxy (2,13);  printf("||||                                                                           ||||");
		gotoxy (2,14);  printf("||||                                                                           ||||");
		gotoxy (2,15);  printf("||||                                                                           ||||");
		gotoxy (2,16);  printf("||||                                                                           ||||");
		gotoxy (2,17);  printf("||||                                                                           ||||");
		gotoxy (2,18);  printf("||||                                                                           ||||");
		gotoxy (2,19);  printf("||||                                                                           ||||");
		gotoxy (2,20);  printf("||||                                                                           ||||");
		gotoxy (2,21);  printf("||||                                                                           ||||");
		gotoxy (2,22);  printf("||||                                                                           ||||");
		gotoxy (2,23);  printf("||||                                                                           ||||");
		gotoxy (2,24);  printf("||||                                                                           ||||");
		gotoxy (2,25);  printf("||||                                                                           ||||");
		gotoxy (2,26);  printf("||||                                                                           ||||");
		gotoxy (2,27);  printf("||||                                                                           ||||");
		gotoxy (2,28);  printf("||||                                                                           ||||");
		gotoxy (2,29);  printf("||||                                                                           ||||");
		gotoxy (2,30);  printf("||||                                                                           ||||");
		gotoxy (2,31);  printf("||||                                                                           ||||");
		gotoxy (2,32);  printf("||||                                                                           ||||");
		gotoxy (2,33);  printf("||||                                                                           ||||");
		gotoxy (2,34);  printf("||||                                                                           ||||");
		gotoxy (2,35);  printf("||||                                                                           ||||");
		gotoxy (2,36);  printf("||||                                                                           ||||");
		gotoxy (2,37);  printf("||||                                                                           ||||");
		gotoxy (2,38);  printf("||||                                                                           ||||");
		gotoxy (2,39);  printf("||||                                                                           ||||");
		gotoxy (2,40);  printf("||||                                                                           ||||");
		gotoxy (2,41);  printf("||||                                                                           ||||");
		gotoxy (2,42);  printf("||||                                                                           ||||");
		gotoxy (2,43);  printf("||||                                                                           ||||");
		gotoxy (2,44);  printf("||||===========================================================================||||");
		gotoxy (2,45);  printf("||||===========================================================================||||");
		gotoxy (2,46);  printf("||||===========================================================================||||");
	
		gotoxy (40,6); printf("AYUDA");
	
	gotoxy (8,10);  printf("PARA REGISTRAR EQUIPOS , HAY ALGUNAS COSAS QUE DEBERIAS SABER : ");
	
	gotoxy (8,14); printf("(1) ES NECESARIO QUE CONSIDERE ESCRIBIR SIN ESPACIOS PARA ALMACENAR");
	gotoxy (8,15); printf("    INFORMACION SI NECESITA COLOCAR ESPACIO, POR FAVOR SUSTITUYA LOS");
	gotoxy (8,16); printf("    ESPACIOS POR GUION (-), UNDERSCORD (_) O CUALQUIER CARACTER DE ");
	gotoxy (8,17); printf("    PREFERENCIA QUE USTED DESEE.");
	
	gotoxy (8,22); printf("(2) PARA CONSULTAR, MODIFICAR Y ELIMINNAR ES IMPORTANTE QUE RECUERDE");
	gotoxy (8,23); printf("    EL NUMERO DE SERIAL CON EL QUE ESTA GUARDANDO EL ARCHIVO. ESTO ");
	gotoxy (8,24); printf("    LE AYUDARA A ACCEDER AL CONTENIDO DEL REGISTRO.");
	
	gotoxy (8,29); printf("(3) LOS REPORTES Y/O DATOS INGRESADOS DEL INVENTARIO SE GUARDARAN");
	gotoxy (8,30); printf("    EN UNA CARPETA CON EL MISMO NOMBRE Y SE LOCALIZARA EN LA MISMA ");
	gotoxy (5,31); printf("       DIRECCION QUE EL ARCHIVO EJECUTABLE DEL PROGRAMA");
	
	
	gotoxy (8,36); printf("PULSE ENTER PARA IR AL MENU PRINCIPPAL");
	getch();	
	
}

void Creditos () {
	
		system("color 07");
		system("mode con: lines=30 cols=85");

	gotoxy (3,3); printf("---                                                                         ---");
	gotoxy (3,4); printf("---                                                                         ---");
	gotoxy (3,5); printf("---                                                                         ---");
	gotoxy (3,6); printf("---                                                                         ---");
	gotoxy (3,7); printf("---                                                                         ---");
	gotoxy (3,8); printf("---                                                                         ---");
	gotoxy (3,9); printf("---                                                                         ---");
	gotoxy (3,10); printf("---                                                                         ---");
	gotoxy (3,11); printf("---                                                                         ---");
	gotoxy (3,12); printf("---                                                                         ---");
	gotoxy (3,13); printf("---                                                                         ---");
	gotoxy (3,14); printf("---                                                                         ---");
	gotoxy (3,15); printf("---                                                                         ---");
	gotoxy (3,16); printf("---                                                                         ---");
	gotoxy (3,17); printf("---                                                                         ---");
	gotoxy (3,18); printf("---                                                                         ---");
	gotoxy (3,19); printf("---                                                                         ---");
	gotoxy (3,20); printf("---                                                                         ---");
	gotoxy (3,21); printf("---                                                                         ---");
	gotoxy (3,22); printf("---                                                                         ---");
	gotoxy (3,23); printf("---                                                                         ---");
	gotoxy (3,24); printf("---                                                                         ---");
	gotoxy (3,25); printf("---                                                                         ---");
	
	
	
	
		
	gotoxy (11,7); printf  ("888b     d888                   d8b 888                   888");
	gotoxy (11,8); printf  ("8888b   d8888                   Y8P 888                   888");
	gotoxy (11,9); printf  ("88888b.d88888                       888                   888");
	gotoxy (11,10); printf ("888Y88888P888  .d88b.  888  888 888 888 88888b.   .d88b.  888888");
	gotoxy (11,11); printf ("888 Y888P 888 d88  88b 888  888 888 888 888 .88b d8P  Y8b 888");
	gotoxy (11,12); printf ("888  Y8P  888 888  888 Y88  88P 888 888 888  888 88888888 888");
	gotoxy (11,13); printf ("888   *   888 Y88..88P  Y8bd8P  888 888 888  888 Y8b.     Y88b.");
	gotoxy (11,14); printf ("888       888  *Y88P*    Y88P   888 888 888  888 Y8888    Y888");

		Sleep(1980);	
 	
 	
// marco  
 	system ("cls");
	system ("color f9");
	system("mode con: lines=50 cols=88");
	
	// tamaño de la consola 
 
	gotoxy (2,2);   printf("||||===========================================================================||||");
	gotoxy (2,3);   printf("||||===========================================================================||||");
	gotoxy (2,4);   printf("||||                                                                           ||||");
	gotoxy (2,5);   printf("||||                                                                           ||||");
	gotoxy (2,6);   printf("||||                                                                           ||||");
	gotoxy (2,7);  printf("||||                                                                           ||||");
	gotoxy (2,8);  printf("||||                                                                           ||||");
	gotoxy (2,9);  printf("||||                                                                           ||||");
	gotoxy (2,10);  printf("||||                                                                           ||||");
	gotoxy (2,11);  printf("||||                                                                           ||||");
	gotoxy (2,12);  printf("||||                                                                           ||||");
	gotoxy (2,13);  printf("||||                                                                           ||||");
	gotoxy (2,14);  printf("||||                                                                           ||||");
	gotoxy (2,15);  printf("||||                                                                           ||||");
	gotoxy (2,16);  printf("||||                                                                           ||||");
	gotoxy (2,17);  printf("||||                                                                           ||||");
	gotoxy (2,18);  printf("||||                                                                           ||||");
	gotoxy (2,19);  printf("||||                                                                           ||||");
	gotoxy (2,20);  printf("||||                                                                           ||||");
	gotoxy (2,21);  printf("||||                                                                           ||||");
	gotoxy (2,22);  printf("||||                                                                           ||||");
	gotoxy (2,23);  printf("||||                                                                           ||||");
	gotoxy (2,24);  printf("||||                                                                           ||||");
	gotoxy (2,25);  printf("||||                                                                           ||||");
	gotoxy (2,26);  printf("||||                                                                           ||||");
	gotoxy (2,27);  printf("||||                                                                           ||||");
	gotoxy (2,28);  printf("||||                                                                           ||||");
	gotoxy (2,29);  printf("||||                                                                           ||||");
	gotoxy (2,30);  printf("||||                                                                           ||||");
	gotoxy (2,31);  printf("||||                                                                           ||||");
	gotoxy (2,32);  printf("||||                                                                           ||||");
	gotoxy (2,33);  printf("||||                                                                           ||||");
	gotoxy (2,34);  printf("||||                                                                           ||||");
	gotoxy (2,35);  printf("||||                                                                           ||||");
	gotoxy (2,36);  printf("||||                                                                           ||||");
	gotoxy (2,37);  printf("||||                                                                           ||||");
	gotoxy (2,38);  printf("||||                                                                           ||||");
	gotoxy (2,39);  printf("||||                                                                           ||||");
	gotoxy (2,40);  printf("||||                                                                           ||||");
	gotoxy (2,41);  printf("||||                                                                           ||||");
	gotoxy (2,42);  printf("||||===========================================================================||||");
	gotoxy (2,43);  printf("||||===========================================================================||||");
	
	gotoxy (30,5);  Sleep (250); printf("CREADO POR LOS ESTUDIANTES");
	gotoxy (20,10); Sleep (250); printf("MARIALYS ANDARCIA");
	gotoxy (20,14); Sleep (250); printf("CARLOS SERVANDO");
	gotoxy (30,26); Sleep (250); printf("AGRADECIMIENTO A :");
	gotoxy (20,30); Sleep (250); printf("PROF. SANCHEZ WISTON");
	gotoxy (20,34); Sleep (250); printf("TODO EL EQUIPO DE SOPORTE CAMPO DE MOVILNET.");
	gotoxy (31,38); Sleep (250); printf("GRACIAS......");
	getch();
	return;

}
