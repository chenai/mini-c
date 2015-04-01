/*
 *
 *		MCC
 *			����Mini C Complier
 *	version : 0.2
 *  Language: ANSI C
 *  License : The MIT License (MIT)
 *	Author  : wsy
 *  Data    : Copyright (c) <2013>
 *  Email   : chenansic@gmail.com
 *  
 *  		    Enjoy it
 *  			     		:)
 *
 *
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "global.h"

extern void Scanner();
extern void PrintScan();
extern void PrintQuad();
extern void Parse();
extern void GenCode();
extern void VmInit();
extern void VmRun();
extern Node head;

static void Menu();
static void Scan();
static void Midle();
static void ObjCode();
static int InputVaild( char key, char * str );
static void VirtualMachine();

int main( int argc, char ** argv )
{
	Node t;
	int choose;

	printf( "\n\n\n" );
	printf( "\t\tMSMCC\n" );
 	printf( "\t\t\t����My Simple Mini"
	  "C Complier\n");
	printf( "\t\tversion : 0.2\n" );
 	printf( "\t\tLanguage: ANSI C\n" );
  	printf( "\t\tLicense : The MIT"
	   "License (MIT)\n " );
 	printf( "\t\tAuthor  : wsy \n" ); 
   	printf( "\t\tDate    : Copyright"
	    			"(c) <2013>\n" );
    printf( "\t\tEmail   : wsy92@qq"
				".com\n\n" );  
  	printf( "\t\t\t\t\tEnjoy it  \n\n" );
   	printf( "\t\t\t\t\t\t:) " );
	
	getche();
	
start:
	system( "cls" );
	Menu();
	while( scanf( "%d", &choose ) != 1 
			|| choose < 1 || choose > 6 )
	{
		fflush( stdin );
		printf( "\n\n\n\n" );
		printf( "\t\t\tOpps\n" );
		printf( "\t\t\t�Ƿ�ѡ��,"
		 "����������!\n" );
		printf( "\t\t\t�����������..." );
		getch();
		system( "cls" );
		Menu();
	}
	switch( choose )
	{
		case 1:
			system( "cls" );
			fflush( stdin );
			printf( "�ʷ�����\n" );
			Scan();
			getche();
			break;
		case 2:
			system( "cls" );
			fflush( stdin );
			printf( "�м��������\n" );
			Midle();
			getche();
			break;
		case 3:
			system( "cls" );
			fflush( stdin );
			printf( "Ŀ�������������\n" );
			ObjCode();
			getche();
			break;
		case 4:
			system( "cls" );
			fflush( stdin );
			printf( "�����ִ��\n" );
			VirtualMachine();
			getche();
			break;
		case 5:
			system( "cls" );
			break;
		case 6:
			system( "cls" );
			fflush( stdin );
			printf( "��������\t:)\n" );
			printf( "\n\n\n\n\t\t\t���߱Ƚ���,"
			"ʲô��ûд...." );
			getche();
			break;
	}
	if( choose != 5 ) 
		goto start;
	return 0;
}


int InputValid( char key, char * str )
{
	int i;
	for( i = strlen(str)-1; i >= 0; i-- )
	{
		if( *(str+i) == '.' )
		{
			if( *(str+i+1) == key 
				|| *(str+i+1) == key )
					return true;
			else
				return false;
		}
	}
	return false;
}


void Scan()
{
	char inputFileName[21];
	char outputFileName[21];
	printf( "������Դ�ļ�����,"
	"����.c��չ������\n" );
	fgets( inputFileName, 20, stdin );
	inputFileName[strlen(inputFileName)-1] = '\0';
	while( !InputValid( 'c', inputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	while((fpIn=fopen(inputFileName, "r")) == NULL )
	{
		printf( "�ļ�������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	
	printf( "����������ļ�����,"
	"����.w��չ������\n" );
	fgets( outputFileName, 20, stdin );
	outputFileName[strlen(outputFileName)-1] = '\0';
	while( !InputValid( 'w', outputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( outputFileName, 20, stdin );
		outputFileName[strlen(outputFileName)-1] = '\0';
	}
	fpOut = fopen( outputFileName, "w+" );
	if( fpOut != NULL )
		printf( "�ļ��򿪳ɹ�,����ִ�дʷ�����...\n" );
	else
	{
		printf( "�ļ���ʧ��..." );
		exit( 0 );
	}
	Scanner();
	PrintScan();
	printf( "�ʷ�������ϣ��鿴�ļ�%s\n",outputFileName );
	fclose( fpIn );
	fclose( fpOut );
}

void Midle()
{
	char inputFileName[21];
	char outputFileName[21];
	printf( "������Դ�ļ�����,"
	"����.c��չ������\n" );
	fgets( inputFileName, 20, stdin );
	inputFileName[strlen(inputFileName)-1] = '\0';
	while( !InputValid( 'c', inputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	while((fpIn=fopen(inputFileName, "r")) == NULL )
	{
		printf( "�ļ�������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	
	printf( "����������ļ�����,"
	"����.m��չ������\n" );
	fgets( outputFileName, 20, stdin );
	outputFileName[strlen(outputFileName)-1] = '\0';
	while( !InputValid( 'm', outputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( outputFileName, 20, stdin );
		outputFileName[strlen(outputFileName)-1] = '\0';
	}
	Scanner();
	fpOut = fopen( outputFileName, "w+" );
	if( fpOut != NULL )
		printf( "�ļ��򿪳ɹ�,����ִ���м��������...\n" );
	else
	{
		printf( "�ļ���ʧ��...");
		exit( 0 );
	}
	Parse();
	PrintQuad();
	printf( "�м����������ϣ��鿴�ļ�%s\n",outputFileName );
	fclose( fpIn );
	fclose( fpOut );
	
}

void ObjCode()
{
	char inputFileName[21];
	char outputFileName[21];
	printf( "������Դ�ļ�����,"
	"����.c��չ������\n" );
	fgets( inputFileName, 20, stdin );
	inputFileName[strlen(inputFileName)-1] = '\0';
	while( !InputValid( 'c', inputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	while((fpIn=fopen(inputFileName, "r")) == NULL )
	{
		printf( "�ļ�������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	
	printf( "����������ļ�����,"
	"����.o��չ������\n" );
	fgets( outputFileName, 20, stdin );
	outputFileName[strlen(outputFileName)-1] = '\0';
	while( !InputValid( 'o', outputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( outputFileName, 20, stdin );
		outputFileName[strlen(outputFileName)-1] = '\0';
	}
	Scanner();
	Parse();
	fpOut = fopen( outputFileName, "w+" );
	if( fpOut != NULL )
		printf( "�ļ��򿪳ɹ�,����ִ��Ŀ���������...\n" );
	else
	{
		printf( "�ļ���ʧ��..." );
		exit( 0 );
	}
	GenCode();
	printf( "Ŀ�����������ϣ��鿴�ļ�%s\n",outputFileName );
	fclose( fpIn );
	fclose( fpOut );
	
}

void VirtualMachine( )
{
	char inputFileName[21];
	char outputFileName[21];
	printf( "������Դ�ļ�����,"
	"����.c��չ������\n" );
	fgets( inputFileName, 20, stdin );
	inputFileName[strlen(inputFileName)-1] = '\0';
	while( !InputValid( 'c', inputFileName ) )
	{	
		printf( "�ļ���չ������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	while((fpIn=fopen(inputFileName, "r")) == NULL )
	{
		printf( "�ļ�������" 
		"����������:\n" );
		fgets( inputFileName, 20, stdin );
		inputFileName[strlen(inputFileName)-1] = '\0';
	}
	Scanner();
	Parse();
	GenCode();
	VmInit();
	VmRun();
	fclose( fpIn );
}
void Menu()
{
	int x;
	for( x = 0; x < 80; x++ )
		printf( "*" );
	printf( "\t\t\t\t1.�ʷ�����\n" );
	printf( "\t\t\t\t2.�м��������\n" );
	printf( "\t\t\t\t3.Ŀ�������������\n" );
	printf( "\t\t\t\t4.�����ִ��\n" );
	printf( "\t\t\t\t5.�˳�����\n" );
	printf( "\t\t\t\t6.��������\t:)\n" );
	for( x = 0; x < 80; x++ )
		printf( "*" );
	printf( "Please choose an option:" );
}

