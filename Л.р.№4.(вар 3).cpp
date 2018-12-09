// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream.h>
#include <vcl.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

template<class T>
T Reset(T massive1[2][3], T X[2], bool &opr)
{
	int k, h, k1, h1;
	bool b = 0;
	float A[2][3], Raz, elem, H = 1, det, Sum;

	int n = 2;

	for (k = 0; k < n; k++)
		for (h = 0; h < n + 1; h++)
			A[k][h] = massive1[k][h];

	
	for (k = 0; k < n - 1; k++)
	{

		if (A[k][k] == 0)
		{
			b = 0;
			for (k1 = k + 1; k1 < n; k1++)
				if (A[k1][k] != 0)
				{
					for (int kk = 0; kk < n + 1; kk++)  // 1
					{
						elem = A[k1][kk];
						A[k1][kk] = A[k][kk];
						A[k][kk] = elem;
					}
					
					H = -H;
					b = 1;
					break;
				}
			if (b == 0)
			{
				k++; break;
			}
		}

		for (k1 = k + 1; k1 < n; k1++)
		{
			Raz = A[k1][k] / A[k][k];

			for (h1 = k; h1 < n + 1; h1++)
				A[k1][h1] -= Raz * A[k][h1];
		}

	}

	if (H == -1)
	{
		for (k = 0; k < n; k++)
			for (h = 0; h < n + 1; h++)
				A[k][h] = -A[k][h];
	}

	det = 1;
	for (k = 0; k < n; k++)
		det *= A[k][k];

	
	if (det == 0)
	{
		opr = false;
	}
	else
	{

		opr = true;

		X[n - 1] = A[n - 1][n] / A[n - 1][n - 1];

		for (k = n - 2; k >= 0; k--)
		{
			Sum = 0;
			for (h = k + 1; h < n; h++)
				Sum += X[h] * A[k][h];

			X[k] = (A[k][n] - Sum) / A[k][k]; 

		}


	}//det!=0

	return *X;
}


float Array(float mas[2][3], float x1, float y1, float x2, float y2, float x3, float y3)
{

	mas[0][0] = 2 * x1 + 2 * x2 - 2 * 2 * x3;
	mas[1][0] = 2 * x1 + 2 * x3 - 2 * 2 * x2;

	mas[0][1] = 2 * y1 + 2 * y2 - 2 * 2 * y3;
	mas[1][1] = 2 * y1 + 2 * y3 - 2 * 2 * y2;

	mas[0][2] = x1 * x1 + x2 * x2 - 2 * x3*x3 + y1 * y1 + y2 * y2 - 2 * y3*y3;
	mas[1][2] = x1 * x1 + x3 * x3 - 2 * x2*x2 + y1 * y1 + y3 * y3 - 2 * y2*y2; 
	return **mas;
}


float Rad(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
{
	float R, ugl;

	if ((x1 == x0 && y1 == y0) || (x2 == x0 && y2 == y0) || (x3 == x0 && y3 == y0))
	{
		R = 0; return R;
	}

	else
	{
		if (x1 != x0)
		{
			ugl = atan((y1 - y0) / (x1 - x0));
			R = (x1 - x0) / cos(ugl);
			return R;
		}

		if (x2 != x0)
		{
			ugl = atan((y2 - y0) / (x2 - x0));
			R = (x2 - x0) / cos(ugl);
			return R;
		}

		if (x3 != x0)
		{
			ugl = atan((y3 - y0) / (x3 - x0));
			R = (x3 - x0) / cos(ugl);
			return R;
		}
		
	}
}


void main()
{
	int n = 2, m, k, h;
	float m_1[2][3];
	float an_1[2];
	float  **To, **Mn;
	float R;
	float x0, y0;
	float Total[9];
	int size = 0, step = 0;

	bool bb = 0, b, opr = 0;

	cout << "Kolichestvo tochek na 1-om mnojestve \n\n n1=";
	cin >> n;
	cout << "Kolichestvo tochek na 2-om  mnojestve \n\n n2=";
	cin >> m;

	To = new float *[n]; 

	for (int k = 0; k < n; k++)
		To[k] = new float[2];

	Mn = new float *[m];  

	for (int k = 0; k < m; k++)
		Mn[k] = new float[2];

	cout << "\n\n";

	cout << "\n\n 1-oe mnojestvo\n\n";
	for (int k = 0; k < n; k++)
	{
		cout << "X" << k + 1 << "=";
		cin >> To[k][0];
		cout << "Y" << k + 1 << "=";
		cin >> To[k][1];
	}

	cout << "\n\n 2-oe mnojestvo\n\n";
	for (int k = 0; k < m; k++)
	{
		cout << "X" << k + 1 << "=";
		cin >> Mn[k][0];
		cout << "Y" << k + 1 << "=";
		cin >> Mn[k][1];
	}


	float Otv[3];
	float  r, x1, y1, x2, y2, x3, y3;

	for (int k1 = 0; k1 < n - 2; k1++)
		for (int k2 = k1 + 1; k2 < n - 1; k2++)
			for (int k3 = k2 + 1; k3 < n; k3++)
			{

				x1 = To[k1][0];
				x2 = To[k2][0];
				x3 = To[k3][0];

				y1 = To[k1][1];
				y2 = To[k2][1];
				y3 = To[k3][1];

				Array(m_1, x1, y1, x2, y2, x3, y3);
				Reset<float>(m_1, an_1, &bb);

				x0 = an_1[0];
				y0 = an_1[1];
				R = Rad(x0, y0, x1, y1, x2, y2, x3, y3);

				b = 1;

				for (int k = 0; k < m; k++)
				{
					r = sqrt((Mn[k][0] - x0)*(Mn[k][0] - x0) + (Mn[k][1] - y0)*(Mn[k][1] - y0));

					if (r > R)
					{
						b = 0; break;
					}
				}

				if (b)
				{
					opr = 1;
					if (step == 0)
					{
						Total[0] = R;
						Total[1] = x0;
						Total[2] = y0;
						Total[3] = x1;
						Total[4] = y1;
						Total[5] = x2;
						Total[6] = y2;
						Total[7] = x3;
						Total[8] = y3;
						step++;
					}
					else
					{
						if (Total[0] > R)
						{
							Total[0] = R;
							Total[1] = x0;
							Total[2] = y0;
							Total[3] = x1;
							Total[4] = y1;
							Total[5] = x2;
							Total[6] = y2;
							Total[7] = x3;
							Total[8] = y3;
						}
					}
				}

			

	if (step == 0)
		cout << "Takaya okrujnost ne suwestvuet";

	else
	{

		cout << endl;
		cout << "x0=" << Total[1] << endl;
		cout << "y0=" << Total[2] << endl;
		cout << "R=" << Total[0] << endl;

		cout << "\n\n\n Udv. toch.\n\n";

		cout << "(" << Total[3] << "," << Total[4] << ")\n";
		cout << "(" << Total[5] << "," << Total[6] << ")\n";
		cout << "(" << Total[7] << "," << Total[8] << ")\n";

	}
	getch();
	return;
}