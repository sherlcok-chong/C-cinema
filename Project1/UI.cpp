#include "DAL.h"
#include "BLL.h"
#pragma warning(disable:4996)

/*WM_MOUSEMOVE��������ƶ�
	 WM_MOUSEWHEEL���������ֹ���
	WM_LBUTTONDOWN��������������
	WM_LBUTTONUP��������������
	WM_LBUTTONDBLCLK����������˫��
	WM_RBUTTONDOWN��������Ҽ�����
	WM_RBUTTONUP��������Ҽ�����
	WM_RBUTTONDBLCLK����������˫��
	WM_MBUTTONDOWN��������м�����
	WM_MBUTTONUP��������м�����
	WM_MBUTTONDBLCLK��������м�˫��*/
void BuyTickets(M *head);
void Sessioinform(M* p,M* q);
void CustomerFace() {
	cleardevice();
	GetMouseMsg();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ�û���", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("��Ҫ��Ʊ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�ѹ���ӰƱ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸��ǳƻ�����", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�˳�����", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	
}
int CustomLo() {
	cleardevice();
	IMAGE Picture;
	U *current = NULL, *tail = NULL;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1)
	{
		if (InputBox(Cuser.name, 40, NULL, _T("��ʢ�л�Ʊ��ϵͳ"), _T("�����û���(�������ȷ�ϰ�ť)"), 400, 200, false)) {
			InputBox(Cuser.key, 40, NULL, _T("��ʢ�л�Ʊ��ϵͳ"), _T("��������(�������ȷ�ϰ�ť)"), 400, 200, false);
		}
		else {
			return 0;
		}
		for (current = Uhead; current != NULL; current = current->next)
		{
			if (!strcmp(Cuser.name, current->name)) {
				if (!strcmp(Cuser.key, current->key)) {
					break;
				}
			}
		}
		if (current == NULL) {
			outtextxy(500, 400, "�˻������������");
			Sleep(1000);
			continue;
		}
		else {
			return current->flag;
		}
		break;
	}
}
void IncreaseMoiveInform() {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	putimage(-400, 150, &Picture);//��ʾͼƬ
	setbkcolor(BLACK);
	settextstyle(40, 0, _T("����"));
	settextcolor(WHITE);
	drawtext("�����ݳ���Ϣ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	M temp;
	M *current = NULL;
	if (InputBox(temp.name, 40, NULL, "��ʢ�л�Ʊ��ϵͳ", "�����Ӱ��(�������ȷ�ϰ�ť)", 400, 200, false)) {
		if (InputBox(temp.grade, 40, NULL, "��ʢ�л�Ʊ��ϵͳ", "��������\n��������8.5(�������ȷ�ϰ�ť)", 400, 200, false)) {
			if (temp.grade[0] != Mhead->grade[0] && temp.grade[1] != Mhead->grade[1] || temp.grade[2] != Mhead->grade[2] && temp.grade[3] != Mhead->grade[3]) {
				outtextxy(500, 400, "�������");
				Sleep(1000);
				return;
			}
			if (InputBox(temp.money, 40, NULL, "��ʢ�л�Ʊ��ϵͳ", "������\n����Ʊ��48Ԫ(�������ȷ�ϰ�ť)", 400, 200, false)) {
				{
					if (temp.money[0] != Mhead->money[0] && temp.money[1] != Mhead->money[1] || temp.money[2] != Mhead->money[2] && temp.money[3] != Mhead->money[3]) {
						outtextxy(500, 400, "�������");
						Sleep(1000);
						return;
					}
				}
				if (InputBox(temp.venue, 40, NULL, "��ʢ�л�Ʊ��ϵͳ", "�����ӳ��(�������ȷ�ϰ�ť)", 400, 200, false)) {
					if (temp.venue[2] != Mhead->venue[2] && temp.venue[3] != Mhead->venue[3] || temp.venue[4] != Mhead->venue[4] && temp.venue[5] != Mhead->venue[5]) {
						outtextxy(500, 400, "�������");
						Sleep(1000);
						return;
					}
					if (InputBox(temp.times, 40, NULL, "��ʢ�л�Ʊ��ϵͳ", "�����ӳʱ��\n��:5��4��11��00(�������ȷ�ϰ�ť)", 400, 200, false)) {
						if (temp.times[0] <= '0' || (temp.times[0] != '1' && (temp.times[1] == '1' || temp.times[1] == '2' || temp.times[1] == '0'))) {
							outtextxy(500, 400, "�������");
							Sleep(1000);
							return;
						}
					}
					else {
						return;
					}
				}
				else {
					return;
				}
			}
			else {
				return;
			}
		}
		else {
			return;
		}
	}
	else {
		return;
	}

	memset(temp.site, '1', sizeof(temp.site));
	for (int i = 0; i < 8; i++)
	{
		temp.site[i][12] = '\0';
	}
	current = (M*)malloc(sizeof(M));
	*current = temp;
	if (Mhead == NULL) {
		current->next = NULL;
		Mhead = current;
	}
	else {
		current->next = Mhead->next;
		Mhead->next = current;
	}
	DownInform();
	cleardevice();
	outtextxy(500, 400, "���ӳɹ�");
	Sleep(1000);
}
void CustomerRe(int i) {
	cleardevice();
	IMAGE Picture;
	U Cuser;
	U *current = NULL, *tail = NULL;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (i==2)
		InputBox(Cuser.name, 40, NULL, _T("��ʢ�л�Ʊ��ϵͳ"), _T("������֤��(�����ṩ)"), 400, 200, false);
	if (strcmp(Cuser.name, key) && i == 2) {
		outtextxy(500, 400, "��֤�����");
		Sleep(1000);
		return;
	}
	while (1)
	{
		if (InputBox(Cuser.name, 40, NULL, _T("��ʢ�л�Ʊ��ϵͳ"), _T("�����û���(�������ȷ�ϰ�ť)"), 400, 200, false) && InputBox(Cuser.key, 40, NULL, _T("��ʢ�л�Ʊ��ϵͳ"), _T("��������(�������ȷ�ϰ�ť)"), 400, 200, false)) {

		}
		else {
			return;
		}
		for (current = Uhead; current != NULL; current = current->next)
		{
			if (!strcmp(Cuser.name, current->name)) {
				outtextxy(500, 400, "�û�����");
				Sleep(1000);
				break;
			}
		}
		if (current != NULL) continue;
		break;
	}

	Cuser.next = NULL;
	Cuser.flag = i;
	current = (U*)malloc(sizeof(U));
	*current = Cuser;
	current->next = NULL;
	if (Uhead == NULL) {
		Uhead = current;
	}
	else {
		tail = Uhead;
		for (; tail->next != NULL; tail = tail->next);
	}
	tail->next = current;
	DownKey();
	outtextxy(500, 400, "ע��ɹ�");
	Sleep(1000);
	MOUSEMSG m;
	m = GetMouseMsg();
	return;
}

void ManagerFace() {
	cleardevice();
	GetMouseMsg();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ�����", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("����ӰƬ��Ϣ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("��ʾ���е�Ӱ��Ϣ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�����ݳ���Ϣ", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸��ǳƻ�����", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�˳�����", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

}
void Userface() {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("������", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("����Աע��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�ο��û�ע��", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("������һ��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�˳�����", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void Faceface() {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("���û�ע��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���û���¼", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�˳�����", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void Ticketsface(M *head) {
	cleardevice();
	IMAGE Picture;
	//char s[10] = "123123";
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	setlinecolor(BLACK);
	settextstyle(40, 0, _T("����"));
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, "����");
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextcolor(RED);
	drawtext("������ӳ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextcolor(WHITE);
	settextstyle(30, 0, "����");
	M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL, *p6 = NULL;
	if (head != NULL) {
		p1 = head; head = head->next;
		drawtext(p1->name, &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(p1->grade, &P2, DT_TOP | DT_LEFT);
		drawtext(p1->money, &P2, DT_TOP | DT_RIGHT);
	}
	if (head != NULL) {
		for (; head != NULL&&!strcmp(head->name, p1->name); head = head->next);
		if (head != NULL) {
			p2 = head; head = head->next;
			drawtext(p2->name, &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(p2->grade, &P3, DT_TOP | DT_LEFT);
			drawtext(p2->money, &P3, DT_TOP | DT_RIGHT);
		}
	}
	if (head != NULL) {
		for (; head != NULL&&(!strcmp(head->name, p2->name) || !strcmp(head->name, p1->name) ); head = head->next);
		if (head != NULL) {
			p3 = head; head = head->next;
			drawtext(p3->name, &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(p3->grade, &P4, DT_TOP | DT_LEFT);
			drawtext(p3->money, &P4, DT_TOP | DT_RIGHT);
		}
	}
	if (head != NULL) {
		for (; head != NULL&&(!strcmp(head->name, p3->name) || !strcmp(head->name, p2->name) || !strcmp(head->name, p1->name)) ; head = head->next);
		if (head != NULL) {
			p4 = head; head = head->next;
			drawtext(p4->name, &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(p4->grade, &P5, DT_TOP | DT_LEFT);
			drawtext(p4->money, &P5, DT_TOP | DT_RIGHT);
		}
	}
	if (head != NULL) {
		for (; head != NULL&&(!strcmp(head->name, p4->name) || !strcmp(head->name, p3->name) || !strcmp(head->name, p2->name) || !strcmp(head->name, p1->name)); head = head->next);
		if (head != NULL) {
			p5 = head; head = head->next;
			drawtext(p5->name, &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(p5->grade, &P6, DT_TOP | DT_LEFT);
			drawtext(p5->money, &P6, DT_TOP | DT_RIGHT);
		}
	}
	for (p6 = head; p6 != NULL; p6 = p6->next) {
		if (strcmp(p5->name, p6->name)) {
			break;
		}
	}
	if (p6!=NULL&& p5->next != NULL) {
		drawtext("��һҳ", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (p1 != Mhead) {
		drawtext("��һҳ", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
void SessioFace(M* p,M* q) {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	putimage(-400, 150, &Picture);//��ʾͼƬ
	setbkcolor(BLACK);
	settextstyle(40, 0, _T("����"));
	settextcolor(WHITE);
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextcolor(RED);
	drawtext(p->name, &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextcolor(WHITE);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	
	M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
	M *current;
	int i = 1, j = 0;
	for (current = q; current != NULL && i <= 5; current = current->next)
	{
		if (!strcmp(current->name, p->name))
		{
			outtextxy(r[i+1][0] + 80, r[i+1][1] + 10, current->times);
			outtextxy(r[i+1][0] + 450, r[i+1][1] + 10, current->venue);
			i++;
			if (p1 == NULL) {
				p1 = current;
			}
			else if (p2 == NULL) {
				p2 = current;
			}
			else if (p3 == NULL) {
				p3 = current;
			}
			else if (p4 == NULL) {
				p4 = current;
			}
			else if (p5 == NULL) {
				p5 = current;
			}
		}
	}
	
	if (p5 != NULL && p5->next != NULL) {
		drawtext("��һҳ", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (p1 != Mhead) {
		drawtext("��һҳ", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	} 
}
void SeatFace(M *p) {
	cleardevice();
	setlinecolor(WHITE);
	settextstyle(40, 0, _T("����"));
	outtextxy(600, 40, "��Ļ");
	settextstyle(30, 0, _T("����"));
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(225, 135, 275, 185);
	outtextxy(300, 150, "δ��");
	fillrectangle(450, 135, 500, 185);
	outtextxy(525, 150, "����");	
	int k = 1;
	int x = 0;
	char y = '0'-1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 12; j++, k++)
		{
			rectangle(s[k][0], s[k][1], s[k][2], s[k][3]);
			if (p->site[i][j] == '3') {
				fillrectangle(s[k][0], s[k][1], s[k][2], s[k][3]);
				x++;
			}
		}
	}
	int sum;
	int money;
	char s[10];
	sprintf(s, "%d", x);
	if (strlen(MoiveName ) == 0) {
		outtextxy(600, 150, " ����ѡƱ���ٴε��ȡ��");
		outtextxy(542, 716, " ȷ��ѡƱ");
	}
	else {
		outtextxy(542, 716, "����");
		outtextxy(670, 716, s);
		sum = x;
		money = p->money[4] - '0';
		if (p->money[5] > '0' && p->money[5] <= '9')
		{
			money = money*10+p->money[5] - '0';
		}
		sum *= money;
		outtextxy(730, 716, "��");
		outtextxy(800, 716, "����");
		sprintf(s, "%d", sum);
		outtextxy(880, 716, s);
		outtextxy(980, 716, "Ԫ");
		MOUSEMSG m;
		int choice = 0;
		while (true)
		{
			m = GetMouseMsg();//��ȡһ�������Ϣ
			if (m.uMsg == WM_MOUSEMOVE) {
				setrop2(R2_XORPEN);
				if (charge(m.x, m.y) != 0) {
					if (choice != charge(m.x, m.y)) {
						choice = charge(m.x, m.y);
						if (choice == 7) {
							fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
						}
					}
				}
				else if (choice != 0 && choice == 7) {
					fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					choice = 0;
				}
			}
			else if (m.uMsg == WM_LBUTTONDOWN) {
				if (choice == 7) {
					return;
				}
			}
		}
	}
}
void RefundFace(B *p) {
	cleardevice();
	settextcolor(WHITE);
	settextstyle(40, 0, _T("����"));
	outtextxy(600, 40, "�ҵ�ӰƱ");
	B *current;
	settextstyle(30, 0, _T("����"));
	B *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
	char x, y[3];
	for (current = p; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		drawtext(current->mname, &B1, DT_LEFT);
		drawtext(current->venue, &B1, DT_CENTER);
		drawtext(current->times, &B1, DT_RIGHT);
		drawtext("��Ʊ", &C1, DT_CENTER);
		p1 = current;
		x = current->x + '0';
		if (current->y >= 10) {
			y[0] = '1';
			y[1] = ((current->y) % 10) + '0';
			y[2] = '\0';
		}
		else {
			y[0] = current->y + '0';
			y[1] = '\0';
		}
		outtextxy(830, 220, x);
		outtextxy(860, 220, "��");
		outtextxy(890, 220, y);
		outtextxy(920, 220, "��");
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		drawtext(current->mname, &B2, DT_LEFT);
		drawtext(current->venue, &B2, DT_CENTER);
		drawtext(current->times, &B2, DT_RIGHT);
		drawtext("��Ʊ", &C2, DT_CENTER);
		x = current->x + '0';
		if (current->y >= 10) {
			y[0] = '1';
			y[1] = ((current->y) % 10) + '0';
			y[2] = '\0';
		}
		else {
			y[0] = current->y + '0';
			y[1] = '\0';
		}
		outtextxy(830, 290, x);
		outtextxy(860, 290, "��");
		outtextxy(890, 290, y);
		outtextxy(920, 290, "��");
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		drawtext(current->mname, &B3, DT_LEFT);
		drawtext(current->venue, &B3, DT_CENTER);
		drawtext(current->times, &B3, DT_RIGHT);
		drawtext("��Ʊ", &C3, DT_CENTER);
		x = current->x + '0';
		if (current->y >= 10) {
			y[0] = '1';
			y[1] = ((current->y) % 10) + '0';
			y[2] = '\0';
		}
		else {
			y[0] = current->y + '0';
			y[1] = '\0';
		}
		outtextxy(830, 360, x);
		outtextxy(860, 360, "��");
		outtextxy(890, 360, y);
		outtextxy(920, 360, "��");
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		drawtext(current->mname, &B4, DT_LEFT);
		drawtext(current->venue, &B4, DT_CENTER);
		drawtext(current->times, &B4, DT_RIGHT);
		drawtext("��Ʊ", &C4, DT_CENTER);
		x = current->x + '0';
		if (current->y >= 10) {
			y[0] = '1';
			y[1] = ((current->y) % 10) + '0';
			y[2] = '\0';
		}
		else {
			y[0] = current->y + '0';
			y[1] = '\0';
		}
		outtextxy(830, 430, x);
		outtextxy(860, 430, "��");
		outtextxy(890, 430, y);
		outtextxy(920, 430, "��");
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		drawtext(current->mname, &B5, DT_LEFT);
		drawtext(current->venue, &B5, DT_CENTER);
		drawtext(current->times, &B5, DT_RIGHT);
		drawtext("��Ʊ", &C5, DT_CENTER);
		x = current->x + '0';
		if (current->y >= 10) {
			y[0] = '1';
			y[1] = ((current->y) % 10) + '0';
			y[2] = '\0';
		}
		else {
			y[0] = current->y + '0';
			y[1] = '\0';
		}
		outtextxy(830, 500, x);
		outtextxy(860, 500, "��");
		outtextxy(890, 500, y);
		outtextxy(920, 500, "��");;
		current = current->next;
		break;
	}
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (current != NULL) {
		drawtext("��һҳ", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (p1 != Bhead) {
		drawtext("��һҳ", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
void FindInformFace(M *p) {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	setbkcolor(BLACK);//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
	putimage(-400, 150, &Picture);//��ʾͼƬ
	settextcolor(WHITE);
	char temp[40];
	temp[3] = '\0';
	int cnt = 1;
	M *current = NULL;
	M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL, *p6 = NULL;
	if (strlen(MoiveName) == 0 && !InputBox(MoiveName, 40, NULL, _T("��ʢ�л�Ʊ��ϵͳ"), _T("�����ѯ��Ϣ(�������ȷ�ϰ�ť)"), 400, 200, false))
	{
		return;
	}
	for (current = p; current != NULL; current = current->next)
	{
		for (int i = 0; i < strlen(current->name); i += 2)
		{
			temp[0] = current->name[i];
			temp[1] = current->name[i + 1];
			if (temp[0] == MoiveName[0] && temp[1] == MoiveName[1]) {
				if (p1 == NULL) {
					p1 = current;
					cnt++;
				}
				else if (p2 == NULL) {
					if (strcmp(p1->name, current->name)) {
						p2 = current;
						cnt++;
					}
				}
				else if (p3 == NULL) {
					if (strcmp(p1->name, current->name) && strcmp(p2->name, current->name))
					{
						p3 = current;
						cnt++;
					}
				}
				else if (p4 == NULL) {
					if (strcmp(p1->name, current->name) && strcmp(p2->name, current->name) && strcmp(p3->name, current->name))
					{
						cnt++;
						p4 = current;
					}
				}
				else if (p5 == NULL) {
					if (strcmp(p1->name, current->name) && strcmp(p2->name, current->name) && strcmp(p3->name, current->name) && strcmp(p4->name, current->name))
					{
						p5 = current;
						cnt++;
					}
				}
				else if (p6 == NULL) {
					if (strcmp(p1->name, current->name) && strcmp(p2->name, current->name) && strcmp(p3->name, current->name) && strcmp(p4->name, current->name) && strcmp(p5->name, current->name))
						p6 = current;
				}
				break;
			}
		}
	}
	settextstyle(30, 0, _T("����"));
	drawtext("�й�", &R0, DT_LEFT);
	drawtext(MoiveName, &R0, DT_CENTER);
	drawtext("��������Ϣ", &R0, DT_RIGHT);
	if (p1 != NULL) {
		drawtext(p1->name, &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(p1->grade, &P1, DT_TOP | DT_LEFT);
		drawtext(p1->money, &P1, DT_TOP | DT_RIGHT);
	}
	if (p2 != NULL) {
		drawtext(p2->name, &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(p2->grade, &P2, DT_TOP | DT_LEFT);
		drawtext(p2->money, &P2, DT_TOP | DT_RIGHT);
	}
	if (p3 != NULL) {
		drawtext(p3->name, &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(p3->grade, &P3, DT_TOP | DT_LEFT);
		drawtext(p3->money, &P3, DT_TOP | DT_RIGHT);
	}
	if (p4 != NULL) {
		drawtext(p4->name, &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(p4->grade, &P4, DT_TOP | DT_LEFT);
		drawtext(p4->money, &P4, DT_TOP | DT_RIGHT);
	}
	if (p5 != NULL) {
		drawtext(p5->name, &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(p5->grade, &P5, DT_TOP | DT_LEFT);
		drawtext(p5->money, &P5, DT_TOP | DT_RIGHT);
	}
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (p6 != NULL) {
		drawtext("��һҳ", &R9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	if (p1 != Mhead) {
		drawtext("��һҳ", &R8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}
void IDCFace() {
	GetMouseMsg();
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	putimage(-400, 150, &Picture);//��ʾͼƬ
	setbkcolor(BLACK);
	settextstyle(40, 0, _T("����"));
	settextcolor(WHITE);
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("����ӰƬ��Ϣ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸�ӰƬ��Ϣ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void ChangeFace() {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	putimage(-400, 150, &Picture);//��ʾͼƬ
	setbkcolor(BLACK);
	settextstyle(40, 0, _T("����"));
	settextcolor(WHITE);
	drawtext("��ʢ�л���ӰƱ��ϵͳ", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(30, 0, _T("����"));
	drawtext("����", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸��ݳ�ʱ��", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸��ݳ�����", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸�ӰƬ����", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�޸�ӰƬƱ��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("ɾ��ӰƬ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
int main() {
	initgraph(1500, 800);
	LoadBuyT();
	Loadkey();
	LoadInform();
	cleardevice();
	MOUSEMSG m;
	if (OpenFace() == 1) {
		m = GetMouseMsg();
		Customer();
	}
	else {
		m = GetMouseMsg();
		Manager();
	}
	getchar();
	return 0;
}

