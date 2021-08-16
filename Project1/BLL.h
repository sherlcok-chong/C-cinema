void fang(M *p);
void Ticketsface(M *head);
void Sessioinform(M* p,M* q);
void Faceface();
void Userface();
void CustomerRe(int i);
void CustomerFace();
void ManagerFace();
void BuyTickets(M *head);
void SessioFace(M* p, M* q);
void SetSeat(M *p); 
void SeatFace(M *p);
void DownBy(M *p);
void RefundTicket(B *p);
void RefundFace(B *p);
void DeleTi(B *p);
void ChangeUserInform();
void FindMoiveInform(M *p);
void FindInformFace(M *p);
void IDCMoive();
void IDCFace();
void IncreaseMoiveInform();
void ChangeMoiveInform();
void ChangeFace();
void MyWay(int i,M *p);
M *Creatsession(M *p);
void Finallyfx(M *p);
int CustomLo();
int charge(int x, int y)
{
	for (int i = 1; i <= 10; i++)
	{
		if (x > r[i][0] && x < r[i][2] && y> r[i][1] && y < r[i][3]) {
			return i;
		}
	}
	return 0;
}
int FindSite(int x,int y) {
	for (int i = 1; i <= 98; i++)
	{
		if (x > s[i][0] && x < s[i][2] && y> s[i][1] && y < s[i][3]) {
			return i;
		}
		/*225,210,275,260
		450,210,500,260
		525,575,630,680
		*/
	}
	return 0;
}
int FindTi(int x, int y) {
	for (int i = 1; i <= 5; i++)
	{
		if (x > c[i][0] && x < c[i][2] && y> c[i][1] && y < c[i][3]) {
			return i;
		}
	}
	return 0;
}
void Customer() {
	CustomerFace();
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (charge(m.x, m.y) <= 4)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				}
			}
			else if (choice != 0 && choice <= 4) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 1) {
				BuyTickets(Mhead);
				CustomerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 2) {
				RefundTicket(Bhead);
				CustomerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 3) {
				ChangeUserInform();
				CustomerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 4) {
				exit(0);
			}
		}
	}
}
void Manager() {
	ManagerFace();
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if(choice!=8&&choice!=9&&choice!=7&&choice!=5&&choice!=6)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				}
			}
			else if (choice != 0) {
				if (choice != 8 && choice != 9 && choice != 7&&choice!=6)
				{
					fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					choice = 0;
				}
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 1) {
				FindMoiveInform(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				ManagerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 2) {
				MoiveName[0] = '1';
				MoiveName[2] = '\0';
				BuyTickets(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				ManagerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 3) {
				IDCMoive();
				ManagerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 4) {
				ChangeUserInform();
				ManagerFace();
				choice = 0;
			}
			else if (charge(m.x, m.y) == 5) {
				exit(0);
			}
		}
	}
}
void RegisterUser() {
	Userface();
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (charge(m.x, m.y) == 2 || charge(m.x, m.y) == 3 || charge(m.x, m.y) == 4 || charge(m.x, m.y) == 5)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				}
			}
			else if (choice != 0 && choice != 1 && choice <= 5) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 2) {
				CustomerRe(2);
				return;
			}
			else if (charge(m.x, m.y) == 3) {
				CustomerRe(1);
				return;
			}
			else if (charge(m.x, m.y) == 4) {
				return;
			}
			else if (charge(m.x, m.y) == 5) {
				exit(0);
			}
		}
	}
}

int OpenFace() {
	int choice = 0, i = 0;
	Faceface();
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice <= 3)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				}
			}
			else if (choice != 0 && choice <= 3) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 1) {
				i = CustomLo();
				if (i != 0) {
					return i;
				}
				else {
					Faceface();
				}
			}
			else if (charge(m.x, m.y) == 2) {
				RegisterUser();
				Faceface();
			}
			else if (charge(m.x, m.y) == 3) {
				exit(0);
				return 0;
			}
		}
		FlushMouseMsgBuffer();
	}
}
void BuyTickets(M *head) {
	Ticketsface(head);
	M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL, *p6 = NULL;
	int cnt = 1;
	if (head != NULL) {
		
		p1 = head; head = head->next;
		cnt++;
	}
	if (head != NULL) {
		for (; head != NULL && !strcmp(head->name, p1->name); head = head->next);
		if (head != NULL) {
			p2 = head; head = head->next;
			cnt++;
		}
	}
	if (head != NULL) {
		for (;head!=NULL&& (!strcmp(head->name, p2->name) || !strcmp(head->name, p1->name)); head = head->next);
		if (head != NULL) {
			p3 = head; head = head->next;
			cnt++;
		}
	}
	if (head != NULL) {
		for (; head != NULL && (!strcmp(head->name, p3->name) || !strcmp(head->name, p2->name) || !strcmp(head->name, p1->name)) ; head = head->next);
		if (head != NULL) {
			p4 = head; head = head->next;
			cnt++;
		}
	}
	if (head != NULL) {
		for (; head != NULL && (!strcmp(head->name, p4->name) || !strcmp(head->name, p3->name) || !strcmp(head->name, p2->name) || !strcmp(head->name, p1->name)); head = head->next);
		if (head != NULL) {
			p5 = head; head = head->next;
			cnt++;
		}
	}
	for (p6 = head; p6 != NULL; p6 = p6->next) {
		if (strcmp(p5->name, p6->name)) {
			break;
		}
	}
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice != 1 && choice <= cnt || choice == 7)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					else if (choice == 8 && p1 != Mhead) {
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					}
					else if (choice == 9 && p6 != NULL &&p5->next != NULL) {
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					}
				}
			}
			else if (choice != 0 && choice != 1 && choice <= cnt || choice == 7) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
			else if (choice == 8 && p1 != Mhead) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
			else if (choice == 9 && p6 != NULL && p5->next != NULL) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 2&&p1!=NULL) {
				session = Creatsession(p1);
				Sessioinform(p1, session);
				Ticketsface(p1);
				free(session);
			}
			else if (charge(m.x, m.y) == 3&&p2!=NULL) {
				session = Creatsession(p2);
				Sessioinform(p2,session);
				Ticketsface(p1);
				fang(session);
			}
			else if (charge(m.x, m.y) == 4&&p3!=NULL) {
				session = Creatsession(p3);
				Sessioinform(p3, session);
				Ticketsface(p1);
				fang(session);
			}
			else if (charge(m.x, m.y) == 5&&p4!=NULL) {
				session = Creatsession(p4);
				Sessioinform(p4, session);
				Ticketsface(p1);
				fang(session);
			}
			else if (charge(m.x, m.y) == 6&&p5!=NULL) {
				session = Creatsession(p5);
				Sessioinform(p5, session);
				Ticketsface(p1);
				fang(session);
				return;
			}
			else if (charge(m.x, m.y) == 7) {
				return;
			}
			else if (charge(m.x, m.y) == 8&&p1!=Mhead) {
				return;
			}
			else if (charge(m.x, m.y) == 9&&p6!=NULL&&p5->next!=NULL) {
				BuyTickets(p6);
				Ticketsface(p1);
			}
		}
	}
}
void Sessioinform(M* p,M* q) {
	SessioFace(p,q);
	M *current;
	M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
	int i = 1, j = 0;
	for (current = q; current != NULL && i <= 5; current = current->next)
	{
		if (!strcmp(current->name, p->name))
		{
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
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice != 1 && choice <= i || choice == 7)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					else if (choice == 8 && p1 != Mhead) {
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					}
					else if (choice == 9 && p5 != NULL && p5->next != NULL) {
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					}
				}
			}
			else if (choice != 0 && choice != 1 && choice <= i || choice == 7) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
			else if (choice == 8 && p1 != Mhead) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
			else if (choice == 9 && p5 != NULL && p5->next != NULL) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 2) {
				if(Way!=0){
					MyWay(Way,p1);
				}
				else if (strlen(MoiveName) == 0) {
					SetSeat(p1);
				}
				else {
					SeatFace(p1);
				}
				Finallyfx(session);
				SessioFace(p, q);
			}
			else if (charge(m.x, m.y) == 3) {
				if (Way != 0) {
					MyWay(Way,p2);
				}
				else if (strlen(MoiveName) == 0) {
					SetSeat(p1);
				}
				else {
					SeatFace(p1);
				}
				SessioFace(p, q);
			}
			else if (charge(m.x, m.y) == 4) {
				if (Way != 0) {
					MyWay(Way,p3);
				}
				else if (strlen(MoiveName) == 0) {
					SetSeat(p1);
				}
				else {
					SeatFace(p1);
				}
				SessioFace(p, q);
			}
			else if (charge(m.x, m.y) == 5) {
				if (Way != 0) {
					MyWay(Way,p4);
				}
				else if (strlen(MoiveName) == 0) {
					SetSeat(p1);
				}
				else {
					SeatFace(p1);
				}
				SessioFace(p, q);
			}
			else if (charge(m.x, m.y) == 6) {
				if (Way != 0) {
					MyWay(Way,p4);
				}
				else if (strlen(MoiveName) == 0) {
					SetSeat(p1);
				}
				else {
					SeatFace(p1);
				}
				SessioFace(p, q);
			}
			else if (charge(m.x, m.y) == 7) {
				return;
			}
			else if (charge(m.x, m.y) == 8 && p1 != Mhead) {
				return;
			}
			else if (charge(m.x, m.y) == 9 && p5 != NULL && p5->next != NULL) {
				Sessioinform(p1, p5->next);
				SessioFace(p1,q);
			}
		}
	}
}
void SetSeat(M *p) {
	SeatFace(p);
	MOUSEMSG m;
	int choice=0;
	int x, y;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice == 7||choice==10) 					
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					
				}
			}
			else if (choice != 0 && (choice == 7||choice==10)) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			choice = charge(m.x, m.y);
			if (choice == 7) {
				return;
			}
			else if (choice == 10) {
				DownBy(p);
				Finallyfx(session);				
				DownInform();
				return;
			}
			choice = FindSite(m.x, m.y);
			y = (choice - 1) / 12;
			x = (choice - 1) % 12;
			if (p->site[y][x] == '2' || p->site[y][x] == '1') {
				fillrectangle(s[choice][0], s[choice][1], s[choice][2], s[choice][3]);
				y = (choice - 1) / 12;
				x = (choice - 1) % 12;
				if (p->site[y][x] == '2') {
					p->site[y][x] = '1';
				}
				else {
					p->site[y][x] = '2';
				}
			}
		}
	} 
}
void DownBy(M *p) {
	cleardevice();
	settextstyle(40, 0, _T("宋体"));
	outtextxy(500, 400, "购票成功");
	B *current = NULL;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (p->site[i][j] == '2')
			{
				p->site[i][j] = '3';
				current = (B*)malloc(sizeof(B));
				if (Bhead == NULL) {
					Bhead = current;
					current->next = NULL;
				}
				else {
					current->next = Bhead->next;
					Bhead->next = current;
				}
				strcpy_s(current->uname, Cuser.name);
				strcpy_s(current->mname, p->name);
				strcpy_s(current->times, p->times);
				strcpy_s(current->venue, p->venue);
				current->x = i + 1;
				current->y = j + 1;
			}
		}
	}
	DownBuyT();
	Sleep(1000);
}
void RefundTicket(B *p) {
	RefundFace(p);
	int choice = 0, option = 0;
	int cnt = 1;
	B *current;
	B *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
	for (current = p; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		p1 = current;
		current = current->next;
		cnt++;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		p2 = current;
		cnt++;
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		p3 = current;;
		cnt++;
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		p4 = current;
		cnt++;
		current = current->next;
		break;
	}
	for (; current != NULL && !strcmp(current->uname, Cuser.name); current = current->next)
	{
		p5 = current;
		cnt++;
		current = current->next;
		break;
	}
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (FindTi(m.x, m.y) != 0) {
				if (choice != FindTi(m.x, m.y)) {
					choice = FindTi(m.x, m.y);
					if(choice<cnt)
						fillrectangle(c[choice][0], c[choice][1], c[choice][2], c[choice][3]);
				}
			}
			else if (choice != 0 && choice<cnt) {
				fillrectangle(c[choice][0], c[choice][1], c[choice][2], c[choice][3]);
				choice = 0;
			}
			if (charge(m.x, m.y) != 0) {
				if (option != charge(m.x, m.y) ){
					option = charge(m.x, m.y);
					if(option == 8 &&p1!=Bhead)
						fillrectangle(r[option][0], r[option][1], r[option][2], r[option][3]);
					else if (option == 9 && p5 != NULL)
						fillrectangle(r[option][0], r[option][1], r[option][2], r[option][3]);
					else if(option==7)
						fillrectangle(r[option][0], r[option][1], r[option][2], r[option][3]);
				}
			}
			else if (option != 0) {
				if (option == 8 && p1 != Bhead)
					fillrectangle(r[option][0], r[option][1], r[option][2], r[option][3]);
				else if (option == 9 && p5 != NULL )
					fillrectangle(r[option][0], r[option][1], r[option][2], r[option][3]);
				else if (option == 7)
					fillrectangle(r[option][0], r[option][1], r[option][2], r[option][3]);
				option = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if(option == 8 && p1 != Bhead){
				return;
			}
			else if (option == 9 && p5!=NULL&&p5->next != NULL) {
				RefundTicket(p5->next);
				RefundFace(p);
			}
			else if (option == 7) {
				return;
			}
			if (choice != 0) {
				if (choice == 1){
					DeleTi(p1);
					return;
				}
				else if (choice == 2) {
					DeleTi(p2);
					return;
				}
				else if (choice == 3) {
					DeleTi(p3);
					return;
				}
				else if (choice == 4) {
					DeleTi(p4);
					return;
				}
				else if (choice == 5) {
					DeleTi(p5);
					return;
				}
			}
		}
	}
	
}
void DeleTi(B *p) {
	B *current = NULL;
	M *t = NULL;
	for (t = Mhead; t != NULL; t = t->next)
	{
		if (!strcmp(t->name, p->mname))
		{
			if (t->site[p->x - 1][p->y - 1] == '3') {
				t->site[p->x - 1][p->y - 1] = '1';
				break;
			}
		}
	}
	for (current = Bhead; current != NULL; current = current->next)
	{
		if (p == Bhead) {
			if (Bhead->next == NULL) {
				free(p);
				Bhead = NULL;
			}
			else {
				Bhead = Bhead->next;
				free(p);
			}
			break;
		}
		else if (current->next == p) {
			current->next = p->next;
			free(p);
			break;
		}
	}
	DownBuyT();
	DownInform();
	cleardevice();
	settextstyle(40, 0, _T("宋体"));
	outtextxy(500, 400, "退票成功");
	Sleep(1000);
	GetMouseMsg();
}
void ChangeUserInform() {
	cleardevice();
	IMAGE Picture;
	loadimage(&Picture, _T("Debug\\flower.jpg"), 1002, 660);
	putimage(-400, 150, &Picture);//显示图片
	setbkcolor(BLACK);
	settextstyle(40, 0, _T("宋体"));
	settextcolor(WHITE);
	drawtext("鼎盛中华电影票务系统用户端", &R0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	U temp;
	U *current = NULL;
	B *t = NULL;
	while (1)
	{
		if (InputBox(temp.name, 40, NULL, _T("鼎盛中华票务系统"), _T("输入新的用户名(输入完后按确认按钮)"), 400, 200, false) && InputBox(temp.key, 40, NULL, _T("鼎盛中华票务系统"), _T("输入新密码(输入完后按确认按钮)"), 400, 200, false)) {
			for (current = Uhead; current != NULL; current = current->next)
			{
				if (!strcmp(temp.name, current->name)) {
					outtextxy(500, 400, "用户存在");
					Sleep(1000);
					break;
				}
			}
			if (current != NULL) {
				continue;
			}
			for (current = Uhead; current != NULL; current = current->next)
			{
				if (!strcmp(Cuser.name, current->name)) {
					if (!strcmp(Cuser.key, current->key)) {
						strcpy_s(current->name, temp.name);
						strcpy_s(current->key, temp.key);
						break;
					}
				}
			}
			break;
		}
		else {
			return;
		}
	}
	outtextxy(500, 400, "修改成功");
	Sleep(1000);
	DownKey();
	for (t = Bhead; t != NULL; t = t->next)
	{
		if (!strcmp(t->uname, Cuser.name)) {
			strcpy_s(t->uname, temp.name);
		}
	}
	DownBuyT();
	cleardevice();
	outtextxy(500, 400, "身份过期请重新登录");
	Sleep(1000);
	exit(0);
}
void FindMoiveInform(M *p) {
	FindInformFace(p);
	char temp[40];
	temp[3] = '\0';
	int cnt = 1;
	MOUSEMSG m;
	int choice = 0;
	M *current = NULL;
	M *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL, *p6 = NULL;
	if (strlen(MoiveName) == 0) {
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
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice < cnt || choice == 7)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					else if (choice == 8 && p1 != Mhead) {
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					}
					else if (choice == 9 && p5 != NULL && p5->next != NULL) {
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					}
				}
			}
			else if ( choice!=0&&choice < cnt || choice == 7) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
			else if (choice == 8 && p1 != Mhead) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
			else if (choice == 9 && p5 != NULL && p6 != NULL) {
				fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				choice = 0;
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 1 && p1 != NULL) {
				session = Creatsession(p1);
				Sessioinform(p1, session);
				Finallyfx(session);
				FindInformFace(p);
				free(session);
			}
			else if (charge(m.x, m.y) == 2 && p2 != NULL) {
				session = Creatsession(p2);
				Sessioinform(p2, session);
				Finallyfx(session);
				FindInformFace(p);
				free(session);
			}
			else if (charge(m.x, m.y) == 3 && p3 != NULL) {
				session = Creatsession(p3);
				Sessioinform(p3, session);
				Finallyfx(session);
				FindInformFace(p);
				free(session);
			}
			else if (charge(m.x, m.y) == 4 && p4 != NULL) {
				session = Creatsession(p4);
				Sessioinform(p4, session);
				Finallyfx(session);
				FindInformFace(p);
				free(session);
			}
			else if (charge(m.x, m.y) == 5 && p5 != NULL) {
				session = Creatsession(p5);
				Sessioinform(p5, session);
				Finallyfx(session);
				FindInformFace(p);
				free(session);
			}
			else if (charge(m.x, m.y) == 7) {
				
				return;
			}
			else if (charge(m.x, m.y) == 8 && p1 != Mhead) {
				return;
			}
			else if (charge(m.x, m.y) == 9 && p6 != NULL) {
				Sessioinform(p6, Mhead);
				FindInformFace(p);
			}
			
		}
	}
}
void IDCMoive() {
	
	IDCFace();
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice <= 2 || choice == 7)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				}
			}
			else if (choice != 0) {
				if (choice <= 2 || choice == 7)
				{
					fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					choice = 0;
				}
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 1) {
				IncreaseMoiveInform();
				choice = 0;
				IDCFace();
			}
			else if (charge(m.x, m.y) == 2) {
				ChangeMoiveInform();
				choice = 0;
				IDCFace();
			}
			else if (charge(m.x, m.y) == 7) {
				return;
			}
		}
	}
}

void ChangeMoiveInform() {
	ChangeFace();
	MOUSEMSG m;
	int choice = 0;
	while (true)
	{
		m = GetMouseMsg();//获取一条鼠标消息
		if (m.uMsg == WM_MOUSEMOVE) {
			setrop2(R2_XORPEN);
			if (charge(m.x, m.y) != 0) {
				if (choice != charge(m.x, m.y)) {
					choice = charge(m.x, m.y);
					if (choice <= 5 || choice == 7)
						fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
				}
			}
			else if (choice != 0) {
				if (choice <= 5 || choice == 7)
				{
					fillrectangle(r[choice][0], r[choice][1], r[choice][2], r[choice][3]);
					choice = 0;
				}
			}
		}
		else if (m.uMsg == WM_LBUTTONDOWN) {
			if (charge(m.x, m.y) == 1) {
				Way = 1;
				FindMoiveInform(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				choice = 0;
				ChangeFace();
				Way = 0;
			}
			else if (charge(m.x, m.y) == 2) {
				Way = 2;
				FindMoiveInform(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				choice = 0;
				ChangeFace();
				Way = 0;
			}
			else if (charge(m.x, m.y) == 3) {
				Way = 3;
				FindMoiveInform(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				choice = 0;
				ChangeFace();
				Way = 0;
			}
			else if (charge(m.x, m.y) == 4) {
				Way = 4;
				FindMoiveInform(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				choice = 0;
				ChangeFace();
				Way = 0;
			}
			else if (charge(m.x, m.y) == 5) {
				Way = 5;
				FindMoiveInform(Mhead);
				memset(MoiveName, '\0', sizeof(MoiveName));
				choice = 0;
				ChangeFace();
				Way = 0;
			}
			else if (charge(m.x, m.y) == 7) {
				return;
			}
		}
	}
}
void MyWay(int i,M *p) {
	int cnt=0;
	M temp;
	settextstyle(40, 0, _T("宋体"));
	cleardevice();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (p->site[i][j] == '3') {
				cnt++;
			}
		}
	}
	temp = *p;
	if (cnt > 0) {
		outtextxy(500, 400, "该场已售出不可修改");
		Sleep(1000);
		return;
	}
	if (i == 1) {
		if (InputBox(temp.times, 40, NULL, "鼎盛中华票务系统", "输入放映时间\n例:5月4日11：00(输入完后按确认按钮)", 400, 200, false)){
			if (temp.times[0] <= '0' || (temp.times[0] != '1' && (temp.times[1] == '1' || temp.times[1] == '2' || temp.times[1] == '0'))) {
				outtextxy(500, 400, "输入错误");
				Sleep(1000);
				return;
			}
		}
		else {
			return;
		}
	}
	else if (i == 2) {
		if (InputBox(temp.venue, 40, NULL, "鼎盛中华票务系统", "输入放映厅(输入完后按确认按钮)", 400, 200, false)) {
			if (temp.venue[2] != Mhead->venue[2] && temp.venue[3] != Mhead->venue[3] || temp.venue[4] != Mhead->venue[4] && temp.venue[5] != Mhead->venue[5]) {
				outtextxy(500, 400, "输入错误");
				Sleep(1000);
				return;
			}
		}
		else return;
	}
	else if (i == 3) {
		if (InputBox(temp.grade, 40, NULL, "鼎盛中华票务系统", "输入评分\n例：评分8.5(输入完后按确认按钮)", 400, 200, false)) {
			if (temp.grade[0] != Mhead->grade[0] && temp.grade[1] != Mhead->grade[1] || temp.grade[2] != Mhead->grade[2] && temp.grade[3] != Mhead->grade[3]) {
				outtextxy(500, 400, "输入错误");
				Sleep(1000);
				return;
			}
		}
		else return;
		for (M *current = Mhead; current != NULL; current = current->next)
		{
			if (!strcmp(current->name, p->name))
			{
				strcpy_s(current->grade, p->grade);
			}
		}
	}
	else if (i == 4) {
		if (InputBox(temp.money, 40, NULL, "鼎盛中华票务系统", "输入金额\n例：票价48元(输入完后按确认按钮)", 400, 200, false)) {
			if (temp.money[0] != Mhead->money[0] && temp.money[1] != Mhead->money[1] || temp.money[2] != Mhead->money[2] && temp.money[3] != Mhead->money[3]) {
				outtextxy(500, 400, "输入错误");
				Sleep(1000);
				return;
			}
		}
		else return;
		for (M *current = Mhead; current != NULL; current = current->next)
		{
			if (!strcmp(current->name, p->name))
			{
				strcpy_s(current->money, p->money);
			}
		}
	}
	else if (i == 5) {
		outtextxy(500, 400, "正在删除");
		Sleep(500);
		for ( M *current = session; current != NULL; current = current->next)
		{
			if (p == session) {
				if (session->next == NULL) {
					free(p);
					session = NULL;
				}
				else {
					session = session->next;
					free(p);
				}
				break;
			}
			else if (current->next == p) {
				current->next = p->next;
				free(p);
				break;
			}
		}
		
	}
	if (i != 5) {
		*p = temp;
	}
	Finallyfx(session);
	outtextxy(500, 400, "修改成功");
	Sleep(1000);
	DownInform();
}
M *Creatsession(M *p) {
	M *current=NULL, *tail=NULL;
	M *current2 = NULL,*tail2=NULL;
	M *head = NULL;
	for (current = Mhead; current != NULL; current = current->next)
	{
		if (!strcmp(current->name, p->name))
		{
			current2 = (M*)malloc(sizeof(M));
			if (head == NULL) {
				head = current2;
			}
			else {
				tail->next = current2;
			}
			*current2 = *current ;
			current2->next = NULL;
			tail = current2;
		}
	}
	for (current2 = head; current2->next != NULL; current2 = current2->next)
	{
		for (tail2 = head; tail2->next != NULL; tail2 = tail2->next)
		{

			if ((strcmp(tail2->times, tail2->next->times) > 0 && strlen(tail2->times) == strlen(tail2->next->times)&& tail2->times[0] >= tail2->next->times[0])||(tail2->times[0]==tail2->next->times[0]&&strlen(tail2->times)>strlen(tail2->next->times)))
			{
				char temp[40];
				strcpy_s(temp, tail2->next->grade);
				strcpy_s(tail2->next->grade, tail2->grade);
				strcpy_s(tail2->grade, temp);
				strcpy_s(temp, tail2->next->money);
				strcpy_s(tail2->next->money, tail2->money);
				strcpy_s(tail2->grade, temp);
				strcpy_s(temp, tail2->next->name);
				strcpy_s(tail2->next->name, tail2->name);
				strcpy_s(tail2->name, temp);
				for (int i = 0; i < 8; i++)
				{
					strcpy_s(temp, tail2->next->site[i]);
					strcpy_s(tail2->next->site[i], tail2->site[i]);
					strcpy_s(tail2->site[i], temp);
				}
				strcpy_s(temp, tail2->next->times);
				strcpy_s(tail2->next->times, tail2->times);
				strcpy_s(tail2->times, temp);
				strcpy_s(temp, tail2->next->venue);
				strcpy_s(tail2->next->venue, tail2->venue);
				strcpy_s(tail2->venue, temp);
			}
		}
	}
	return head;
}
void fang(M *head)
{ 
	M *current = head;
	M *tail = NULL;
	while (current != NULL)
	{
		tail = current;
		current = current->next;
		free(tail);
	}
}
void Finallyfx(M *p) {
	M *current1=NULL, *current2 = NULL;
	current1 = Mhead;
	current2 = p;
	M *temp;
	M *t = NULL;
	for (; current1 != NULL && current2 != NULL;)
	{
		if (!strcmp(current1->name, current2->name)) {
			temp = current1->next;
			*current1 = *current2;
			current1->next = temp;
			t = current1;
			current1 = current1->next;
			current2 = current2->next;
		}
		else {
			t = current1;
			current1 = current1->next;
		}
	}
	
	for (current1=t; current1->next != NULL; current1 = current1->next)
	{
		if (!strcmp(current1->next->name, p->name)) {
			temp = current1->next;
			current1->next = current1->next->next;
			free(temp);
			break;
		}
	}
}
