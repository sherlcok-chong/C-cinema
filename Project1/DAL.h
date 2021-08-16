#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <tchar.h>
typedef struct Moive {
	char name[40];
	char grade[40];
	char money[40];
	char times[40];
	char venue[40];
	char site[8][15];
	struct Moive *next;
}M;
M *Mhead;
M *session = NULL;
M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
typedef struct Users {
	char name[40];
	char key[40];
	int flag;
	struct Users *next;
}U;
U *Uhead;
U Cuser;
typedef struct BuyTic {
	char uname[40];
	char mname[40];
	char times[40];
	char venue[40];
	int x;
	int y;
	struct BuyTic *next;
}B;
B *Bhead;
int r[11][4] = { { 300,100,1000,200 },
				{ 500,220,800,270 },
				{ 500,290,800,340 },
				{ 500,360,800,410 },
				{ 500,430,800,480 },
				{ 500,500,800,550 },
				{ 500,570,800,620 },
				{ 20,20,80,60 }, 
				{ 600,670,700,700},
				{ 800,670,900,700 },
				{525,710,700,760},
				};

RECT R0 = { r[0][0],r[0][1],r[0][2],r[0][3] };
RECT R1 = { r[1][0],r[1][1],r[1][2],r[1][3] };
RECT R2 = { r[2][0],r[2][1],r[2][2],r[2][3] };
RECT R3 = { r[3][0],r[3][1],r[3][2],r[3][3] };
RECT R4 = { r[4][0],r[4][1],r[4][2],r[4][3] };
RECT R5 = { r[5][0],r[5][1],r[5][2],r[5][3] };
RECT R6 = { r[6][0],r[6][1],r[6][2],r[6][3] };
RECT R7 = { r[7][0],r[7][1],r[7][2],r[7][3] };
RECT R8 = { r[8][0],r[8][1],r[8][2],r[8][3] };
RECT R9 = { r[9][0],r[9][1],r[9][2],r[9][3] };
RECT R10 = { r[10][0],r[10][1],r[10][2],r[10][10] };
int p[7][4] = { { 300,100,1200,200 },
				{ 850,220,1200,270 },
				{ 850,290,1200,340 },
				{ 850,360,1200,410 },
				{ 850,430,1200,480 },
				{ 850,500,1200,550 },
				{ 850,570,1200,620 } };
RECT P1 = { p[1][0],p[1][1],p[1][2],p[1][3] };
RECT P2 = { p[2][0],p[2][1],p[2][2],p[2][3] };
RECT P3 = { p[3][0],p[3][1],p[3][2],p[3][3] };
RECT P4 = { p[4][0],p[4][1],p[4][2],p[4][3] };
RECT P5 = { p[5][0],p[5][1],p[5][2],p[5][3] };
RECT P6 = { p[6][0],p[6][1],p[6][2],p[6][3] };
int b[6][4] = { { 300,100,1200,200 },
				{ 200,220,800,270 },
				{ 200,290,800,340 },
				{ 200,360,800,410 },
				{ 200,430,800,480 },
				{ 200,500,800,550 }};
RECT B0 = { b[0][0],b[0][1],b[0][2],b[0][3] };
RECT B1 = { b[1][0],b[1][1],b[1][2],b[1][3] };
RECT B2 = { b[2][0],b[2][1],b[2][2],b[2][3] };
RECT B3 = { b[3][0],b[3][1],b[3][2],b[3][3] };
RECT B4 = { b[4][0],b[4][1],b[4][2],b[4][3] };
RECT B5 = { b[5][0],b[5][1],b[5][2],b[5][3] };
int c[6][4] = { { 100,100,200,200 },
				{ 1000,220,1100,260 },
				{ 1000,290,1100,330 },
				{ 1000,360,1100,400 },
				{ 1000,430,1100,470 },
				{ 1000,500,1100,540 } };
RECT C1 = { c[1][0],c[1][1],c[1][2],c[1][3] };
RECT C2 = { c[2][0],c[2][1],c[2][2],c[2][3] };
RECT C3 = { c[3][0],c[3][1],c[3][2],c[3][3] };
RECT C4 = { c[4][0],c[4][1],c[4][2],c[4][3] };
RECT C5 = { c[5][0],c[5][1],c[5][2],c[5][3] };
int s[98][4];
char MoiveName[40];
int Way;
char key[100];
void Loadkey() {
	int k = 1;
	for (int j = 1; j <= 8; j++)
	{
		for (int i = 1; i <= 12; i++,k++)
		{
			s[k][0] = 150 + i * 75;
			s[k][1] = 150 + j * 60;
			s[k][2] = 200 + i * 75;
			s[k][3] = 200 + j * 60;
		}
	}
	FILE *fp;
	fopen_s(&fp, "账号密码.txt", "a+");
	U *current = NULL, *tail = NULL;
	fscanf_s(fp, "%s", key, 40);
	char temp[40];
	fscanf_s(fp, "%s", temp,40);
	while (!feof(fp))
	{
		current = (U*)malloc(sizeof(U));
		if (Uhead == NULL) {
			Uhead = current;
		}
		else {
			tail->next = current;
		}
		strcpy_s(current->name, temp);
		fscanf_s(fp, "%s", &current->key,40);
		fscanf_s(fp, "%d", &current->flag);
		current->next = NULL;
		tail = current;
		fscanf_s(fp, "%s", temp,40);
	}
	fclose(fp);
}
void LoadInform() {
	FILE *fp;
	fopen_s(&fp, "影院信息.txt", "a+");
	M *current = NULL, *tail = NULL;
	M temp;
	fscanf_s(fp, "%s", temp.name,40);
	while (!feof(fp))
	{
		fscanf_s(fp, "%s", temp.grade,20);
		fscanf_s(fp, "%s", temp.money, 20);
		fscanf_s(fp, "%s", temp.venue, 20);
		fscanf_s(fp, "%s", temp.times, 20);
		for (int i = 0; i < 8; i++)
		{
			fscanf_s(fp,"%s", temp.site[i],15);
		}
		current = (M*)malloc(sizeof(M));
		*current = temp;
		if (Mhead == NULL) {
			Mhead = current;
		}
		else {
			tail->next = current;
		}
		//fscanf_s(fp, "%d", &current->flag);
		current->next = NULL;
		tail = current;
		fscanf_s(fp, "%s", &temp.name, 40);
	}
	fclose(fp);
}
void LoadBuyT() {
	FILE *fp;
	fopen_s(&fp, "购票信息.txt", "a+");
	B temp;
	B *current = NULL, *tail = NULL;
	fscanf_s(fp, "%s", temp.uname, 40);
	while (!feof(fp))
	{
		fscanf_s(fp, "%s", temp.mname, 40);
		fscanf_s(fp, "%s", temp.times, 20);
		fscanf_s(fp, "%s", temp.venue, 20);
		fscanf_s(fp, "%d", &temp.x);
		fscanf_s(fp, "%d", &temp.y);
		current = (B*)malloc(sizeof(B));
		*current = temp;
		if (Bhead == NULL) {
			Bhead = current;
		}
		else {
			tail->next = current;
		}
		current->next = NULL;
		tail = current;
		fscanf_s(fp, "%s", &temp.uname, 40);
	}
	fclose(fp);
}

void DownKey(){
	FILE *fp;
	U *current = Uhead;
	fopen_s(&fp, "账号密码.txt", "w+");
	for (; current != NULL; current = current->next)
	{
		fprintf(fp, "%s\n", current->name);
		fprintf(fp, "%s\n", current->key);
		fprintf(fp, "%d\n", current->flag);
	}
	fclose(fp);
	return;
}
void DownInform() {
	FILE *fp;
	M *current = Mhead;
	fopen_s(&fp, "影院信息.txt", "w+");
	for (; current != NULL; current = current->next)
	{
		fprintf(fp, "%s\n%s\n%s\n%s\n", current->name,current->grade,current->money,
			current->venue);
		fprintf(fp, "%s\n", current->times);
		for (int i = 0; i < 8; i++)
		{
			fprintf(fp, "%s\n", current->site[i]);
		}

	}
	fclose(fp);
	return;
}
void DownBuyT() {
	FILE *fp;
	fopen_s(&fp, "购票信息.txt", "w+");
	B temp;
	B *current = NULL, *tail = NULL;
	for(current=Bhead; current != NULL; current = current->next)
	{
		fprintf(fp, "%s\n%s\n%s\n%s\n%d\n%d\n", current->uname, current->mname,
			current->times,current->venue,current->x,current->y);
	}
	fclose(fp);
}
void t() {
	FILE *fp;
	M *current = Mhead;
	fopen_s(&fp, "影院信息.txt", "a+");
	fprintf(fp, "我是谁\n");
	fclose(fp);
}