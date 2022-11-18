#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

double Func(double x) {
  return (pow(x,3)/20)-(5*pow(x,2))+1000;
}
int Max1 (int value1, int value2){
if(value1 > value2){
    return value1;

}else{
return value2;
}
}
void Method_chord(double a, double b, double EPSILON, int Debug, int Values_Print) {
  double x_next = 0;
  double tmp;
  int WhatToDoo;
  int ValuesPrinedCounter;

  do {
    tmp = x_next;
    x_next = b - Func(b) * (a - b) / (Func(a) - Func(b));
    a = b;
    b = tmp;

    if (Debug == 1) {
      printf("root  = %lf\n", x_next);
      ValuesPrinedCounter ++;
      if (ValuesPrinedCounter > Values_Print) {

        printf("\n ��������� ������� �������� � ������� ���������� ��� ��������� ������, �� ������ ��� :");
        printf("\n 0) ���������� � ����� � ������� ��������;");
        printf("\n 1) �������� �������� �� ����, ���� �� ������ �������� ����� �������; ");
        printf("\n 2) ����� �� ��������, ����� ������� ������ �� ����� ��������� �������� ��������� ���������;");
        printf("\n ���� ²���²��: ");

        scanf("\n %d", &WhatToDoo);

        printf("\n");

        if (WhatToDoo == 0) {
          ValuesPrinedCounter = 0;
        }
        if (WhatToDoo == 1) {
          Debug = 0;
        }
        if (WhatToDoo == 2) {
          break;
        }
      }
    }
  } while (abs(x_next - b) > EPSILON);

  printf("\n method_chord = %f \n\n", x_next); // ���� ���������� ����������
}
void Method_bisection(double a, double b, double EPSILON, int Debug, int Values_Print) {
  double c = a;
  int WhatToDoo;
  int ValuesPrinedCounter;

  while ((b - a) >= EPSILON) {
    c = (a + b) / 2;
    if (Func(c) == 0.0) {
      break;
    }
    else if (Func(c) * Func(a) < 0) {
      b = c;
    }
    else {
      a = c;
    }

    if (Debug == 1) {
      printf("root  = %lf\n", c);
      ValuesPrinedCounter ++;
      if (ValuesPrinedCounter >= Values_Print) {

        printf("\n ��������� ������� �������� � ������� ���������� ��� ��������� ������, �� ������ ��� :");
        printf("\n 0) ���������� � ����� � ������� ��������;");
        printf("\n 1) �������� �������� �� ����, ���� �� ������ �������� ����� �������; ");
        printf("\n 2) ����� �� ��������, ����� ������� ������ �� ����� ��������� �������� ��������� ���������;");
        printf("\n ���� ²���²��: ");

        scanf("\n %d", &WhatToDoo);

        printf("\n");

        if (WhatToDoo == 0) {
          ValuesPrinedCounter = 0;
        }
        if (WhatToDoo == 1) {
          Debug = 0;
        }
        if (WhatToDoo == 2) {
          break;
        }
      }
    }
  }

  printf("\n method_bisection = %lf\n", c); // ���� ���������� ����������
}

int main() {
    int value1=2;
    int value2=4;
    int value=Max1(value1,value2);


  double input_A = -10, input_B = 20, input_Epsilon = 0.01;
  int Metod_Used;
  double Start_Time;
  int Debug, Values_Print;
  int ValuesPrinedCounter;

printf("Max1 = %d", Max1(1,2));
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);

  printf("\n ������� ����� ���������� �������:\n");
  printf("\n   1 - ������� ����������� ������");
  printf("\n   2 - ������� ����");


  while (1) { // ������ ����� �� ���� ������ � ���������� ���������� ����������
    printf("\n �������� ����� : ");
    scanf("%d", &Metod_Used);
    if (Metod_Used != 1 && Metod_Used != 2) {
      printf("\n Error please try egain ");
    } else {
      break;
    }
  };

  printf("\n �� ������� ���� �������� ���������� ? 0-ͳ 1-��� : "); // �� ������� ���� �������� ����������
  scanf("%d", &Debug);
  if (Debug == 1) {
    printf("\n ������� �������� � ������� ���������� ��� ��������� ������, �� ������ ��� :");
    scanf("%d", &Values_Print);
  }

  printf("\n ������ a, b, eps:");
  while (1) {
    printf("\n a, b, eps = ");
    scanf("%d %d %fl", &input_A, &input_B, &input_Epsilon);
    if (Func(input_A) * Func(input_B) >= 0) {
      printf("\n Error please try egain ");
    } else {
      break;
    }
  };
  printf("\n");


  Start_Time = clock();// ������ ���

  if (Metod_Used == 1) {
    Method_bisection(input_A, input_B, input_Epsilon, Debug, Values_Print);
  } else {
    Method_chord(input_A, input_B, input_Epsilon, Debug, Values_Print);
  }

  printf("\n ���������� ��� �� ���������� = %f Sec\n\n", clock() - Start_Time);

  return 0;
}
